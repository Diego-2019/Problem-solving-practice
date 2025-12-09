/*
Dado un array de strings, devuelve los anagramas agrupados. Cualquier orden es valido.

Ejemplo:
Input: ["saco", "arresto", "programa", "rastreo", "caso"].
Output: [["saco", "caso"], ["arresto", "rastreo"], ["programa"]].
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Anagram {
    public:
        vector<vector<string>> anagrams(vector<string> &words) {
            // Si esta vacio retornamos un vector vacio
            if(words.empty()) return {};

            string hash;
            unordered_map<string, vector<string>> map;
            for(string& word : words) {
                hash = get_hash(word);
                // si no existe el elemeto lo crea, si existe agrega la palabra al vector
                map[hash].push_back(word);
            }

            // creamos el vector de vectores de anagramas
            vector<vector<string>> anagramList;
            // iteramos cada par del mapa
            for(auto& pair : map) {
                // agragamos el vector de cada hash
                anagramList.push_back(pair.second);
            }
            return anagramList;
        }

        string get_hash(string &s) {
            string letterCounts(26, 0); // string de tamaño 26 lleno de 0's

            // sumamos 1 a la letra correspondiente
            for(char& c : s) letterCounts[c - 'a']++; // c - 97

            return letterCounts;
        }
};