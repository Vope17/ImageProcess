#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int w=5, h=5, nw, nh;
	double ry,rx,cx,cy;
	
	int f[1][8]={0, 2, 7, 10, 6, 3, 5, 11};
	
	nw = 1;
	nh = 15;	
	int g[nw][nh]={0};
	for(int i = 0; i < nw; ++i)
	{
		for(int j = 0; j < nh; ++j)
			g[i][j] = 0;
	}

	double a, b, c;
	double alpha, beta;
	for(int j=1;j<=nh;j++)
	{
		// rx = (w)/double(nw)*(i + 1)+1.0-(w-1.0)/double(nw-1); 
		cx = 1.0 + (1 - 1) / 
		alpha = rx - int(rx);  
		beta = cx - int(cx); 
		a=(1-alpha)*f[i][j]+alpha*f[i+1][j];
		b=(1-alpha)*f[i][j+1]+alpha*f[i+1][j+1];
		c=beta*b+(1-beta)*a;
		g[i][j]= int(c + 0.5);	
	}

	for(int i = 0; i < nw; ++i)
	{
		for(int j = 0; j < nh; ++j)
			cout << g[i][j] << ' ';
		cout << '\n';
	}

	return 0;
} 

