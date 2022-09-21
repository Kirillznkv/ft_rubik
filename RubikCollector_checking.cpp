#include "RubikCollector.hpp"

bool	RubikCollector::checkCross(Colors (*side)[3]) {
    Colors color = side[1][1];
    return  checkLeftEdge(side, color) && \
            checkRightEdge(side, color) && \
            checkUpEdge(side, color) && \
            checkDownEdge(side, color);
}

bool	RubikCollector::checkLeftEdge(Colors (*side)[3], Colors color) {
    return side[1][0] == color;
}

bool	RubikCollector::checkRightEdge(Colors (*side)[3], Colors color) {
    return side[1][2] == color;
}

bool	RubikCollector::checkUpEdge(Colors (*side)[3], Colors color) {
    return side[0][1] == color;
}

bool	RubikCollector::checkDownEdge(Colors (*side)[3], Colors color) {
    return side[2][1] == color;
}

bool	RubikCollector::checkCorner(Colors (*side)[3]) {
    Colors color = side[1][1];
    return  checkLUCorner(side, color) && \
            checkRUCorner(side, color) && \
            checkLDCorner(side, color) && \
            checkRDCorner(side, color);
}

bool	RubikCollector::checkLUCorner(Colors (*side)[3], Colors color) {
    return side[0][0] == color;
}

bool	RubikCollector::checkRUCorner(Colors (*side)[3], Colors color) {
    return side[0][2] == color;
}

bool	RubikCollector::checkLDCorner(Colors (*side)[3], Colors color) {
    return side[2][0] == color;
}

bool	RubikCollector::checkRDCorner(Colors (*side)[3], Colors color) {
    return side[2][2] == color;
}
