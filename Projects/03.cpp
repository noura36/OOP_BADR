#include <iostream>
#include <utility>
using namespace std;
template <typename T>
class IntVector {
private:
    T* data;
    int size;
public:
    // Constructor
    IntVector(int s) {
        size = s;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }cout << "Constructor" << endl;
    }
     // Destructor
    ~IntVector() {
        delete[] data;
        cout << "Destructor" << endl;
    }
      IntVector(const IntVector& other) {
        size = other.size;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        cout << "Copy Constructor" << endl;
    }
       IntVector& operator=(const IntVector& other) {
        if (this == &other) {
            return *this;
        }T* newData = new T[other.size];
        for (int i = 0; i < other.size; i++) {
            newData[i] = other.data[i];
        }delete[] data;
        data = newData;
        size = other.size;
        cout << "Copy Assignment" << endl;
        return *this;
    }// Move Constructor
    IntVector(IntVector&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        cout << "Move Constructor" << endl;
    }// Print array elements
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }cout << endl;
    }// Set array elements
    void setValue(int index, T value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }
};

int main() {
    // 1. Standard Constructor
    IntVector<int> v1(5);
    v1.setValue(0, 10);
    v1.setValue(1, 20);
    v1.setValue(2, 30);
    v1.setValue(3, 40);
    v1.setValue(4, 50);
    cout << "v1: ";
    v1.print();
    // 2. Copy Constructor
    IntVector<int> v2 = v1;
    cout << "v2 after copying: ";
    v2.print();
    // 3. Copy Assignment Operator
    IntVector<int> v3(2);
    v3.setValue(0, 100);
    v3.setValue(1, 200);
    v3 = v1;
    cout << "v3 after assignment: ";
    v3.print();
    // 4. Move Constructor
    IntVector<int> v4 = std::move(v2);
    cout << "v4 after moving: ";
    v4.print();
    cout << "v1: ";
    v1.print();
  return 0;
}