/**
 * @file OllamaClient.cpp
 * @brief Implementacja klasy klienta do komunikacji z modelem językowym Ollama.
 * * Zawiera logikę wysyłania żądań HTTP POST do lokalnego serwera API.
 */
#include "OllamaClient.h"
#include <cpr/cpr.h>           
#include <nlohmann/json.hpp>    
#include <iostream>
#include <string>
/// komunikacja z ollama
using json = nlohmann::json;
/**
 * @brief Konstruktor klasy OllamaClient.
 * @param apiUrl Adres URL punktu końcowego API (np. http://localhost:11434/api/generate). [cite: 19]
 */
OllamaClient::OllamaClient(std::string apiUrl) : apiUrl(apiUrl) {}
/**
 * @brief Wysyła zapytanie do modelu językowego i odbiera odpowiedź.
 * * Funkcja buduje obiekt JSON zawierający model, system prompt i user prompt, [cite: 22, 23, 24]
 * a następnie przesyła go synchronicznie do serwera Ollama. [cite: 13, 25]
 * * @param systemPrompt Kontekst i rola określająca zachowanie modelu. [cite: 10]
 * @param userPrompt Treść zapytania lub tekst dostarczony przez użytkownika. [cite: 10]
 * @return std::string Zredagowany tekst z modelu lub komunikat o błędzie. [cite: 33, 34]
 */
std::string OllamaClient::sendRequest(const std::string& systemPrompt, const std::string& userPrompt) {
    
    if (systemPrompt.empty() && userPrompt.empty()) {
        return "Blad: Brak danych do przetworzenia.";
    }
    /// @note Obsługa wyjątków zapewnia odporność na błędy sieciowe.
    try {
       /// biblioteka 
        json requestBody = {
            {"model", "speakleash/bielik-11b-v2.3-instruct:q4_k_m"},        
            {"system", systemPrompt},   
            {"prompt", userPrompt},     
            {"stream", false}           
        };

        
        cpr::Response r = cpr::Post(
            cpr::Url{apiUrl},
            cpr::Body{requestBody.dump()},
            cpr::Header{{"Content-Type", "application/json"}} /// inf ze dane w formacie json
        );

       ///czy ollama działa
        if (r.status_code == 0) {
            return "Blad: Nie mozna polaczyc sie z Ollama. Upewnij sie, ze jest wlaczona!";
        }
        //blad serwera
        if (r.status_code != 200) {
            return "Blad serwera: " + std::to_string(r.status_code);
        }

       
        auto jsonResponse = json::parse(r.text);
        return jsonResponse["response"].get<std::string>();

    } catch (const std::exception& e) {
        return "Wystapil blad: " + std::string(e.what());
    }
}