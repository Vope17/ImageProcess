#include <iostream>
#include <cstring>
#include <cmath>
#define pi acos(-1)
using namespace std;
int main()
{
	int f[5][5]={{1,2,3,4,5},
			{6,7,8,9,10},
			{11,12,13,14,15},
			{16,17,18,19,20},
			{21,22,23,24,25}};
	int w, h;
	int nw, nh;
	w = h = 5;		
	double t=45;

	double theta1 = cos(t*pi/180);
	double theta2 = sin(t*pi/180); 

	nw = std::abs(w * theta1 + h * theta2);
	nh = std::abs(h * theta1 + h * theta2);

	cout << nw << ' ' << nh << '\n';
	double g[nh][nw] = {0};
	
	
	return 0;
} 

