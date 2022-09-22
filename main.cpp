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
		if (str.empty() == false)
			vec.push_back(str);

	Rubik cube;
	cube.mix(vec);

	RubikCollector collector(cube);
	collector.collector();
	string res = collector.getResult();

	cube.printCube();
	cout<<res<<endl;
	istringstream ff(res);
	vector<string> v;
	while (getline(ff, res, ' '))
		if (res.empty() == false)
			v.push_back(res);
	cube.mix(v);
	cube.printCube();
	return 0;
}