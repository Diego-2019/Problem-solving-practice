#define CATCH_CONFIG_MAIN
#include "..\..\catch.hpp"
#include "Ejercicio 4.h"

TEST_CASE("Se retorna una matriz con filas y columnas en 0 donde originalmente habia un 0") {
    Matrix obj;
    
    SECTION("Prueba principal") {
        vector<vector<int>> inputMat = {{2, 1, 3, 0, 2}, 
                                        {7, 4, 1, 3, 8}, 
                                        {4, 0, 1, 2, 1}, 
                                        {9, 3, 4, 1, 9}};
    
        vector<vector<int>> outputMat =    {{0, 0, 0, 0, 0},
                                            {7, 0, 1, 0, 8},
                                            {0, 0, 0, 0, 0},
                                            {9, 0, 4, 0, 9}};

        REQUIRE(obj.zero_matrix(inputMat) == outputMat);
    }

    SECTION("Matriz sin ceros") {
        vector<vector<int>> inputMat = {{2, 1, 3, 2},
                                        {7, 4, 1, 3},
                                        {4, 1, 1, 2},
                                        {9, 3, 4, 1}};

        vector<vector<int>> outputMat = inputMat;

        REQUIRE(obj.zero_matrix(inputMat) == outputMat);
    }

    SECTION("Matriz vacia") {
        vector<vector<int>> inputMat = {};

        vector<vector<int>> outputMat = {};

        REQUIRE(obj.zero_matrix(inputMat) == outputMat);
    }

    SECTION("Cero en la primera fila"){
        vector<vector<int>> inputMat = {{9, 1, 0, 2},
                                        {7, 4, 1, 3},
                                        {4, 1, 1, 2},
                                        {9, 3, 4, 1}};

        vector<vector<int>> outputMat = {{0, 0, 0, 0},
                                        {7, 4, 0, 3},
                                        {4, 1, 0, 2},
                                        {9, 3, 0, 1}};

        REQUIRE(obj.zero_matrix(inputMat) == outputMat);
    }

    SECTION("Cero en la primera columna"){
        vector<vector<int>> inputMat = {{9, 1, 4, 2},
                                        {7, 4, 1, 3},
                                        {0, 1, 1, 2},
                                        {9, 3, 4, 1}};
                                        
        vector<vector<int>> outputMat = {{0, 1, 4, 2},
                                        {0, 4, 1, 3},
                                        {0, 0, 0, 0},
                                        {0, 3, 4, 1}};

        REQUIRE(obj.zero_matrix(inputMat) == outputMat);
    }

    SECTION("Matriz Rectangular 2x4 (Prueba de bucles i vs j)") {
        vector<vector<int>> input = {{1, 1, 1, 1}, 
                                     {1, 0, 1, 1}};

        vector<vector<int>> outputMat = {{1, 0, 1, 1}, 
                                        {0, 0, 0, 0}};

        REQUIRE(obj.zero_matrix(input) == outputMat);
    }

    SECTION("Matriz de 1x1") {
        vector<vector<int>> input = {{0}};
        vector<vector<int>> expected = {{0}};

        REQUIRE(obj.zero_matrix(input) == expected);

        vector<vector<int>> input2 = {{1}};
        vector<vector<int>> expected2 = {{1}};
        REQUIRE(obj.zero_matrix(input2) == expected2);
    }
}