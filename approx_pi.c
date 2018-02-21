#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

double approx_pi(int);
double approx_pi2(int);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    clock_t t1 = clock();
    double pi = approx_pi(n);
    clock_t t2 = clock();
    printf("PI is approximately %.16f, Error is %.16f\n",
	   pi, fabs(pi - M_PI));
    printf("Time = %.16f sec\n", (double)(t2 - t1)/CLOCKS_PER_SEC);
    return 0;
}

double approx_pi(int intervals)
{
     double pi = 0.0;
     int i;
     for (i = 0; i < intervals; i++) {
         // Note: using "float" instead of "double" is a little faster here
         pi += (4 - ((i % 2) * 8)) / (double)(2 * i + 1);
     }
     return pi;
}

double approx_pi2(int intervals)
{
     double pi1 = 0.0;
     double pi2 = 0.0;
     int i;
     int i_max= intervals/2;
     double un=1.;
     for (i = 0; i < i_max; i++) {
         // Note: using "float" instead of "double" is a little faster here
         pi1 += un / (4 * i + 1);
         pi2 += un / (4 * i + 3);
     }
     return 4*(pi1-pi2);
}
