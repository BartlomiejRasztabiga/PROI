#include "DrawingSnapshot.h"


DrawingSnapshot::DrawingSnapshot(const std::vector<IFigure *> &figures) {
    this->timestamp = std::chrono::system_clock::now();
    this->figures = figures;
}

DrawingSnapshot::~DrawingSnapshot() {
    for (IFigure *figure:this->figures) {
        delete figure;
    }
    this->figures.clear();
}

const std::vector<IFigure *> &DrawingSnapshot::getFigures() const {
    return this->figures;
}

DrawingSnapshot::Iterator DrawingSnapshot::begin() {
    return Iterator(&this->figures.front());
}

DrawingSnapshot::Iterator DrawingSnapshot::begin() const {
    return Iterator(&this->figures.front());
}

DrawingSnapshot::Iterator DrawingSnapshot::end() {
    return Iterator(&this->figures.back() + 1);
}

DrawingSnapshot::Iterator DrawingSnapshot::end() const {
    return Iterator(&this->figures.back() + 1);
}

std::chrono::system_clock::time_point DrawingSnapshot::getTimestamp() {
    return this->timestamp;
}

DrawingSnapshot::Iterator::Iterator(DrawingSnapshot::Iterator::value_type const *ptr) : ptr(const_cast<pointer>(ptr)) {}

DrawingSnapshot::Iterator::Iterator(DrawingSnapshot::Iterator::value_type *ptr) : ptr(ptr) {}

DrawingSnapshot::Iterator::value_type &DrawingSnapshot::Iterator::operator*() const {
    return *ptr;
}

DrawingSnapshot::Iterator::pointer DrawingSnapshot::Iterator::operator->() const {
    return ptr;
}

DrawingSnapshot::Iterator &DrawingSnapshot::Iterator::operator++() {
    ptr++;
    return *this;
}

DrawingSnapshot::Iterator &DrawingSnapshot::Iterator::operator--() {
    ptr--;
    return *this;
}

DrawingSnapshot::Iterator::value_type &DrawingSnapshot::Iterator::operator[](const int &n) const {
    return ptr[n];
}

bool operator==(const DrawingSnapshot::Iterator &a, const DrawingSnapshot::Iterator &b) {
    return a.ptr == b.ptr;
}

bool operator!=(const DrawingSnapshot::Iterator &a, const DrawingSnapshot::Iterator &b) {
    return a.ptr != b.ptr;
}

bool operator<(const DrawingSnapshot::Iterator &a, const DrawingSnapshot::Iterator &b) {
    return a.ptr < b.ptr;
}

bool operator<=(const DrawingSnapshot::Iterator &a, const DrawingSnapshot::Iterator &b) {
    return a.ptr <= b.ptr;
}

bool operator>(const DrawingSnapshot::Iterator &a, const DrawingSnapshot::Iterator &b) {
    return a.ptr > b.ptr;
}

bool operator>=(const DrawingSnapshot::Iterator &a, const DrawingSnapshot::Iterator &b) {
    return a.ptr >= b.ptr;
}