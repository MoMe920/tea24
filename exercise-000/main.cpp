#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value);
void changeValueByPointer(int* ptr);      // int* prt oder int *ptr


int main(int argc, char **argv) {

    
    // Teil 0: Kommandozeilenparameter ( argc und argv )
    // 1. Anzahl der Argumente ausgeben
    fmt::print("Anzahl Argumente (argc): {}\n", argc);

    // 2. Alle Argumente und deren Adressen in einer Schleife ausgeben
    for (int i = 0; i < argc; i++) {
        // {} ersetzt %s für Strings und %p für Speicheradressen
        fmt::print("argv[{0}] = \"{1}\" (Adresse: {2})\n", i, argv[i], static_cast<const void*>(argv[i]));
    }



    // Teil 1: Zeiger-Grundlagen
    int var = 4711;
    int x = 10;
    int* ptr = &x;  // & gehe zu Variable x, schaue auf welcher Adresse sie liegt und schreibe sie in den Pointer rein 
    int y = 5;

    *ptr = 42;

    
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/12.0/api/
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */
    fmt::print("Value of var: {}\n", var);
    fmt::print("Value of x: {}\n", x);
    fmt::print("Die Adresse von x ist: {}\n", fmt::ptr(&x));
    fmt::print("Value of argc: {}\n", argc);


    // Teil 2: Dynamische Speicherverwaltung
    // 1. Zeiger auf double deklarieren
    // 2. Speicher mit 'new' reservieren und mit 3.1415 initialisieren
    double* d = new double(3.1415);

    // 3. Wert und Adresse mit fmt::print ausgeben
    fmt::print("Wert: {}\n", *d);
    fmt::print("Adresse: {}\n", fmt::ptr(d));

    // 4. Speicher anschließend wieder mit delete freigeben
    delete d;


    //Teil 3: Funktionen mit Zeigern 
    fmt::print("--- Test mit changeValueByParameter ---\n");
    // 2. Aufruf von changeValueByParameter
    fmt::print("Vor dem Aufruf: y = {}\n", y);
    changeValueByParameter(y);
    fmt::print("Nach dem Aufruf: y = {}\n\n", y);


    fmt::print("--- Test mit changeValueByPointer ---\n");
    // 3. Aufruf von changeValueByPointer
    fmt::print("Vor dem Aufruf: y = {}\n", y);
    changeValueByPointer(&y); // Adresse von y wird übergeben
    fmt::print("Nach dem Aufruf: y = {}\n", y);
    


    return 0; /* exit gracefully*/
}


//Teil 3: Funktionen mit Zeigern 
// 1. Übergabe als Kopie (Call-by-Value)
void changeValueByParameter(int value) {
    value = 99;
    fmt::print("[In Funktion] value wurde geändert auf: {}\n", value);
}

// 2. Übergabe als Zeiger (Call-by-Pointer)
void changeValueByPointer(int* ptr) {
        *ptr = 77;
        fmt::print("[In Funktion] *ptr wurde geändert auf: {}\n", *ptr);
}

