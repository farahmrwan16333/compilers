#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->input->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file","C:/Users/Dell/Documents/Compilers",tr("text files (*.txt)"));
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Error","file not open");
        return;

    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->input->setPlainText(text);
    file.close();
}


void MainWindow::on_resetButton_clicked()
{
    ui->input->setText("");
    ui->output->setText("");
}


void MainWindow::on_scanButton_clicked()
{

}


void MainWindow::on_parseButton_clicked()
{

}

