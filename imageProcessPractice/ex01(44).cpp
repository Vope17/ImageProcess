#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int f[5][5]={{1,2,3,4,5},
			{6,7,8,9,10},
			{11,12,13,14,15},
			{16,17,18,19,20},
			{21,22,23,24,25}};
	
	double m[3][3]={{1.0/9,1.0/9,1.0/9},
				{1.0/9,1.0/9,1.0/9},
				{1.0/9,1.0/9,1.0/9}};

	double g[5][5]={0};
	
	
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			for(int k = -1; k <= 1; ++k)
				for(int z = -1; z <= 1; ++z)
					g[i][j] += f[i + k][j + z] * m[k + 1][z + 1];

								
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
					 
	return 0;
} 

