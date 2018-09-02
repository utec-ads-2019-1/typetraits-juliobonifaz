#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++();
        DListIterator<T> operator--();
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
              
    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            // TODO
        }

        void push_back(T data) {
            // TODO
        }
             
        void pop_front() {
            // TODO
        }
             
        void pop_back() {
            // TODO
        }
             
        iterator begin() {
            // TODO
        }
             
        iterator end() {
            // TODO
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif