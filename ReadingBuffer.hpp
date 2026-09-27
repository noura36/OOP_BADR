#pragma once

class ReadingBuffer {
public:
    void init(int capacity);
    void release();
    bool push(double sample);
    bool get(int index, double& out) const;
    int size() const;
    int capacity() const;
    double average() const;

private:
    double* samples_ = nullptr;
    int capacity_ = 0;
    int size_ = 0;
};
