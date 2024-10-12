#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() 
{
    srand(SEED);  // Seed the random number generator

    long int i, count = 0, n;
    long double x, y, z, pi;  // Use long double for precision
    double start, end, wall_clock_time;
    printf("n = ");
    scanf("%ld", &n);

    start = omp_get_wtime(); // Record the start time

    // Monte Carlo simulation for estimating the value of pi
    for(i = 0; i < n; ++i) {
        x = (long double)rand() / RAND_MAX;  // Generate random x in [0, 1]
        y = (long double)rand() / RAND_MAX;  // Generate random y in [0, 1]
        z = x * x + y * y;                   // Check if inside the unit circle

        if(z <= 1) {
            count++;  // Count points inside the circle
        }
    }

    pi = ((long double)count * 4) / n;  // Calculate the approximation of π
    printf("Approximate PI = %.9Lf\n", pi);  // Print the result

    return 0;
}