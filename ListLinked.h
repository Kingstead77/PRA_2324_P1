#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first; // Puntero al primer nodo de la lista enlazada
        int n;          // Número de elementos en la lista

    public:
        // Constructor sin argumentos
        ListLinked() : first(nullptr), n(0) {}

        // Destructor
        ~ListLinked() {
            // Liberar la memoria de los nodos
            while (first != nullptr) {
                Node<T>* aux = first->next; // Guardar el siguiente nodo
                delete first;               // Liberar el nodo actual
                first = aux;                // Avanzar al siguiente nodo
            }
        }

        // Sobrecarga del operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Índice fuera de rango");
            }

            Node<T>* current = first; // Comenzar en el primer nodo
            for (int i = 0; i < pos; ++i) {
                current = current->next; // Avanzar al nodo en la posición deseada
            }
            return current->data; // Devolver el elemento en la posición pos
        }

        // Sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data << " "; // Imprimir el data de cada nodo
                current = current->next;     // Avanzar al siguiente nodo
            }
            return out;
        }
};

