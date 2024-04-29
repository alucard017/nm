#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x - 4;
}

double bisection(double a, double b, double tol)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "Bisection method fails." << endl;
        return 0;
    }

    double c = a;
    while ((b - a) >= tol)
    {
        c = (a + b) / 2;

        if (func(c) == 0.0)
            break;

        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

int main()
{
    double a, b, tol;
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter tolerance: ";
    cin >> tol;

    double root = bisection(a, b, tol);
    cout << "Root is: " << root << endl;
    return 0;
}
