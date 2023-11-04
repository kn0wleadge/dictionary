#ifndef ADDWORD_H
#define ADDWORD_H

#include <QWidget>
#include<vector>
namespace Ui {
class addWord;
}

class addWord : public QWidget
{
    Q_OBJECT

public:
    explicit addWord(QWidget *parent = nullptr);
    ~addWord();
    Ui::addWord *ui;
    std::vector<QString> getNewWord();

private:

    std::vector<QString> newWord;
//    QString rus;
//    QString eng;
//    QString trc;


signals:
    void SignalAddNewWordToDb();

private slots:
    void SlotAddWordButtonClicked();
};

#endif // ADDWORD_H
