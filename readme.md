## Changes
- Changed colour of all payloads to black.
- Wind increases by 9.99 instead of 15.0
- Wind speed (mostly) renamed to wind resistance
- Added payload "apple"
- Added additional aircraft
- Fatter man

## Beskrivning
 Ett litet projekt som installerar Raylib och bygger en **Bombardment Simulator** där spelaren kan släppa olika typer av laster från ett flygplan. Programmet körs på macOS + linux och byggs med CMake.

## Installation
### Förutsättningar
Se till att du har följande installerat på din Mac:
- **Homebrew** (för att installera Raylib)
- **CMake**
- **g++ eller clang**

### Installationssteg
1. Klona detta repository:
   ```sh
   git clone https://github.com/ditt-användarnamn/note.git
   ```
2. Navigera till projektmappen:
   ```sh
   cd bombardSim
   ```
3. Installera Raylib:
   ```sh
   vanligtvis installerar man Raylib genom "brew install raylib"
   Men i detta projekt så installeras det iom cmake i /build 
   ```
4. Skapa en byggmapp och konfigurera projektet:
   ```sh
   mkdir build && cd build
   cmake ..
   ```
5. Bygg projektet:
   ```sh
   make
   ```
6. Kör programmet:
   ```sh
   ./Simulation
   ```

## Användning
Spelet låter dig släppa olika objekt från ett flygplan, justera vindhastigheten och observera hur lasten påverkas av fysiken.

### Styrning:
- **Bombard-knapp:** Släpper vald last
- **Dropdown-meny:** Välj vilken last du vill släppa
- **+ / - knappar:** Justera vindhastigheten

## Teknologier
- **Språk:** C++
- **Bibliotek:** Raylib
- **Byggsystem:** CMake
- **Plattform:** macOS

## Kortfattat om 
Raylib är ett enkelt och lättanvänt C-bibliotek för att skapa spel och grafiska<br>
applikationer. Det är designat för att vara lätt att komma igång med och används
<br> ofta för 2D- och 3D-rendering. Biblioteket innehåller funktioner för grafik,<br> ljud, fysik och inmatning, vilket gör det till ett kraftfullt verktyg för <br>både nybörjare och erfarna utvecklare.

<br>Raylib är plattformsoberoende och fungerar på Windows, macOS och Linux. Det är <br>särskilt populärt inom utbildning och hobbyprojekt tack vare sin enkla API och <br>få beroenden.

<br>"Dock inte på Raspberry pi 5 ännu...:/"
