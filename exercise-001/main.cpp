#include <fmt/chrono.h>
#include <fmt/format.h>


#include "config.h"

void foo();

int globalVar = 1;
int* ptr_global = &globalVar;

int g_beliebig = 42;    // Initialisierter Wert (.data Segment)
int* ptr_beliebig = &g_beliebig;
int g_null = 0;         // Nullwert (BSS Segment)
int* ptr_null = &g_null;
int g_uninit;           // Keine Werte / uninitialisiert (BSS Segment)
int* ptr_uninit = &g_uninit;



static int g_static = 100; // Statische globale Variable (nur in dieser Übersetzungseinheit sichtbar)
int* ptr_static = &g_static;
const int g_const = 500;   // Konstante globale Variable (meist .rodata Segment)
const int* ptr_const = &g_const;


int main(int argc, char **argv) {

    int localVar = 2;                            // "Normale" lokale Variable (Stack)
    int* ptr_localVar = &localVar;

    static int localStaticVar = 5;               // Statische lokale Variable (Daten-/BSS-Segment)
    int* ptr_localStaticVar = &localStaticVar;

    const int localConstVar = 10;                // Konstante lokale Variable (Stack / Schreibgeschützt)
    const int* ptr_localConstVar = &localConstVar;

    static const int localStaticConstVar = 99;   // Statisch-konstante lokale Variable (.rodata Segment)
    const int* ptr_localStaticConstVar = &localStaticConstVar;

    

    int* heapVar = new int(3);


    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */

    fmt::print("globalVar (Wert: {}, Adresse: {})\n", globalVar, fmt::ptr(&globalVar));
    fmt::print("g_beliebig (Wert: {}, Adresse: {})\n", g_beliebig, fmt::ptr(&g_beliebig));
    fmt::print("g_null     (Wert: {}, Adresse: {})\n", g_null, fmt::ptr(&g_null));
    fmt::print("g_uninit   (Wert: {}, Adresse: {})\n", g_uninit, fmt::ptr(&g_uninit));
    fmt::print("g_static   (Wert: {}, Adresse: {})\n", g_static, fmt::ptr(&g_static));
    fmt::print("g_const    (Wert: {}, Adresse: {})\n", g_const, fmt::ptr(&g_const));

    fmt::print("localVar              (Wert: {}, Adresse: {})\n", localVar, fmt::ptr(&localVar));
    fmt::print("localStaticVar        (Wert: {}, Adresse: {})\n", localStaticVar, fmt::ptr(&localStaticVar));
    fmt::print("localConstVar         (Wert: {}, Adresse: {})\n", localConstVar, fmt::ptr(&localConstVar));
    fmt::print("localStaticConstVar   (Wert: {}, Adresse: {})\n", localStaticConstVar, fmt::ptr(&localStaticConstVar));

    
    fmt::print("heapVar (Heap-Wert)   (Wert: {}, Adresse: {})\n", *heapVar, fmt::ptr(heapVar));

    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));



    delete heapVar;

    return 0; /* exit gracefully*/
}


void foo() { 

    fmt::print("Hello from foo!\\n"); 
}