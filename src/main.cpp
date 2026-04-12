#include <iostream>
#include <string>
#include <windows.h>
#include <future>   // Do wielowatkowosci
#include <chrono>   // Do mierzenia czasu/pauz
#include <vector>
#include "OllamaClient.h"

// Funkcja pomocnicza do animacji ładowania
void playLoadingAnimation(std::future<std::string>& future) {
    const std::vector<char> animation = {'|', '/', '-', '\\'};
    int i = 0;
    // Dopóki wynik z drugiego wątku nie jest gotowy
    while (future.wait_for(std::chrono::milliseconds(100)) != std::future_status::ready) {
        std::cout << "\rBielik mysli... " << animation[i++ % 4] << std::flush;
    }
    std::cout << "\r" << std::string(20, ' ') << "\r"; // Czyszczenie linii animacji
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    OllamaClient client("http://localhost:11434/api/generate");

    std::string textToProcess;
    std::string choice;
    std::string systemPrompt;
    
    std::cout << "===============================================" << std::endl;
    std::cout << "                  REDAKTOR AI                  " << std::endl;
    std::cout << "===============================================" << std::endl;

    while (true) {
        std::cout << "\nWYBIERZ TRYB REDAKCJI (1-3) lub 'koniec': ";
        std::getline(std::cin, choice);

        if (choice == "koniec") break;

        if (choice == "1") {
            systemPrompt = "Zredaguj tekst, aby byl jasny i prosty dla dziecka w przedszkolu, nie dodawaj żadnych innych informacji tylko zredaguj tekst tak aby mogł się np. pojawić w książce dla dzieci, nie tłumacz tylko przepisz językiem zrozumiałym dla dzieci .";
        } else if (choice == "2") {
            systemPrompt = "Zredaguj tekst w stylu mlodziezowym (rel, sigma). Nie dodawaj zadnych innych informacji tylko zredaguj tekst tak aby była to nadal formułka ale tylko napisana w stylu mlodziezowym, nie tłumacz tylko przepisz językiem zrozumiałym dla dzieci.";
        } else if (choice == "3") {
            systemPrompt = "Zrob profesjonalna korekte i streszczenie w punktach.";
        } else {
            continue;
        }

        std::cout << ">>> WKLEJ TEKST: ";
        std::getline(std::cin, textToProcess);
        if (textToProcess.empty()) continue;

        std::string chatHistory = "Tekst: " + textToProcess;

        // PĘTLA KONWERSACJI
        while (true) {
            // --- OBSŁUGA WYJĄTKÓW I WIELOWĄTKOWOŚĆ ---
            try {
                // Uruchamiamy zapytanie w osobnym watku (std::async)
                std::future<std::string> futureResponse = std::async(std::launch::async, [&]() {
                    return client.sendRequest(systemPrompt, chatHistory);
                });

                // W glownym watku puszczamy animacje
                playLoadingAnimation(futureResponse);

                // Pobieramy wynik (jesli wystapil blad w watku, get() go wyrzuci)
                std::string response = futureResponse.get();

                chatHistory += "\nAsystent: " + response;
                std::cout << "\nBIELIK:\n" << response << "\n" << std::string(30, '-') << std::endl;

            } catch (const std::exception& e) {
                // To wyłapie błędy sieciowe, błędy JSONa, wyłączoną Ollamę itp.
                std::cerr << "\n[BLAD KRYTYCZNY]: " << e.what() << std::endl;
                std::cerr << "Upewnij sie, ze Ollama jest wlaczona i sprobuj ponownie." << std::endl;
                break; // Powrót do menu głównego przy błędzie
            }

            std::cout << "\n(Popraw/dopytaj lub wpisz 'nowy'): ";
            std::string followUp;
            std::getline(std::cin, followUp);

            if (followUp == "nowy") break;
            if (followUp == "koniec") return 0;

            chatHistory += "\nUzytkownik: " + followUp;
        }
    }
    return 0;
}