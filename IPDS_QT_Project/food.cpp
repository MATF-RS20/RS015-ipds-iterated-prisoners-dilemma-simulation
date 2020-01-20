#include "food.h"

Food::Food(double posX, double posY, unsigned ID)
    :m_posX(posX)
    ,m_posY(posY)
    ,m_ID(ID)
{
    specimen1 = nullptr;
    specimen2 = nullptr;
    m_noOfSpecimen = 0;
}

Food::Food(const Food &f)
    : QGraphicsItem()
    ,m_posX(f.m_posX)
    ,m_posY(f.m_posY)
    ,m_ID(f.m_ID)
{
    specimen1 = nullptr;
    specimen2 = nullptr;
    m_noOfSpecimen = 0;
}

Food& Food::operator=(Food&& f)
{
    m_posX = f.m_posX;
    m_posY = f.m_posY;
    m_ID = f.m_ID;

    return *this;
}

Food& Food::operator=(Food& f)
{
    m_posX = f.m_posX;
    m_posY = f.m_posY;
    m_ID = f.m_ID;

    return *this;
}

std::string Food::toString()
{
    return "X:" + std::to_string(m_posX) + " Y:" + std::to_string(m_posY);
}

bool Food::addSpecimen(std::shared_ptr<Specimen> newSpecimen)
{
    /* Set coordinates of food as target for this specimen */
    newSpecimen->setTarget(m_posX, m_posY);

    if(specimen1 == nullptr)
    {
        specimen1 = newSpecimen;
        m_noOfSpecimen++;
        return true;
    }
    else if(specimen2 == nullptr)
    {
        specimen2 = newSpecimen;
        m_noOfSpecimen++;
        return true;
    }
    return false;

}
void Food::releaseSpecimen()
{
    specimen1 = nullptr;
    specimen2 = nullptr;
}

int Food::noOfSpecimen() const
{
    return m_noOfSpecimen;
}

unsigned Food::id() const
{
    return m_ID;
}

void Food::resetNoOfSpecimen(void){
    m_noOfSpecimen = 0;
}

QRectF Food::boundingRect() const {
    qreal adjust = -0.5;
    return QRectF(-20 - adjust, -20 - adjust, 10 + adjust, 10 + adjust);
}


QPainterPath Food::shape() const {
    QPainterPath path;

    path.addRect(-10, -20, 10, 10);
    return path;
}

void Food::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)


    /*
     * Point that will signify the top-left corner of where the image will be placed.
     */
    QPoint point(this->m_posX-5, this->m_posY-7.5);


    QString  imgSrc = QString::fromStdString(":/foodPics/food.png");

    QImage image(imgSrc);


    /*
     * We draw the actual image with it's top-left corner being point.
    */
    painter->drawImage(point, image);

    //painter->drawEllipse(3,3,3,3);
}

