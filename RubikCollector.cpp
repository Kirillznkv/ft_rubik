#include "RubikCollector.hpp"

RubikCollector::RubikCollector(Rubik rubik) : _rubik(rubik) {
}

RubikCollector::~RubikCollector() {
}

string RubikCollector::getResult() const {
	return _res;
}

void RubikCollector::printCube() const {
	_rubik.printCube();
}

void RubikCollector::collector() {
	collectFirstCross();
	collectFirstCorner();
	collectSecondLayer();
	collectLastCross();
	collectLastCorner();
}