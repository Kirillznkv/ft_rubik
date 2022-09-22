#include "RubikCollector.hpp"

void RubikCollector::collectLastCross() {
	if (checkCross(_rubik._downArray) == false) {
		int idCross = checkPreLastCross();
		if (idCross == 1) {
			lineCross();
		} else if (idCross == 2) {
			dawCross();
		} else {
			lineCross();
			dawCross();
		}
	}
}

void RubikCollector::lineCross() {
	vector<string> line{"F", "L", "D", "L'", "D'", "F'"};
	if (checkPreLastCross() == 0) {
		transformNormal(line);
		return;
	}

	if (checkUpEdge(_rubik._downArray, Colors::Yellow) && checkDownEdge(_rubik._downArray, Colors::Yellow)) {
		transformToLeft(line);
	} else {
		transformNormal(line);
	}
}

void RubikCollector::dawCross() {
	vector<string> daw{"F", "D", "L", "D'", "L'", "F'"};
	if (checkPreLastCross() == 0) {
		transformNormal(daw);
		return;
	}

	if (checkDownEdge(_rubik._downArray, Colors::Yellow) && checkRightEdge(_rubik._downArray, Colors::Yellow)) {
		transformNormal(daw);
	} else if (checkUpEdge(_rubik._downArray, Colors::Yellow) && checkRightEdge(_rubik._downArray, Colors::Yellow)) {
		transformToLeft(daw);
	} else if (checkUpEdge(_rubik._downArray, Colors::Yellow) && checkLeftEdge(_rubik._downArray, Colors::Yellow)) {
		transformToBack(daw);
	} else {
		transformToRight(daw);
	}
}

void RubikCollector::correctLastCross() {

}