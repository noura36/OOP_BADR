#include <iostream>


int* allocateScores(int size) {
    
    return new int[size]; 
}

void freeScores(int* ptr) {

    delete[] ptr; 
}

int main() {

  
    for (int i = 0; i < 10000; ++i) {
        int* scores = allocateScores(100); 
       // freeScores(scores);
    }
    return 0;
}