#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

class LinMatrix
{
public:
	vector<int> data;
	int n;
	int& at(int i,int j)
	{
		return data.at(i*n + j);
	}
	LinMatrix(int n):n(n)
	{
		data = vector<int>(n*n);
		for(int i = 0;i < n;i++)
		{
			for(int j = 0; j <n;j++)
			{
				this->at(i, j) = rand() % 1000;
			}
		}
	}
	~LinMatrix()
	{
		data.clear();
	}
	void show()
	{
		for(int i = 0; i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				cout << this->at(i, j) << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
};

void multyply(LinMatrix A,LinMatrix B,LinMatrix& C)
{
	int n = A.n;

	for(int i = 0; i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			int resij = 0;
			for(int k = 0;k < n;k++)
			{
				resij += A.at(i, k) * B.at(k, j);
			}
			C.at(i, j) = resij;
		}
	}
}

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
	
	//better multy
	LinMatrix A(n);
	LinMatrix B(n);
	LinMatrix C(n);
	auto t1 = chrono::high_resolution_clock::now();
	multyply(A, B, C);
	auto t2 = chrono::high_resolution_clock::now();
	auto betterTime = chrono::duration<double>(t2 - t1).count();
	cout << "n = " << n<<endl;
	//cout << "standart mult time = \t" << standartTime << endl;
	cout << "better mult time = \t" << betterTime << endl;
}



int main()
{
	for(int i = 1;i < 16;i++)
	{
		test_time(100*i);
	}
	return 0;
}