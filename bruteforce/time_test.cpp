#include "time_test.h"

void test_time(const std::string& word, const std::string& alphabet, int max_length)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	bruteforce(sha256(word), alphabet, max_length);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto seconds = std::chrono::duration<double>(t2 - t1).count();
	std::cout << "time with alphabet(\"" << alphabet << "\")\nmax_lenght(" << max_length << ")\ntime :" << seconds<<std::endl;
}

