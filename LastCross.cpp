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
	correctLastCross();
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

int RubikCollector::num_correctEdge_Down() {
    int res = 0;
    if (checkDownEdge(_rubik._frontArray, Colors::Green))
        res++;
    if (checkDownEdge(_rubik._rightArray, Colors::Red))
        res++;
    if (checkDownEdge(_rubik._backArray, Colors::Blue))
        res++;
    if (checkDownEdge(_rubik._leftArray, Colors::Orange))
        res++;
    return res;
}

void RubikCollector::correctLastCross() {
    if (num_correctEdge_Down() < 2) {
		_rubik.twist_D();
         if (num_correctEdge_Down() < 2) {
             _rubik.twist_D();
             if (num_correctEdge_Down() < 2) {
                _rubik.twist_D();
                _res += "D' ";
             } else {
                 _res += "D2 ";
             }
         } else {
             _res += "D ";
         }
    }
    if (num_correctEdge_Down() != 4) {
		vector<string> swapEdge{"L", "D", "L'", "D", "L", "D2", "L'", "D"};
		if (checkDownEdge(_rubik._frontArray, Colors::Red)) {
			transformNormal(swapEdge);
		} else if (checkDownEdge(_rubik._rightArray, Colors::Blue)) {
			transformToRight(swapEdge);
		} else if (checkDownEdge(_rubik._backArray, Colors::Orange)) {
			transformToBack(swapEdge);
		} else if (checkDownEdge(_rubik._leftArray, Colors::Green)) {
			transformToLeft(swapEdge);
		}
    }
}