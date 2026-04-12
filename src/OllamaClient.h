#ifndef OLLAMACLIENT_H
#define OLLAMACLIENT_H

#include <string>

/**
 * @brief Klasa odpowiedzialna za komunikację z lokalnym modelem językowym Ollama.
 * Wykorzystuje REST API do wysyłania zapytań i odbierania wygenerowanego tekstu.
 */
class OllamaClient {
public:
    /**
     * @brief Konstruktor klasy.
     * @param apiUrl Adres URL do API Ollamy (domyślnie http://localhost:11434/api/generate).
     */
    OllamaClient(std::string apiUrl = "http://localhost:11434/api/generate");

    /**
     * @brief Wysyła zapytanie do modelu Bielik.
     * @param systemPrompt Rola modelu (kontekst).
     * @param userPrompt Zapytanie użytkownika (trudne pojęcie).
     * @return std::string Wygenerowana przez model odpowiedź lub komunikat o błędzie.
     */
    std::string sendRequest(const std::string& systemPrompt, const std::string& userPrompt);

private:
    std::string apiUrl;
};

#endif // OLLAMACLIENT_H