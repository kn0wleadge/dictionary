#include "addword.h"
#include "ui_addword.h"

addWord::addWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWord),
    newWord(3)
{
    ui->setupUi(this);

    connect(ui->addWordButton,&QPushButton::clicked,
            this,&addWord::SlotAddWordButtonClicked);
}

addWord::~addWord()
{
    delete ui;
}


void addWord::SlotAddWordButtonClicked()
{

    qDebug()<<"addWord button works!";
    std::vector<QString> newVec(3);
    newVec[0]= ui->lineEdit->text();
    newVec[1] = ui->lineEdit_2->text();
    newVec[2] = ui->lineEdit_3->text();
    this->newWord = newVec;
    emit this->SignalAddNewWordToDb();

}
std::vector<QString> addWord::getNewWord()
{
    return this->newWord;
}
