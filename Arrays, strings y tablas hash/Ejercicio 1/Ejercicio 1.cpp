#define CATCH_CONFIG_MAIN // Se llama al main predeterminado de catch
#include "..\..\catch.hpp"
#include "Ejercicio 1.h"

// Así se ve una prueba en Catch2
TEST_CASE("Se comprueba si un string tiene caracteres unicos", "[unique]") {
    Unique obj;
    SECTION("Fuerza bruta") {
        REQUIRE(obj.is_unique1("abcde") == true);
        REQUIRE(obj.is_unique1("aAbBcCdDeE") == true);
        REQUIRE(obj.is_unique1("abcded") == false);
        // --- Casos adicionales ---
        REQUIRE(obj.is_unique1("") == true);           // String vacío
        REQUIRE(obj.is_unique1("a") == true);           // Un solo carácter
        REQUIRE(obj.is_unique1("aaaaa") == false);      // Iguales
        REQUIRE(obj.is_unique1("abc def") == true);     // Con espacios (si cuentan)
        REQUIRE(obj.is_unique1("abc def def") == false); // Espacio repetido
    }
    
    SECTION("Solucion optimizada") {
        REQUIRE(obj.is_unique2("abcde") == true);
        REQUIRE(obj.is_unique2("aAbBcCdDeE") == true);
        REQUIRE(obj.is_unique2("abcded") == false);
        // --- Casos adicionales ---
        REQUIRE(obj.is_unique2("") == true);           // String vacío
        REQUIRE(obj.is_unique2("a") == true);           // Un solo carácter
        REQUIRE(obj.is_unique2("aaaaa") == false);      // Iguales
        REQUIRE(obj.is_unique2("abc def") == true);     // Con espacios (si cuentan)
        REQUIRE(obj.is_unique2("abc def def") == false); // Espacio repetido
    }
}
