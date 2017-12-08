/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actionHabilitar;
    QAction *actionDeshabilitar;
    QAction *actionHabilitar_2;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QWidget *tab_4;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1292, 658);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        actionHabilitar = new QAction(MainWindow);
        actionHabilitar->setObjectName(QStringLiteral("actionHabilitar"));
        actionHabilitar->setCheckable(true);
        actionHabilitar->setChecked(false);
        actionDeshabilitar = new QAction(MainWindow);
        actionDeshabilitar->setObjectName(QStringLiteral("actionDeshabilitar"));
        actionHabilitar_2 = new QAction(MainWindow);
        actionHabilitar_2->setObjectName(QStringLiteral("actionHabilitar_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 10, 51, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(680, 10, 80, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1210, 10, 80, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 10, 91, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 10, 101, 16));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 10, 51, 23));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(true);
        lineEdit_3->setGeometry(QRect(610, 10, 51, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(380, 10, 241, 16));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(1150, 10, 41, 31));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 40, 1281, 571));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(tab_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1257, 522));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        plainTextEdit = new QPlainTextEdit(tab_4);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(40, 30, 611, 441));
        tabWidget->addTab(tab_4, QString());
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(760, 10, 31, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1292, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Areopuerto", nullptr));
        action->setText(QApplication::translate("MainWindow", "Habilitar Casillas", nullptr));
        actionHabilitar->setText(QApplication::translate("MainWindow", "Habilitar", nullptr));
        actionDeshabilitar->setText(QApplication::translate("MainWindow", "Deshabilitar", nullptr));
        actionHabilitar_2->setText(QApplication::translate("MainWindow", "Habilitar", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Simulacion", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Turno", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Cant. Aviones", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Cant. Escritorios", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Cant. Estaciones de Mantenimiento", nullptr));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Estructuras", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Consola", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
