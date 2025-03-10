#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include "complete_linked_list.hpp"

template <typename Key, typename Value>
class HashTable {
    private:
        class Pair{
            private:
                Key key;
                Value value;

            public:
                Pair() : key(""), value("") {}
                Pair(const Key& k, const Value& v) : key(k), value(v) {}
                ~Pair() = default;
        }; 

        static const int m = 101; // tamanho fixo da tabela
        int count; // quantidade de elementos válidos na tabela
        LinkedList<Pair>* table[m];
        //Pair* table[m]; // array de ponteiros para Pair 
        static Pair* DELETED; // ponteiro para marcar posições removidas

        // trivial
        int hashFunction(const int &key){
            return key % m;
        }

        // mid-square
        int hashFunction(const int &key, bool efficient){
            int r = 1;
            while (std::pow(10, r) - 1 < m) {
                r++;
            }
            r--;
            
            long long squared = std::pow(key, 2);
            
            string s = to_string(squared);
            int L = s.size();
            int inicio = (L - r) / 2;
            string meio = s.substr(inicio, r);

            return stoi(meio) % m;
        }

        // fold
        int hashFunction(const string &key){
            int s = key.length();
            long long sum = 0;
            for (int i = 0; i < s; i++){
                sum += key[i];
            }
            return abs(sum) % m;
        }
        
        // sfold
        int hashFunction(const string &key, bool efficient){
            int intLength = key.length() / 4; // número de partes completas de 4 caracteres
            long long sum = 0;
            for (int i = 0; i < intLength; i++) {
                string part = key.substr(i * 4, 4);
                long long mult = 1;
                for (int j = 0; j < part.length(); j++) {
                    sum += part[j] * mult;
                    mult *= 256;
                }
            }

            string remaining = key.substr(intLength * 4); // parte restante da string que não completa 4 caracteres
            long long mult = 1;
            int s = remaining.length();
            for (int j = 0; j < s; j++) {
                sum += remaining[j] * mult;
                mult *= 256;
            }

            return abs(sum) % m;
        }
    
    public:
        HashTable() : count(0) {
            for (int i = 0; i < m; i++){
                table[i] = new LinkedList<Pair>(); 
            }
        }
        ~HashTable() = default;
        // ------- COLLISION RESOLUTION -------
        // Open Hashing (seperate chaining)
        // -- Each address is associated with a linked list
        template <typename Key, typename E>
        void insert(Key k, E e){
            // compute h(K) = j, insert in the j-th linked list, 
                // list is sorted: better search, worse insertion, 
                // for unsorted lists: worse search, better insertion
            // assuming the lists are not sorted and always insert in the end
            if (search(k) == nullptr){
                int pos = hashFunction(k);
                auto l = table[pos];
                Pair* pair = new Pair(k, e);
                l.push_back(pair);
            }
        }

        template <typename Key>
        bool search(Key k){
            // compute h(K) = j, if the j-th linked list is empty, element not found, otherwise, search the linked list
            int j = hashFunction(k);
            auto lista = table[j];
            Node* curr = lista.front();
            while (curr != nullptr){
                if (curr->data == k){
                    return true;
                } else {
                    curr = curr->next;
                }
            }
            return false;
        }

        void delete(){
            // compute h(K) = j, remove from the j-th linked list
        }



        // Closed Hashing (open addressing)


        https://chatgpt.com/c/67bd9655-9a30-8011-8490-87e5e44195d1 @cin
        // Construtor: inicializa todos os slots como vazios (nullptr)
        // Destrutor: libera a memória dos elementos armazenados.
        // Busca uma chave na tabela; retorna o índice se encontrado ou -1 se não.
        // Insere um par chave-valor na tabela. Retorna false se a chave já existir ou se não houver slot disponível.
        // Remove um par chave-valor da tabela. Retorna false se a chave não for encontrada.
        // Imprime o número de elementos armazenados e, em seguida, cada posição ocupada no formato: índice:key:value
        // Inicialização do ponteiro DELETED para marcar slots removidos.

};

#endif

