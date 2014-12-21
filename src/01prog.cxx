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
	int N = 6;
	double * x = new double [N];
	double * yv = new double [N];
	double * yl = new double [N];
	
	for(int i = 0; i < 7; i++){
		cin >> x[i];
		cin >> yv[i];
		cin >> yl[i];
	}

	
	line retv, retl;
	retv.a = interp_a(N, x, yv);
	retv.b = interp_b(N, x, yv);
	retv.sa = interp_sigmaa(N, x, yv);
	retv.sb = interp_sigmab(N, x, yv);
	
	retl.a = interp_a(N, x, yl);
	retl.b = interp_b(N, x, yl);
	retl.sa = interp_sigmaa(N, x, yl);
	retl.sb = interp_sigmab(N, x, yl);
	
	cout <<
		"x medio = " << media(N, x) << ", Var(x) = " << scarto2(N, x) << endl <<
		"y vicino medio = " << media(N, yv) << ", Var(y) = " << scarto2(N, yv) << endl <<
		"y lontano medio = " << media(N, yl) << ", Var(y) = " << scarto2(N, yl) << endl;
	
	cout << 
		"Da vicino" <<
		"\nm = " << retv.b << " +/- " << retv.sb << 
		"\nq = " << retv.a << " +/- " << retv.sa <<
		"\ncov(m, q) = " << covab(N, x, yv) << 
		"\nfv(x) = " << retv.b << " * x + " << retv.a <<
		"\nfv_hh(x) = " << retv.b + retv.sb << " * x + " << retv.a + retv.sa <<
		"\nfv_hl(x) = " << retv.b + retv.sb << " * x + " << retv.a - retv.sa <<
		"\nfv_lh(x) = " << retv.b - retv.sb << " * x + " << retv.a + retv.sa <<
		"\nfv_ll(x) = " << retv.b - retv.sb << " * x + " << retv.a - retv.sa <<
		"\nDa lontano" <<
		"\nm = " << retl.b << " +/- " << retl.sb << 
		"\nq = " << retl.a << " +/- " << retl.sa <<
		"\ncov(m, q) = " << covab(N, x, yl) << 
		"\nfl(x) = " << retl.b << " * x + " << retl.a <<
		"\nfl_hh(x) = " << retl.b + retl.sb << " * x + " << retl.a + retl.sa <<
		"\nfl_hl(x) = " << retl.b + retl.sb << " * x + " << retl.a - retl.sa <<
		"\nfl_lh(x) = " << retl.b - retl.sb << " * x + " << retl.a + retl.sa <<
		"\nfl_ll(x) = " << retl.b - retl.sb << " * x + " << retl.a - retl.sa << endl;
	
	
	return 0;
}



