#include "RubikCollector.hpp"

void RubikCollector::collectSecondLayer() {
	while (checkCorrect_2layer() == false) {
		while (checkEdgeFor_2layer()) {
			collectSecondLayerFromThird();
		}
		if (!checkCorrect_2layer()) {
			breakEdgeFromSecondLayer();
		}
	}
}

void RubikCollector::collectSecondLayerFromThird() {
	vector<string> toL{"D", "L", "D'", "L'", "D'", "F'", "D", "F"};
	vector<string> toR{"D'", "R'", "D", "R", "D", "F", "D'", "F'"};
	
	int idSide = checkEdgeFor_2layer();
	if (idSide == 2) {
		_rubik.twist_D_counter();
		_res += "D' ";
	} else if (idSide == 3) {
		_rubik.twist_D();
		_rubik.twist_D();
		_res += "D2 ";
	} else if (idSide == 4) {
		_rubik.twist_D();
		_res += "D ";
	}

	if (checkDownEdge(_rubik._frontArray, Colors::Green)) {
		if (checkUpEdge(_rubik._downArray, Colors::Red)) {
			transformNormal(toR);
		} else {
			transformNormal(toL);
		}
	} else if (checkDownEdge(_rubik._frontArray, Colors::Red)) {
		_rubik.twist_D();
		_res += "D ";
		if (checkRightEdge(_rubik._downArray, Colors::Green)) {
			transformToRight(toL);
		} else {
			transformToRight(toR);
		}
	} else if (checkDownEdge(_rubik._frontArray, Colors::Blue)) {
		_rubik.twist_D();
		_rubik.twist_D();
		_res += "D2 ";
		if (checkDownEdge(_rubik._downArray, Colors::Red)) {
			transformToBack(toL);
		} else {
			transformToBack(toR);
		}
	} else {
		_rubik.twist_D_counter();
		_res += "D' ";
		if (checkLeftEdge(_rubik._downArray, Colors::Green)) {
			transformToLeft(toR);
		} else {
			transformToLeft(toL);
		}
	}
}

void RubikCollector::breakEdgeFromSecondLayer() {
	vector<string> breakRight{"R'", "D'", "R", "D", "F", "D", "F'"};

	if (checkRightEdge(_rubik._frontArray, Colors::Red)) {
		transformNormal(breakRight);
	} else if (checkRightEdge(_rubik._rightArray, Colors::Blue)) {
		transformToRight(breakRight);
	} else if (checkRightEdge(_rubik._backArray, Colors::Orange)) {
		transformToBack(breakRight);
	} else {
		transformToLeft(breakRight);
	}
}