#define CATCH_CONFIG_MAIN // Se llama al main predeterminado de catch
#include "..\..\catch.hpp"
#include "Ejercicio 1.h"

// Así se ve una prueba en Catch2
TEST_CASE("Se comprueba si un string tiene caracteres unicos", "[unique]") {
    Unique bf, opt;
    SECTION("Fuerza bruta") {
        REQUIRE(bf.is_unique1("abcde") == true);
        REQUIRE(bf.is_unique1("aAbBcCdDeE") == true);
        REQUIRE(bf.is_unique1("abcded") == false);
        // --- Casos adicionales ---
        REQUIRE(bf.is_unique1("") == true);           // String vacío
        REQUIRE(bf.is_unique1("a") == true);           // Un solo carácter
        REQUIRE(bf.is_unique1("aaaaa") == false);      // Iguales
        REQUIRE(bf.is_unique1("abc def") == true);     // Con espacios (si cuentan)
        REQUIRE(bf.is_unique1("abc def def") == false); // Espacio repetido
    }
    
    SECTION("Solucion optimizada") {
        REQUIRE(opt.is_unique2("abcde") == true);
        REQUIRE(opt.is_unique2("aAbBcCdDeE") == true);
        REQUIRE(opt.is_unique2("abcded") == false);
        // --- Casos adicionales ---
        REQUIRE(bf.is_unique2("") == true);           // String vacío
        REQUIRE(bf.is_unique2("a") == true);           // Un solo carácter
        REQUIRE(bf.is_unique2("aaaaa") == false);      // Iguales
        REQUIRE(bf.is_unique2("abc def") == true);     // Con espacios (si cuentan)
        REQUIRE(bf.is_unique2("abc def def") == false); // Espacio repetido
    }
}
