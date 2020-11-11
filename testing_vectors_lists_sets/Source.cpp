#include <iostream>
#include <list>
#include <set>
#include <chrono>
#include <vector>
#include <random>
using namespace std;

int main()
{
	const int N = 100000;
	list<int> myList;
	vector<int> myVector;
	set<int> mySet;
	
	//push front list O(1)
	auto t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		myList.push_front(i);
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto pushFrontListTime = std::chrono::duration<double>(t2 - t1).count();

	//push front vector O(n)
	 t1 = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < N;i++)
	{
		myVector.insert(myVector.begin(), i);
	}

	 t2 = std::chrono::high_resolution_clock::now();
	auto pushFrontVectorTime = std::chrono::duration<double>(t2 - t1).count();

	myVector.clear();
	myList.clear();

	//pushback list O(1) in theory
	 t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		myList.push_back(i);
	}

	 t2 = std::chrono::high_resolution_clock::now();
	auto pushBackListTime = std::chrono::duration<double>(t2 - t1).count();

	//push back vector O(n) in theory
	t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		myVector.push_back(i);
	}

	t2 = std::chrono::high_resolution_clock::now();
	auto pushBackVectorTime = std::chrono::duration<double>(t2 - t1).count();
	
	//add to set O(1)
	 t1 = std::chrono::high_resolution_clock::now();
	for(int i = 0;i < N;i++)
	{
		mySet.emplace(i);
	}
	 t2 = std::chrono::high_resolution_clock::now();
	auto addToSetTime = std::chrono::duration<double>(t2 - t1).count();


	//SEARCH
	const int M = 10000;
	//list O(n) should be slow
	t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < M; i++) {
		find(myList.begin(), myList.end(), rand()%N);
	}
	 t2 = std::chrono::high_resolution_clock::now();
	auto searchList = std::chrono::duration<double>(t2 - t1).count();
	//vector O(n) 
	 t1 = std::chrono::high_resolution_clock::now();
	 for(int i =0;i < M;i++)
	 {
		 find(myVector.begin(), myVector.end(), rand() % N);
	 }
	 t2 = std::chrono::high_resolution_clock::now();
	auto searchVector = std::chrono::duration<double>(t2 - t1).count();
	//set O(log(n))
	 t1 = std::chrono::high_resolution_clock::now();
	 for(int i = 0;i < M;i++)
	 {
		 mySet.find(rand() % N);
	 }
	 t2 = std::chrono::high_resolution_clock::now();
	auto searchSet = std::chrono::duration<double>(t2 - t1).count();
	//PRINT

	cout << "push front(" << N << ") items in list :" << pushFrontListTime;
	cout << "\npush back (" << N << ") items in list :" << pushBackListTime;
	
	cout << "\npush front(" << N << ")items in vector:" << pushFrontVectorTime;
	cout << "\npush back (" << N << ")items in vector:" << pushBackVectorTime;
	
	cout << "\nemplace  (" << N << ") items in set   :" << pushBackVectorTime;

	cout << "\nFIND "<< M <<" items \n";
	cout << "find in list : " << searchList;
	cout << "\nfind in vector: " << searchVector;
	cout << "\nfind in set: " << searchSet;
 	
	return 0;
}