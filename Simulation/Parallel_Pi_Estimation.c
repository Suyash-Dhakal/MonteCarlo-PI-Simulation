#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    long int n;
    long int count = 0;
    long double x, y, z;
    double start, end, wall_clock_time;

    // Input number of iterations
    printf("\nn = ");
    scanf("%ld", &n);
    
    omp_set_num_threads(8); // Set the number of threads
    unsigned int true_random_numbers[8] = {74, 51, 54, 89, 54, 15, 23, 31}; // True random numbers from random.org (based on atmospheric noise)
    start = omp_get_wtime(); // Record the start time

    #pragma omp parallel
    {
        unsigned int seed = true_random_numbers[omp_get_thread_num()]; // Seed each thread once
        long int local_count = 0;

        #pragma omp for private(x, y, z)
        for(long int i = 0; i < n; ++i) {
            x = (long double)rand_r(&seed) / RAND_MAX;  // Generate random x in [0, 1]
            y = (long double)rand_r(&seed) / RAND_MAX;  // Generate random y in [0, 1]
            z = x * x + y * y;                          // Check if inside the unit circle

            if(z <= 1) {
                local_count++;  // Count points inside the circle
            }
        }

        #pragma omp atomic
        count += local_count;
    }

    end = omp_get_wtime(); // Record the end time

    long double pi = (long double)count / n * 4; // Estimate of Pi
    printf("\nApproximate PI = %.9Lf\n", pi);

    wall_clock_time = end - start;
    printf("Elapsed Wall Clock Time: %f seconds\n", wall_clock_time);

    return 0;
}
