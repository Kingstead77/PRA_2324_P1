
#include <ostream>

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;

		Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

        	// Sobrecarga del operador <<
        	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
            		out << node.data; // Imprimir el atributo data
            		return out; // Devuelve el flujo de salida
        	}
};
