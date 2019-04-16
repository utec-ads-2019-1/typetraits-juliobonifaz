#ifndef LIST_H
#define LIST_H

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
            // TODO
        }
             
        bool insert(T data) {
            // TODO
        }
             
        bool remove(T item) {
            // TODO
        }  
             
        iterator begin() {
            // TODO
        }
             
        iterator end() {
            // TODO
        }
             
        ~List() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif