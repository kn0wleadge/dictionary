#include "dictionary.h"
#include "./ui_dictionary.h"


dictionary::dictionary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dictionary)
    ,addWordWindow(new addWord(nullptr))
{
    ui->setupUi(this);
    bool connectOpenAddWordWindow = connect(this->ui->addWordButton,&QPushButton::clicked,
                                            this,dictionary::openAddWordWindow);
    bool connectOpenWordListWindow = connect(this->ui->wordListButton,&QPushButton::clicked,
                                             this,&dictionary::openWordListWindow);
    bool connectInsertingWord = connect(this->addWordWindow,&addWord::SignalAddNewWordToDb,
                                        this,&dictionary::SlotAdding);
    qDebug()<<connectOpenAddWordWindow<<connectOpenWordListWindow << connectInsertingWord;

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
    dbQ->exec("CREATE TABLE dictionary(InEnglish TEXT, InRussian TEXT, Transcription TEXT);");
    if(dbQ->isActive())
    {
        qDebug("\n active");
    }
    else
    {
        qDebug("not active");
        qDebug()<<"database query error"<<dbQ->lastError();
    }


}

dictionary::~dictionary()
{
    delete ui;
}

void dictionary::SlotAdding()
{
    qDebug()<<"new word adding connected";
    std::vector<QString> newWord = this->addWordWindow->getNewWord();
    qDebug()<<newWord[0]<<newWord[1]<<newWord[2];
    dbQ->prepare("INSERT INTO Dictionary (InEnglish, InRussian, Transcription) VALUES(:engWord,:rusWord,:transc);");
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


void dictionary::openWordListWindow()
{
    dbModel= new QSqlTableModel(this,this->db);
    dbModel->setTable("dictionary");
    qDebug()<<"database model error"<<dbModel->lastError();

    wordList = new WordList(nullptr,dbModel);
    qDebug()<<"wordList window opening connected";

  wordList->show();
}

