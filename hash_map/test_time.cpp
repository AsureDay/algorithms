#include "test_time.h"
using namespace std;
using namespace chrono;

void test_time(int M, int N)
{
	test_time(M, N,N/2);
}

void test_time(int M, int N,int num_of_buckets)
{
	Dictionary dic(num_of_buckets);
	vector<string> keys(N);
	for(int i = 0;i < N;i++)
	{
		keys[i] = random_string(20);
	}
	auto t1 = high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		dic.set(keys[i], to_string(i));
	}
	auto t2 = high_resolution_clock::now();
	double pushN = duration<double>(t2 - t1).count();
	t1 = high_resolution_clock::now();
	for(int i = 0;i < M;i++)
	{
		dic.get(keys[i]);
	}
	t2 = high_resolution_clock::now();
	double findM = duration<double>(t2 - t1).count();
	cout << "push :" << pushN << endl;
	cout << "find :" << findM << endl;
}
