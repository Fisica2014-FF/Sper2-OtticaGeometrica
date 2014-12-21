#include <iostream>
#include <vector>
#include <climits>
using namespace std;
double sum (vector <double> a, vector <double> b);
double diff (vector <double> a, vector <double> b);
int main ()
{
	char c;
	double t1, t2;
	int counter = 0;
	vector <double> xi;
	vector <double> yi;
	while (cin >> t1)
	{
		cin >> t2;
		xi.push_back(t1);
		yi.push_back(t2);
		if(t1 == 0) break;
	}
	int n = xi.size();
	double a,b,q;
	cerr << "Inserire pendenza retta interpolante a due parametri: ";
	cin >> a;
	cerr << "Inserire intercetta retta interpolante a due parametri: ";
	cin >> b;
	cerr << "Inserire intercetta retta a parametro singolo: ";
	cin >> q;
	double Ftest;
	vector <double> f2par;
	vector <double> f1par;
	for (int i =0; i < n; i++)
	{
		f1par.push_back(q - (xi.at(i) ) );
		f2par.push_back(b + a * (xi.at(i) ) );
	}
	Ftest= (((diff(yi, f1par) * diff(yi, f1par) ) - (diff(yi , f2par) * diff(yi , f2par) ) ) * (n - 2) )/
				(diff(yi , f2par) * diff(yi , f2par) );
	cerr << "Il tuo Ftest per il fit ad un parametro e due parametri ha dato un risultato di " << Ftest << " ora vai a "
	     << "controllarlo in una tabella che dà le probabilità per la distribuzione di Fisher per capire quale delle due "
	     << "interpolazioni è milgiore, prendi quella a due parametri se f(Ftest) > CL";
	return 0;
	
	
}

double sum (vector <double> a, vector <double> b)
{
	int n = a.size();
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum =+ a.at(i) + b.at(i);
	}
	return sum;
}

double diff (vector <double> a, vector <double> b)
{
	int n = a.size();
	double diff = 0;
	for (int i = 0; i < n; i++)
	{
		diff =+ a.at(i) - b.at(i);
	}
	return diff;
}
