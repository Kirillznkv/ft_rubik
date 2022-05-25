#include "RubikCollector.hpp"

RubikCollector::RubikCollector(Rubik rubik) : _rubik(rubik) {}

RubikCollector::~RubikCollector() {}

string RubikCollector::getResult() const { return _res; }

void RubikCollector::collector() {
	baseCross();
	// trueCross();
	// firstAngle();
	// middle();
	// upBaseCross();
	// upTrueCross();
	// turnOverAngle();
	// finish();
}

bool RubikCollector::checkCross(Colors (*arr)[3]) {
	Colors center = arr[1][1];
	if (center == arr[0][1] && center == arr[1][0] && center == arr[1][2] && center == arr[2][1])
		return true;
	return false;
}

pair<int, int>	RubikCollector::findEdge(Colors (*arr)[3], Colors color) {
	if (arr[0][1] == color)
		return make_pair(0, 1);
	if (arr[1][0] == color)
		return make_pair(1, 0);
	if (arr[1][2] == color)
		return make_pair(1, 2);
	if (arr[2][1] == color)
		return make_pair(2, 1);
	return make_pair(-1, -1);
}

pair<int, int>	RubikCollector::getRightEdgeInx(pair<int, int> inx) {
	if (inx.first == 0 && inx.second == 1)
		return make_pair(1, 2);
	if (inx.first == 1 && inx.second == 2)
		return make_pair(2, 1);
	if (inx.first == 2 && inx.second == 1)
		return make_pair(1, 0);
	if (inx.first == 1 && inx.second == 0)
		return make_pair(0, 1);
	return make_pair(-1, -1);
}
pair<int, int>	RubikCollector::getLeftEdgeInx(pair<int, int> inx) {
	if (inx.first == 0 && inx.second == 1)
		return make_pair(1, 0);
	if (inx.first == 1 && inx.second == 2)
		return make_pair(0, 1);
	if (inx.first == 2 && inx.second == 1)
		return make_pair(1, 2);
	if (inx.first == 1 && inx.second == 0)
		return make_pair(2, 1);
	return make_pair(-1, -1);
}

void RubikCollector::moveEdgeToCrossFromDown(pair<int, int> inx) {
	pair<int, int> inxCheck(inx);
	if (inxCheck.first == 0)
		inxCheck.first = 2;
	else if (inxCheck.first == 2)
		inxCheck.first = 0;
	if (_rubik._upArray[inxCheck.first][inxCheck.second] == _rubik._upArray[1][1]) {
		pair<int, int> inxNewCheck = getRightEdgeInx(inxCheck);
		if (_rubik._upArray[inxNewCheck.first][inxNewCheck.second] == _rubik._upArray[1][1]) {
			inxNewCheck = getLeftEdgeInx(inxCheck);
			if (_rubik._upArray[inxNewCheck.first][inxNewCheck.second] == _rubik._upArray[1][1]) {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			} else {
				_rubik.twist_U();
				_res += "U ";
			}
		} else {
			_rubik.twist_U_counter();
			_res += "U' ";
		}
	}
}

void RubikCollector::baseCross() {
	while (checkCross(_rubik._upArray) == false) {
		pair<int, int> inx = findEdge(_rubik._downArray, _rubik._upArray[1][1]);
		if (inx.first != -1)
			moveEdgeToCrossFromDown(inx);
	}
}