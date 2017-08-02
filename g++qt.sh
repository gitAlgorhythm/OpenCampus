#!/bin/sh

sudo apt install make
export PATH="/opt/Qt/5.5/gcc_64/bin:"$PATH
qmake -project

#Qt5 & C++14に対応
sed -i -e '$a QT += widgets' *.pro
sed -i -e '$a CONFIG += c++14' *.pro

qmake 

make



