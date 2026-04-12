PROJEKT: Redaktor AI 
PRZEDMIOT: Języki Programowania Obiektowego
AUTOR: Julia Procek

OPIS PROJEKTU:
Aplikacja desktopowa służąca do automatycznej redakcji i zmiany stylu 
tekstu przy użyciu lokalnego modelu językowego (LLM) przez API Ollama.
Program pozwala na transformację tekstu w trzech wariantach:
1. Styl dziecięcy (uproszczony, bajkowy).
2. Styl młodzieżowy (slang: rel, sigma).
3. Styl naukowy (formalny, precyzyjny).

FUNKCJONALNOŚCI:
- Komunikacja z modelem LLM poprzez REST API (biblioteka CPR).
- Przetwarzanie asynchroniczne (QtConcurrent) - GUI nie zamarza podczas pracy AI.
- Personalizowany interfejs graficzny (Qt Widgets + CSS).
- Obsługa błędów połączenia i walidacja danych wejściowych.

INSTRUKCJA URUCHOMIENIA:
1. Upewnij się, że aplikacja Ollama jest uruchomiona w tle.
2. Pobierz model poleceniem w terminalu: ollama pull llama3 (lub bielik).
3. Skompiluj projekt przy użyciu CMake (zalecane VS Code + CMake Tools).
4. Uruchom plik RedaktorAI.exe.

STRUKTURA PROJEKTU:
/src - Kod źródłowy (MainWindow, OllamaClient)
/vcpkg - Zarządzanie bibliotekami (CPR, nlohmann_json)
/build - Pliki binarne i biblioteki DLL