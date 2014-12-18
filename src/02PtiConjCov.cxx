#include <iostream>
#include <fstream>
#include <cmath>
#include "libstat.h"

using namespace std;

struct line
	{
		double a, b, sa, sb;
	};
	
int main (){
	int N = 16;
	double * x = new double [N];
	double * y = new double [N];
	
	for(int i = 0; i < N; i++){
		cin >> x[i];
		cin >> y[i];
	}

	
	line ret;
	ret.a = interp_a(N, x, y);
	ret.b = interp_b(N, x, y);
	ret.sa = interp_sigmaa(N, x, y);
	ret.sb = interp_sigmab(N, x, y);
		
	cout <<
		"x medio = " << media(N, x) << ", Var(x) = " << scarto2(N, x) << endl <<
		"y medio = " << media(N, y) << ", Var(y) = " << scarto2(N, y) << endl;
	
	cout << 
		"Parametri retta:" <<
		"\nm = " << ret.b << " +/- " << ret.sb << 
		"\nq = " << ret.a << " +/- " << ret.sa <<
		"\ncov(m, q) = " << covab(N, x, yv) << endl;	
	return 0;
}



