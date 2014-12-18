#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	double q, m, sq, sm, cqm;
	cerr << "Inserisci in ordine: q, sq, m, sm, cqm: " << endl;
	cin >> q >> sq >> m >> sm >> cqm;
	double sx;
	sx = sqrt ( ((1/( m * m) ) * sq * sq ) + ((q * q ) /( m * m * m * m) * sm * sm ) + ( 2 * cqm ));
	cerr << "L'errore su f_x vale " << sx << endl;
	return 0;
}
