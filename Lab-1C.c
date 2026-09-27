#include <stdio.h>

int main()
{
    double a, b, c;
    double xn, xk, dx;
    double x, F;

    printf("Enter a: ");
    scanf("%lf", &a);

    printf("Enter b: ");
    scanf("%lf", &b);

    printf("Enter c: ");
    scanf("%lf", &c);

    printf("Enter initial value xn: ");
    scanf("%lf", &xn);

    printf("Enter final value xk: ");
    scanf("%lf", &xk);

    printf("Enter step dx: ");
    scanf("%lf", &dx);

    int Ac = (int)a;
    int Bc = (int)b;
    int Cc = (int)c;
    int is_real = ((Ac & Bc) | (Ac & Cc)) != 0;

    printf("\nResults:\n");

    for (x = xn; x <= xk + dx / 2.0; x = x + dx)
    {
        int valid = 1;

        if (c < 0 && b != 0)
        {
            F = a * x * x + b * b * x + c;
        }
        else if (c > 0 && b == 0)
        {
            if (x + c == 0)
                valid = 0;
            else
                F = (x + a) / (x + c);
        }
        else
        {
            if (c == 0)
                valid = 0;
            else
                F = x / c;
        }

        if (!valid)
        {
            printf("x = %.4lf   F(x) = Undefined\n", x);
        }
        else
        {
            if (is_real)
            {
                printf("x = %.4lf   F(x) = %.4lf\n", x, F);
            }
            else
            {
                printf("x = %.4lf   F(x) = %d\n", x, (int)F);
            }
        }
    }

    return 0;
}
