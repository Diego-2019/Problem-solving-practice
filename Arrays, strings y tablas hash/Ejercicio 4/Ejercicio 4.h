/*
Dada una matriz de enteros, debes modificarla de tal manera que si un elemento es 
cero, toda la fila y toda la columna que contienen ese elemento se establezcan en 
cero.

Ejemplo:
Input:     [[1  1  1]
            [1  0  1]
            [1  1  1]]

Output:    [[1  0  1]
            [0  0  0]
            [1  0  1]]
*/

#include <vector>

using namespace std;

class Matrix {
    public:
        // revisamos si hay algun 0 en la primera fila
        bool first_row(vector<vector<int>> &matrix) {
            for(int i = 0; i < matrix[0].size(); i++) {
                if(matrix[0][i] == 0) return true;
            }
            return false;
        }

        // revisamos si hay algun 0 en la primera columna
        bool first_column(vector<vector<int>> &matrix) {
            for(int i = 0; i < matrix.size(); i++) {
                if(matrix[i][0] == 0) return true;
            }
            return false;
        }

        // revisamos si hay 0's a partir de la segunda fila y columna usando las primera fila y columna para notas
        void check_zeros(vector<vector<int>> &matrix) {
            for(int i = 1; i < matrix.size(); i++) {
                for(int j = 1; j < matrix[0].size(); j++) {
                    if(matrix[i][j] == 0) {
                        // usamos la primera fila y columna para saber que filas y columnas se vuelven 0
                        matrix[i][0] = matrix[0][j] = 0;
                    }
                }
            }
        }

        // llenamos la fila con 0's
        void fill_row(vector<vector<int>> &matrix, int row) {
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[row][i] = 0;
            }
        }

        // llenamos la columna con 0's
        void fill_column(vector<vector<int>> &matrix, int col) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }

        vector<vector<int>> zero_matrix(vector<vector<int>> &matrix) {
            if(matrix.empty()) return matrix;
            
            bool firstRowHasZero = first_row(matrix);
            bool firstColHasZero = first_column(matrix);

            // revisamos donde hay ceros
            check_zeros(matrix);

            // iteramos sobre la primera fila y columna
            for(int i = 0; i < matrix[0].size(); i++) {
                // llenamos las columnas con 0's
                if(matrix[0][i] == 0) fill_column(matrix, i);
            }

            for(int i = 0; i < matrix.size(); i++) {
                // llenamos las filas con 0's
                if(matrix[i][0] == 0) fill_row(matrix, i);
            }

            if(firstRowHasZero) fill_row(matrix, 0);
            if(firstColHasZero) fill_column(matrix, 0);

            return matrix;
        }
};