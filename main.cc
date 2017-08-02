#include "caesar.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    
    auto dialog = new Question();

    dialog->show();

    return app.exec();
}
