#include "RubikCollector.hpp"

void RubikCollector::collectFirstCross() {
	while (checkCross(_rubik._upArray) == false) {
		collectFirstCross_1Layer();
		collectFirstCross_2Layer();
		collectFirstCross_3Layer();
	}
    correctFirstCross();
}

void RubikCollector::collectFirstCross_1Layer() {
	if (checkUpEdge(_rubik._frontArray, Colors::White)) {
		_rubik.twist_F();
		_rubik.twist_U_counter();
		_rubik.twist_R();
		_res += "F U' R ";
	} else if (checkUpEdge(_rubik._rightArray, Colors::White)) {
		_rubik.twist_R();
		_rubik.twist_U_counter();
		_rubik.twist_B();
		_res += "R U' B ";
	} else if (checkUpEdge(_rubik._backArray, Colors::White)) {
		_rubik.twist_B();
		_rubik.twist_U_counter();
		_rubik.twist_L();
		_res += "B U' L ";
	} else if (checkUpEdge(_rubik._leftArray, Colors::White)) {
		_rubik.twist_L();
		_rubik.twist_U_counter();
		_rubik.twist_F();
		_res += "L U' F ";
	}
}

void RubikCollector::collectFirstCross_2Layer() {
	if (checkLeftEdge(_rubik._frontArray, Colors::White)) {
		if (checkLeftEdge(_rubik._upArray, Colors::White)) {
			if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_L_counter();
		_res += "L' ";
	} else if (checkRightEdge(_rubik._frontArray, Colors::White)) {
		if (checkRightEdge(_rubik._upArray, Colors::White)) {
			if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_R();
		_res += "R ";
	} else if (checkLeftEdge(_rubik._rightArray, Colors::White)) {
		if (checkDownEdge(_rubik._upArray, Colors::White)) {
			if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_F_counter();
		_res += "F' ";
	} else if (checkRightEdge(_rubik._rightArray, Colors::White)) {
		if (checkUpEdge(_rubik._upArray, Colors::White)) {
			if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_B();
		_res += "B ";
	} else if (checkLeftEdge(_rubik._backArray, Colors::White)) {
		if (checkRightEdge(_rubik._upArray, Colors::White)) {
			if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_L_counter();
		_res += "L' ";
	} else if (checkRightEdge(_rubik._backArray, Colors::White)) {
		if (checkLeftEdge(_rubik._upArray, Colors::White)) {
			if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_L();
		_res += "L ";
	} else if (checkLeftEdge(_rubik._leftArray, Colors::White)) {
		if (checkUpEdge(_rubik._upArray, Colors::White)) {
			if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_B_counter();
		_res += "B' ";
	} else if (checkRightEdge(_rubik._leftArray, Colors::White)) {
		if (checkDownEdge(_rubik._upArray, Colors::White)) {
			if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_F();
		_res += "F ";
	}
}

void RubikCollector::collectFirstCross_3Layer() {
	if (checkDownEdge(_rubik._frontArray, Colors::White)) {
		if (checkDownEdge(_rubik._upArray, Colors::White)) {
			if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_F();
		_rubik.twist_U();
		_rubik.twist_L_counter();
		_res += "F U L' ";
	} else if (checkDownEdge(_rubik._rightArray, Colors::White)) {
		if (checkRightEdge(_rubik._upArray, Colors::White)) {
			if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_R();
		_rubik.twist_U();
		_rubik.twist_F_counter();
		_res += "R U F' ";
	} else if (checkDownEdge(_rubik._backArray, Colors::White)) {
		if (checkUpEdge(_rubik._upArray, Colors::White)) {
			if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_B();
		_rubik.twist_U();
		_rubik.twist_R_counter();
		_res += "B U R' ";
	} else if (checkDownEdge(_rubik._leftArray, Colors::White)) {
		if (checkLeftEdge(_rubik._upArray, Colors::White)) {
			if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_L();
		_rubik.twist_U();
		_rubik.twist_B_counter();
		_res += "L U B' ";
	} else if (checkUpEdge(_rubik._downArray, Colors::White)) {
		if (checkDownEdge(_rubik._upArray, Colors::White)) {
			if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_F();
		_rubik.twist_F();
		_res += "F2 ";
	} else if (checkRightEdge(_rubik._downArray, Colors::White)) {
		if (checkRightEdge(_rubik._upArray, Colors::White)) {
			if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_R();
		_rubik.twist_R();
		_res += "R2 ";
	} else if (checkDownEdge(_rubik._downArray, Colors::White)) {
		if (checkUpEdge(_rubik._upArray, Colors::White)) {
			if (checkLeftEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkRightEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_B();
		_rubik.twist_B();
		_res += "B2 ";
	} else if (checkLeftEdge(_rubik._downArray, Colors::White)) {
		if (checkLeftEdge(_rubik._upArray, Colors::White)) {
			if (checkDownEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U();
				_res += "U ";
			} else if (checkUpEdge(_rubik._upArray, Colors::White) == false) {
				_rubik.twist_U_counter();
				_res += "U' ";
			} else {
				_rubik.twist_U();
				_rubik.twist_U();
				_res += "U2 ";
			}
		}
		_rubik.twist_L();
		_rubik.twist_L();
		_res += "L2 ";
	}
}

int RubikCollector::num_correctEdge_Up() {
    int res = 0;
    if (checkUpEdge(_rubik._frontArray, Colors::Green))
        res++;
    if (checkUpEdge(_rubik._rightArray, Colors::Red))
        res++;
    if (checkUpEdge(_rubik._backArray, Colors::Blue))
        res++;
    if (checkUpEdge(_rubik._leftArray, Colors::Orange))
        res++;
    return res;
}

void RubikCollector::correctFirstCross() {
    if (num_correctEdge_Up() < 2) {
		_rubik.twist_U();
         if (num_correctEdge_Up() < 2) {
             _rubik.twist_U();
             if (num_correctEdge_Up() < 2) {
                _rubik.twist_U();
                _res += "U' ";
             } else {
                 _res += "U2 ";
             }
         } else {
             _res += "U ";
         }
    }
    if (num_correctEdge_Up() != 4) {
        if (checkUpEdge(_rubik._frontArray, Colors::Green) == false) {
            _rubik.twist_F();
            _rubik.twist_F();
            if (checkUpEdge(_rubik._rightArray, Colors::Red) == false) {
                _rubik.twist_D();
                _rubik.twist_R();
                _rubik.twist_R();
                _rubik.twist_D_counter();
                 _res += "F2 D R2 D' F2 ";
            } else if (checkUpEdge(_rubik._backArray, Colors::Blue) == false) {
                _rubik.twist_D();
                _rubik.twist_D();
                _rubik.twist_B();
                _rubik.twist_B();
                _rubik.twist_D();
                _rubik.twist_D();
                 _res += "F2 D2 B2 D2 F2 ";
            } else {
                _rubik.twist_D_counter();
                _rubik.twist_L();
                _rubik.twist_L();
                _rubik.twist_D();
                 _res += "F2 D' L2 D F2 ";
            }
            _rubik.twist_F();
            _rubik.twist_F();
        } else if (checkUpEdge(_rubik._rightArray, Colors::Red) == false) {
            _rubik.twist_R();
            _rubik.twist_R();
            if (checkUpEdge(_rubik._backArray, Colors::Blue) == false) {
                _rubik.twist_D();
                _rubik.twist_B();
                _rubik.twist_B();
                _rubik.twist_D_counter();
                 _res += "R2 D B2 D' R2 ";
            } else {
                _rubik.twist_D();
                _rubik.twist_D();
                _rubik.twist_L();
                _rubik.twist_L();
                _rubik.twist_D();
                _rubik.twist_D();
                 _res += "R2 D2 L2 D2 R2 ";
            }
            _rubik.twist_R();
            _rubik.twist_R();
        } else {
            _rubik.twist_L();
            _rubik.twist_L();
            _rubik.twist_D_counter();
            _rubik.twist_B();
            _rubik.twist_B();
            _rubik.twist_D();
            _rubik.twist_L();
            _rubik.twist_L();
            _res += "L2 D' B2 D L2 ";
        }
    }
}