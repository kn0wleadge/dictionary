#include "addword.h"
#include "ui_addword.h"

addWord::addWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWord)
{
    ui->setupUi(this);
}

addWord::~addWord()
{
    delete ui;
}
void addWord::addWordButtonClicked()
{
    std::vector<QString> newVec(3);
    newVec[0]= ui->lineEdit->text();
    newVec[1] = ui->lineEdit_2->text();
    newVec[2] = ui->lineEdit_3->text();
    emit SignalAddNewWordToDb(newVec);
}
