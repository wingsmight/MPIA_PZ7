#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "activities.h"
#include <conio.h>
#include <chrono>
#include <math.h>
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[]) {
	int result = Catch::Session().run(argc, argv);

	
	std::vector<Activity> res;
	
	int st, fi;
	for (int i = 100; i < 1000001; i *= 5)
	{
		std::vector<Activity> acts;
		for (int j = 0; j < i; j++) {
			st = rand() % 100;
			fi = st + rand() % 100;
			Activity temp;
			temp.add_act(st, fi);
			acts.push_back(temp);
		}
		auto t1 = std::chrono::high_resolution_clock::now();

		res = get_max_activities(acts);

		auto t2 = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(t2 - t1).count();
		std::cout << "Time: ";
		std::cout << std::scientific << seconds;
		std::cout << " sec. in " << acts.size() << std::endl;
	}
    
	_getch();
    return result;
}