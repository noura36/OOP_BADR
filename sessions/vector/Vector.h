#paragma once 

template <typename T>    
class vector {
public:
    using ElementType = T;
    constexpr static int c = 100;
    vector (int c)
    :ptr(new T[C])
    ,capacity(c)
    ,size(0)
    { }

    vector(const vector& other) 
    : ptr(new T[other.capcity])
    , capcity(other.capcity)
    , size(pther.size)
    {
        for (int i = 0 ; i < capcity; ++i)
            ptr[i] = other.data()[i];
    }
    vector(vector&& other) 
    : ptr(other.ptr)
    , capcity(other.capcity)
    , size(pther.size)
    {
        other.ptr = nullptr;
    } 
    void operator=(const vector& other) {
        ptr = new T[other.capcity];
        capcity = other.capcity;
        size = other.size;
        for (int i = 0 ; i < capcity; ++i)
            ptr[i] = other.data()[i];
    }
    
    ~vector() {
        delete[] ptr;
    }
    
    // v[3]
    // subscript 
    // returning by value will cause changes in a copyy 
    // e.g. v[3] = 4; 
    T& operator[](int idx) {
        if (idx > size)
            return 0; // ERROR
        return ptr[idx];
    }
    int get_size() const{
        return size;
    }

    int get_capacity() const{
        return capacity;
    }

    T* data(){
        return ptr;
    }

    void push_back( T value){
        if (size >= capcity) {
            T* ptr2 = ptr;
            ptr = new T [capacity*2] ;
            for(int i = 0 ; i < capacity; i++){
                ptr[i]=ptr2[i];
    
            }
            delete[] ptr2;
        }
        ptr[size] = value;
        size++;
    }
 
    T back() {
        return ptr[size];
    }
 
    T pop_back() {
        size --;
        return ptr[size];
    }

private: 
    T *ptr;
    int size;
    int capacity;

};

