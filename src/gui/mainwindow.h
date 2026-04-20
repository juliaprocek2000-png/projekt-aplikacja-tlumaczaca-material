/**
 * @file mainwindow.h
 * @brief Definicja klasy MainWindow, głównego okna aplikacji Redaktor AI.
 * * Klasa zarządza interfejsem użytkownika.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "OllamaClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Worker : public QObject {
    Q_OBJECT
public slots:
    // funkcja wykonująca zapytanie do modelu w osobnym wątku
    void doWork(OllamaClient* client, const QString& systemPrompt, const QString& userPrompt) {
        try {
            //  wysyłanie zapytania do modelu i odbieranie odpowiedzi
            std::string response = client->sendRequest(systemPrompt.toStdString(), userPrompt.toStdString());
            emit resultReady(QString::fromStdString(response));
        } catch (...) {
            emit errorOccurred();
        }
    }
signals:
    void resultReady(const QString &result);
    void errorOccurred();
};
/**
 * @class MainWindow
 * @brief Klasa odpowiedzialna za główne okno aplikacji Redaktor AI.
 * * Zarządza interfejsem użytkownika, pobiera dane wejściowe i wyświetla
 * zredagowany tekst otrzymany z modelu językowego.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy MainWindow.
     * @param parent Wskaźnik na obiekt rodzica (domyślnie nullptr).
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Destruktor klasy MainWindow.
     * Zwalnia zasoby zajmowane przez interfejs i klienta API.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot obsługujący kliknięcie przycisku redagowania.
     * Pobiera tekst z okna, wybiera odpowiedni prompt i uruchamia
     * zapytanie do modelu w osobnym wątku.
     */
    void handleSend(); ///deklaracja funkcji reagującej na wciśnięcie przycisku

private:
    Ui::MainWindow *ui; ///< Wskaźnik na wygenerowany interfejs UI.
    OllamaClient *client; ///< Klient do komunikacji z API Ollama.
    QString chatHistory; ///< Przechowuje historię rozmowy z modelem AI.
    QTimer *statusTimer; ///< Timer odpowiedzialny za animację kropek.
    int dotCount = 0; ///< Licznik kropek w animacji statusu.
};


#endif