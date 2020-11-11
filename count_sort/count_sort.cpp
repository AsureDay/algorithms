#include "count_sort.h"

std::vector<int> count_sort(const std::vector<int> &array, int min, int max) {
	
	int size_array = array.size();
	std::vector<int> result(size_array);	
	std::vector<int> counts(max - min+1);
	
	for(int i = 0; i < size_array;i++)
	{
		++counts[array[i] - min];
	}
	
	int current_indx = 0;
	for(int i = 0; i < max-min+1;i++)
	{
		for(int j = 0;j < counts[i];j++)
		{
			result[current_indx] = i + min;
			++current_indx;
		}
	}
    return result;
}
