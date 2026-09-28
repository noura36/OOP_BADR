#include <iostream>
#include <vector>

// Simple Heap Manager Simulation for High Scores
void manageHighScoreHeap() {
    int capacity = 5;
    int currentSize = 0;
    
    // Allocating raw memory on the Heap using new[]
    int* highScores = new int[capacity];
    
    std::cout << "[Heap Manager] Allocated memory for " << capacity << " scores on the Heap.\n";
    
    // Simulating adding scores
    for (int i = 0; i < 3; ++i) {
        highScores[currentSize++] = (i + 1) * 150;
        std::cout << "Added score: " << highScores[currentSize - 1] << "\n";
    }
    
    // Proper cleanup to prevent memory leaks (RAII / Manual delete)
    delete[] highScores;
    highScores = nullptr;
    std::cout << "[Heap Manager] Memory successfully deallocated.\n";
}

int main() {
    std::cout << "=== Running Mini-Project: Heap Manager ===\n";
    manageHighScoreHeap();
    return 0;
}