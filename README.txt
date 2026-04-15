PROJEKT: Redaktor AI 
PRZEDMIOT: Języki Programowania Obiektowego
AUTOR: Julia Procek

OPIS PROJEKTU:
Aplikacja służąca do automatycznej redakcji i zmiany stylu 
tekstu przy użyciu lokalnego modelu językowego (LLM) przez API Ollama.
Program pozwala na transformację tekstu w trzech wariantach:
1. Styl dziecięcy.
2. Styl młodzieżowy.
3. Styl poetycki.

FUNKCJONALNOŚCI:
- Komunikacja z modelem LLM poprzez REST API (biblioteka CPR).
- Przetwarzanie asynchroniczne (QtConcurrent) - GUI nie zamarza podczas pracy AI.
- Personalizowany interfejs graficzny (Qt Widgets + CSS).
- Obsługa błędów połączenia i walidacja danych wejściowych.

INSTRUKCJA URUCHOMIENIA:
1. Upewnij się, że aplikacja Ollama jest uruchomiona w tle.
2. Pobierz model.
3. Skompiluj projekt przy użyciu CMake (zalecane VS Code + CMake Tools).
4. Uruchom plik RedaktorAI.exe.

STRUKTURA PROJEKTU:
/src - Kod źródłowy (MainWindow, OllamaClient)
/vcpkg - Zarządzanie bibliotekami (CPR, nlohmann_json)
/build - Pliki binarne i biblioteki DLL