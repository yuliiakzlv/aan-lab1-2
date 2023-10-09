#include <iostream>

double Horner(int n, double a[], double c)
{
    double w = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        w = w * c + a[i];
    }
    return w;
}

void HornerU(int n, double a[], double c)
{
    for (int i = n; i >= 0; i--)
    {
        for (int k = i; k >= 1; k--)
        {
            a[k] = a[k] * c + a[k - 1];
        }
    }
}

int main()
{
    int degree;
    std::cout << "Podaj stopien wielomianu >>> ";
    std::cin >> degree;

    double* coefficients = new double[degree + 1];  // Dynamic memory allocation

    std::cout << "Podaj wspolczynniki wielomianu (pocznac od najwyzszej potegi): ";
    for (int i = degree; i >= 0; i--)
    {
        std::cout << "a" << i << ": ";
        std::cin >> coefficients[i];
    }

    double point;
    std::cout << "Podaj punkt, w ktorym chcesz obliczyc wartosc wielomianu: ";
    std::cin >> point;

    double result = Horner(degree, coefficients, point);

    std::cout << "Wartosc wielomianu w punkcie " << point << " wynosi: " << result << "\n";

    // Release dynamically allocated memory
    delete[] coefficients;

    return 0;
}
