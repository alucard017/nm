#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x;
}

double simpson(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i += 2)
    {
        double x = a + i * h;
        sum += 4 * func(x);
    }

    for (int i = 2; i < n - 1; i += 2)
    {
        double x = a + i * h;
        sum += 2 * func(x);
    }

    return (h / 3) * sum;
}

int main()
{
    double a, b;
    int n;

    cout << "Enter lower limit of integration: ";
    cin >> a;
    cout << "Enter upper limit of integration: ";
    cin >> b;
    cout << "Enter the number of subintervals (must be even): ";
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "Number of subintervals must be even." << endl;
        return 1;
    }

    double integral = simpson(a, b, n);
    cout << "Integral using Simpson's 1/3 rule: " << integral << endl;

    return 0;
}
