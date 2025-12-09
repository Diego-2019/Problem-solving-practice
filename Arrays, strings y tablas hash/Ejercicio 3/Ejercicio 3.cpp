#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "Ejercicio 3.h"

#include <vector>
#include <string>
#include <algorithm> // Necesario para is_permutation

using namespace std;

/*
Comprueba si la lista de resultados 'anagrams' contiene un grupo
que sea una permutación del grupo 'group' esperado.
*/
bool containsGroup(vector<vector<string>>& anagrams, vector<string>& group) {
    
    for (auto& g : anagrams) {
        if (g.size() == group.size() && is_permutation(g.begin(), g.end(), group.begin())) {
            return true;
        }
    }
    return false;
}


// Este es el test principal
TEST_CASE("Pruebas de GroupAnagrams") {

    Anagram groupAnagrams; // Instancia de la clase

    SECTION("Prueba con input vacío") {
        vector<string> inputVacio = {};
        vector<vector<string>> empty = groupAnagrams.anagrams(inputVacio);
        
        REQUIRE(empty.empty());
    }

    SECTION("Prueba con el ejemplo principal") {
        vector<string> input = {"saco", "arresto", "programa", "rastreo", "caso"};
        vector<vector<string>> anagrams = groupAnagrams.anagrams(input);

        REQUIRE(anagrams.size() == 3);

        REQUIRE(containsGroup(anagrams, {"programa"}));

        REQUIRE(containsGroup(anagrams, {"caso", "saco"}));

        REQUIRE(containsGroup(anagrams, {"arresto", "rastreo"}));
    }
}