#!/bin/sh

qmake -project

#Qt5 & C++14に対応
sed -i -e '$a QT += widgets' *.pro
sed -i -e '$a CONFIG += c++14' *.pro

qmake 

make



