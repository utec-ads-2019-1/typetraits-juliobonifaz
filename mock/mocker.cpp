#include "mocker.h"

int Mocker::generateRandomInt(int min) {
    uniform_int_distribution<mt19937::result_type> distribution(min, MAX);
    return distribution(rng);
}

char Mocker::generateRandomChar() {
    int increment = generateRandomInt() % 26;
    return 'a' + increment;
}

float Mocker::generateRandomFloat() {
    uniform_int_distribution<mt19937::result_type> distribution(MIN, MAX);
    return distribution(rng);
}