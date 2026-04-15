#include "OllamaClient.h"
#include <cpr/cpr.h>           
#include <nlohmann/json.hpp>    
#include <iostream>
#include <string>
/// komunikacja z ollama
using json = nlohmann::json;

OllamaClient::OllamaClient(std::string apiUrl) : apiUrl(apiUrl) {}

std::string OllamaClient::sendRequest(const std::string& systemPrompt, const std::string& userPrompt) {
    ///obsługa błedów systemowych
    try {
       /// biblioteka m=nlohmann/json
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