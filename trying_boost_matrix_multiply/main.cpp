#include <iostream>
#include <chrono>
using namespace std;

int** classicMultyNxN(int** A,int** B,int n)
{
	
	int** res = new int* [n];
	for (int i = 0; i < n; i++)
		res[i] = new int[n];
	
	for(int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			int cij = int();
			for (int k = 0;k < n;k++)
			{
				cij += A[i][k] * B[k][j];
			}
			res[i][j] = cij;
		}
	}
	return res;
}

//B transposed
int** fasterMultyNxN(int** A, int** B,int n)
{
	int** res = new int* [n];
	for (int i = 0; i < n; i++)
		res[i] = new int[n];

	
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j <n;j++)
		{
			int cij = int();
			for(int k = 0;k < n;k++)
			{
				cij += A[i][k] * B[j][k];
			}
			res[i][j] = cij;
		}
	}
	return res;
}
void transpose(int** A,int n)
{
	for(int i = 0; i< n-1;i++)
	{
		for(int j = i+1;j < n;j++)
		{
			int tmp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = tmp;
		}
	}
	
}
void show(int** a,int n)
{
	for(int i = 0;i < n;i++)
	{
		std::cout << std::endl;
		for(int j = 0; j < n;j++)
		{
			std::cout << a[i][j] << "\t";
		}
	}
	std::cout << "\n";
}

int** createRandMatrix(int n)
{
	int** res = new int* [n];
	for(int i = 0;i < n;i++)
	{
		res[i] = new int[n];
		for(int j = 0;j < n;j++)
		{
			res[i][j] = rand() % 1000;
		}
	}
	return res;
}
void deleteMatrix(int** A,int n)
{
	for(int i = 0;i < n;i++)
	{
		delete[] A[i];
	}
	delete A;
}
void test_time(int n)
{
	int** A = createRandMatrix(n);
	int** B = createRandMatrix(n);
	//standart multy
	auto t1 = chrono::high_resolution_clock::now();
	classicMultyNxN(A, B, n);
	auto t2 = chrono::high_resolution_clock::now();
	auto standartTime = chrono::duration<double>(t2 - t1).count();


	//better multy
	
	transpose(B, n);
	t1 = chrono::high_resolution_clock::now();
	fasterMultyNxN(A, B, n);
	t2 = chrono::high_resolution_clock::now();
	auto betterTime = chrono::duration<double>(t2 - t1).count();
	cout << "n = " << n<<endl;
	cout << "standart mult time = \t" << standartTime << endl;
	cout << "better mult time = \t" << betterTime << endl;
	deleteMatrix(A,n);
	deleteMatrix(B, n);
}
int main()
{
	for(int i = 1;i < 20;i++)
	{
		test_time(i * 100);
	}
	return 0;
}