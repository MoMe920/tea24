#include "module.h"
#include "bonus_config.h"

#include <fmt/format.h>

/* .bss Segment */
int foo;
int foo2 = 0;
static int moduleCounter; // Name der Variablen (moduleCounter) ausschließlich innerhalb von module.cpp bekannt

/* .data Segment */
int data = 45;
int data2 = 43;
static int moduleValue = 123; // Name der Variablen (moduleValue) ausschließlich innerhalb von module.cpp bekannt
static int shadow = 11;

/* .rodata Segment */

const int rodata = 45;
const int rodata2 = 43;

const int big_data_blob[] = {42,0xff};



void doSomething(int value)
{
    value = value + 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPtr(int* ptr)
{
    *ptr = *ptr + 1;
    fmt::print("doSomethingPtr, value {}\n", *ptr);
}

int* doReturnAPtr()
{
    int value = 4711;
    fmt::print("doReturnAPtr, value {}\n", value);
    /* 
     * This causes a warning and shall be avoided by all means
     * warning: address of stack memory associated with local variable 'value' returned [-Wreturn-stack-address]
     */
    return &value;
}

void doSomethingStatic()
{
    static int value = 56;
    value = value + 1;
    // fmt::print("doSomethingStatic, value {}\n", value);
    fmt::print("doSomethingStatic, value {}, address {}\n", value, fmt::ptr(&value));

    /*
    Statische Variablen innerhalb von Funktionen werden im globalen Datenbereich 
    (bzw. im .data- oder .bss-Segment) des Programms abgelegt und nicht auf dem Stack.
    Daher belibt die Adresse der Variablen über alle Funktionsaufrufe hinweg exakt gleich.
    */

    /*
    Eine static-Variable besitzt eine statische Lebensdauer. Sie wird nur beim allererstes Erreichen der 
    Deklaration initialisiert (hier mit 56). Beim Verlassen der Funktion wird die Variable nicht zerstört. 
    Sie behält ihren Wert im Speicher bei, sodass der nächste Funktionsaufruf auf genau dieselbe Variable 
    zugreift und den bereits erhöhten Wert weiterverarbeitet (value = value + 1).
    */
}

void doSomethingNonStatic()
{
    int value = 56; // Keine statische Variable
    value = value + 1;
    fmt::print("doSomethingNonStatic, value {}, address {}\n", value, fmt::ptr(&value));

    /*
    Adresse: Die Adresse würde sich bei jedem Aufruf auf dem Stack befinden und je nach Stack-Auslastung und 
    Optimierungen des Compilers entweder gleich bleiben oder sich von Aufruf zu Aufruf ändern. Sie besitzt 
    im Gegensatz zur statischen Variablen keine dauerhafte Speicherpersistenz über Funktionsgrenzen hinweg.
    */
}

void printStaticModuleVariables()
{
    moduleCounter++; // Nur als Beispiel, um zu zeigen, dass sie veränderbar ist
    fmt::print("moduleCounter: Wert = {}, Adresse = {}\n", moduleCounter, fmt::ptr(&moduleCounter));
    fmt::print("moduleValue: Wert = {}, Adresse = {}\n", moduleValue, fmt::ptr(&moduleValue));
}

void printModuleShadow()
{
    fmt::print("module.cpp -> shadow: Wert = {}, Adresse = {}\n", shadow, fmt::ptr(&shadow));
}