/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *sendButton;
    QComboBox *styleCombo;
    QLabel *statusLabel;
    QTextEdit *inputEdit;
    QTextEdit *outputEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"    background-color: #F4EEF0; \n"
"}\n"
"\n"
"\n"
"QTextEdit {\n"
"    background-color: #5D3A42;\n"
"    color: #F2E9EB;           \n"
"    border: 1px solid #4A2E35; \n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"\n"
"QPushButton, QComboBox {\n"
"    background-color: #A67B88; \n"
"    color: #FFFFFF;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 10px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #BC95A0; /* Delikatne roz\305\233wietlenie */\n"
"}\n"
"\n"
"/* --- Labele (Napisy): Ciemny, zgaszony r\303\263\305\274 --- */\n"
"QLabel {\n"
"    color: #7D5A64; \n"
"    background: transparent;\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #F4EEF0;\n"
"    selection-background-color: #A67B88;\n"
"    color: #5D3A42;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(580, 120, 190, 41));
        styleCombo = new QComboBox(centralwidget);
        styleCombo->addItem(QString());
        styleCombo->addItem(QString());
        styleCombo->addItem(QString());
        styleCombo->setObjectName("styleCombo");
        styleCombo->setGeometry(QRect(30, 120, 201, 41));
        styleCombo->setStyleSheet(QString::fromUtf8(""));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(320, 570, 191, 16));
        statusLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 128, 171); \n"
"\n"
"\n"
"\n"
"\n"
"font-weight: 300;\n"
"font: 900 11pt \"Arial Black\";"));
        inputEdit = new QTextEdit(centralwidget);
        inputEdit->setObjectName("inputEdit");
        inputEdit->setGeometry(QRect(30, 191, 741, 171));
        outputEdit = new QTextEdit(centralwidget);
        outputEdit->setObjectName("outputEdit");
        outputEdit->setGeometry(QRect(30, 391, 741, 171));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 20, 311, 71));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 128, 171); \n"
"\n"
"\n"
"\n"
"font: 48pt \"Gabriola\";\n"
"font-weight: 300;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 91, 241, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 128, 171); \n"
"font: 900 11pt \"Arial Black\";\n"
"\n"
"font-weight: 300;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 170, 161, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(370, 370, 91, 16));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Redaktor AI - Bielik", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Zredaguj tekst", nullptr));
        styleCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Styl dzieci\304\231cy", nullptr));
        styleCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Styl m\305\202odzie\305\274owy", nullptr));
        styleCombo->setItemText(2, QCoreApplication::translate("MainWindow", "Styl Poetrycki", nullptr));

        statusLabel->setText(QCoreApplication::translate("MainWindow", "Czekam na tw\303\263j tekst", nullptr));
        inputEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        outputEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Redaktor AI", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "wybierz styl odpowiedzi:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Wpisz tekst do redakcji", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Odpowied\305\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
