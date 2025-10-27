/*
Dado un metodo que recibe un string comprobar si todos los caracteres son unicos o no
ejemplo:
"abcde" -> true
"abcded" -> false
*/

#include <string>
#include <unordered_set> // para usar una tabla hash con solo clave (sin valor asociado)

using namespace std;

class Unique {
    public:
        // fuerza bruta -> O(n^2)
        bool is_unique1(string s) {
            for(int i = 0; s[i]; i++) {
                for(int j = i + 1; s[j]; j++) {
                    if(s[i] == s[j]) return false;                    
                }
            }
            return true;
        }

        // optimizada -> O(n)
        bool is_unique2(string s) {
            /*
            La solucion se puede llegar a optimizar hasta O(1) pero para un caso puntual en
            el cual la longitud del string es mayor al numero total de caracteres disponibles
            por ejemplo 128 en ascii o 256 en ascii extendido
            */
            int maxChars = 256;
            if(s.length() > maxChars) return false; // O(1) para este caso

            unordered_set<char> hashTable;
            for(int i = 0; s[i]; i++) {
                // find() si encuentra el elemento devuelve su indice 
                if(hashTable.find(s[i]) != hashTable.end()) return false;
                else hashTable.insert(s[i]);
            }
            return true;
        }
};

