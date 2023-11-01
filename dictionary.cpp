#include "dictionary.h"
#include "./ui_dictionary.h"


dictionary::dictionary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dictionary)
{
    ui->setupUi(this);

    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDb.db");
    //db.setUserName("db");
    //db.setPassword("qwe");
    if(!db.open())
    {
        qDebug("not opened");
    }
    else
    {
        qDebug("opened");
    }
    dbQ = new QSqlQuery(db);
    //dbQ->exec("DROP TABLE Dictionary");
    dbQ->exec("CREATE TABLE Dictionary(InEnglish TEXT, InRussian TEXT, Transcription TEXT);");
    if(dbQ->isActive())
    {
        qDebug("\n active");
    }
    else
    {
        qDebug("not active");
        qDebug()<<dbQ->lastError();
    }
    dbModel = new QSqlTableModel(this,db);
    dbModel->setTable("Dictionary");
    dbModel->select();


    qDebug()<<dbModel->lastError();


    addWordWindow = new addWord(nullptr);
    wordList = new WordList(nullptr,dbModel);

}

dictionary::~dictionary()
{
    delete ui;
}

void dictionary::adding(std::vector<QString> someVec)
{
    dbQ->prepare("INSERT INTO Dictionary (InEnglish, InRussian, Transcription"
              "VALUES(:engWord,:rusWord,:transc)");
    dbQ->bindValue("engWord",someVec[0]);
    dbQ->bindValue("rusWord",someVec[1]);
    dbQ->bindValue("transc",someVec[2]);
    dbQ->exec();
    qDebug()<<dbQ->lastError();

}
void dictionary::on_pushButton_clicked()
{


    connect(addWordWindow, SIGNAL(SignalAddNewWordToDb(std::vector)),this,SLOT(adding(std::vector)));
    addWordWindow->show();





}


void dictionary::on_pushButton_3_clicked()
{


    wordList->show();


}

