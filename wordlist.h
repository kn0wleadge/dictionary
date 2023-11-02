#ifndef WORDLIST_H
#define WORDLIST_H

#include <QWidget>
#include "includes.h"
namespace Ui {
class WordList;
}

class WordList : public QWidget
{
    Q_OBJECT

public:
    explicit WordList(QWidget *parent = nullptr, QSqlTableModel* tableModel = nullptr);
    ~WordList();
    //QTableView* tableView;
private:
    Ui::WordList *ui;

};

#endif // WORDLIST_H
