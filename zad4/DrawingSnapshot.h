#pragma once


#include <vector>
#include <chrono>
#include "IFigure.h"

class DrawingSnapshot {
public:
    struct Iterator {
        using value_type = IFigure *;
        using pointer = value_type *;
        using reference = value_type &;

        explicit Iterator(const value_type *ptr);

        explicit Iterator(value_type *ptr);

        reference operator*() const;

        pointer operator->() const;

        Iterator &operator++();

        Iterator &operator--();

        reference operator[](const int &n) const;

        friend bool operator==(const Iterator &a, const Iterator &b);

        friend bool operator!=(const Iterator &a, const Iterator &b);

        friend bool operator<(const Iterator &a, const Iterator &b);

        friend bool operator<=(const Iterator &a, const Iterator &b);

        friend bool operator>(const Iterator &a, const Iterator &b);

        friend bool operator>=(const Iterator &a, const Iterator &b);

    protected:
        pointer ptr;
    };

    explicit DrawingSnapshot(const std::vector<IFigure *> &figures);

    ~DrawingSnapshot();

    const std::vector<IFigure *> &getFigures() const;

    std::chrono::system_clock::time_point getTimestamp();

    Iterator begin();

    Iterator begin() const;

    Iterator end();

    Iterator end() const;

private:
    std::vector<IFigure *> figures;
    std::chrono::system_clock::time_point timestamp;
};

