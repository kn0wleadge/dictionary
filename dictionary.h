#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "includes.h"
#include "addword.h"
#include "wordlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class dictionary; }
QT_END_NAMESPACE

class dictionary : public QMainWindow
{
    Q_OBJECT

public:
    dictionary(QWidget *parent = nullptr);
    ~dictionary();
private slots:
    void on_pushButton_clicked();
    //void addNewWordToDatabase();
    void adding(std::vector<QString> someVec);

    void on_pushButton_3_clicked();

private:
    Ui::dictionary *ui;



    QSqlDatabase db;
    QSqlQuery* dbQ;
    QSqlTableModel* dbModel;

    //QWidget* addWordWindow;
    addWord* addWordWindow;
    WordList* wordList;


};
#endif // DICTIONARY_H
