# `class` vs. `struct` in C++

## Der einzige technische Unterschied

In C++ sind `class` und `struct` fast identisch. Es gibt genau **zwei technische Unterschiede**:

| Eigenschaft | `struct` | `class` |
|---|---|---|
| Standard-Sichtbarkeit von Membern | `public` | `private` |
| Standard-Vererbung | `public` | `private` |

Das bedeutet: Jedes `struct` kann 1:1 durch `class` ersetzt werden – und umgekehrt – solange die fehlenden Zugriffsmodifikatoren (`public:`, `private:`) manuell ergänzt werden.

### Beispiel

```cpp
struct Foo {
    int x;  // implizit public
};

class Bar {
    int x;  // implizit private
};
```

```cpp
// Diese beiden sind nicht äquivalent:
struct Foo { public: int x; };
class  Foo {         int x; };  // nein – private!

// Diese beiden sind äquivalent:
struct Foo {          int x; };
class  Foo { public:  int x; };
```

---

## Konvention: Wann wird was verwendet?

Obwohl die Sprache keinen Unterschied erzwingt, gibt es eine weit verbreitete **Konvention** in der C++-Community:

### `struct` verwenden, wenn …

- der Typ **nur Daten** gruppiert (Plain Old Data, POD)
- **keine oder kaum Logik** (Methoden) vorhanden ist
- alle Member **öffentlich** sind
- der Typ als **reiner Datenbehälter** fungiert

```cpp
struct Position {
    int x = 0;
    int y = 0;
};

struct Color {
    uint8_t r, g, b, a;
};
```

### `class` verwenden, wenn …

- der Typ **Verhalten** kapselt (Methoden, Invarianten)
- Member **private** sein sollen (Datenkapselung)
- **Konstruktoren, Destruktoren** oder Vererbung eingesetzt werden
- ein vollständiges **Objekt mit Zustand und Logik** modelliert wird

```cpp
class Vehicle {
public:
    Vehicle();
    ~Vehicle();
    void move(int seconds);
    void printPosition();
private:
    Position m_position;
    int m_speed = 2;
};
```

---

## Vererbung: Standard-Sichtbarkeit

```cpp
struct Base { int x; };

struct DerivedA : Base {};   // entspricht: public Base
class  DerivedB : Base {};   // entspricht: private Base  ← Achtung!
```

Bei Vererbung mit `class` als abgeleiteter Typ muss `public` explizit angegeben werden, wenn gewünscht:

```cpp
class DerivedB : public Base {};  // jetzt korrekt
```

---

## Zusammenfassung

| | `struct` | `class` |
|---|---|---|
| Technischer Unterschied | Standard `public` | Standard `private` |
| Typischer Einsatz | Reine Datenbehälter (POD) | Objekte mit Kapselung & Logik |
| Methoden erlaubt? | Ja (aber unüblich) | Ja |
| Vererbung erlaubt? | Ja | Ja |

> **Faustregel:** Wenn du dich fragst, ob du `struct` oder `class` nehmen sollst: Gibt es private Member oder nicht-triviale Methoden? → `class`. Sind es nur zusammengehörige Datenfelder? → `struct`.
