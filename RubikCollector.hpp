#ifndef RUBIKCOLLECTOR_HPP
#define RUBIKCOLLECTOR_HPP

# include "Rubik.hpp"

class RubikCollector {
private:
	string _res;
	Rubik _rubik;
private:
	typedef typename Rubik::Colors Colors;
	RubikCollector(const RubikCollector&);
	RubikCollector &operator=(const RubikCollector&);
	void baseCross();
	// void trueCross();
	// void firstAngle();
	// void middle();
	// void upBaseCross();
	// void upTrueCross();
	// void turnOverAngle();
	// void finish();
	bool 			checkCross(Colors (*arr)[3]);
	pair<int, int>	findEdge(Colors (*arr)[3], Colors color);
	void 			moveEdgeToCrossFromDown(pair<int, int> inx);
	pair<int, int>	getRightEdgeInx(pair<int, int> inx);
	pair<int, int>	getLeftEdgeInx(pair<int, int> inx);
public:
	RubikCollector(Rubik rubik);
	~RubikCollector();
	void collector();
	string getResult() const;
};

#endif