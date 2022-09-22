#include "RubikCollector.hpp"

void RubikCollector::collectLastCorner() {
	vector<string> clock{"F", "R'", "F'", "R", "F", "R'", "F'", "R"};
	vector<string> unClock{"R'", "F", "R", "F'", "R'", "F", "R", "F'"};

	for (int i = 0; i < 4; i++) {
		if (checkRUCorner(_rubik._downArray, Colors::Yellow) == false) {
			if (checkRDCorner(_rubik._frontArray, Colors::Yellow)) {
				transformNormal(unClock);
			} else {
				transformNormal(clock);
			}
		}
		_res += "D ";
		_rubik.twist_D();
	}
	correctLastCorner();
}

void RubikCollector::correctLastCorner() {
	vector<string> left{"L'", "F", "L'", "B2", "L", "F'", "L'", "B2", "L2"};
	vector<string> right{"R", "F'", "R", "B2", "R'", "F", "R", "B2", "R2"};
	if (checkCornerDone() == false) {
		if (checkThreeCorner() == false) {
			transformNormal(left);
		}
		if (checkRDCorner(_rubik._frontArray, Colors::Green)) {
			if (checkRDCorner(_rubik._leftArray, Colors::Blue)) {
				transformToRight(right);
			} else {
				transformNormal(left);
			}
		} else if (checkRDCorner(_rubik._rightArray, Colors::Red)) {
			if (checkRDCorner(_rubik._frontArray, Colors::Orange)) {
				transformToBack(right);
			} else {
				transformToRight(left);
			}
		} else if (checkRDCorner(_rubik._backArray, Colors::Blue)) {
			if (checkRDCorner(_rubik._rightArray, Colors::Green)) {
				transformToLeft(right);
			} else {
				transformToBack(left);
			}
		} else if (checkRDCorner(_rubik._leftArray, Colors::Orange)) {
			if (checkRDCorner(_rubik._backArray, Colors::Red)) {
				transformNormal(right);
			} else {
				transformToLeft(left);
			}
		}
	}
}