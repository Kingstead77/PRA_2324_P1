#ifndef LIST_H
#define LIST_H

#include <stdexcept> // Para usar std::out_of_range

template <typename T>
class List {
    public:
        // Método para insertar un elemento en una posición específica
        virtual void insert(int pos, T e) = 0;

        // Método para agregar un elemento al final de la lista
        virtual void append(T e) = 0;

        // Método para agregar un elemento al principio de la lista
        virtual void prepend(T e) = 0;

        // Método para eliminar un elemento en una posición específica y devolverlo
        virtual T remove(int pos) = 0;

        // Método para obtener un elemento en una posición específica
        virtual T get(int pos) = 0;

        // Método para buscar un elemento y devolver su posición
        virtual int search(T e) = 0;

        // Método para comprobar si la lista está vacía
        virtual bool empty() const = 0;

        // Método para obtener el número de elementos en la lista
        virtual int size() const = 0;

        // Virtual destructor (opcional pero recomendado para clases base)
        virtual ~List() {}
#endif
};
