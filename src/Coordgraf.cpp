#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <double> c1;
	vector <double> c2;
	vector <double> c3;
	vector <double> c4;
	vector <double> c5;
	vector <double> xi;
	vector <double> yi;
	int counter = 0;
	int shift;
	double t1,t2,t3,t4,t5;;
	while (cin >> t1) {
	  cin >> t2;
	  cin >> t3;
	  cin >> t4;
	  cin >> t5;
	  
	  c1.push_back(t1);
	  c2.push_back(t2);
	  c3.push_back(t3);
	  c4.push_back(t4);
	  c5.push_back(t5);
	}
	int n = c1.size();
	for (int i = 0 ; i < n ; i++)
	{
		xi.push_back(1.0/(c2.at(i)-c1.at(i)+0.1*c4.at(i)-0.1*c5.at(i)));
		yi.push_back(1.0/(c3.at(i)-c2.at(i)-0.1*c4.at(i)-0.1*c5.at(i)));
		cout << xi.at(i) << "\t" << yi.at(i) << endl;
	}
	return 0;
}
