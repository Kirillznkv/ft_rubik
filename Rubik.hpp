#ifndef RUBIK_HPP
#define RUBIK_HPP

# include <iostream>
# include <vector>
# include <string>

using namespace std;
class RubikCollector;

class Rubik {
friend class RubikCollector;
	enum class Colors
	{
		Red = 0,
		Orange,
		Green,
		Blue,
		Yellow,
		White
	};
private:
	Colors _upArray[3][3];
	Colors _downArray[3][3];
	Colors _leftArray[3][3];
	Colors _rightArray[3][3];
	Colors _backArray[3][3];
	Colors _frontArray[3][3];
private:
	void initCube();
	void printOneSide(const Colors arr[3][3]) const;
	void printMiddleSides() const;
	void setColor(Colors color) const;
	void turnClockwise(Colors (*arr)[3]);
	void turnСounterСlockwise(Colors (*arr)[3]);
public:
	Rubik();
	Rubik(const Rubik &copy);
	~Rubik();
	Rubik &operator=(const Rubik &copy);
	void twist_U();
	void twist_F();
	void twist_L();
	void twist_R();
	void twist_D();
	void twist_B();
	void twist_U_counter();
	void twist_F_counter();
	void twist_L_counter();
	void twist_R_counter();
	void twist_D_counter();
	void twist_B_counter();
	void mix(vector<string> vec);
	void printCube() const;
	bool checkCube() const;
};

#endif