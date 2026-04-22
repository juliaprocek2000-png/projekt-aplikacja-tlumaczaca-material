/**
 * @file mainwindow.cpp
 * @brief Implementacja klasy MainWindow, głównego okna aplikacji Redaktor AI.
 * * Klasa zarządza interfejsem użytkownika, obsługuje interakcje z użytkownikiem
 * 
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtConcurrent> 
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
/**
 * @class MainWindow
 * @brief Główna klasa interfejsu użytkownika aplikacji Redaktor AI.
 * * Klasa zarządza interfejsem graficznym, obsługuje interakcje z użytkownikiem
 * oraz koordynuje komunikację z modelem językowym w osobnym wątku.
 */
/**
 * @brief Konstruktor klasy MainWindow.
 * @param parent Wskaźnik na rodzica obiektu (domyślnie nullptr).
 * Inicjalizuje UI, klienta Ollama oraz timer animacji statusu.
 */
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
/**
 * @brief Destruktor klasy MainWindow.
 * Zwalnia pamięć zajmowaną przez klienta API oraz obiekty interfejsu.
 */
MainWindow::~MainWindow() {
    delete client; 
    delete ui;   
}
/**
 * @brief Przesyłanie promptu do modelu i odbieranie odpowiedzi.
 * 
 * * Funkcja waliduje dane wejściowe, dobiera system prompt na podstawie wybranego stylu
 * i uruchamia zapytanie do modelu AI w osobnym wątku przy użyciu QThread i Worker.
 * * Odbiera odpowiedź i aktualizuje interfejs użytkownika, zapewniając płynność działania aplikacji.
 
 */
void MainWindow::handleSend() {
    // walidacja danych wejściowych
    QString textToProcess = ui->inputEdit->toPlainText().trimmed();
    if (textToProcess.isEmpty() || textToProcess == "Wklej tekst do redakcji") {
        QMessageBox::warning(this, "Brak danych", "Wpisz lub wklej tekst do redakcji!");
        return; 
    }

    // system prompt
    QString systemPrompt;
    int choice = ui->styleCombo->currentIndex();
    if (choice == 0) {
        systemPrompt = "Jesteś edytorem tekstów dla dzieci. Twoim zadaniem jest uproszczenie poniższego tekstu. Tekst ma być napisany językiem zrozumiałym dla dzieci.Nie wymyślaj nowych historii. Jeśli tekst wejściowy jest krótki, Twoja odpowiedź też ma być krótka. Nie zmieniaj sensu tekstu. Nie dodawaj żadnych informacji. wygeneruj tekst podobnej długości co dostarczony ci fragment. Tekst do uproszczenia: ";
    } else if (choice == 1) {
        systemPrompt = "Jesteś edytorem tekstu. Przetłumacz poniższy tekst na slang młodzieżowy, używaj słów, których używa młodzież. Nie zmieniaj sensu tekstu. wygeneruj tekst podobnej długości co dostarczony ci fragment. Na końcu nie zadawaj pytań, czy rozumiem. Tekst: ";
    } else if (choice == 2) {
        systemPrompt = "Zmień styl poniższego tekstu na poetycki i artystyczny. Nie zmieniaj sensu tekstu. wygeneruj tekst podobnej długości co dostarczony ci fragment. Tekst: ";
    }
    
    // animacja kropek
    ui->statusLabel->setText("Bielik myśli");
    statusTimer->start(500);
    ui->outputEdit->clear();

    // wielowątkowość
    QThread* thread = new QThread;
    Worker* worker = new Worker;
    worker->moveToThread(thread);

    // wywołanie funkcji doWork i przekazanie danych
    connect(thread, &QThread::started, [=]() {
        worker->doWork(client, systemPrompt, textToProcess);
    });

    // odbiór wyniku i aktualizacja gui
    connect(worker, &Worker::resultReady, this, [=](const QString &result) {
        ui->outputEdit->setPlainText(result);
        ui->statusLabel->setText("Gotowe!");
        statusTimer->stop();
        thread->quit();
    });

    // obsługa błędów
    connect(worker, &Worker::errorOccurred, this, [=]() {
        ui->statusLabel->setText("Błąd połączenia!");
        statusTimer->stop();
        thread->quit();
    });

    // sprzątanie wątku po zakończeniu
    connect(thread, &QThread::finished, worker, &QObject::deleteLater);
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);

    thread->start(); // uruchomienie wątku
}