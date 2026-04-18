#ifndef OLLAMACLIENT_H
#define OLLAMACLIENT_H

#include <string>
/// obsługa api ollama
/**
 * @class OllamaClient
 * @brief Klasa odpowiedzialna za komunikację z lokalnym serwerem Ollama poprzez REST API.
 * * Klasa wykorzystuje bibliotekę CPR do wykonywania żądań HTTP i nlohmann/json 
 * do przetwarzania danych w formacie JSON. Umożliwia wysyłanie zapytań do modelu Bielik[cite: 7, 13, 19].
 */
class OllamaClient {
public:
    /**
     * @brief Konstruktor klasy OllamaClient.
     * @param apiUrl Adres URL punktu końcowego API (domyślnie http://localhost:11434/api/generate)[cite: 19].
     */
    
    OllamaClient(std::string apiUrl = "http://localhost:11434/api/generate");
    /**
     * @brief Przesyła prompt do modelu językowego i zwraca odpowiedź.
     * * @param systemPrompt Określenie kontekstu i roli modelu (system prompt)[cite: 10, 23].
     * @param userPrompt Tekst wprowadzony przez użytkownika do przetworzenia (user prompt)[cite: 10, 24].
     * @return std::string Wygenerowana odpowiedź modelu lub komunikat o błędzie[cite: 33, 34].
     */
    std::string sendRequest(const std::string& systemPrompt, const std::string& userPrompt);

private:
    std::string apiUrl; ///< Adres serwera API Ollama
};

#endif