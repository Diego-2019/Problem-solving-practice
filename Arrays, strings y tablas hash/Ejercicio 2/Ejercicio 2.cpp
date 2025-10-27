#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "Ejercicio 2.h"

TEST_CASE("Se retorna los indices de dos numeros para los que la suma de ambos sea igual al target.") {
    Sum obj;
    vector<int> arr = {9, 2, 5, 6};
    vector<int> result1 = obj.two_sum1(arr, 7), result2 = obj.two_sum2(arr, 7);

    SECTION("Fuerza bruta") {
        REQUIRE(((result1[0] == 2 && result1[1] == 1) || (result1[0] == 1 && result1[1] == 2)));
        REQUIRE(obj.two_sum1(arr, 50) == vector<int>{});
    }
    SECTION("Optimizada") {
        REQUIRE(((result2[0] == 2 && result2[1] == 1) || (result2[0] == 1 && result2[1] == 2)));
        REQUIRE(obj.two_sum2(arr, 50) == vector<int>{});
    }
}