#include <iostream>
#include <cmath>
using namespace std;

class Equation
{
public:
	Equation() {}
	virtual double EquationRoots()
	{
		cout << "nothing" << endl;
		return 0;
	}
	~Equation() {}
};

class LinearEquation: public Equation
{
private:
	double a;
	double b;
public:
	LinearEquation(double a, double b)
	{
		this->a = a;
		this->b = b;
	}
	virtual double EquationRoots()
	{
		double x;
		x = b / (a*(-1));
		return x;
	}
	~LinearEquation() {};
};

class QuadricEquation : public Equation
{
private:
	double a;
	double b;
	double c;
public:
	QuadricEquation(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	virtual double EquationRoots()
	{
		double disc = (b*b)-(4*a*c);
		double x1, x2;
		if (disc > 0)
		{
			x1 = (-b + sqrt(disc)) / (2 * a);
			x2 = (-b - sqrt(disc)) / (2 * a);
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
		if (disc == 0)
		{
			disc = (-b) / (a * 2);
			cout << disc << endl;
		}
		if (disc < 0)
		{
			cout << "Roots does not exist!" << endl;
		}
		return 0;
	}
	~QuadricEquation() {};
};

int main()
{
	cout << "Linear equation: " << endl;
	double a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	LinearEquation c(a,b);
	Equation* temp = &c;
	cout << a << "x + " << b << " = " << temp->EquationRoots() << endl;

	cout << "Quadratic equation: " << endl;
	double d, f, g;
	cout << "a = ";
	cin >> d;
	cout << "b = ";
	cin >> f;
	cout << "c = ";
	cin >> g;
	QuadricEquation h(d,f,g);
	Equation* temp1 = &h;
	cout << d << "x^2 + " << f << "x + " << g << " = " << endl;
	temp1->EquationRoots();
	return 0;
}