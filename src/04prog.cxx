//Estrae e analizza i dati da 04dat_pr.txt:
//fm fi ff fp t s(sigma su t)
//corretto da Fra

#include <iostream>
#include <fstream>
#include <cmath>
#include "libstat.h"


double const sch = 40.80;
int const N = 10;
double const f = 6.89091; ///////
double const sf = 0.151888; ///////
double const R = 1.4;
using namespace std;

struct mis
{
	double fm /*mm*/, fi /*mm*/, ff /*mm*/, fp /*mm*/, t /*mm*/, s /*cm*/, c;
};


int main(){
	mis * arr = new mis [N];
	double lmpes = 0;
	double lspes = 0;
	double mpes = 0;
	double spes = 0;	
	double sl;
	for(int i = 0; i < N; i++){
		cin >> arr[i].fm; 
		cin >> arr[i].fi; 
		cin >> arr[i].ff;
		cin >> arr[i].fp;
		cin >> arr[i].t;
		cin >> arr[i].s;
		arr[i].s = 0.001;
		arr[i].fm = arr[i].fm; 
		arr[i].fi = arr[i].fi; 
		arr[i].ff = arr[i].ff; 
		arr[i].fp = arr[i].fp; 
		arr[i].c = ((arr[i].fi + arr[i].ff)/2 - arr[i].fm)/10;
		// trascuro l'errore su fm, perche' piccolo rispetto a quello su fp=(ff+fi)/2
		sl = (arr[i].ff-arr[i].fi)/20;
		lmpes += arr[i].c / (sl * sl);
		lspes += 1 / (sl * sl);
		cout << i + 1 << "esimo l = " <<  arr[i].c << ", sigma = " <<  sl << endl;
		arr[i].s = sqrt((f * f * sl * sl + arr[i].c * arr[i].c * sf * sf) / (R * R * R * R));
		arr[i].c = arr[i].c * f / (R * R);
		cout << i + 1 << " esimo c = " <<  arr[i].c << ", sigma = " <<  arr[i].s  << endl;
		mpes += arr[i].c / ((arr[i].s) * (arr[i].s));
		spes += 1 / ((arr[i].s) * (arr[i].s));
	}
	lmpes = lmpes / lspes;
	lspes = sqrt(1.0 / lspes);
	
	cout << "Media pesata di l = " << lmpes << "cm, con sigma = " << lspes << "cm." << endl;
	
	mpes = mpes / spes;
	spes = sqrt(1 / spes);
	
	cout << "Media pesata di c = " << mpes << "cm, con sigma = " << spes << "cm." << endl;	
	
	double tsum = 0;
	double * t = new double [N - 3];
	for(int i = 0; i < (N - 3); i++){	//gli ultimi tre t non sono considerati
		//cin >> arr[i].fm; 
		//cin >> arr[i].fi; 
		//cin >> arr[i].ff;
		//cin >> arr[i].fp;
		//cin >> arr[i].t;
		//cin >> arr[i].s;
		tsum += arr[i].t;
		t[i] = arr[i].t;
	}
	double tau = tsum / (10 * (N -3));
	double st = scarto2((N - 3), t)/(10 * (sqrt(N - 3)));
		
	cout << "t = " << tau << "cm, sigmat = cm" << st << endl;
		
		
	
	return 0;
}
