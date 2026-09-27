#include "ReadingBuffer.hpp"

void ReadingBuffer::init(int capacity) {
    release();
    if (capacity > 0) {
        capacity_ = capacity;
        samples_ = new double[capacity_];
        size_ = 0;
    }
}

void ReadingBuffer::release() {
    delete[] samples_;
    samples_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

bool ReadingBuffer::push(double sample) {
    if (size_ >= capacity_ || samples_ == nullptr) {
        return false;
    }
    samples_[size_++] = sample;
    return true;
}

bool ReadingBuffer::get(int index, double& out) const {
    if (index < 0 || index >= size_ || samples_ == nullptr) {
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
    if (size_ == 0 || samples_ == nullptr) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < size_; ++i) {
        sum += samples_[i];
    }
    return sum / size_;
}