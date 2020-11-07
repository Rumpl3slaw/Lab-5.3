#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double h(const double x);

int main()
{
	double rp, rk, z;
	int n;

	cout << "rp=";cin >> rp;
	cout << "rk=";cin >> rk;
	cout << "n=";cin >> n;

	cout << fixed;

	cout << "------------------------------------------" << endl;
	cout << "|" << setw(5) << "rp" << "   |"
		<< setw(10) << "rk" << "    |"
		<< setw(7) << "   z" << "         |"
		<< endl;
	cout << "------------------------------------------" << endl;

	double dr=(rk - rp)/ n;

	double r = rp;

	while(r<= rk)
	{
		z = h(r + 1) + pow(h(r * r + 1), 2) + 1;
		cout << "|" << setw(7) << setprecision(2) << rp << "   |"
			<< setw(10) << setprecision(5) << rk << "   |"
			<< setw(10) << setprecision(5) << z << "    |"
			<< endl;
		r += dr;
	}
	cout << "------------------------------------------" << endl;

	return 0;

}
double h(const double x)
{
	if (abs(x) >= 1 && x == 0)
		return cos(x) + 1 / exp(x);
	else
	{
		double S = 0;
		int n = 0;
		double a = 1;
		S = a;
		do 
		{
			n++;
			double R = pow(x, 4 * n + 2) / ((2 * n -1)* (2 * n )* (2 * n + 1));
			a *= R;
			S += a;
		} while (n < 6);
		return 1./sin(x*x)*S;
	}
}