#!/bin/sh

export PATH="/opt/Qt/5.5/gcc/bin:"$PATH
qmake -project

#Qt5 & C++14に対応
sed -i -e '$a QT += widgets' *.pro
sed -i -e '$a CONFIG += c++14' *.pro

qmake 

make



