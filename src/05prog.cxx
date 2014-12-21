//Estrae e analizza i dati da 05dat_pr.txt:
//
//

#include <iostream>
#include <fstream>
#include <cmath>
#include "libstat.h"


int const N = 10;
double const f = 6.89091; ///////
double const sf = 0.151888;; ///////
double const s = 0.005;
using namespace std;

struct mis
{
	double fF /*mm*/, fC /*mm*/, V;
};


int main(){
	mis * arr = new mis [N];
	double * A = new double [N];
	double mpes = 0;
	double spes = 0;
	double Am = 0;
	double sigma;
	double frac;
	for(int i = 0; i < N; i++){
		cin >> arr[i].fF;
		cin >> arr[i].fC;
		A[i] = (arr[i].fC - arr[i].fF) / 10;
		Am += A[i];
		frac = 1 / A[i];
		arr[i].V = f * frac;
		//debug
		cout << arr[i].V << "    " << frac << endl;
		sigma = sqrt(frac * frac * (sf * sf + 2 * f * f * frac * frac * s * s));
		cout << i + 1 << "esimo V = " <<  arr[i].V << ", sigma = " <<  sigma  << endl;
		mpes += arr[i].V / ((sigma) * (sigma));
		//debug
		cout << "mpes " << mpes << endl;
		spes += 1 / ((sigma) * (sigma));
	}
	Am = Am / N;
	double sAm = scarto2(N, A)/((sqrt(N)));
	
	cout << "Media di A = " << Am << ", con sigma = " << sAm << endl;	 
	
	mpes = mpes / spes;
	spes = sqrt(1 / spes);
	
	cout << "Media pesata di V = " << mpes << ", con sigma = " << spes << endl;	
	
	return 0;
}
