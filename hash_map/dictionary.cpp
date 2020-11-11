#include "dictionary.h"


Dictionary::Dictionary(int num_of_buckets, HashFunction hash) : 
table(num_of_buckets), hash_function(hash) {    
}

Dictionary::~Dictionary() {
	table.clear();
}

void Dictionary::set(const std::string &key, const std::string &value) {
    // Insert key-value pair into the dictionary.
    // If such key already exists, replace old value with the new one.

	size_t size = hash_function(key) % table.size();
	if (table[size].empty())
	{
		table[size].emplace_back(key, value);
		return;
	}
	
	for (auto& elem : table[size])
	{
		if (elem.first == key)
		{
			elem.second = value;
			return;
		}
	}
	table[size].emplace_back(key, value);
}

std::string Dictionary::get(const std::string &key) const {
    // Return value for the key.
    // Return empty string if there is no such key.
	size_t i = hash_function(key) % table.size();

	for (const auto &elem : table[i])
		if (elem.first == key)
			return elem.second;
    return "";
}

int Dictionary::size() const {
    // Return size of the dictionary, i.e. number of key-value pairs.    
    int size = 0;
    for (const auto &bucket: table) 
	{
    	size += bucket.size();    	
    }
    return size;
}

