# Initialisierungslisten in C++

## Was ist eine Initialisierungsliste?

Eine **Initialisierungsliste** (engl. *member initializer list*) ist ein Mechanismus in C++, mit dem Member-Variablen direkt beim Anlegen eines Objekts initialisiert werden – noch **bevor** der Rumpf des Konstruktors ausgeführt wird.

**Syntax:**

```cpp
class B
{
public:
    B() : m_a1(), m_a2(2)   // <-- Initialisierungsliste
    {
        std::cout << "B\n";  // Konstruktorrumpf
    }
private:
    A m_a1;
    A m_a2;
};
```

Die Initialisierungsliste steht zwischen dem `:` nach dem Konstruktorkopf und der öffnenden `{` des Konstruktorrumpfs. Jeder Eintrag hat die Form `member(wert)`.

---

## Initialisierungsliste vs. manuelle Zuweisung im Konstruktor

### Variante 1 – Initialisierungsliste

```cpp
class Foo
{
public:
    Foo(int x) : m_x(x) {}   // direkte Initialisierung
private:
    int m_x;
};
```

`m_x` wird **einmal** direkt mit `x` initialisiert.

### Variante 2 – Manuelle Zuweisung im Konstruktorrumpf

```cpp
class Foo
{
public:
    Foo(int x)
    {
        m_x = x;   // erst Default-Initialisierung, dann Zuweisung
    }
private:
    int m_x;
};
```

`m_x` wird hier **zuerst** mit dem Standardwert initialisiert (bei `int`: unbestimmter Wert) und **danach** überschrieben – also zwei Schritte statt einem.

---

## Reihenfolge der Initialisierung

Member werden **in der Reihenfolge ihrer Deklaration** in der Klasse initialisiert, unabhängig von der Reihenfolge in der Initialisierungsliste.

Im Beispiel gilt: `m_a1` wird immer vor `m_a2` initialisiert, weil es zuerst deklariert ist.

---

## Wann Initialisierungsliste verwenden?

| Situation | Initialisierungsliste |
|---|---|
| `const`-Member | **Pflicht** – kann danach nicht mehr zugewiesen werden |
| Referenz-Member (`int&`) | **Pflicht** – Referenzen müssen sofort gebunden werden |
| Member ohne Default-Konstruktor | **Pflicht** – sonst Compiler-Fehler |
| Basis-Klasse mit Parametern | **Pflicht** – Aufruf des Basisklassen-Konstruktors |
| Einfache Member (int, double, ...) | **Empfohlen** – effizienter, klarer |
| Member-Objekte (wie Klasse `A`) | **Empfohlen** – vermeidet doppelte Initialisierung |

---

## Wann manuelle Zuweisung im Konstruktor sinnvoll ist

- Komplexe Logik ist nötig, bevor ein Wert feststeht (z. B. Berechnung, Validierung, Fehlerbehandlung mit Exceptions).
- Der Wert eines Members hängt vom Wert eines anderen Members ab, der erst im Rumpf gesetzt wird.
- Zuweisung an Arrays oder andere Container-Elemente, die keine Konstruktorargumente unterstützen.

```cpp
Foo(int x)
{
    if (x < 0) throw std::invalid_argument("x muss positiv sein");
    m_x = x;
}
```

---

## Vor- und Nachteile im Überblick

### Initialisierungsliste

| Vorteile | Nachteile |
|---|---|
| Effizient: nur ein Schritt (kein Default + Zuweisung) | Reihenfolge abhängig von Deklaration, nicht von der Liste – kann verwirren |
| Für `const` und Referenzen zwingend erforderlich | Komplexe Logik schlecht lesbar in der Liste |
| Explizit: zeigt direkt, welcher Konstruktor aufgerufen wird | |
| Bessere Performance bei Member-Objekten | |
| **Keine extra Kopie**: Member wird direkt mit den richtigen Argumenten konstruiert – kein temporäres Objekt, kein nachträglicher `operator=`-Aufruf | |

### Manuelle Zuweisung im Konstruktor

| Vorteile | Nachteile |
|---|---|
| Beliebig komplexe Logik möglich | Zwei Schritte: Default-Init + Zuweisung → schlechter Performance |
| Für viele Entwickler vertrauter | Für `const`/Referenz-Member nicht verwendbar |
| Einfachere Fehlerbehandlung | Gefahr, einen Member versehentlich nicht zu initialisieren |

---

## Zusammenfassung

> **Faustregel:** Initialisierungslisten sind der bevorzugte Weg in C++. Manuelle Zuweisungen im Konstruktorrumpf sind nur dann notwendig, wenn die Initialisierung komplexe Logik erfordert, die sich nicht in der Liste ausdrücken lässt.

```
Initialisierungsreihenfolge bei B():
1. m_a1 wird konstruiert  →  A()   gibt "A" aus
2. m_a2 wird konstruiert  →  A(2)  gibt "X2" aus
3. Konstruktorrumpf von B →  gibt "B" aus
```

Daraus ergibt sich der Output des Beispielprogramms:

```
--- this is line 32
AX2B
--- this is line 34
```
