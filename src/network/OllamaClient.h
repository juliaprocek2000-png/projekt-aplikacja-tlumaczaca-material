#ifndef OLLAMACLIENT_H
#define OLLAMACLIENT_H

#include <string>
/// obsługa api ollama
class OllamaClient {
public:
    
    
    OllamaClient(std::string apiUrl = "http://localhost:11434/api/generate");

    std::string sendRequest(const std::string& systemPrompt, const std::string& userPrompt);

private:
    std::string apiUrl; ///  adres servera
};

#endif