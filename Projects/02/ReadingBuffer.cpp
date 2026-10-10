#include "ReadingBuffer.h"

ReadingBuffer::ReadingBuffer()
:  samples_(nullptr)
,  capacity_(0)
,  size_(0)
{ /* EMPTY */ }

ReadingBuffer::ReadingBuffer(int capacity)
:  samples_(new double[capacity_])
,  capacity_(capacity)
,  size(0)
{ /* EMPTY */ }


ReadingBuffer::ReadingBuffer(const ReadingBuffer& other)
:  samples_(new double[other.capacity_])
,  capacity_(other.capacity_)
,  size_(other.size_)
{
    for (int i = 0; i < size_; i++) {
        samples_[i] = other.samples_[i];
    }
}

ReadingBuffer::ReadingBuffer(ReadingBuffer&& other)
:  samples_(other.samples_)
,  capacity_(other.capacity_)
,  size_(other.size_)
{
    other.samples_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
}

ReadingBuffer::~ReadingBuffer() {
    delete[] samples_;
    samples_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

// Appends a sample. Returns false if the buffer is full.
bool ReadingBuffer::push(double sample) {
    if (size_ >= capacity_) {
        return false;
    }
    samples_[size_] = sample;
    size_++;
    return true;
}

// Bounds-checked read. Returns false and leaves 'out' untouched if index is invalid.
bool ReadingBuffer::get(int index, double& out) const {
    if (index < 0 || index >= size_) {
        return false;
    }
    out = samples_[index];
    return true;
}

int    ReadingBuffer::size() const {
    return size_;
}
int    ReadingBuffer::capacity() const {
    return capacity_;
}

// Mean of the stored samples. Returns 0.0 for an empty buffer (never divide by zero).
double ReadingBuffer::average() const {
    if (size_ == 0) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < size_; i++) {
        sum += samples_[i];
    }
    return sum / size_;
}