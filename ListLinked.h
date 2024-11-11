#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first; 
        int n;          
	int max;
	static const int MINISIZE = 2;
    public:
        
		ListLinked(){
			first = nullptr;
			n = 0;
		} 

        
        ~ListLinked() {
            Node<T>* aux;
            while (first != nullptr) {
                aux = first->next; 
                delete first;               
                first = aux;                
            }
        }


        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Índice fuera de rango");
            }

            Node<T>* current = first; 
            for (int i = 0; i < pos; ++i) {
                current = current->next; 
	    }
            return current->data; 
        }

        
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data << " "; 
                current = current->next;     
            }
            return out;
        }

		void insert(int pos, T e) override {
			if (pos < 0 || pos > n) {  
					throw std::out_of_range("Posición fuera de rango");
				}

				Node<T>* newNode = new Node<T>{e, nullptr};  

				if (pos == 0) {  
					newNode->next = first;  
					first = newNode;        
				} else {
					Node<T>* current = first;

			
					for (int i = 0; i < pos - 1; ++i) {
						current = current->next;
					}

					newNode->next = current->next;
					current->next = newNode;
				}

				++n; 
		}


        void append(T e) override {
            insert(n, e); 
        }

        void prepend(T e) override {
            insert(0, e); 
        }
	
	T remove(int pos) override {
	    if (pos < 0 || pos >= n) {  
        	throw std::out_of_range("Posición fuera de rango");
 	   	}

	    Node<T>* toDelete = nullptr;
	    T removed_element;

	    if (pos == 0) {  
	        toDelete = first;        
	        removed_element = first->data;  
	        first = first->next;     
	    } else {
	        Node<T>* current = first;

	        for (int i = 0; i < pos - 1; ++i) {
	            current = current->next;
        	}

	        toDelete = current->next;
        	removed_element = toDelete->data;

                current->next = toDelete->next;
	    }

	    delete toDelete;  
	    --n;              

	    return removed_element;  
	}

	T get(int pos) override {
	    if (pos < 0 || pos >= n) {  
	        throw std::out_of_range("Posición fuera de rango");
	    }

	    Node<T>* current = first;

    
	    for (int i = 0; i < pos; ++i) {
	        current = current->next;
	    }

	    return current->data;  
	}

	int search(T e) override {
	    Node<T>* current = first;  
	    int pos = 0;               
    
	    while (current != nullptr) {
	        if (current->data == e) {  
	            return pos;  
	        }
	        current = current->next;  
	        ++pos;  
	    }
	    return -1;  
	}

        
    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n; 
	}
};

