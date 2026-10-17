#include <iostream>
#include <string>
#include "ReadingBuffer.hpp"

void ReadingBuffer::init(int capacity) {
    if (capacity > 0) {
        capacity_ = capacity;
        samples_ = new double[capacity];
    }
}

void ReadingBuffer::release() {
    delete[] samples_;
    samples_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

bool ReadingBuffer::push(double sample) {
    if (size_ < capacity_) {
        samples_[size_] = sample;
        size_++;
        return true;
    }
    return false;
}

bool ReadingBuffer::get(int index, double& out) const {
    if (index < size_ && index >= 0) {
        out = samples_[index];
        return true;
    }
    return false;
}

int ReadingBuffer::size() const {
    return size_;
}

int ReadingBuffer::capacity() const {
    return capacity_;
}

double ReadingBuffer::average() const {
    if (size_ > 0) {
        double sum = 0;
        for (int i = 0; i < size_; i++)
            sum += samples_[i];
        return sum / size_;
    }
    return 0.0;
}
