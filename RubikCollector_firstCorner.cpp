#include "RubikCollector.hpp"

void RubikCollector::collectFirstCorner() {
	while (checkCorner(_rubik._upArray) == false) {
		collectFirstCorner_1();
		collectFirstCorner_2();
		collectFirstCorner_3();
	}
    // correctCross();
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
            return 1;
        } else if (checkLUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
            return 2;
        } else if (checkRUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
            return 3;
        }
    }
    return 0;
}

int RubikCollector::newPos_RD() {
    if (checkRDCorner(_rubik._upArray, Colors::White)) {
        if (checkRUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            return 1;
        } else if (checkLDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
            return 2;
        } else if (checkLUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
            return 3;
        }
    }
    return 0;
}

int RubikCollector::newPos_LU() {
    if (checkLUCorner(_rubik._upArray, Colors::White)) {
        if (checkLDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            return 1;
        } else if (checkRUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
            return 2;
        } else if (checkRDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
            return 3;
        }
    }
    return 0;
}

int RubikCollector::newPos_RU() {
    if (checkRUCorner(_rubik._upArray, Colors::White)) {
        if (checkLUCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            return 1;
        } else if (checkRDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U_counter();
            return 2;
        } else if (checkLDCorner(_rubik._upArray, Colors::White) == false) {
            _rubik.twist_U();
            _rubik.twist_U();
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