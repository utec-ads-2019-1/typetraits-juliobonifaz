#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        List() : head(nullptr) {};

        bool find(T search, Node<T> **&pointer) {
            pointer = &head;
            while (*pointer && cmp((*pointer)->data, search)) {
                if ((*pointer)->data == search) {
                    return true;
                }
                pointer = &((*pointer)->next);
            }

            return false;
        }
             
        bool insert(T data) {
            Node<T> **temp;
            if (find(data, temp)) {
                return false;
            }
                  
            Node<T> *node = new Node<T>(data);
            node->next = *temp;
            *temp = node;
            return true;
        }
             
        bool remove(T item) {
            Node<T> **temp;
                  
            if (!find(item, temp)) {
                return false;
            }

            Node<T> *node = *temp;
            *temp = (*temp)->next;
            delete node;
            return true;
        }  
             
        int size() {
            int count = 0;

            Node<T> *next = head;
            while (next) {
                next = next->next;
                count++;
            }

            return count;
        }

        T operator[](int index) {
            Node<T>* next = this->head;
            for (int i = 0; i < index; i++) {
                if (!next) {
                    throw out_of_range("Position out of bounds");
                }

                next = next->next;
            }

            return next->data;
        }

        ~List() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif