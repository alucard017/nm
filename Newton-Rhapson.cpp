#include <iostream>
#include <cmath>

using namespace std;
double func(double x)
{
    return x * x - 4;
}

double funcDerivative(double x)
{
    return 2 * x;
}

double newtonRaphson(double x0, double tol, int maxIter)
{
    double x = x0;
    int iter = 0;

    while (fabs(func(x)) > tol && iter < maxIter)
    {
        x = x - func(x) / funcDerivative(x);
        iter++;
    }

    if (iter == maxIter)
    {
        cout << "Maximum iterations reached." << endl;
        return NAN;
    }

    return x;
}

int main()
{
    double x0, tol;
    int maxIter;

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    double root = newtonRaphson(x0, tol, maxIter);

    if (!isnan(root))
    {
        cout << "Root is: " << root << endl;
    }

    return 0;
}
