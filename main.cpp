#include "Rubik.hpp"
#include "RubikCollector.hpp"
#include "sstream"



int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr<<"Error: arguments"<<endl;
		return 1;
	}
	string str(argv[1]);
	istringstream f(str);
	vector<string> vec;
	while (getline(f, str, ' '))
		if (str.empty() != true)
			vec.push_back(str);
	Rubik cube;
	cube.mix(vec);
	cube.printCube();
	// RubikCollector collector(cube);
	// collector.collector();
	// cout<<collector.getResult()<<endl;
	return 0;
}