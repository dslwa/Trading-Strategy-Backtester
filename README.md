# Trading-Strategy-Backtester

Prosty backtester strategii tradingowych w C++. Projekt oparty na przetwarzaniu danych z plików CSV i symulacji transakcji na podstawie wybranych reguł wejścia i wyjścia.

## 📌 Funkcje

- Wczytywanie danych OHLC z plików CSV
- Symulacja transakcji na podstawie reguł strategii
- Obliczanie podstawowych metryk:
  - Zysk/strata
  - Liczba transakcji
  - Skuteczność strategii
- Możliwość łatwego rozszerzania o własne strategie

## 🛠️ Wymagania

- Kompilator C++17 lub nowszy (np. `g++`, `clang++`, MSVC)
- CMake 3.10+
- System Linux, macOS lub Windows

## 🧱 Struktura projektu

├── data/ # Przykładowe dane w formacie CSV
├── include/ # Pliki nagłówkowe
├── src/ # Główna logika programu
├── strategies/ # Implementacje strategii
├── tests/ # Testy jednostkowe (do dodania)
├── main.cpp # Punkt wejścia programu
├── CMakeLists.txt # Konfiguracja CMake
└── README.md
