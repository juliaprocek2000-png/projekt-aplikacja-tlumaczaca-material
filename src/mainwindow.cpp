#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtConcurrent> // Odpowiednik std::async w Qt
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    client = new OllamaClient("http://localhost:11434/api/generate");
    
    // Łączymy kliknięcie przycisku z funkcją handleSend
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::handleSend);
}
MainWindow::~MainWindow() {
    delete client; // Zwalniamy pamięć po kliencie Ollamy
    delete ui;     // Zwalniamy pamięć interfejsu
}
void MainWindow::handleSend() {
    QString textToProcess = ui->inputEdit->toPlainText();
    QString systemPrompt;

    // Pobieramy wybór stylu (np. z rozwijanej listy QComboBox)
    int choice = ui->styleCombo->currentIndex();
    if (choice == 0) systemPrompt = "Zredaguj tekst dla dziecka w wieku około 5 lat. Tekst ma wyglądać jakby byl w książce dla dzieci. Nie dodawaj żadnych nowych informacji, tylko zredaguj ten tekst. Nie zmieniaj znaczenia tekstu. Tekst ma być napisany prostym językiem, żeby byłłatwy do zrozumienia dla dziecka.";
    else if (choice == 1) systemPrompt = "Zredaguj tekst w stylu mlodziezowym (rel, sigma, mega, ziomek itd .). Tekst ma byc łatwy do zrozumienia dla młodzieży. Nie dodawaj żadnych nowych informacji, tylko zredaguj ten tekst. Nie zmieniaj znaczenia tekstu.";
    else if (choice == 2) systemPrompt = "Zdedaguj tekst w stylu poetyckim. Tekst ma być napisany w sposób artystyczny, z użyciem metafor i bogatego języka. Nie dodawaj żadnych nowych informacji, tylko zredaguj ten tekst. Nie zmieniaj znaczenia tekstu.";
    ui->statusLabel->setText("Bielik myśli...");

    // QtConcurrent::run wysyła to w tle, żeby okno nie "zamarzło"
    QtConcurrent::run([this, systemPrompt, textToProcess]() {
        try {
            std::string response = client->sendRequest(systemPrompt.toStdString(), textToProcess.toStdString());
            
            // Wracamy do głównego wątku, żeby zaktualizować okno
            QMetaObject::invokeMethod(this, [this, response]() {
                ui->outputEdit->setPlainText(QString::fromStdString(response));
                ui->statusLabel->setText("Gotowe!");
            });
        } catch (...) {
            QMetaObject::invokeMethod(this, [this]() {
                ui->statusLabel->setText("Błąd połączenia!");
            });
        }
    });
}