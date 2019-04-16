#ifndef MOCKER_H
#define MOCKER_H

#include <random>
#include <type_traits>

using namespace std;

#define MIN 0
#define MAX 100

class Mocker {
    private:
        mt19937 rng;
        
    public:
        Mocker() {
            rng.seed(random_device()());
        }

        int generateRandomInt(int min = MIN);
        char generateRandomChar();
        float generateRandomFloat();

        template <typename T>
        T* generateRandomArray(unsigned int size) {
            T *elements = new T[size];
            for (int i = 0; i < size; i++) {
                if (is_same<T, int>::value) {
                    elements[i] = generateRandomInt();
                }
                else if (is_same<T, char>::value) {
                    elements[i] = generateRandomChar();
                }
            }

            return elements;
        }
};

#endif