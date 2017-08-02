#include "caesar.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Question::Question(const char *font, QWidget *parent) : QDialog(parent)
{
    setMaximumSize(1280,960);
    setMinimumSize(1280,960);
    resize(1280,960);

    plainText = new QLabel("テキストがここに表示されます", this);
    plainText->setFont(QFont(font, 38, QFont::Bold));
    plainText->setAlignment(Qt::AlignCenter);
    plainText->setGeometry(0,80,1280,100);

    result = new QLabel("", this);
    result->setFont(QFont(font, 38, QFont::Bold));
    result->setAlignment(Qt::AlignCenter);
    result->setGeometry(0,130,1280,200);

    process = new QLabel("", this);
    process->setFont(QFont(font, 20, QFont::Normal));
    process->setAlignment(Qt::AlignLeft);
    process->setGeometry(680,180,400,50);

    auto textLabel = new QLabel("Text",this);
    textLabel->setFont(QFont(font, 15, QFont::Bold));
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setGeometry(80,380,520,80);

    auto textKey = new QLabel("Key",this);
    textKey->setAlignment(Qt::AlignCenter);
    textKey->setFont(QFont(font, 15, QFont::Bold));
    textKey->setGeometry(680,380,520,80);

    inputText = new QLineEdit(this);
    inputText->setAlignment(Qt::AlignCenter);
    inputText->setFont(QFont(font, 25, QFont::Normal));
    inputText->setGeometry(80,450,520,80);

    inputKey = new QLineEdit(this);
    inputKey->setAlignment(Qt::AlignCenter);
    inputKey->setFont(QFont(font, 25, QFont::Normal));
    inputKey->setGeometry(680,450,520,80);

    encryptButton = new QPushButton("暗号化",this);
    encryptButton->setFont(QFont(font, 45, QFont::Bold));
    QPalette ebColor = encryptButton->palette();
    ebColor.setColor(QPalette::ButtonText, Qt::red);
    encryptButton->setPalette(ebColor);
    encryptButton->setAutoFillBackground(true);
    encryptButton->setGeometry(80,600,520,200);

    decryptButton = new QPushButton("復号",this);
    decryptButton->setFont(QFont(font, 45, QFont::Bold));
    decryptButton->setGeometry(680,600,520,200);

    connect(inputText, SIGNAL(textChanged(QString)), plainText, SLOT(setText(QString)));
    connect(inputText, SIGNAL(textChanged(QString)), process, SLOT(clear()));
    connect(inputText, SIGNAL(textChanged(QString)), result, SLOT(clear()));
    connect(encryptButton, SIGNAL(clicked()), this, SLOT(Encrypt()));
    connect(decryptButton, SIGNAL(clicked()), this, SLOT(Decrypt()));

}

void Question::Encrypt()
{  
	int a = 97, ra = 65,
	    z = 122, rz = 90;

    stringstream ss; 
    auto ss_clear = [&ss = ss](){ ss.str(""); ss.clear(stringstream::goodbit); }; // sstreamのクリア

    auto keyText = inputKey->text();
    unsigned long long secretKey = keyText.toLongLong() % 26;

    string cipherText = inputText->text().toStdString();

    for ( auto &&c : cipherText ) {
        if ( c > 96 && c < 123 ) //小文字処理
            for ( unsigned long long i = 0; i < secretKey; i++ ) 
                if ( c == z ) c = a; else c++;
        else if ( c > 64 && c < 91 ) //大文字処理
            for ( unsigned long long i = 0; i < secretKey; i++ ) 
                if ( c == rz ) c = ra; else c++;
    }

    ss << keyText.toStdString() << "文字進める";
    process->setText(QString(ss.str().c_str()));
    ss_clear();

    ss << "↓\n" << cipherText;
    result->setText(QString(ss.str().c_str()));
    ss_clear();
}

void Question::Decrypt()
{  
	int a = 97, ra = 65,
	    z = 122, rz = 90;

    stringstream ss;
    auto ss_clear = [&ss = ss](){ ss.str(""); ss.clear(stringstream::goodbit); }; // sstreamのクリア

    auto keyText = inputKey->text();
    unsigned long long secretKey = keyText.toLongLong() % 26;

    string cipherText = inputText->text().toStdString();

    for ( auto &&c : cipherText ) {
        if ( c > 96 && c < 123 ) //小文字処理
            for ( unsigned long long i = 0; i < secretKey; i++ ) 
                if ( c == a ) c = z; else c--;
        else if ( c > 64 && c < 91 ) //大文字処理
            for ( unsigned long long i = 0; i < secretKey; i++ ) 
                if ( c == ra ) c = rz; else c--;
    }

    ss << keyText.toStdString() << "文字戻す";
    process->setText(QString(ss.str().c_str()));
    ss_clear();

    ss << "↓\n" << cipherText;
    result->setText(QString(ss.str().c_str()));
    ss_clear();
}
