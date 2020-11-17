#include "bruteforce.h"
#include "sha256.h"

using namespace std;

struct someWord
{
	string alphabet;
	int alphabet_size;
	int* word;
	char* readyWord;
	int wordlen;
	int idx;
	someWord(const string& alphabet, int wordlen)
	{
		this->alphabet = alphabet;
		this->alphabet_size = alphabet.size();
		this->wordlen = wordlen;
		word = new int[wordlen];
		this->idx = 0;
		readyWord = new char[wordlen + 1];
		readyWord[wordlen] = '\0';
		for (int i = 0; i < wordlen; i++)
		{
			word[i] = 0;
		}
	}
	void operator++(int i)
	{
		if (word[i] == alphabet_size - 1) {
			word[i] = 0;
			operator++((i + 1) % wordlen);
		}
		else
			word[i]++;
	}
	void operator++()
	{
		
		if (alphabet_size!=1) operator++(0);
	}

	string getword()
	{

		for (int i = 0; i < wordlen; i++)
		{
			readyWord[i] = alphabet[word[i]];
		}
		return (string)readyWord;
	}
};

string bruteforce(const string& password_hash, const string& alphabet, int max_length) {
    // Try to crack password by brute force, using all possible passwords with given alphabet and length in [1, max_length].
    // Use sha256(string) function to compute password's hash and match it with given hash.
    // If password is found for which hashes are equal, return it.
    // Return empty string if password wasn't found.

    int absize = alphabet.size();
	if (absize == 0) return "";
	
	for(int i = 1;i <= max_length;++i)
	{
		size_t thatrange = pow(absize,i);
		someWord word(alphabet, i);
		for(size_t j = 0; j < thatrange; j++)
		{
			string generated_word = word.getword();
			if (sha256(generated_word) == password_hash) return generated_word;
			word.operator++();
		}
		word.~word();
	}
    return "";
}
