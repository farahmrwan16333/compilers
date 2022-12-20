#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <string>
#include <QString>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "Parse.h"
#include "Scan.h"
#include "gvc.h"
#include "cdt.h"
#include "cgraph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        int drawNode(Node* node, string &str, int id);
        void draw(Node* tree);

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_resetButton_clicked();

    void on_scanButton_clicked();

    void on_parseButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
