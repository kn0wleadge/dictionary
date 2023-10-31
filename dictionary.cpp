#include "dictionary.h"
#include "./ui_dictionary.h"


dictionary::dictionary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dictionary)
{
    ui->setupUi(this);

    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDb.db");
    db.setUserName("db");
    db.setPassword("qwe");
    if(!db.open())
    {
        qDebug("not opened");
    }
    else
    {
        qDebug("opened");
    }
    dbQ = new QSqlQuery(db);
    dbQ->exec("CREATE TABLE Dictionary(In english TEXT, In Russian TEXT, Transcription TEXT);");

//    dbModel = new QSqlTableModel(this,db);
//    dbModel->setTable("Dictionary");
//    dbModel->select();

}

dictionary::~dictionary()
{
    delete ui;
}

void dictionary::adding(std::vector<QString> someVec)
{
    dbModel->insertRow(1);
    dbModel->setData(dbModel->index(dbModel->rowCount(),0),someVec[0]);
    dbModel->setData(dbModel->index(dbModel->rowCount(),1),someVec[1]);
    dbModel->setData(dbModel->index(dbModel->rowCount(),2),someVec[2]);

}
void dictionary::on_pushButton_clicked()
{

    addWord* addWordWindow = new addWord();
    connect(addWordWindow, SIGNAL(SignalAddNewWordToDb(std::vector)),this,SLOT(adding(std::vector)));
    addWordWindow->show();
    dbModel = new QSqlTableModel(addWordWindow,db);
    dbModel->setTable("Dictionary");
    dbModel->select();




}

