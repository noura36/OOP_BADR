// ReadingBuffer.hpp
#pragma once

// empty buffer
ReadingBuffer rb;
// initiate buffer with certain size
ReadingBuffer rb(4);

class ReadingBuffer {
public:
    // CONSTRUCTORS
    ReadingBuffer();
    ReadingBuffer(int capacity);
    ReadingBuffer(const ReadingBuffer& other);
    ReadingBuffer(ReadingBuffer&& other);
    ~ReadingBuffer();

    // Appends a sample. Returns false if the buffer is full.
    bool push(double sample);

    // Bounds-checked read. Returns false and leaves 'out' untouched if index is invalid.
    bool get(int index, double& out) const;

    int    size() const;
    int    capacity() const;

    // Mean of the stored samples. Returns 0.0 for an empty buffer (never divide by zero).
    double average() const;

private:
    double* samples_ ;
    int     capacity_;
    int     size_;
};
