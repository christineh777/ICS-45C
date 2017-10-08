#include <iostream>
using namespace std;
double convert(int knot)
{
	double mpm = (double)knot * 6076. / 5280.;
	return mpm;
}

int main()
{
	int knot;
	cin >> knot;
	cout << convert(knot) << endl;
	return 0;
}
