#include "ReadingBuffer.hpp"

void ReadingBuffer::init(int capacity) {
    if (capacity <= 0) {
        return; 
    }
    
    samples_ = new double[capacity];
    capacity_ = capacity;
    size_ = 0;
}

void ReadingBuffer::release() {
    if (samples_ != nullptr) {
        delete[] samples_;
        samples_ = nullptr;
    }
    capacity_ = 0;
    size_ = 0;
}

bool ReadingBuffer::push(double sample) {
    if (size_ >= capacity_) {
        return false;
    }
    
    samples_[size_] = sample;
    size_++;
    return true;
}

bool ReadingBuffer::get(int index, double& out) const {
    if (index < 0 || index >= size_) {
        return false;
    }
    
    out = samples_[index];
    return true;
}

int ReadingBuffer::size() const {
    return size_;
}

int ReadingBuffer::capacity() const {
    return capacity_;
}

double ReadingBuffer::average() const {
    if (size_ == 0) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (int i = 0; i < size_; ++i) {
        sum += samples_[i];
    }
    
    return sum / size_;
}