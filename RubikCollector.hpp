#ifndef RUBIKCOLLECTOR_HPP
#define RUBIKCOLLECTOR_HPP

# include <vector>
# include "Rubik.hpp"

using namespace std;

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
	bool	checkCorrectUpCorner();
	bool	checkCorner(Colors (*side)[3]);
	bool	checkLUCorner(Colors (*side)[3], Colors color);
	bool	checkRUCorner(Colors (*side)[3], Colors color);
	bool	checkLDCorner(Colors (*side)[3], Colors color);
	bool	checkRDCorner(Colors (*side)[3], Colors color);
	//
	bool	checkCorrect_2layer();
	int		checkEdgeFor_2layer();
	//
	int		checkPreLastCross();
	//----Transform----//
	void	transformToRight(vector<string> cmds);
	void	transformToLeft(vector<string> cmds);
	void	transformToBack(vector<string> cmds);
	void	transformNormal(vector<string> cmds);
	//----Collecting----//
	void	collectFirstCross();
	void	collectFirstCross_1Layer();
	void	collectFirstCross_2Layer();
	void	collectFirstCross_3Layer();
	int		num_correctEdge_Up();
	void	correctFirstCross();
	//
	int		newPos_LD();
	int		newPos_RD();
	int		newPos_LU();
	int		newPos_RU();
	int		newPos_LD_bug();
	int		newPos_RD_bug();
	int		newPos_LU_bug();
	int		newPos_RU_bug();
	void	correctCorner();
	void	collectFirstCorner();
	void	collectFirstCorner_1();
	void	collectFirstCorner_2();
	void	collectFirstCorner_3();
	//
	void	collectSecondLayer();
	void	collectSecondLayerFromThird();
	void	breakEdgeFromSecondLayer();
	//
	void	collectLastCross();
	void	correctLastCross();
	void	lineCross();
	void	dawCross();
	int		num_correctEdge_Down();
public:
	RubikCollector(Rubik rubik);
	~RubikCollector();
	void collector();
	void printCube() const;
	string getResult() const;
};

#endif