#include <iostream> 
using namespace std;
int* allocateScores (int size){
    int* scores = new int[size];
    return scores;
}
foid freeScores (int* ptr){
    delete[] ptr;
}
int main(){
    for (int i=0; i<10000; i++){
        int* scores = allocateScores(100);
    }return 0;
}