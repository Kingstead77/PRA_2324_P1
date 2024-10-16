#include <iostream>
#include <stdexcept> // Para std::out_of_range
#include "List.h"

template <typename T>
class ListArray : public List<T> {
    private:
        T* arr;                      // Puntero al inicio del array
        int max;                     // Tamaño actual del array
        int n;                       // Número de elementos en la lista
        static const int MINSIZE = 2; // Tamaño mínimo del array

        // Método privado para redimensionar el array
        void resize(int new_size) {
            // Crear un nuevo array dinámico
            T* new_arr = new T[new_size];

            // Copiar el contenido del array actual al nuevo array
            for (int i = 0; i < n; ++i) {
                new_arr[i] = arr[i];
            }

            // Liberar la memoria del array antiguo
            delete[] arr;

            // Actualizar puntero y tamaño
            arr = new_arr;
            max = new_size;
        }

    public:
        // Constructor
        ListArray() : max(MINSIZE), n(0) {
            arr = new T[max]; // Reserva memoria para MINSIZE elementos
        }

        // Destructor
        ~ListArray() {
            delete[] arr; // Liberar memoria dinámica
        }

        // Sobrecarga del operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Índice fuera de rango");
            }
            return arr[pos]; // Devuelve el elemento en la posición pos
        }

        // Sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
            for (int i = 0; i < list.n; ++i) {
                out << list.arr[i] << " "; // Imprime cada elemento
            }
            return out; // Devuelve el flujo de salida
        }

        // Implementación de otros métodos heredados
        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición fuera de rango");
            }

            if (n == max) {
                resize(max * 2); // Duplicar el tamaño si está lleno
            }

            // Mover elementos a la derecha
            for (int i = n; i > pos; --i) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = e; // Insertar el nuevo elemento
            ++n; // Incrementar el número de elementos
        }

        void append(T e) override {
            insert(n, e); // Inserta al final
        }

        void prepend(T e) override {
            insert(0, e); // Inserta al principio
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }

            T removed_element = arr[pos]; // Guardar el elemento a eliminar

            // Mover elementos a la izquierda
            for (int i = pos; i < n - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            --n; // Decrementar el número de elementos

            // Redimensionar si es necesario
            if (n < max / 4 && max > MINSIZE) {
                resize(max / 2); // Reducir tamaño si está "demasiado vacío"
            }

            return removed_element; // Devolver el elemento eliminado
        }

        T get(int pos) override {
            return (*this)[pos]; // Usar la sobrecarga del operador []
        }

        int search(T e) override {
            for (int i = 0; i < n; ++i) {
                if (arr[i] == e) {
                    return i; // Devolver la posición del elemento
                }
            }
            return -1; // Devolver -1 si no se encuentra
        }

        bool empty() const override {
            return n == 0; // La lista está vacía si n es 0
        }

        int size() const override {
            return n; // Devolver el número de elementos
        }
};
