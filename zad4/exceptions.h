#pragma once

struct FigureOutOfBoundsException : public std::exception {
    const char *what() const noexcept override {
        return "New figure cannot exceed drawing's dimensions.";
    }
};

struct FigureNotFoundException : public std::exception {
    const char *what() const noexcept override {
        return "No figure under given index.";
    }
};