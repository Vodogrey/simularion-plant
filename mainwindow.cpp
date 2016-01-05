#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    :QMainWindow(parent)
{
    GUI();
    Buttons();

}

MainWindow::~MainWindow()
{

}

void MainWindow::GUI()
{
    m_layout = new QGridLayout();
    m_widget = new QWidget();
    m_pb_start = new QPushButton("Start");
    m_pb_pause = new QPushButton("Pause");
    m_pb_stop = new QPushButton("Stop");
    m_le_input = new QLineEdit();
    m_lb_input = new QLabel("Введите число частей");
    m_lb_countDetals = new QLabel();
    outCountDetals = new QLabel();
    outPerfomance = new QLabel();

    m_actions = new MainActoins();

    m_layout->addWidget(m_lb_countDetals, 1, 1, 5, 1);
    m_layout->addWidget(m_lb_input, 1, 5, 1, 4);
    m_layout->addWidget(m_le_input, 1, 10, 1, 1);
    m_layout->addWidget(m_pb_start, 2, 8, 1, 1);
    m_layout->addWidget(m_pb_pause, 2, 9, 1, 1);
    m_layout->addWidget(m_pb_stop, 2, 10, 1, 1);
    m_layout->addWidget(outCountDetals, 3, 1, 4, 5);
    m_layout->addWidget(outPerfomance, 3, 6, 3, 3);

    m_widget->setLayout(m_layout);
    this->setCentralWidget(m_widget);
}

void MainWindow::Buttons()
{
    connect(this, SIGNAL(processOn()), m_actions, SLOT(Process()));
    connect(m_pb_pause, SIGNAL(clicked()), this, SLOT(slot_pb_pause()));
    connect(m_pb_stop, SIGNAL(clicked()), this, SLOT(slot_pb_stop()));
    connect(m_pb_start, SIGNAL(clicked()), this, SLOT(slot_pb_start()));
    connect(this, SIGNAL(getCountDetals(QChar)),m_actions, SLOT(slot_getCountDetals(QChar)));
    connect(m_actions,SIGNAL(updateStats()), this, SLOT(slot_outResult()));
    connect(this,SIGNAL(getProcessTime(QChar,int)), m_actions, SLOT(slot_getProcessTime(QChar,int)));
}

void MainWindow::slot_pb_start()
{
    int count = m_le_input->text().toInt();
    qDebug() << count;
    m_pb_start->setDisabled(true);
    emit processOn();
}

void MainWindow::slot_pb_pause()
{
    QEventLoop loop;
    if(pauseEnabled) {
        pauseEnabled = false;
        loop.exit(0);
    }
    else {
        QTimer::singleShot(99999,&loop,SLOT(quit()));
        loop.exec();
        pauseEnabled = true;
    }
    qDebug() << "pause is " << pauseEnabled;
}

void MainWindow::slot_pb_stop()
{

}


void MainWindow::slot_outResult()
{
    outCountDetals->clear();
    outCountDetals->setText(QString("Деталей А: %1").arg(getCountDetals('A')) +
                 QString("\nДеталей B: %1").arg(getCountDetals('B')) +
                 QString("\nДеталей C: %1").arg(getCountDetals('C')) +
                 QString("\nДеталей D: %1").arg(getCountDetals('D')) +
                 QString("\nДеталей E: %1").arg(getCountDetals('E')) +
                 QString("\nДеталей F: %1").arg(getCountDetals('F')) +
                 QString("\nДеталей G: %1").arg(getCountDetals('G')) +
                 QString("\nДеталей H: %1").arg(getCountDetals('H')));


    outPerfomance->clear();

    QString gen1;
    QString gen2;
    QString gen3;


//    outPerfomance->setText(QString("Деталь А поступит через: %1 минут").arg(getProcessTime('G',1)) +
//                           QString("Деталь В поступит через: %1 минут").arg(getCountDetals('G',2)) +
//                           QString("Деталь С поступит через: %1 минут").arg(getCountDetals('G',3)) +
//                           QString("Деталь D поступит через: %1 минут").arg(getCountDetals('G',3)) +


  //              )

}
