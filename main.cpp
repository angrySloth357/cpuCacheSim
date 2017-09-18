/*
Cache Simulator: Ducksim

Compile: g++ -std=c++11 *.cpp
Run: ./cache address_file #lines

*/

#include <fstream>
#include <stdlib.h>
#include "config.hpp"
#include "types.h"

using namespace std;

int main(int argc, char** argv) {
	
	Cache default_cache = Config::configureCache();
	ifstream input_file(argv[1]);
	if (!input_file.is_open()) {
		cout << "\nError... Cannot open address file!!!" << endl;
	}
	else {
		//bool mode = 1; //0 = restart run, 1 = continuous run <both will save rpevious state just update on stats>
		long lines = strtoul(argv[2], NULL, 0);
		default_cache.run(input_file, lines, argv[1]); //mode=false => save hit/miss to file
		input_file.close();
		//default_cache.dump_stats(cout);
		//default_cache.dump_cache(cout);
		//default_cache.dump_settings(cout);
	}
	return 0;
}
