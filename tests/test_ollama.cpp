/**
 * @file test_ollama.cpp
 * @brief Testy jednostkowe dla klasy OllamaClient.
 */

#include <QtTest>
#include <string>
#include <QString>
#include "OllamaClient.h"

/**
 * @class TestOllama
 * @brief Klasa testowa weryfikująca poprawność komunikacji z API i obsługę błędów.
 */
class TestOllama : public QObject {
    Q_OBJECT

private slots: // Zmieniono na private slots, aby Qt Test automatycznie uruchomił te funkcje
    
    /**
     * @brief Testuje zachowanie klienta przy błędnym adresie URL.
     * Weryfikuje spełnienie punktu 27 założeń projektu (obsługa błędów połączenia).
     */
    void testConnectionError() {
        OllamaClient client("http://invalid-address:11434/api/generate");
        std::string result = client.sendRequest("System", "User");
        
        // Sprawdzamy, czy odpowiedź zawiera informację o błędzie
        QVERIFY(QString::fromStdString(result).contains("Blad")); 
    }

    /**
     * @brief Testuje zachowanie przy pustych danych wejściowych.
     * Weryfikuje spełnienie punktu 32 założeń projektu (walidacja danych).
     */
    void testEmptyInput() {
        // Używamy adresu localhost (nawet jeśli Ollama nie jest włączona, test sprawdzi reakcję)
        OllamaClient client("http://localhost:11434/api/generate");
        std::string result = client.sendRequest("", ""); 
        
        // Sprawdzamy, czy program nie zwrócił pustego ciągu (powinien zwrócić komunikat błędu)
        QVERIFY(!QString::fromStdString(result).isEmpty());
    }
};

/**
 * @brief Generowanie funkcji main dla testów jednostkowych.
 */
QTEST_MAIN(TestOllama)


#include "test_ollama.moc"