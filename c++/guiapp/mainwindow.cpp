#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

// basic file operations
#include <iostream>
#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()
{
    // need to call this to init all widgets used in the
    // mainWindow.ui design file.
    ui->setupUi(this);

    // Set up a connection using signal/slot mechanism, to call
    // addTask() function when our add task button clicked signal is emitted.
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
    // Call our method
    updateStatus();

}

MainWindow::

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;

    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task *task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        // We can do this because task is a QWidget
        ui->tasksLayout->addWidget(task);
        writeTask(name.toStdString());
        updateStatus();
    }
}

void MainWindow::writeTask(const std::string& new_task)
{
    qDebug() << "Reading local file";
    std::ofstream ofs("./task.txt", std::ios_base::app);
    ofs << new_task << '\n';
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);

    task->setParent(nullptr);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task *task)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;
    for (auto t : mTasks) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = mTasks.size() - completedCount;

    ui->statusLabel->setText(
                QString("Status: %1 todo / %2 completed")
                        .arg(todoCount)
                        .arg(completedCount));
}