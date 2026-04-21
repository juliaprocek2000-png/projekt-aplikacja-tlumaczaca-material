/**
 * @file OllamaClient.h
 * @brief Definicja klasy OllamaClient do komunikacji z modelem językowym Ollama.
 * * Klasa umożliwia wysyłanie zapytań do lokalnego serwera API Ollama i odbieranie odpowiedzi.
 */
#ifndef OLLAMACLIENT_H
#define OLLAMACLIENT_H

#include <string>
/// obsługa api ollama
/**
 * @class OllamaClient
 * @brief Klasa odpowiedzialna za komunikację z lokalnym serwerem Ollama poprzez REST API.
 * * Klasa wykorzystuje bibliotekę CPR do wykonywania żądań HTTP i nlohmann/json 
 * do przetwarzania danych w formacie JSON. Umożliwia wysyłanie zapytań do modelu Bielik.
 */
class OllamaClient {
public:
    /**
     * @brief Konstruktor klasy OllamaClient.
     * @param apiUrl Adres URL punktu końcowego API (domyślnie http://localhost:11434/api/generate).
     */
    
    OllamaClient(std::string apiUrl = "http://localhost:11434/api/generate");
    /**
     * @brief Przesyła prompt do modelu językowego i zwraca odpowiedź.
     * * @param systemPrompt Określenie kontekstu i roli modelu (system prompt).
     * @param userPrompt Tekst wprowadzony przez użytkownika do przetworzenia (user prompt).
     * @return std::string Wygenerowana odpowiedź modelu lub komunikat o błędzie.
     */
    std::string sendRequest(const std::string& systemPrompt, const std::string& userPrompt);

private:
    std::string apiUrl; ///< Adres serwera API Ollama
};

#endif