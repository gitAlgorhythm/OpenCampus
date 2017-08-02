#ifndef CAESAR_H
#define CAESAR_H

#include <QtWidgets>
#include <sstream>

class Question : public QDialog
{
    Q_OBJECT
private:
    QLabel      *plainText,
                *arrow,
                *result,
                *process;
    QPushButton *encryptButton,
                *decryptButton;
    QLineEdit   *inputText,
                *inputKey;

private slots:
    void Encrypt();
    void Decrypt();

public:
    explicit Question(QWidget *parent = 0);
};

#endif
