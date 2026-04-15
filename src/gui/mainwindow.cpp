#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtConcurrent> 
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //połączenie z ollama lokalnie
    client = new OllamaClient("http://localhost:11434/api/generate");
    /// migające kropki
    statusTimer = new QTimer(this);
    connect(statusTimer, &QTimer::timeout, this, [this]() {
        dotCount = (dotCount + 1) % 4; 
        QString dots = QString(".").repeated(dotCount);
        ui->statusLabel->setText("Bielik myśli" + dots);
    });
    /// łączenie przycisku wyślij z funkcja
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::handleSend);
}
MainWindow::~MainWindow() {
    delete client; 
    delete ui;   
}

void MainWindow::handleSend() {
 
    QString textToProcess = ui->inputEdit->toPlainText().trimmed();

    ///jeśli nic nie jest wpisane wyświetla sie napis
    if (textToProcess.isEmpty() || textToProcess == "Wklej tekst do redakcji") {
        ui->statusLabel->setText("Błąd!");
        return; 
    }

   
    dotCount = 0;
    ui->statusLabel->setText("Bielik myśli");
    statusTimer->start(500); 

  ///system propmt 
    QString systemPrompt;
    int choice = ui->styleCombo->currentIndex();

    if (choice == 0) {
        systemPrompt = "Jesteś edytorem tekstów dla dzieci. Twoim zadaniem jest uproszczenie PONIŻSZEGO tekstu. Nie wymyślaj nowych historii. Jeśli tekst wejściowy jest krótki, Twoja odpowiedź też ma być krótka. Tekst do uproszczenia: ";
    } else if (choice == 1) {
        systemPrompt = "Przetłumacz poniższy tekst na slang młodzieżowy (możesz użyć słów takich jak: rel, sigma, ziomek). Nie zmieniaj sensu tekstu. Tekst: ";
    } else if (choice == 2) {
        systemPrompt = "Zmień styl poniższego tekstu na poetycki i artystyczny. Nie dodawaj faktów, których nie ma w oryginale. Tekst: ";
    }
    
   
    ui->outputEdit->clear();

   ///obsługa wielowątkowości
    QtConcurrent::run([this, systemPrompt, textToProcess]() {
        try {
            std::string response = client->sendRequest(systemPrompt.toStdString(), textToProcess.toStdString());
            
           
            QMetaObject::invokeMethod(this, [this, response]() {
                statusTimer->stop(); 
                ui->outputEdit->setPlainText(QString::fromStdString(response));
                ui->statusLabel->setText("Gotowe!");
            });
        } catch (...) {
            QMetaObject::invokeMethod(this, [this]() {
                statusTimer->stop(); 
                ui->statusLabel->setText("Błąd połączenia!");
            });
        }
    });
}