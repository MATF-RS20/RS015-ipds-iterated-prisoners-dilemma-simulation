#include "simulation.h"

Simulation::Simulation(const unsigned foodNo, std::vector<unsigned> &specimenNoInfo)
    : m_foodNo(foodNo)
{
    m_specimenNo = std::accumulate(std::begin(specimenNoInfo), std::end(specimenNoInfo), 0);
    m_graphInfo.update(specimenNoInfo);

    int size = static_cast<int>(specimenNoInfo.size());
    for(int i = 0; i < size; i++){
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < specimenNoInfo[i]; j++)
        {
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
        }
    }

    initializeFood();
    log();
}


Simulation::Simulation(const Simulation& other)
{
    m_foodNo = other.m_foodNo;
    m_specimenNo = other.m_specimenNo;

    int size = static_cast<int>(other.m_specimen.size());

    for(int i = 0; i < size; i++)
    {
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < other.m_specimen[i].size() ; j++)
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
    }

    m_graphInfo = other.m_graphInfo;
    initializeFood();

}

Simulation& Simulation::operator=(const Simulation& other)
{
    m_foodNo = other.m_foodNo;
    m_specimenNo = other.m_specimenNo;
    m_graphInfo = other.m_graphInfo;

    int size = static_cast<int>(other.m_specimen.size());
    for(int i = 0; i < size; i++)
    {
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < other.m_specimen[i].size() ; j++)
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
    }

    initializeFood();

    return *this;
}

const StateHistory Simulation::graphInfo() const
{
    return m_graphInfo;
}

void Simulation::updateFoodsVectorWithNullptrs()
{
    m_noOfNullptrsAdditions = m_specimenNo - 2*m_foodNo;

    if(m_noOfNullptrsAdditions > 0) {
        m_foodsActive.erase(std::begin(m_foodsActive) + m_foodNo, std::end(m_foodsActive));
        for(int i = 0; i < m_noOfNullptrsAdditions; i++)
        {
            m_foodsActive.push_back(nullptr);
        }
    }
    else if(m_noOfNullptrsAdditions <= 0)
        m_foodsActive.erase(std::begin(m_foodsActive) + m_foodNo, std::end(m_foodsActive));
}

void Simulation::initializeFood()
{    
    double randa;

    // Generates random position inside a circle
    // randr signifies the distance from the center,
    // randa signifies the angle for the polar coordinates
    for(unsigned i = 0; i < m_foodNo; i++)
    {
        double r = static_cast<double>(qrand())/RAND_MAX;
        r = r*100;

        randa = static_cast<double>(qrand())/RAND_MAX;
        double tmpX = r * std::cos(randa * 2 * M_PI);
        double tmpY = r * std::sin(randa * 2 * M_PI);

        /*Adds the generated food to the appropriate attribute*/
        Food* tmpFood = new Food(tmpX, tmpY, i);

        m_foodsActive.push_back(tmpFood);
    }

    updateFoodsVectorWithNullptrs();

}

std::shared_ptr<Specimen> Simulation::specimenFactory(strategy indicator)
{

    switch(indicator)
    {
    case (E_DOVE):
        return std::make_shared<Dove>();
    case (E_RANDOM):
        return std::make_shared<AllRandom>();
    case (E_HAWK):
        return std::make_shared<Hawk>();
    case (E_PAVLOV):
        return std::make_shared<Pavlov>();
    case (E_TITFORTAT):
        return std::make_shared<TitForTat>();
    case (E_TWOTITSFORTAT):
        return std::make_shared<TwoTitsForTat>();
    case (E_TITFORTWOTATS):
        return std::make_shared<TitForTwoTats>();
    default:
        return nullptr;
    }
}

int Simulation::randomFoodIndexPicker(unsigned foodsRndCounter)
{
    // Obtaining random number from hardware
    std::random_device rd;

    // Mersenne Twister random number generator
    // https://en.wikipedia.org/wiki/Mersenne_Twister
    std::mt19937 eng(rd());

    /* Produces random int from a range where each
     * number from a range has equal likelihood to
     * be produced
     */
    std::uniform_int_distribution<> distr(foodsRndCounter, m_foodsActive.size()-1);

    return static_cast<unsigned>(distr(eng));
}

void Simulation::swapFoods(unsigned a, unsigned b)
{
    Food* tmp = m_foodsActive[a];
    m_foodsActive[a] = m_foodsActive[b];
    m_foodsActive[b] = tmp;
}

void Simulation::assignFoods()
{
    unsigned assFood;
    unsigned foodsRndCounter = 0;

    for(unsigned i = 0; i < m_specimen.size(); i++)
    {
        for(unsigned j = 0; j < m_specimen[i].size() ; j++)
        {
            assFood = randomFoodIndexPicker(foodsRndCounter);
            if(m_foodsActive[assFood] != nullptr)
            {
                m_foodsActive[assFood]->addSpecimen(m_specimen[i][j]);
                if(m_foodsActive[assFood]->noOfSpecimen() == 2)
                {
                    swapFoods(foodsRndCounter, assFood);                 
                    foodsRndCounter++;
                }
            }
            else {
               m_specimen[i][j]->setTarget(420.0,420.0);
               m_specimen[i][j]->toggleGotLeftOut();
               swapFoods(foodsRndCounter, assFood);
               foodsRndCounter++;
            }
        }
    }

    std::sort(std::begin(m_foodsActive), std::end(m_foodsActive),
              [](const Food* a, const Food* b)
                {
                    if(a != nullptr && b != nullptr)
                        return a->id() < b->id();
                    else if(a == nullptr)
                        return false;
                    else if(b == nullptr)
                        return true;
                    else
                        return true;
                });

}

void Simulation::specimenDeath(unsigned r, unsigned c)
{
    m_specimen[r].erase(std::begin(m_specimen[r]) + c);
}

void Simulation::specimenReproduce(unsigned r)
{
    std::shared_ptr<Specimen> tmp = specimenFactory(static_cast<strategy>(r));
    m_specimen[r].push_back(tmp);
    m_newSpecimen.push_back(tmp);
}

void Simulation::clearAssignedFoods()
{
    for(unsigned i = 0; i < m_foodNo; i++)
    {
        m_foodsActive[i]->releaseSpecimen();
        m_foodsActive[i]->resetNoOfSpecimen();
    }
}

double randomUniform(double a, double b){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(a, b);
    return dis(gen);
}

void Simulation::simulate()
{
    playRound();
}

void Simulation::playRound()
{
    fightForFood();
    generationalChange();
    log();
}

void Simulation::fightForFood(void){

    // Set everyone to death, so that only
    // those who get another setting during
    // fights will survive
    for(auto strategy : m_specimen){
        for(auto specimen : strategy){
            specimen->resetTotalFoodEaten();
        }
    }

    // Let specimen pick foods
    assignFoods();

    // Fight it out
    for(auto food : m_foodsActive){
        if(food != nullptr) {
            switch(food->noOfSpecimen()){
                case 0:
                    // no specimen fighting over this food
                break;

                case 1:
                    // food claimed by the first specimen
                food->specimen1->update(T,-1);
                break;

                case 2:
                    // two specimen fighting over food
                    std::shared_ptr<Specimen> spec1 = food->specimen1;
                    std::shared_ptr<Specimen> spec2 = food->specimen2;
                    bool coop1 = spec1->isCooperating(spec2->SPECIMEN_ID);
                    bool coop2 = spec2->isCooperating(spec1->SPECIMEN_ID);
                    if(coop1 && coop2){
                        spec1->update(R,spec2->SPECIMEN_ID);
                        spec2->update(R,spec2->SPECIMEN_ID);
                    }
                    else if(coop1){
                        spec1->update(S,spec2->SPECIMEN_ID);
                        spec2->update(T,spec1->SPECIMEN_ID);
                    }
                    else if(coop2){
                        spec1->update(T,spec2->SPECIMEN_ID);
                        spec2->update(S,spec1->SPECIMEN_ID);
                    }
                    else{
                        spec1->update(P,spec2->SPECIMEN_ID);
                        spec2->update(P,spec2->SPECIMEN_ID);
                    }
                break;
            }
        }
    }

    clearAssignedFoods();
}

void Simulation::generationalChange(void){
    m_newSpecimen.clear();

    enum res{
        SURVIVE,
        DIE,
        REPRODUCE
    };

    std::vector<std::vector<res>> resVec;

    double p = 0.75;
    for(unsigned i=0; i<strategy::COUNT; i++){
        resVec.push_back(std::vector<res>());
        for(unsigned j=0; j<m_specimen[i].size(); j++){
            int ate = m_specimen[i][j]->getTotalFoodEaten();
            m_specimen[i][j]->resetTotalFoodEaten();

            switch(ate){
                case 0:
                    resVec[i].push_back(DIE);
                break;

                case 1:
                    if(randomUniform(0.0,1.0)<p){
                        resVec[i].push_back(DIE);
                    }
                    else{
                        resVec[i].push_back(SURVIVE);
                    }
                break;

                case 3:
                    if(randomUniform(0.0,1.0)<p){
                        resVec[i].push_back(REPRODUCE);
                    }
                    else{
                        resVec[i].push_back(SURVIVE);
                    }
                break;

                case 4:
                    resVec[i].push_back(REPRODUCE);
                break;
            }
        }
    }

    int size = static_cast<int>(resVec.size());
    for(int i=0; i<size; i++){
        if(resVec[i].empty())
            continue;

        int iSize = static_cast<int>(resVec[i].size());
        for(int j=iSize-1; j>=0; j--){
            if(resVec[i][j]==DIE){
                specimenDeath(i,j);
            }
            else if(resVec[i][j]==REPRODUCE){
                specimenReproduce(i);
            }
        }
    }

    updateSpecimenNo();
}

void Simulation::log()
{
    std::vector<unsigned> iterationInfo(strategy::COUNT);
    for(unsigned i = 0; i < strategy::COUNT; i++){
        iterationInfo[i] = m_specimen[i].size();
    }
    m_graphInfo.update(iterationInfo);
}


void Simulation::updateSpecimenNo(void){
    m_specimenNo=0;
    for(auto strategy : m_specimen){
        m_specimenNo += strategy.size();
    }
    updateFoodsVectorWithNullptrs();
}
