# Aufgabe: Klasse Vehicle mit Header-Datei

## Beschreibung

In dieser Aufgabe soll eine bestehende C++-Datei, die eine Klasse `Vehicle` in einer einzigen `.cpp`-Datei enthält, in eine saubere **Header/Source-Struktur** aufgeteilt werden.

Das Ziel ist es, die Klasse `Vehicle` gemäß dem **Trennungsprinzip von Deklaration und Definition** in drei Dateien aufzuteilen:

- `Vehicle.hpp` – enthält die **Klassendeklaration** (Member-Variablen, Methodenprototypen)
- `Vehicle.cpp` – enthält die **Methodendefinitionen** (Implementierungen)
- `main.cpp` – enthält die `main()`-Funktion und nutzt die Klasse über den Header

Die Logik der Klasse soll dabei **nicht verändert** werden.

### Ausgangsdatei

Die vollständige Klasse als Einzeldatei findet sich hier:
[VehicleV1/task_vehicle.cpp](../212_Konstruktoren/VehicleV1/task_vehicle.cpp)

## Vorgehen

1. Erstellen Sie `Vehicle.hpp` mit der Klassendeklaration und einem Include Guard.
2. Erstellen Sie `Vehicle.cpp`, das `Vehicle.hpp` inkludiert und alle Methoden implementiert.
3. Erstellen Sie `main.cpp`, das `Vehicle.hpp` inkludiert und die `main()`-Funktion enthält.
4. Stellen Sie sicher, dass das Programm korrekt gebaut und ausgeführt werden kann.

## Beispielablauf

```
--- CONSTRUCTOR ---
    Name of vehicle is: PORSCHE
    Maximum distance with current gas is: 500 km
--- New position is: 0
    Current gas is: 50
    Total consumption is 0
--- New position is: 150
    Current gas is: 35
    Total consumption is 15
...
--- DESTRUCTOR ---
```

## Bewertungskriterien

- **Funktionalität**: Kann das Programm fehlerfrei gebaut und ausgeführt werden?
- **Struktur**: Sind Deklaration (`Vehicle.hpp`) und Definition (`Vehicle.cpp`) korrekt getrennt?
- **Include Guard**: Ist `Vehicle.hpp` gegen mehrfaches Inkludieren geschützt?
- **Keine Logikänderung**: Verhält sich das Programm identisch zur ursprünglichen Einzeldatei?
- **Code-Qualität**: Ist der Code sauber, verständlich und entspricht den Coding Conventions?
