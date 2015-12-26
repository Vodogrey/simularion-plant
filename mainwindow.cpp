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
    m_pb_pause = new QPushButton();
    m_pb_stop = new QPushButton();
    m_le_input = new QLineEdit();
    m_lb_input = new QLabel("Введите число частей");
    m_lb_countDetals = new QLabel();

    m_actions = new MainActoins();

    m_layout->addWidget(m_lb_countDetals, 1, 1, 5, 1);
    m_layout->addWidget(m_lb_input, 1, 5, 1, 4);
    m_layout->addWidget(m_le_input, 1, 10, 1, 1);
    m_layout->addWidget(m_pb_start, 2, 8, 1, 1);



    m_widget->setLayout(m_layout);
    this->setCentralWidget(m_widget);
}

void MainWindow::Buttons()
{
    connect(this, SIGNAL(processOn()), m_actions, SLOT(Process()));
    connect(m_pb_pause, SIGNAL(clicked()), this, SLOT(slot_pb_pause()));
    connect(m_pb_stop, SIGNAL(clicked()), this, SLOT(slot_pb_stop()));
    connect(m_pb_start, SIGNAL(clicked()), this, SLOT(slot_pb_start()));
}

void MainWindow::slot_pb_start()
{
    int count = m_le_input->text().toInt();
    qDebug() << count;
    emit processOn();
}

void MainWindow::slot_pb_pause()
{

}

void MainWindow::slot_pb_stop()
{

}
