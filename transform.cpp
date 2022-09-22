#include "RubikCollector.hpp"


void RubikCollector::transformToRight(vector<string> cmds){
    for (auto it = cmds.begin(); it != cmds.end(); it++) {
        if (*it == "F") { // F
            _res += "R ";
            _rubik.twist_R();
        } else if (*it == "F'") {
            _res += "R' ";
            _rubik.twist_R_counter();
        } else if (*it == "F2") {
            _res += "R2 ";
            _rubik.twist_R();
            _rubik.twist_R();
        } else if (*it == "R") { // R
            _res += "B ";
            _rubik.twist_B();
        } else if (*it == "R'") {
            _res += "B' ";
            _rubik.twist_B_counter();
        } else if (*it == "R2") {
            _res += "B2 ";
            _rubik.twist_B();
            _rubik.twist_B();
        } else if (*it == "B") { // B
            _res += "L ";
            _rubik.twist_L();
        } else if (*it == "B'") {
            _res += "L' ";
            _rubik.twist_L_counter();
        } else if (*it == "B2") {
            _res += "L2 ";
            _rubik.twist_L();
            _rubik.twist_L();
        } else if (*it == "L") { // L
            _res += "F ";
            _rubik.twist_F();
        } else if (*it == "L'") {
            _res += "F' ";
            _rubik.twist_F_counter();
        } else if (*it == "L2") {
            _res += "F2 ";
            _rubik.twist_F();
            _rubik.twist_F();
        } else if (*it == "U") { // U
            _res += "U ";
            _rubik.twist_U();
        } else if (*it == "U'") {
            _res += "U' ";
            _rubik.twist_U_counter();
        } else if (*it == "U2") {
            _res += "U2 ";
            _rubik.twist_U();
            _rubik.twist_U();
        } else if (*it == "D") { // D
            _res += "D ";
            _rubik.twist_D();
        } else if (*it == "D'") {
            _res += "D' ";
            _rubik.twist_D_counter();
        } else if (*it == "D2") {
            _res += "D2 ";
            _rubik.twist_D();
            _rubik.twist_D();
        }
    }
}

void RubikCollector::transformToLeft(vector<string> cmds){
    for (auto it = cmds.begin(); it != cmds.end(); it++) {
        if (*it == "F") { // F
            _res += "L ";
            _rubik.twist_L();
        } else if (*it == "F'") {
            _res += "L' ";
            _rubik.twist_L_counter();
        } else if (*it == "F2") {
            _res += "L2 ";
            _rubik.twist_L();
            _rubik.twist_L();
        } else if (*it == "R") { // R
            _res += "F ";
            _rubik.twist_F();
        } else if (*it == "R'") {
            _res += "F' ";
            _rubik.twist_F_counter();
        } else if (*it == "R2") {
            _res += "F2 ";
            _rubik.twist_F();
            _rubik.twist_F();
        } else if (*it == "B") { // B
            _res += "R ";
            _rubik.twist_R();
        } else if (*it == "B'") {
            _res += "R' ";
            _rubik.twist_R_counter();
        } else if (*it == "B2") {
            _res += "R2 ";
            _rubik.twist_R();
            _rubik.twist_R();
        } else if (*it == "L") { // L
            _res += "B ";
            _rubik.twist_B();
        } else if (*it == "L'") {
            _res += "B' ";
            _rubik.twist_B_counter();
        } else if (*it == "L2") {
            _res += "B2 ";
            _rubik.twist_B();
            _rubik.twist_B();
        } else if (*it == "U") { // U
            _res += "U ";
            _rubik.twist_U();
        } else if (*it == "U'") {
            _res += "U' ";
            _rubik.twist_U_counter();
        } else if (*it == "U2") {
            _res += "U2 ";
            _rubik.twist_U();
            _rubik.twist_U();
        } else if (*it == "D") { // D
            _res += "D ";
            _rubik.twist_D();
        } else if (*it == "D'") {
            _res += "D' ";
            _rubik.twist_D_counter();
        } else if (*it == "D2") {
            _res += "D2 ";
            _rubik.twist_D();
            _rubik.twist_D();
        }
    }
}

void RubikCollector::transformToBack(vector<string> cmds){
    for (auto it = cmds.begin(); it != cmds.end(); it++) {
        if (*it == "F") { // F
            _res += "B ";
            _rubik.twist_B();
        } else if (*it == "F'") {
            _res += "B' ";
            _rubik.twist_B_counter();
        } else if (*it == "F2") {
            _res += "B2 ";
            _rubik.twist_B();
            _rubik.twist_B();
        } else if (*it == "R") { // R
            _res += "L ";
            _rubik.twist_L();
        } else if (*it == "R'") {
            _res += "L' ";
            _rubik.twist_L_counter();
        } else if (*it == "R2") {
            _res += "L2 ";
            _rubik.twist_L();
            _rubik.twist_L();
        } else if (*it == "B") { // B
            _res += "F ";
            _rubik.twist_F();
        } else if (*it == "B'") {
            _res += "F' ";
            _rubik.twist_F_counter();
        } else if (*it == "B2") {
            _res += "F2 ";
            _rubik.twist_F();
            _rubik.twist_F();
        } else if (*it == "L") { // L
            _res += "R ";
            _rubik.twist_R();
        } else if (*it == "L'") {
            _res += "R' ";
            _rubik.twist_R_counter();
        } else if (*it == "L2") {
            _res += "R2 ";
            _rubik.twist_R();
            _rubik.twist_R();
        } else if (*it == "U") { // U
            _res += "U ";
            _rubik.twist_U();
        } else if (*it == "U'") {
            _res += "U' ";
            _rubik.twist_U_counter();
        } else if (*it == "U2") {
            _res += "U2 ";
            _rubik.twist_U();
            _rubik.twist_U();
        } else if (*it == "D") { // D
            _res += "D ";
            _rubik.twist_D();
        } else if (*it == "D'") {
            _res += "D' ";
            _rubik.twist_D_counter();
        } else if (*it == "D2") {
            _res += "D2 ";
            _rubik.twist_D();
            _rubik.twist_D();
        }
    }
}

void RubikCollector::transformNormal(vector<string> cmds){
    for (auto it = cmds.begin(); it != cmds.end(); it++) {
        if (*it == "F") { // F
            _res += "F ";
            _rubik.twist_F();
        } else if (*it == "F'") {
            _res += "F' ";
            _rubik.twist_F_counter();
        } else if (*it == "F2") {
            _res += "F2 ";
            _rubik.twist_F();
            _rubik.twist_F();
        } else if (*it == "R") { // R
            _res += "R ";
            _rubik.twist_R();
        } else if (*it == "R'") {
            _res += "R' ";
            _rubik.twist_R_counter();
        } else if (*it == "R2") {
            _res += "R2 ";
            _rubik.twist_R();
            _rubik.twist_R();
        } else if (*it == "B") { // B
            _res += "B ";
            _rubik.twist_B();
        } else if (*it == "B'") {
            _res += "B' ";
            _rubik.twist_B_counter();
        } else if (*it == "B2") {
            _res += "B2 ";
            _rubik.twist_B();
            _rubik.twist_B();
        } else if (*it == "L") { // L
            _res += "L ";
            _rubik.twist_L();
        } else if (*it == "L'") {
            _res += "L' ";
            _rubik.twist_L_counter();
        } else if (*it == "L2") {
            _res += "L2 ";
            _rubik.twist_L();
            _rubik.twist_L();
        } else if (*it == "U") { // U
            _res += "U ";
            _rubik.twist_U();
        } else if (*it == "U'") {
            _res += "U' ";
            _rubik.twist_U_counter();
        } else if (*it == "U2") {
            _res += "U2 ";
            _rubik.twist_U();
            _rubik.twist_U();
        } else if (*it == "D") { // D
            _res += "D ";
            _rubik.twist_D();
        } else if (*it == "D'") {
            _res += "D' ";
            _rubik.twist_D_counter();
        } else if (*it == "D2") {
            _res += "D2 ";
            _rubik.twist_D();
            _rubik.twist_D();
        }
    }
}
