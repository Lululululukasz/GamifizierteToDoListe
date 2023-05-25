# Kontra-Krastination

### Beschreibung

Dies ist ein Aufgabenmanager, der über ein grafisches Interface gesteuert werden kann. Davon abgesehen, können weitere Funktionalitäten in der main.cpp genutzt werden.

Mit diesem Programm lassen sich Tasks erstellen, löschen, nach Kategorien sortieren und auslesen. Außerdem können Defaulttasks vorgeschlagen werden.

Dieses Projekt befindet sich in der zweiten Phase der Entwicklung.
Das Programm ist von der C++ Standardbibliothek abhängig. Es wurde in CLion programmiert mit der 20 Version von C++.

### Ziele:

- Graphic UI
- Achievement-System (spielerische Gestaltung zur Motivation beim Erledigen von Tasks)
- Erfüllung von Task

### Arbeitsfortschritt:
- Grafisches UI Einstieg
- Erstellen / Löschen von Kategorien und Tasks
- Abstreichen von Tasks
- Grafische Implementierung von Icons
- Erstellung eines Deployments für Windows

### Installation: 
## Build & Run

- Download MSYS2 https://www.msys2.org/
- Start MSYS2 MinGW x64 shell
- Install toolchain and dependencies
    - pacman -Su git mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake mingw-w64-x86_64-qt5
- Build with
    - mkdir build
    - cd build
    - cmake -G "MinGW Makefiles" ..
    - mingw32-make
- Run with
    - ./pic_aem_projekt.exe

## Create installer / deployment
- Install deployment dependencies / nsis installer
    - pacman -Su mingw-w64-x86_64-nsis
- Build and create installer with
    - mkdir build
    - cd build
    - cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
    - mingw32-make
    - cpack -C Release

### Checkout:
- Clone den main Branch: https://gitlab.iue.fh-kiel.de/pic_2023_Gruppe6/pic-aem-gruppe-6.git
- git fetch
- git pull origin/develop
