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

private slots: 
    
    /**
     * @brief Testuje zachowanie klienta przy błędnym adresie URL.
     * obsługa błędów połączenia
     */
    void testConnectionError() {
        OllamaClient client("http://invalid-address:11434/api/generate");
        std::string result = client.sendRequest("System", "User");
        
        // sprawdzenie czy odpowiedź zawiera informację o błędzie
        QVERIFY(QString::fromStdString(result).contains("Blad")); 
    }

    /**
     * @brief Testuje zachowanie przy pustych danych wejściowych.
     * walidacja danych
     */
    void testEmptyInput() {
        
        OllamaClient client("http://localhost:11434/api/generate");
        std::string result = client.sendRequest("", ""); 
        
        // sprawdzenie czy program nie zwrócił pustego ciągu  - powinien zwrócić błąd 
        QVERIFY(!QString::fromStdString(result).isEmpty());
    }
};

/**
 * @brief Generowanie funkcji main dla testów jednostkowych.
 */
QTEST_MAIN(TestOllama)


#include "test_ollama.moc"