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

    m_actions = new MainActions();

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
    connect(this, SIGNAL(processOn(int)), m_actions, SLOT(Process(int)));
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
    if(count > 0) {
        m_pb_start->setDisabled(true);
        pauseEnabled = false;
        emit processOn(count);
    }
}

void MainWindow::slot_pb_pause()
{
    QEventLoop loop;
    if(pauseEnabled) {
        pauseEnabled = false;
    }
    else {

        pauseEnabled = true;
        while(pauseEnabled) {
            QTimer::singleShot(100,&loop,SLOT(quit()));
            loop.exec();
        }
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
                            QString("\nДеталей D: %1 и %2 непроверенных").arg(getCountDetals('D')).arg(getCountDetals('d')) +
                            QString("\nДеталей E: %1 и %2 непроверенных").arg(getCountDetals('E')).arg(getCountDetals('e')) +
                            QString("\nДеталей F: %1").arg(getCountDetals('F')) +
                            QString("\nДеталей G: %1").arg(getCountDetals('G')) +
                            QString("\nДеталей H: %1").arg(getCountDetals('H'))
                            );


    outPerfomance->clear();


    outPerfomance->setText(QString("Деталь А поступит через: %1 ").arg(getProcessTime('G',0)) +
                           QString("\nДеталь В поступит через: %1 минут").arg(getProcessTime('G',1)) +
                           QString("\nДеталь С поступит через: %1 минут").arg(getProcessTime('G',2)) +
                           QString("\nДеталь D %1").arg(getProcessTime('C',0)) +
                           QString("\nДеталь E %1").arg(getProcessTime('C',1)) +
                           QString("\nДеталь D и Е %1").arg(getProcessTime('C',2)) +
                           QString("\nДеталь F %1").arg(getProcessTime('C',3)) +
                           QString("\nДеталь G %1").arg(getProcessTime('C',4)) +
                           QString("\nДеталь H %1").arg(getProcessTime('C',5))
                           );

}
