#include "RubikCollector.hpp"

void RubikCollector::collectFirstCorner() {
	while (checkCorner(_rubik._upArray) == false) {
		collectFirstCorner_1();
		collectFirstCorner_2();
		collectFirstCorner_3();
	}
    correctCorner();
}

void RubikCollector::correctCorner() {
	vector<string> l1{"L", "D", "L'", "R'", "D'", "R", "L", "D", "L'"}, l2{"L", "D2", "L'", "B'", "D'", "B", "D'", "L", "D", "L'"}, l3{"F'", "D'", "F", "B", "D", "B'", "F'", "D'", "F"};
	vector<string> r1{"F", "D", "F'", "B'", "D'", "B", "F", "D", "F'"}, r2{"F", "D2", "F'", "L'", "D'", "L", "D'", "F", "D", "F'"}, r3{"R'", "D'", "R", "L", "D", "L'", "R'", "D'", "R"};
	while (checkCorrectUpCorner() == false) {
		if (checkLUCorner(_rubik._frontArray, Colors::Green) == false) { // not green left
			if (checkLUCorner(_rubik._frontArray, Colors::Red)) {
				transformNormal(l1);
			}
			if (checkLUCorner(_rubik._frontArray, Colors::Blue)) {
				transformNormal(l2);
			}
			if (checkLUCorner(_rubik._frontArray, Colors::Orange)) {
				transformNormal(l3);
			}
		}
		if (checkRUCorner(_rubik._frontArray, Colors::Green) == false) { // not green right
			if (checkRUCorner(_rubik._frontArray, Colors::Red)) {
				transformNormal(r1);
			}
			if (checkRUCorner(_rubik._frontArray, Colors::Blue)) {
				transformNormal(r2);
			}
			if (checkRUCorner(_rubik._frontArray, Colors::Orange)) {
				transformNormal(r3);
			}
		}
		if (checkLUCorner(_rubik._backArray, Colors::Blue) == false) { // not blue left
			if (checkLUCorner(_rubik._backArray, Colors::Orange)) {
				transformToBack(l1);
			}
			if (checkLUCorner(_rubik._backArray, Colors::Green)) {
				transformToBack(l2);
			}
			if (checkLUCorner(_rubik._backArray, Colors::Red)) {
				transformToBack(l3);
			}
		}
		if (checkRUCorner(_rubik._backArray, Colors::Blue) == false) { // not blue right
			if (checkRUCorner(_rubik._backArray, Colors::Orange)) {
				transformToBack(r1);
			}
			if (checkRUCorner(_rubik._backArray, Colors::Green)) {
				transformToBack(r2);
			}
			if (checkRUCorner(_rubik._backArray, Colors::Red)) {
				transformToBack(r3);
			}
		}
	}
}

void RubikCollector::collectFirstCorner_1() {
    vector<string> leftPoint{"F'", "D'", "F", "D", "F'", "D'", "F"};
    vector<string> rightPoint{"F", "D", "F'", "D'", "F", "D", "F'"};

    if (checkLUCorner(_rubik._frontArray, Colors::White)) { // F
        transformNormal(leftPoint);
    } else if (checkRUCorner(_rubik._frontArray, Colors::White)) {
        transformNormal(rightPoint);
    } else if (checkLUCorner(_rubik._rightArray, Colors::White)) { // R
        transformToRight(leftPoint);
    } else if (checkRUCorner(_rubik._rightArray, Colors::White)) {
        transformToRight(rightPoint);
    } else if (checkLUCorner(_rubik._backArray, Colors::White)) { // B
        transformToBack(leftPoint);
    } else if (checkRUCorner(_rubik._backArray, Colors::White)) {
        transformToBack(rightPoint);
    } else if (checkLUCorner(_rubik._leftArray, Colors::White)) { // L
        transformToLeft(leftPoint);
    } else if (checkRUCorner(_rubik._leftArray, Colors::White)) {
        transformToLeft(rightPoint);
    }
}

int RubikCollector::newPos_LD() {
    if (checkLDCorner(_rubik._upArray, Colors::White)) {
        if (checkRDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
			_res += "U ";
            return 1;
        } else if (checkLUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
			_res += "U' ";
            return 2;
        } else if (checkRUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
			_res += "U2 ";
            return 3;
        }
    }
    return 0;
}

int RubikCollector::newPos_RD() {
    if (checkRDCorner(_rubik._upArray, Colors::White)) {
        if (checkRUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
			_res += "U ";
            return 1;
        } else if (checkLDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
			_res += "U' ";
            return 2;
        } else if (checkLUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
			_res += "U2 ";
            return 3;
        }
    }
    return 0;
}

int RubikCollector::newPos_LU() {
    if (checkLUCorner(_rubik._upArray, Colors::White)) {
        if (checkLDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
			_res += "U ";
            return 1;
        } else if (checkRUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
			_res += "U' ";
            return 2;
        } else if (checkRDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
			_res += "U2 ";
            return 3;
        }
    }
    return 0;
}

int RubikCollector::newPos_RU() {
    if (checkRUCorner(_rubik._upArray, Colors::White)) {
        if (checkLUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
			_res += "U ";
            return 1;
        } else if (checkRDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
			_res += "U' ";
            return 2;
        } else if (checkLDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
			_res += "U2 ";
            return 3;
        }
    }
    return 0;
}

void RubikCollector::collectFirstCorner_2() {
    vector<string> leftPoint{"F'", "D'", "F"};
    vector<string> rightPoint{"F", "D", "F'"};

    int flag = 0; // 1-U    2-U'    3-U2
    if (checkLDCorner(_rubik._frontArray, Colors::White)) { // F
        flag = newPos_LD();
        transformNormal(leftPoint);
    } else if (checkRDCorner(_rubik._frontArray, Colors::White)) {
        flag = newPos_RD();
        transformNormal(rightPoint);
    } else if (checkLDCorner(_rubik._rightArray, Colors::White)) { // R
        flag = newPos_RD();
        transformToRight(leftPoint);
    } else if (checkRDCorner(_rubik._rightArray, Colors::White)) {
        flag = newPos_RU();
        transformToRight(rightPoint);
    } else if (checkLDCorner(_rubik._backArray, Colors::White)) { // B
        flag = newPos_RU();
        transformToBack(leftPoint);
    } else if (checkRDCorner(_rubik._backArray, Colors::White)) {
        flag = newPos_LU();
        transformToBack(rightPoint);
    } else if (checkLDCorner(_rubik._leftArray, Colors::White)) { // L
        flag = newPos_LU();
        transformToLeft(leftPoint);
    } else if (checkRDCorner(_rubik._leftArray, Colors::White)) {
        flag = newPos_LD();
        transformToLeft(rightPoint);
    }

    if (flag == 1) {
        _rubik.twist_U_counter();
        _res += "U' ";
    } else if (flag == 2) {
        _rubik.twist_U();
        _res += "U ";
    } else if (flag == 3) {
        _rubik.twist_U();
        _rubik.twist_U();
        _res += "U2 ";
    }
}

void RubikCollector::collectFirstCorner_3() {
    vector<string> cmds{"D'", "F'", "D2", "F", "L", "D", "L'"};

    int flag = 0; // 1-U    2-U'    3-U2
    if (checkLUCorner(_rubik._downArray, Colors::White)) {
        flag = newPos_LU();
        transformNormal(cmds);
    } else if (checkRUCorner(_rubik._downArray, Colors::White)) {
        flag = newPos_RU();
        transformToRight(cmds);
    } else if (checkRDCorner(_rubik._downArray, Colors::White)) {
        flag = newPos_RD();
        transformToBack(cmds);
    } else if (checkLDCorner(_rubik._downArray, Colors::White)) {
        flag = newPos_LD();
        transformToLeft(cmds);
    }

    if (flag == 1) {
        _rubik.twist_U_counter();
        _res += "U' ";
    } else if (flag == 2) {
        _rubik.twist_U();
        _res += "U ";
    } else if (flag == 3) {
        _rubik.twist_U();
        _rubik.twist_U();
        _res += "U2 ";
    }
}