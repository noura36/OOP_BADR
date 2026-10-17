#pragma once

class ReadingBuffer {
public:
// Allocates capacity slots on the heap. Safe to call on a fresh buffer only.
// A capacity <= 0 leaves the buffer empty and allocates nothing.
void init(int capacity);

// Frees the heap block and resets the buffer to the empty state.
// Calling release() twice must NOT crash.
void release();

// Appends a sample. Returns false if the buffer is full.
bool push(double sample);

// Bounds-checked read. Returns false and leaves 'out' untouched if index is
// invalid.
bool get(int index, double& out) const;

int size()const;
int capacity()const;

// Mean of the stored samples. Returns 0.0 for an empty buffer (never divide
// by zero).
double average() const;

private:
double* samples_ = nullptr;
int capacity_= 0;
int size_= 0;

};