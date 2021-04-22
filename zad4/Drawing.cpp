#include <algorithm>
#include "Drawing.h"
#include "exceptions.h"

Drawing::Drawing(int width, int height) : width(width), height(height) {
    this->snapshots.push_back(new DrawingSnapshot(std::vector<IFigure *>()));
}

Drawing::~Drawing() {
    for (DrawingSnapshot *snapshot:this->snapshots) {
        delete snapshot;
    }
    this->snapshots.clear();
}

size_t Drawing::addFigure(const IFigure &figure) {
    std::vector<IFigure *> newFigures = this->cloneLatestSnapshotFigures();
    newFigures.push_back(figure.clone());

    auto *newSnapshot = new DrawingSnapshot(newFigures);
    this->snapshots.push_back(newSnapshot);

    return newFigures.size() - 1;
}

void Drawing::updateFigure(size_t index, const IFigure &figure) {
    this->validateFigureIndex(index);

    std::vector<IFigure *> newFigures = this->cloneLatestSnapshotFigures();
    delete newFigures[index];
    newFigures[index] = figure.clone();

    auto *newSnapshot = new DrawingSnapshot(newFigures);
    this->snapshots.push_back(newSnapshot);
}

void Drawing::deleteFigure(size_t index) {
    this->validateFigureIndex(index);

    std::vector<IFigure *> newFigures = this->cloneLatestSnapshotFigures();
    delete newFigures[index];
    newFigures.erase(newFigures.begin() + index);

    auto *newSnapshot = new DrawingSnapshot(newFigures);
    this->snapshots.push_back(newSnapshot);
}

IFigure *Drawing::getFigure(size_t index) const {
    this->validateFigureIndex(index);

    IFigure *figure = this->getLatestSnapshot()->getFigures().at(index);
    return figure->clone();
}

DrawingSnapshot::Iterator Drawing::begin() {
    return this->getLatestSnapshot()->begin();
}

DrawingSnapshot::Iterator Drawing::begin() const {
    return this->getLatestSnapshot()->begin();
}

DrawingSnapshot::Iterator Drawing::end() {
    return this->getLatestSnapshot()->end();
}

DrawingSnapshot::Iterator Drawing::end() const {
    return this->getLatestSnapshot()->end();
}

int Drawing::getWidth() const {
    return this->width;
}

int Drawing::getHeight() const {
    return this->height;
}

DrawingSnapshot *Drawing::getLatestSnapshot() const {
    return this->snapshots.back();
}

std::vector<IFigure *> Drawing::cloneLatestSnapshotFigures() const {
    std::vector<IFigure *> newFigures;
    for (IFigure *oldFigure : this->getLatestSnapshot()->getFigures()) {
        newFigures.push_back(oldFigure->clone());
    }
    return newFigures;
}

DrawingSnapshot *Drawing::getSnapshotForTimestamp(std::chrono::system_clock::time_point timestamp) {
    DrawingSnapshot *snapshotForTimestamp;

    for (DrawingSnapshot *snapshot:this->snapshots) {
        if (snapshot->getTimestamp() > timestamp) {
            break;
        }
        snapshotForTimestamp = snapshot;
    }

    return snapshotForTimestamp;
}

void Drawing::validateFigureIndex(size_t index) const {
    if (this->getLatestSnapshot()->getFigures().size() <= index) {
        throw FigureNotFoundException();
    }
}
