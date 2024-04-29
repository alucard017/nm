#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x;
}

double simpson_3_8(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * func(x);
        else
            sum += 3 * func(x);
    }

    return (3 * h / 8) * sum;
}

int main()
{
    double a, b;
    int n;

    cout << "Enter lower limit of integration: ";
    cin >> a;
    cout << "Enter upper limit of integration: ";
    cin >> b;
    cout << "Enter the number of subintervals (must be multiple of 3): ";
    cin >> n;

    if (n % 3 != 0)
    {
        cout << "Number of subintervals must be multiple of 3." << endl;
        return 1;
    }

    double integral = simpson_3_8(a, b, n);
    cout << "Integral using Simpson's 3/8 rule: " << integral << endl;

    return 0;
}
