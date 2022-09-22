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

bool	RubikCollector::checkCorrectUpCorner() {
	if (checkLUCorner(_rubik._frontArray, Colors::Green) == false) {
		return false;
	}
	if (checkRUCorner(_rubik._frontArray, Colors::Green) == false) {
		return false;
	}
	if (checkLUCorner(_rubik._backArray, Colors::Blue) == false) {
		return false;
	}
	if (checkRUCorner(_rubik._backArray, Colors::Blue) == false) {
		return false;
	}
	return true;
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

bool	RubikCollector::checkCorrect_2layer() {
	return	checkLeftEdge(_rubik._frontArray, Colors::Green) && \
			checkRightEdge(_rubik._frontArray, Colors::Green) && \
			checkLeftEdge(_rubik._rightArray, Colors::Red) && \
			checkRightEdge(_rubik._rightArray, Colors::Red) && \
			checkLeftEdge(_rubik._backArray, Colors::Blue) && \
			checkRightEdge(_rubik._backArray, Colors::Blue) && \
			checkLeftEdge(_rubik._leftArray, Colors::Orange) && \
			checkRightEdge(_rubik._leftArray, Colors::Orange);
}

int		RubikCollector::checkCrossFor_2layer() {
	if (!checkDownEdge(_rubik._frontArray, Colors::Yellow) && !checkUpEdge(_rubik._downArray, Colors::Yellow)) {
		return 1;
	}
	if (!checkDownEdge(_rubik._rightArray, Colors::Yellow) && !checkRightEdge(_rubik._downArray, Colors::Yellow)) {
		return 2;
	}
	if (!checkDownEdge(_rubik._backArray, Colors::Yellow) && !checkDownEdge(_rubik._downArray, Colors::Yellow)) {
		return 3;
	}
	if (!checkDownEdge(_rubik._leftArray, Colors::Yellow) && !checkLeftEdge(_rubik._downArray, Colors::Yellow)) {
		return 4;
	}
	return 0;
}