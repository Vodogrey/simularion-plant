/*когда я начинал писать это, я еще что-то понимал
 * но времена изменились. это уже не остановить.
 * хаос пришел в нааши дома
 * я посвящаю свой код самому близкому мне существу
 * компилятору
 * пожалуйста, смилуйся надо мной. тут все плохо
 *
 */
#include <qapplication.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qsrand(time(NULL));

    return a.exec();
}
