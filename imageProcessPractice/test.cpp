#include <iostream>
#include <cstring>
#include <math.h>
using std::cout;
int main()
{
	int graph[1][7] = {2, 7, 10, 6, 3, 5, 11};	
	for (int i = 0; i < 7; ++i)
		cout << graph[0][i] << ' ';
	cout << '\n';
	double deltaX = 7.0 / 15.0;
	double pointX;
	int result[1][15] = {0};
	for (int i = 0; i < 15; ++i)
	{
		pointX = (i + 0.5) * deltaX - 0.5;
		cout << pointX << '\n';
		if (pointX < 0)
		{
			result[0][i] = graph[0][0];
			continue;
		}
		double w1 = ceil(pointX) - pointX;
		double w2 = 1 - w1;
		// cout << w1 << ' ' << w2 << '\n';
		int tmp = 0;
		if (ceil(pointX) < 7)
			tmp = graph[0][(int)ceil(pointX)] * w2 + graph[0][(int)floor(pointX)] * w1;
		else 
			tmp = graph[0][6];
		result[0][i] = tmp;
	}
	for (int i = 0; i < 15; ++i)
		cout << result[0][i] << ' ';
	return 0;
} 

