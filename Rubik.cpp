#include "Rubik.hpp"

Rubik::Rubik() {
	initCube();
}

Rubik::Rubik(const Rubik &copy) {
	operator=(copy);
}

Rubik::~Rubik() {}

void Rubik::initCube() {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			_upArray[i][j] = Colors::White;
			_downArray[i][j] = Colors::Yellow;
			_leftArray[i][j] = Colors::Orange;
			_rightArray[i][j] = Colors::Red;
			_backArray[i][j] = Colors::Blue;
			_frontArray[i][j] = Colors::Green;
		}
}

Rubik &Rubik::operator=(const Rubik &copy) {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			_upArray[i][j] = copy._upArray[i][j];
			_downArray[i][j] = copy._downArray[i][j];
			_leftArray[i][j] = copy._leftArray[i][j];
			_rightArray[i][j] = copy._rightArray[i][j];
			_backArray[i][j] = copy._backArray[i][j];
			_frontArray[i][j] = copy._frontArray[i][j];
		}
	return (*this);
}

void Rubik::setColor(Colors color) const{
	switch (color) {
	case Colors::Red: { cout<<"\033[31;1m"; break; }
	case Colors::Orange: { cout<<"\033[95;1m"; break; }
	case Colors::Green: { cout<<"\033[32;1m"; break; }
	case Colors::Blue: { cout<<"\033[34;1m"; break; }
	case Colors::Yellow: { cout<<"\033[93;1m"; break; }
	case Colors::White: { cout<<"\033[97;1m"; break; }
	}
}

void Rubik::printOneSide(const Colors arr[3][3]) const{
	for (int i = 0; i < 3; ++i) {
		cout<<"    ";
		for (int j = 0; j < 3; ++j) {
			setColor(arr[i][j]);
			cout<<"◼︎\033[0m";
		}
		cout<<endl;
	}
}

void Rubik::printMiddleSides() const{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			setColor(_leftArray[i][j]);
			cout<<"◼︎\033[0m";
		}
		cout<<" ";
		for (int j = 0; j < 3; ++j) {
			setColor(_frontArray[i][j]);
			cout<<"◼︎\033[0m";
		}
		cout<<" ";
		for (int j = 0; j < 3; ++j) {
			setColor(_rightArray[i][j]);
			cout<<"◼︎\033[0m";
		}
		cout<<" ";
		for (int j = 0; j < 3; ++j) {
			setColor(_backArray[i][j]);
			cout<<"◼︎\033[0m";
		}
		cout<<endl;
	}
}

void Rubik::printCube() const{
	printOneSide(_upArray);
	printMiddleSides();
	printOneSide(_downArray);
}

void Rubik::turnClockwise(Colors (*arr)[3]) {
	Colors buf = arr[0][0];
	arr[0][0] = arr[2][0];
	arr[2][0] = arr[2][2];
	arr[2][2] = arr[0][2];
	arr[0][2] = buf;
	buf = arr[0][1];
	arr[0][1] = arr[1][0];
	arr[1][0] = arr[2][1];
	arr[2][1] = arr[1][2];
	arr[1][2] = buf;
}

void Rubik::turnСounterСlockwise(Colors (*arr)[3]) {
	Colors buf = arr[0][0];
	arr[0][0] = arr[0][2];
	arr[0][2] = arr[2][2];
	arr[2][2] = arr[2][0];
	arr[2][0] = buf;
	buf = arr[0][1];
	arr[0][1] = arr[1][2];
	arr[1][2] = arr[2][1];
	arr[2][1] = arr[1][0];
	arr[1][0] = buf;
}

void Rubik::twist_U() {
	Colors buf[3];
	buf[0] = _frontArray[0][0];
	buf[1] = _frontArray[0][1];
	buf[2] = _frontArray[0][2];
	_frontArray[0][0] = _rightArray[0][0];
	_frontArray[0][1] = _rightArray[0][1];
	_frontArray[0][2] = _rightArray[0][2];
	_rightArray[0][0] = _backArray[0][0];
	_rightArray[0][1] = _backArray[0][1];
	_rightArray[0][2] = _backArray[0][2];
	_backArray[0][0] = _leftArray[0][0];
	_backArray[0][1] = _leftArray[0][1];
	_backArray[0][2] = _leftArray[0][2];
	_leftArray[0][0] = buf[0];
	_leftArray[0][1] = buf[1];
	_leftArray[0][2] = buf[2];
	turnClockwise(_upArray);
}

void Rubik::twist_F() {
	Colors buf[3];
	buf[0] = _upArray[2][0];
	buf[1] = _upArray[2][1];
	buf[2] = _upArray[2][2];
	_upArray[2][0] = _leftArray[2][2];
	_upArray[2][1] = _leftArray[1][2];
	_upArray[2][2] = _leftArray[0][2];
	_leftArray[2][2] = _downArray[0][2];
	_leftArray[1][2] = _downArray[0][1];
	_leftArray[0][2] = _downArray[0][0];
	_downArray[0][2] = _rightArray[0][0];
	_downArray[0][1] = _rightArray[1][0];
	_downArray[0][0] = _rightArray[2][0];
	_rightArray[0][0] = buf[0];
	_rightArray[1][0] = buf[1];
	_rightArray[2][0] = buf[2];
	turnClockwise(_frontArray);
}

void Rubik::twist_L() {
	Colors buf[3];
	buf[0] = _upArray[0][0];
	buf[1] = _upArray[1][0];
	buf[2] = _upArray[2][0];
	_upArray[0][0] = _backArray[2][2];
	_upArray[1][0] = _backArray[1][2];
	_upArray[2][0] = _backArray[0][2];
	_backArray[2][2] = _downArray[0][0];
	_backArray[1][2] = _downArray[1][0];
	_backArray[0][2] = _downArray[2][0];
	_downArray[0][0] = _frontArray[0][0];
	_downArray[1][0] = _frontArray[1][0];
	_downArray[2][0] = _frontArray[2][0];
	_frontArray[0][0] = buf[0];
	_frontArray[1][0] = buf[1];
	_frontArray[2][0] = buf[2];
	turnClockwise(_leftArray);
}

void Rubik::twist_R() {
	Colors buf[3];
	buf[0] = _upArray[2][2];
	buf[1] = _upArray[1][2];
	buf[2] = _upArray[0][2];
	_upArray[2][2] = _frontArray[2][2];
	_upArray[1][2] = _frontArray[1][2];
	_upArray[0][2] = _frontArray[0][2];
	_frontArray[2][2] = _downArray[2][2];
	_frontArray[1][2] = _downArray[1][2];
	_frontArray[0][2] = _downArray[0][2];
	_downArray[2][2] = _backArray[0][0];
	_downArray[1][2] = _backArray[1][0];
	_downArray[0][2] = _backArray[2][0];
	_backArray[0][0] = buf[0];
	_backArray[1][0] = buf[1];
	_backArray[2][0] = buf[2];
	turnClockwise(_rightArray);
}

void Rubik::twist_D() {
	Colors buf[3];
	buf[0] = _frontArray[2][0];
	buf[1] = _frontArray[2][1];
	buf[2] = _frontArray[2][2];
	_frontArray[2][0] = _leftArray[2][0];
	_frontArray[2][1] = _leftArray[2][1];
	_frontArray[2][2] = _leftArray[2][2];
	_leftArray[2][0] = _backArray[2][0];
	_leftArray[2][1] = _backArray[2][1];
	_leftArray[2][2] = _backArray[2][2];
	_backArray[2][0] = _rightArray[2][0];
	_backArray[2][1] = _rightArray[2][1];
	_backArray[2][2] = _rightArray[2][2];
	_rightArray[2][0] = buf[0];
	_rightArray[2][1] = buf[1];
	_rightArray[2][2] = buf[2];
	turnClockwise(_downArray);
}

void Rubik::twist_B() {
	Colors buf[3];
	buf[0] = _upArray[0][2];
	buf[1] = _upArray[0][1];
	buf[2] = _upArray[0][0];
	_upArray[0][2] = _rightArray[2][2];
	_upArray[0][1] = _rightArray[1][2];
	_upArray[0][0] = _rightArray[0][2];
	_rightArray[2][2] = _downArray[2][0];
	_rightArray[1][2] = _downArray[2][1];
	_rightArray[0][2] = _downArray[2][2];
	_downArray[2][0] = _leftArray[0][0];
	_downArray[2][1] = _leftArray[1][0];
	_downArray[2][2] = _leftArray[2][0];
	_leftArray[0][0] = buf[0];
	_leftArray[1][0] = buf[1];
	_leftArray[2][0] = buf[2];
	turnClockwise(_backArray);
}

void Rubik::twist_D_counter() {
	Colors buf[3];
	buf[0] = _frontArray[2][0];
	buf[1] = _frontArray[2][1];
	buf[2] = _frontArray[2][2];
	_frontArray[2][0] = _rightArray[2][0];
	_frontArray[2][1] = _rightArray[2][1];
	_frontArray[2][2] = _rightArray[2][2];
	_rightArray[2][0] = _backArray[2][0];
	_rightArray[2][1] = _backArray[2][1];
	_rightArray[2][2] = _backArray[2][2];
	_backArray[2][0] = _leftArray[2][0];
	_backArray[2][1] = _leftArray[2][1];
	_backArray[2][2] = _leftArray[2][2];
	_leftArray[2][0] = buf[0];
	_leftArray[2][1] = buf[1];
	_leftArray[2][2] = buf[2];
	turnСounterСlockwise(_downArray);
}

void Rubik::twist_U_counter() {
	Colors buf[3];
	buf[0] = _frontArray[0][0];
	buf[1] = _frontArray[0][1];
	buf[2] = _frontArray[0][2];
	_frontArray[0][0] = _leftArray[0][0];
	_frontArray[0][1] = _leftArray[0][1];
	_frontArray[0][2] = _leftArray[0][2];
	_leftArray[0][0] = _backArray[0][0];
	_leftArray[0][1] = _backArray[0][1];
	_leftArray[0][2] = _backArray[0][2];
	_backArray[0][0] = _rightArray[0][0];
	_backArray[0][1] = _rightArray[0][1];
	_backArray[0][2] = _rightArray[0][2];
	_rightArray[0][0] = buf[0];
	_rightArray[0][1] = buf[1];
	_rightArray[0][2] = buf[2];
	turnСounterСlockwise(_upArray);
}

void Rubik::twist_F_counter() {
	Colors buf[3];
	buf[0] = _upArray[2][0];
	buf[1] = _upArray[2][1];
	buf[2] = _upArray[2][2];
	_upArray[2][0] = _rightArray[0][0];
	_upArray[2][1] = _rightArray[1][0];
	_upArray[2][2] = _rightArray[2][0];
	_rightArray[0][0] = _downArray[0][2];
	_rightArray[1][0] = _downArray[0][1];
	_rightArray[2][0] = _downArray[0][0];
	_downArray[0][0] = _leftArray[0][2];
	_downArray[0][1] = _leftArray[1][2];
	_downArray[0][2] = _leftArray[2][2];
	_leftArray[0][2] = buf[2];
	_leftArray[1][2] = buf[1];
	_leftArray[2][2] = buf[0];
	turnСounterСlockwise(_frontArray);
}

void Rubik::twist_L_counter() {
	Colors buf[3];
	buf[0] = _upArray[0][0];
	buf[1] = _upArray[1][0];
	buf[2] = _upArray[2][0];
	_upArray[0][0] = _frontArray[0][0];
	_upArray[1][0] = _frontArray[1][0];
	_upArray[2][0] = _frontArray[2][0];
	_frontArray[0][0] = _downArray[0][0];
	_frontArray[1][0] = _downArray[1][0];
	_frontArray[2][0] = _downArray[2][0];
	_downArray[0][0] = _backArray[2][2];
	_downArray[1][0] = _backArray[1][2];
	_downArray[2][0] = _backArray[0][2];
	_backArray[2][2] = buf[0];
	_backArray[1][2] = buf[1];
	_backArray[0][2] = buf[2];
	turnСounterСlockwise(_leftArray);
}

void Rubik::twist_R_counter() {
	Colors buf[3];
	buf[0] = _upArray[2][2];
	buf[1] = _upArray[1][2];
	buf[2] = _upArray[0][2];
	_upArray[2][2] = _backArray[0][0];
	_upArray[1][2] = _backArray[1][0];
	_upArray[0][2] = _backArray[2][0];
	_backArray[0][0] = _downArray[2][2];
	_backArray[1][0] = _downArray[1][2];
	_backArray[2][0] = _downArray[0][2];
	_downArray[2][2] = _frontArray[2][2];
	_downArray[1][2] = _frontArray[1][2];
	_downArray[0][2] = _frontArray[0][2];
	_frontArray[2][2] = buf[0];
	_frontArray[1][2] = buf[1];
	_frontArray[0][2] = buf[2];
	turnСounterСlockwise(_rightArray);
}

void Rubik::twist_B_counter() {
	Colors buf[3];
	buf[0] = _upArray[0][2];
	buf[1] = _upArray[0][1];
	buf[2] = _upArray[0][0];
	_upArray[0][2] = _leftArray[0][0];
	_upArray[0][1] = _leftArray[1][0];
	_upArray[0][0] = _leftArray[2][0];
	_leftArray[0][0] = _downArray[2][0];
	_leftArray[1][0] = _downArray[2][1];
	_leftArray[2][0] = _downArray[2][2];
	_downArray[2][0] = _rightArray[2][2];
	_downArray[2][1] = _rightArray[1][2];
	_downArray[2][2] = _rightArray[0][2];
	_rightArray[2][2] = buf[0];
	_rightArray[1][2] = buf[1];
	_rightArray[0][2] = buf[2];
	turnСounterСlockwise(_backArray);
}

void Rubik::mix(vector<string> vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i].front() == 'U') {
			if (vec[i].size() == 1) {
				twist_U();
			} else if (vec[i][1] == '\'') {
				twist_U_counter();
			} else if (vec[i][1] == '2') {
				twist_U();
				twist_U();
			}
		} else if (vec[i].front() == 'F') {
			if (vec[i].size() == 1) {
				twist_F();
			} else if (vec[i][1] == '\'') {
				twist_F_counter();
			} else if (vec[i][1] == '2') {
				twist_F();
				twist_F();
			}
		} else if (vec[i].front() == 'L') {
			if (vec[i].size() == 1) {
				twist_L();
			} else if (vec[i][1] == '\'') {
				twist_L_counter();
			} else if (vec[i][1] == '2') {
				twist_L();
				twist_L();
			}
		} else if (vec[i].front() == 'R') {
			if (vec[i].size() == 1) {
				twist_R();
			} else if (vec[i][1] == '\'') {
				twist_R_counter();
			} else if (vec[i][1] == '2') {
				twist_R();
				twist_R();
			}
		} else if (vec[i].front() == 'D') {
			if (vec[i].size() == 1) {
				twist_D();
			} else if (vec[i][1] == '\'') {
				twist_D_counter();
			} else if (vec[i][1] == '2') {
				twist_D();
				twist_D();
			}
		} else if (vec[i].front() == 'B') {
			if (vec[i].size() == 1) {
				twist_B();
			} else if (vec[i][1] == '\'') {
				twist_B_counter();
			} else if (vec[i][1] == '2') {
				twist_B();
				twist_B();
			}
		}
	}
}

bool Rubik::checkCube() const {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (_upArray[i][j] != Colors::White)
				return false;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (_downArray[i][j] != Colors::Yellow)
				return false;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (_frontArray[i][j] != Colors::Green)
				return false;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (_backArray[i][j] != Colors::Blue)
				return false;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (_leftArray[i][j] != Colors::Orange)
				return false;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (_rightArray[i][j] != Colors::Red)
				return false;
	return true;
}