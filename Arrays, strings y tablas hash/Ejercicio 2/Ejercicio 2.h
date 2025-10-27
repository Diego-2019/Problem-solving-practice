/*
Dado un array de números enteros y un target, retorna los índices de dos números para los que 
la suma de ambos sea igual al target.

Puedes asumir que hay 1 solamente una solución.

Ejemplo 1:
    Input: nums = [9, 2, 5, 6], target = 7
    Output: [1, 2]
    Explicación: nums[1] + nums[2] == 7, devolvemos [1, 2]

Ejemplo 2:
    Input: nums = [9, 2, 5, 6], target = 100
    Output: null
*/

#include <unordered_map>
#include <vector>

using namespace std;

class Sum {
    public:
        // fuerza bruta -> O(n^2)
        vector<int> two_sum1(vector<int> array, int target) {
            for(int i = 0; i < array.size(); i++) {
                for(int j = i + 1; j < array.size(); j++) {
                    if((array[i] + array[j]) == target) {
                        
                        return {i, j};
                    }
                }
            }
            return {};
        }
        
        // optimizada -> O(n)
        vector<int> two_sum2(vector<int> &array, int target) {
            int complement;
            // tabla hash para buscar las soluciones {complemento, indice} = {target - num, indice}
            unordered_map<int, int> complements;

            for(int i = 0; i < array.size(); i++) {
                // buscamos si el numero esta en la tabla hash
                if(complements.count(array[i])) return {complements.at(array[i]), i};
                // calculamos el complemento y lo guardamos en la tabla hash
                complement = target - array[i];
                complements.insert({complement, i});                
            }
            return {};
        }
};