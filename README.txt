PROJEKT: Redaktor AI 
PRZEDMIOT: Języki Programowania Obiektowego
AUTOR: Julia Procek

OPIS PROJEKTU:
Aplikacja służąca do automatycznej redakcji i zmiany stylu 
tekstu przy użyciu lokalnego modelu językowego przez REST API programu Ollama.
Program pozwala na transformację tekstu w trzech wariantach:
1. Styl dziecięcy.
2. Styl młodzieżowy.
3. Styl poetycki.

FUNKCJONALNOŚCI:
- Komunikacja z modelem LLM poprzez REST API (biblioteka CPR).
- Podejście wielowątkowe - GUI nie zamarza podczas pracy AI.
- Personalizowany interfejs graficzny (Qt Widgets + CSS).
- Obsługa błędów połączenia i walidacja danych wejściowych.

INSTRUKCJA URUCHOMIENIA:
1. Aplikacja Ollama powinna byc uruchomiona w tle.
2. Pobierz model.
3. Skompiluj projekt przy użyciu CMake.
4. Uruchom plik RedaktorAI.exe.

STRUKTURA PROJEKTU:
/src /gui- Obsługa interfejsu użytkownika (MainWindow)
/src /network - Logika komunikacji API (OllamaClient)
/vcpkg - Zarządzanie zewnętrznymi bibliotekami
/build - Pliki binarne i biblioteki DLL
/doc - Dokumentacja Doxygen

TESTY JEDNOSTKOWE:

-Lokalizacja:
Pliki testowe znajdują się w dedykowanym folderze `/tests`.

-Zakres testów:
1. testConnectionError – weryfikuje poprawność obsługi błędów w przypadku braku połączenia z serwerem Ollama (wymaganie pkt 27).
2. testEmptyInput – sprawdza mechanizmy walidacji przy próbie przesłania pustych danych do modelu (wymaganie pkt 32).

-Instrukcja uruchomienia testów:
Aby uruchomić testy, należy:
1. Skompilować projekt (cel UnitTests).
2. Wejść do folderu budowania: `cd build/Debug`.
3. Uruchomić plik wykonywalny: `./UnitTests.exe`.