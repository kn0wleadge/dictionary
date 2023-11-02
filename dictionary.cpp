#include "dictionary.h"
#include "./ui_dictionary.h"


dictionary::dictionary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dictionary)
    ,addWordWindow(new addWord(nullptr))
{
    ui->setupUi(this);
    bool connectOpenAddWordWindow = connect(this->ui->pushButton,this->ui->pushButton->clicked,this,dictionary::openAddWordWindow);
    bool connectAddingWord = connect(addWordWindow,&addWord::SignalAddNewWordToDb,this,&dictionary::SlotAdding);
    qDebug()<<connectOpenAddWordWindow << connectAddingWord;
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDb.db");
    if(!db.open())
    {
        qDebug("not opened");
    }
    else
    {
        qDebug("opened");
    }
    dbQ = new QSqlQuery(db);
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

void dictionary::SlotAdding()
{
    qDebug()<<"new word adding connected";
    std::vector<QString> newWord = this->addWordWindow->getNewWord();
    dbQ->prepare("INSERT INTO Dictionary (InEnglish, InRussian, Transcription"
              "VALUES(:engWord,:rusWord,:transc)");
    dbQ->bindValue("engWord",newWord[0]);
    dbQ->bindValue("rusWord",newWord[1]);
    dbQ->bindValue("transc",newWord[2]);
    dbQ->exec();
    qDebug()<<dbQ->lastError();

}
void dictionary::openAddWordWindow()
{
    qDebug()<<"addWord window opening connected";
    addWordWindow->show();
}


void dictionary::on_pushButton_3_clicked()
{
  wordList->show();
}

