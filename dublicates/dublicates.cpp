
#include "dublicates.h"

using namespace std;


bool has_duplicates(const std::vector<int>& data) {
    map<int, bool> mymap;
	size_t data_size = data.size();
	for(int i =0;i < data_size;i++)
	{
		if (mymap.contains(data[i])) return true;
		mymap[data[i]] = false;
	}
	return false;
}

//mymap.contains works only with C++20
std::vector<int> get_duplicates(const std::vector<int>& data) {
    vector<int> result;
	map<int, bool> mymap;
	size_t data_size = data.size();
   
	for (int i = 0; i < data_size; i++)
	{
		if(!mymap.contains(data[i])) mymap[data[i]] = true;
		else if(mymap[data[i]]){
			result.push_back(data[i]);
			mymap[data[i]] = false;
		}
	}
   
    return result;
}
