/* Covered Topics:
1. Constructors and Destructors
2. Friend Functions
3. Operator and Function Overloading
4. Inheritance
5. Polymorphism
6. Templates
7. STL
8. File Handling
9. Dynamic Casting and Type Identification
10. Aggregation
*/

/* Extra Topics:
1. Graphics and Animations
2. Music
3. Markup Language, Stylesheet and css
*/
#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(&a);
    w.show();

    QFile file(":/assets/style/stylesheet.css");
    file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    a.setStyleSheet(stylesheet);
    file.close();

    //Recursion running on the main application class
    return a.exec();
}
