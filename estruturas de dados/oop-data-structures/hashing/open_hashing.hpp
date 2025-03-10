#ifndef OPEN_HASHING_HPP
#define OPEN_HASHING_HPP

#include <iostream>
#include <cstdlib>

class HashTable {
    private:
        class Node {
            public:
                int dado;
                Node* prox;
                
                Node(int valor) : dado(valor), prox(nullptr) {}
            };
        
        class LinkedList {
            private:
                Node* inicio;
                Node* fim;
                int size;
                
            public:
                LinkedList() : inicio(nullptr), fim(nullptr), size(0) {}
                
                ~LinkedList() {
                    Node* atual = inicio;
                    while (atual != nullptr) {
                        Node* temp = atual;
                        atual = atual->prox;
                        delete temp;
                    }
                }
                
                void inserir(int dado) {
                    Node* ptr = new Node(dado);
                    if (inicio == nullptr) {
                        inicio = ptr;
                    } else {
                        fim->prox = ptr; 
                    }
                    fim = ptr;
                    size++;
                }
                
                Node* buscar(int key) {
                    Node* ptr = inicio;
                    while (ptr != nullptr) {
                        if (ptr->dado == key) {
                            return ptr;
                        } else {
                            ptr = ptr->prox;
                        }
                    }
                    return nullptr;
                }
                
                void imprimir() const {
                    Node* ptr = inicio;
                    while (ptr != nullptr) {
                        std::cout << ptr->dado << " ";
                        ptr = ptr->prox;
                    }
                }
                
                Node* getInicio() const {
                    return inicio;
                }
                
                int getSize() const {
                    return size;
                }
            };
        
            int m; // tamanho da tabela
            LinkedList** tabela;
            
            int funcaoHash(int k) const {
                return std::abs(k) % m;
            }
    
    public:
        HashTable(int tamanho = 10) : m(tamanho) {
            tabela = new LinkedList*[m];
            inicializar();
        }
        
        ~HashTable() {
            for (int i = 0; i < m; i++) {
                delete tabela[i];
            }
            delete[] tabela;
        }
        
        void inicializar() {
            for (int i = 0; i < m; i++) {
                tabela[i] = new LinkedList();
            }
        }
        
        void inserir(int dado) {
            int indice = funcaoHash(dado);
            tabela[indice]->inserir(dado);
        }
        
        int* buscar(int key) {
            int indice = funcaoHash(key);
            Node* ptr = tabela[indice]->buscar(key);
            if (ptr != nullptr) {
                return &ptr->dado;
            } else {
                return nullptr;
            }
        }
        
        void imprimir() const {
            for (int i = 0; i < m; i++) {
                std::cout << i << " ";
                tabela[i]->imprimir();
                std::cout << std::endl;
            }
        }
        
        int getTamanho() const {
            return m;
        }
};

#endif // OPEN_HASHING_HPP
