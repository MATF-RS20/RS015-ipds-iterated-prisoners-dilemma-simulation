#include "help.h"
#include "ui_help.h"
#include <fstream>
#include <iostream>

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);

    std::ifstream htmlFile;
    std::string line;
    htmlFile.open(":/HTML/Help.html");
    if (htmlFile)
    {
        std::string line;
        while (htmlFile >> line) {
                std::cout << line << std::endl;
                ui->mdText->append(QString::fromStdString(line));
            }
    }

}

Help::~Help()
{
    delete ui;
}
