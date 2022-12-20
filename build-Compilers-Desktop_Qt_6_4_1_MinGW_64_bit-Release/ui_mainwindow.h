/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QWidget *centralwidget;
    QTextEdit *input;
    QTextEdit *output;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *scanButton;
    QPushButton *parseButton;
    QPushButton *resetButton;
    QLabel *tree;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1493, 753);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/icons/document_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/icons/document_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        input = new QTextEdit(centralwidget);
        input->setObjectName("input");
        input->setGeometry(QRect(10, 50, 371, 451));
        output = new QTextEdit(centralwidget);
        output->setObjectName("output");
        output->setGeometry(QRect(400, 50, 371, 451));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 91, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 0, 111, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setStrikeOut(false);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(790, 0, 171, 41));
        label_3->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(340, 530, 431, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scanButton = new QPushButton(layoutWidget);
        scanButton->setObjectName("scanButton");
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        scanButton->setFont(font2);

        horizontalLayout->addWidget(scanButton);

        parseButton = new QPushButton(layoutWidget);
        parseButton->setObjectName("parseButton");
        parseButton->setFont(font2);

        horizontalLayout->addWidget(parseButton);

        resetButton = new QPushButton(layoutWidget);
        resetButton->setObjectName("resetButton");
        resetButton->setFont(font2);

        horizontalLayout->addWidget(resetButton);

        tree = new QLabel(centralwidget);
        tree->setObjectName("tree");
        tree->setGeometry(QRect(790, 50, 471, 521));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1493, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        statusbar->setFont(font3);
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        toolBar->addAction(actionNew);
        toolBar->addSeparator();
        toolBar->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Syntax tree", nullptr));
        scanButton->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        parseButton->setText(QCoreApplication::translate("MainWindow", "Parse", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        tree->setText(QCoreApplication::translate("MainWindow", "click on parse to view the tree", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
