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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("/* --- Styl dla g\305\202\303\263wnego okna --- */\n"
"QMainWindow {\n"
"    background-color: #2a0a1a; /* Bardzo ciemny, bordowy fiolet */\n"
"    color: #fce4ec; /* Jasny, pudrowy r\303\263\305\274 dla napis\303\263w */\n"
"}\n"
"\n"
"/* --- Styl dla p\303\263l tekstowych (input/output) --- */\n"
"QTextEdit {\n"
"    background-color: #3e1e2d; /* Ciemny, nasycony r\303\263\305\274owo-bordowy */\n"
"    color: #fce4ec; /* Jasny, pudrowy r\303\263\305\274 dla tekstu */\n"
"    border: 1px solid #ff4081; /* Jaskrawy r\303\263\305\274owy brzeg */\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    selection-background-color: #e91e63; /* Intensywny r\303\263\305\274owy dla zaznaczenia */\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* --- Styl dla przycisku (Zredaguj tekst) --- */\n"
"QPushButton {\n"
"    background-color: #ff4081; /* Jaskrawy, nasycony r\303\263\305\274owy */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
""
                        "    min-width: 150px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #ff80ab; /* Ja\305\233niejszy, pudrowy r\303\263\305\274 po najechaniu */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e91e63; /* Ciemniejszy, intensywny r\303\263\305\274owy po klikni\304\231ciu */\n"
"}\n"
"\n"
"/* --- Styl dla listy rozwijanej (styleCombo) --- */\n"
"QComboBox {\n"
"    background-color: #3e1e2d; /* Ciemny, nasycony r\303\263\305\274owo-bordowy */\n"
"    color: #fce4ec; /* Jasny, pudrowy r\303\263\305\274 dla tekstu */\n"
"    border: 1px solid #ff4081; /* Jaskrawy r\303\263\305\274owy brzeg */\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #3e1e2d; /* Ciemny, nasycony r\303\263\305\274owo-bordowy dla listy */\n"
"    color: #fce4ec; /* Jasny, pudrowy r\303\263\305\274 dla opcji */\n"
"    selection-background-color: #e91e63; /* Intensywny r\303\263\305\274owy dla wybranej opcji */\n"
"    selection-color: white;\n"
""
                        "}\n"
"\n"
"/* --- Styl dla etykiety statusu --- */\n"
"QLabel {\n"
"    color: #ff80ab; /* Pudrowy r\303\263\305\274 dla statusu */\n"
"    background: transparent;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(570, 120, 190, 41));
        styleCombo = new QComboBox(centralwidget);
        styleCombo->addItem(QString());
        styleCombo->addItem(QString());
        styleCombo->addItem(QString());
        styleCombo->setObjectName("styleCombo");
        styleCombo->setGeometry(QRect(20, 120, 138, 41));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(320, 570, 191, 16));
        inputEdit = new QTextEdit(centralwidget);
        inputEdit->setObjectName("inputEdit");
        inputEdit->setGeometry(QRect(20, 170, 741, 192));
        outputEdit = new QTextEdit(centralwidget);
        outputEdit->setObjectName("outputEdit");
        outputEdit->setGeometry(QRect(20, 370, 741, 192));
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
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Wklej tekst do redakcji</p></body></html>", nullptr));
        outputEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Odpowied\305\272 </p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
