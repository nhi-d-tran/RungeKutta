
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const double pi = 4.0*atan2(1.0,1.0);

int f(int n, double x, vector<double> &y, vector<double> &g)
{
	g[0] = y[1];
	g[1] = -y[0] - (sin(x)/pi);

	return 0;
}

int RK4(int n, double x, double h, vector<double> &y_in, vector<double> &y_out)
{
	int i = 0;
	int rc = 0;
	y_out = y_in;
	if ((n < 1) || (y_in.size() < n) || (y_out.size() < n))
		return 1; // fail

	std::vector<double> g1(n, 0.0);
	std::vector<double> g2(n, 0.0);
	std::vector<double> g3(n, 0.0);
	std::vector<double> g4(n, 0.0);

	std::vector<double> y_tmp(n, 0.0); // temporary storage

	rc = f(n, x, y_in, g1);
	if (rc) return rc;

	for (i = 0; i < n; ++i)
	{
		y_tmp[i] = y_in[i] + 0.5*h*g1[i];
	}

	rc = f(n, x+0.5*h, y_tmp, g2);

	if (rc)
		return rc;

	for (i = 0; i < n; ++i)
	{
		y_tmp[i] = y_in[i] + 0.5*h*g2[i];
	}

	rc = f(n, x+0.5*h, y_tmp, g3);

	if (rc)
		return rc;

	for (i = 0; i < n; ++i)
	{
		y_tmp[i] = y_in[i] + h*g3[i];
	}

	rc = f(n, x+h, y_tmp, g4);

	if (rc)
		return rc;

	for (i = 0; i < n; ++i)
	{
		y_out[i] = y_in[i] + (h/6.0)*(g1[i] + 2.0*g2[i] + 2.0*g3[i] + g4[i]);
	}
    return 0;
}

int main()
{
	int N = 10;
	double *x1, *x2;
	x1 = new double[N];
	x2 = new double[2*N + 1];
	double h1 = (double) (2*pi)/N;	// for forward stepsize
	double h2 = -(double) (2*pi)/N;	// for backward stepsize
	const int n = 2;
	vector<double> y_in(n, 0.0);		//(y, v)_i
	vector<double> y_out(n, 0.0);		//(y, v)_{i+1}

	y_in[0] = 1.0;
	y_in[1] = -1.0;

	//initialize the array
	for(int k = 0; k <= N; k++)
	{
		x1[k] = 0;

	}
	for(int z = N + 1; z <= 2*N; z++)
	{
		x2[z] = 0;
	}

	cout << "i" << setw(10) << "x[i]" << setw(10) << "y_in[0]" <<setw(10)<<"y_out[0]" << endl;
	cout << "------------------------------------" << endl;

	for(int i = 0; i <= N; i++)
	{

		cout << fixed;
		cout << setprecision(6);
		x1[i] = h1*i;
		RK4(n, x1[i], h1, y_in, y_out);
		cout << i << setw(10) << x1[i] << setw(10)  << y_in[0] << setw(10) << y_out[0] << endl;
		y_in = y_out;

	}
	cout << endl;
	cout << endl;
	cout << "j" << setw(10) << "x[j]" << setw(10) << "y_in[0]" <<setw(10)<<"y_out[0]" << endl;
	cout << "------------------------------------" << endl;
	for(int j = N; j <= 2*N; j++)
	{
		cout << fixed;
		cout << setprecision(6);
		x2[j] = 4*pi - h1*j;
		RK4(n, x2[j], h2, y_in, y_out);
		cout << j << setw(10) << x2[j] << setw(10)  << y_in[0] << setw(10) << y_out[0] << endl;
		y_in = y_out;
	}

	delete[] x1;
	delete[] x2;
	y_in.clear();
	y_out.clear();
	return 0;
}
