#include "test_time.h"

void testTime(int N, int M, int range)
{
	set<int> not_my_set;
	Set my_set;
	//insert in my set
	auto t1 = high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		my_set.insert(rand() % range);
	}
	auto t2 = high_resolution_clock::now();
	auto insertMy = duration<double>(t2 - t1).count();
	//insetr in stl set
	t1 = high_resolution_clock::now();
	for (int i = 0; i < N; i++)
	{
		not_my_set.insert(rand() % range);
	}
	t2 = high_resolution_clock::now();
	auto insertSTL = duration<double>(t2 - t1).count();
	//find in my set
	t1 = high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		my_set.find(rand() % range);
	}
	auto findMy = duration<double>(t2 - t1).count();

	//find in STL
	t1 = high_resolution_clock::now();
	for (int i = 0; i < M; i++)
	{
		not_my_set.find(rand() % range);
	}
	t2 = high_resolution_clock::now();
	auto findSTL = duration<double>(t2 - t1).count();
	cout << "STL:\n";
	cout << "find  :" << findSTL;
	cout << "\ninsert:" << insertSTL;
	cout << "\nMY:\n";
	cout << "find  :" << findMy;
	cout << "\ninser:" << insertMy;	
}