#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include "count_sort.h"

using namespace std;
using namespace chrono;


void testTime(int size, int min, int max)
{
	//creating rand vector with (min<= values <=max)
	vector<int> randVec(size);
	vector<int> randVecCopy(size);
	for (int i = 0; i < size; i++)
	{
		randVec[i] = min + rand() % (max - min);
		randVecCopy[i] = randVec[i];
	}
	// my sort
	auto t1 = high_resolution_clock::now();
	count_sort(randVec, min, max);
	auto t2 = high_resolution_clock::now();
	auto mysortTime = duration<double>(t2 - t1).count();
	
	// standart sort
	t1 = high_resolution_clock::now();
	sort(randVecCopy.begin(), randVecCopy.end());
	t2 = high_resolution_clock::now();
	auto standartsortTime = duration<double>(t2 - t1).count();

	cout << "\nmy sort time" << mysortTime;
	cout << "\nstandart sort itme" << standartsortTime<<endl;

}


int main(int argc, char **argv) {
	for(int i = 3;i < 7;i++){
		cout << "i = "<<i<<std::endl;
		testTime(pow(10,i), 500, 1000);
	}
	int result = Catch::Session().run(argc, argv);
   	return result;
}
