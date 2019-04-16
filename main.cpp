#include <iostream>

#include "list.h"

using namespace std;

void testSimpleLinkedList();

template <typename T>
struct Greater {
    bool operator()(T a, T b) {
        return a >= b; // What would happend without the =?
    }
};

template <typename T>
struct Less {
    bool operator()(T a, T b) {
        return a <= b; // What would happend without the =?
    }
};

struct Integer {
       typedef int T;
       typedef Less<T> Operation;
};

struct Float {
       typedef float T;
       typedef Greater<T> Operation;
};

int main(int argc, char const *argv[]) {
    testSimpleLinkedList();

    return EXIT_SUCCESS;
}

void testSimpleLinkedList() {
    cout << "Simple Linked List" << endl;

    List<Integer> integers;
    List<Float> floats;
    
    for (int i = 0; i < 5; i++) {
        integers.insert(2 * i + 1);
        floats.insert(20.f / (i + 1.f) + 2.f);
    }

    integers.remove(5);
    floats.remove(7);
}