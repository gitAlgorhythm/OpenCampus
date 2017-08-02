#include "caesar.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
    if (argc != 2) {	
        cerr << "usage : ./caesar [font]\n";
        exit(1);
    }

    QApplication app(argc, argv);
    
    auto dialog = new Question(argv[1]);

    dialog->show();

    return app.exec();
}
