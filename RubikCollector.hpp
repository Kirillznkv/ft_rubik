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
	//----Checking----//
	bool	checkCross(Colors (*side)[3]);
	bool	checkLeftEdge(Colors (*side)[3], Colors color);
	bool	checkRightEdge(Colors (*side)[3], Colors color);
	bool	checkUpEdge(Colors (*side)[3], Colors color);
	bool	checkDownEdge(Colors (*side)[3], Colors color);
	//
	bool	checkCorner(Colors (*side)[3]);
	bool	checkLUCorner(Colors (*side)[3], Colors color);
	bool	checkRUCorner(Colors (*side)[3], Colors color);
	bool	checkLDCorner(Colors (*side)[3], Colors color);
	bool	checkRDCorner(Colors (*side)[3], Colors color);
	//----Collecting----//
	int		num_correctEdge_Up();
	void	correctCross();
	void	collectFirstCross();
	void	collectFirstCross_1Layer();
	void	collectFirstCross_2Layer();
	void	collectFirstCross_3Layer();
public:
	RubikCollector(Rubik rubik);
	~RubikCollector();
	void collector();
	void printCube() const;
	string getResult() const;
};

#endif