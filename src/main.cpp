#include <iostream>
#include <string>
#include <windows.h>
#include "OllamaClient.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    OllamaClient client("http://localhost:11434/api/generate");

    std::string textToProcess;
    std::string choice;
    std::string systemPrompt;
    
    std::cout << "===============================================" << std::endl;
    std::cout << "                 Redaktor Tekstu               " << std::endl;
    std::cout << "===============================================" << std::endl;

    while (true) {
        std::cout << "\nWYBIERZ TYP ODPOWIEDZI:" << std::endl;
        std::cout << "1. Książka dla dzieci" << std::endl;
        std::cout << "2. Slang mlodziezowy" << std::endl;
        std::cout << "3. Konkretne streszczenie" << std::endl;
        std::cout << "Wpisz 'koniec', aby wyjsc." << std::endl;
        
        std::cout << "\nTwoj wybor: ";
        std::getline(std::cin, choice);

        if (choice == "koniec") break;

        if (choice == "1") {
            systemPrompt = "Jesteś redaktorem i przeredaguj ten tekst na zrozumiały dla małego dziecka. Używaj prostych słów i przykładów, jakbyś pisał ksiązkę dla dzieci.";
        } else if (choice == "2") {
            systemPrompt = "Jesteś kumplem z podwórka. Przeredaguj ten tekst na slang młodzieżowy, ma być to formułka która będzie krótka i zawierała słowa zrozumiałe dla młodzieży. Używaj popularnych zwrotów i skrótów";
        } else if (choice == "3") {
            systemPrompt = "jesteś asystentem naukowym. Streszcz ten tekst w kilku zdaniach, zachowując najważniejsze informacje i terminy.";
        } else {
            continue;
        }

        std::cout << "\nWKLEJ TEKST NAUKOWY DO ANALIZY:\n";
        std::getline(std::cin, textToProcess);
        
        // Tu zaczynamy historie rozmowy od wklejonego tekstu
        std::string chatHistory = "Oto tekst naukowy do analizy: " + textToProcess;
        
        std::cout << "\n[Bielik analizuje...]\n";
        std::string response = client.sendRequest(systemPrompt, chatHistory);
        chatHistory += "\nAsystent: " + response;

        std::cout << "\nBIELIK: " << response << std::endl;

        // PĘTLA DOPYTYWANIA
        while (true) {
            std::cout << "\n(Zadaj pytanie do tematu lub wpisz 'nowy', aby zmienic tekst, wpisz 'koniec', aby wyjsc): ";
            std::string followUp;
            std::getline(std::cin, followUp);

            if (followUp == "nowy") break;
            if (followUp == "koniec") return 0;

            chatHistory += "\nUzytkownik: " + followUp;
            
            std::cout << "\nBielik mysli... ";
            response = client.sendRequest(systemPrompt, chatHistory);
            chatHistory += "\nAsystent: " + response;

            std::cout << "\nBIELIK: " << response << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
    }

    return 0;
}