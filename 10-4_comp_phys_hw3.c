#include<stdio.h>
#include <math.h>

double f(double x);
double trapezoidf(double a, double b, int N);
void rombergf(double a[6][6], int n);

double g(double x);
double trapezoidg(double a, double b, int N);
void rombergg(double a[6][6], int n);

double p(double x);
double trapezoidp(double a, double b, int N);
void rombergp(double a[6][6], int n);

int main()
{
    int i, j;
    int n = 6;
    double a[6][6];
    rombergf(a, n);
    printf("\n\n");
    rombergg(a, n);
    printf("\n\n");
    rombergp(a, n);
    return 0;
}

double f(double x)
{
    return 1 / (1 + x);
}

double g(double x)
{
    return exp(x);
}

double p(double x)
{
    return sqrt(x);
}

double trapezoidf(double a, double b, int N)
{
    double sum = 0.0;
    double h = (b - a) / N;
    sum = 0.5 * f(a) + 0.5 * f(b);
    for (int k = 1; k < N + 1; k = k + 1)
    {
        sum += f(a + k * h);
    }
    return h * sum;
}

double trapezoidg(double a, double b, int N)
{
    double sum = 0.0;
    double h = (b - a) / N;
    sum = 0.5 * g(a) + 0.5 * g(b);
    for (int k = 1; k < N + 1; k = k + 1)
    {
        sum += g(a + k * h);
    }
    return h * sum;
}
double trapezoidp(double a, double b, int N)
{
    double sum = 0.0;
    double h = (b - a) / N;
    sum = 0.5 * p(a) + 0.5 * p(b);
    for (int k = 1; k < N + 1; k = k + 1)
    {
        sum += p(a + k * h);
    }
    return h * sum;
}

void rombergf(double a[6][6], int n)
{
    int i, j;
    printf("Romberg for function f\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(j == 1)
            {
                a[i][j] = trapezoidf(0.0, 1.0, i);
            }
            else
            {
                a[i][j] = a[i][j - 1] + ((1 / (pow(4, j - 1) - 1)) * (a[i][j - 1] - a[i - 1][j - 1]));
            }
            printf("Position (%d,%d): %.2f\n", i, j, a[i][j]);
        }
    }
}

void rombergg(double a[6][6], int n)
{
    int i, j;
    printf("Romberg for function g\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(j == 1)
            {
                a[i][j] = trapezoidg(0.0, 1.0, i);
            }
            else
            {
                a[i][j] = a[i][j - 1] + ((1 / (pow(4, j - 1) - 1)) * (a[i][j - 1] - a[i - 1][j - 1]));
            }
            printf("Position (%d,%d): %.2f\n", i, j, a[i][j]);
        }
    }
}
void rombergp(double a[6][6], int n)
{
    int i, j;
    printf("Romberg for function p\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if(j == 1)
            {
                a[i][j] = trapezoidp(0.0, 1.0, i);
            }
            else
            {
                a[i][j] = a[i][j - 1] + ((1 / (pow(4, j - 1) - 1)) * (a[i][j - 1] - a[i - 1][j - 1]));
            }
            printf("Position (%d,%d): %.2f\n", i, j, a[i][j]);
        }
    }
}
