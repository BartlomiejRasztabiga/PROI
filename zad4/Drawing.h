#pragma once


#include <utility>
#include <vector>
#include <memory>
#include "IFigure.h"
#include "DrawingSnapshot.h"

//TODO: custom iterator by figure type
//TODO: move definitions to cpp

class Drawing {
public:
    Drawing(int width, int height);

    ~Drawing();

    size_t addFigure(const IFigure &figure);

    void updateFigure(size_t index, const IFigure &figure);

    void deleteFigure(size_t index);

    IFigure *getFigure(size_t index) const;

    int getWidth() const;

    int getHeight() const;

    DrawingSnapshot *getLatestSnapshot() const;

    DrawingSnapshot *getSnapshotForTimestamp(std::chrono::system_clock::time_point timestamp);

    DrawingSnapshot::Iterator begin();

    DrawingSnapshot::Iterator begin() const;

    DrawingSnapshot::Iterator end();

    DrawingSnapshot::Iterator end() const;

private:
    int width;
    int height;
    std::vector<DrawingSnapshot *> snapshots;

    std::vector<IFigure *> cloneLatestSnapshotFigures() const;

    void validateFigureIndex(size_t index) const;
};

