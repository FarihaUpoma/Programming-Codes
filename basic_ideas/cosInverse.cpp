#include <stdio.h>
#include <math.h>

#define pi (2*acos(0.0))

int main()
{
    double a = acos(5.0/6);
    a = a * 180 / pi;
    printf("%lf", a);
    return 0;
}
