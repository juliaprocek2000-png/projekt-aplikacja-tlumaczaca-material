#include "OllamaClient.h"
#include <cpr/cpr.h>           
#include <nlohmann/json.hpp>    
#include <iostream>
#include <string>

using json = nlohmann::json;

OllamaClient::OllamaClient(std::string apiUrl) : apiUrl(apiUrl) {}

std::string OllamaClient::sendRequest(const std::string& systemPrompt, const std::string& userPrompt) {
    try {
        // 1. Przygotowanie danych
        json requestBody = {
            {"model", "speakleash/bielik-11b-v2.3-instruct:q4_k_m"},        
            {"system", systemPrompt},   
            {"prompt", userPrompt},     
            {"stream", false}           
        };

        // 2. Wysyłanie zapytania
        cpr::Response r = cpr::Post(
            cpr::Url{apiUrl},
            cpr::Body{requestBody.dump()},
            cpr::Header{{"Content-Type", "application/json"}}
        );

        // 3. Sprawdzenie połączenia
        if (r.status_code == 0) {
            return "Blad: Nie mozna polaczyc sie z Ollama. Upewnij sie, ze jest wlaczona!";
        }
        
        if (r.status_code != 200) {
            return "Blad serwera: " + std::to_string(r.status_code);
        }

        // 4. Odczyt odpowiedzi
        auto jsonResponse = json::parse(r.text);
        return jsonResponse["response"].get<std::string>();

    } catch (const std::exception& e) {
        return "Wystapil blad: " + std::string(e.what());
    }
}