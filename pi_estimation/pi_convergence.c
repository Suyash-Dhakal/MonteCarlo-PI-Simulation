#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // File to write the convergence data
    FILE *file = fopen("convergence.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // Array of discrete sample sizes for the Monte Carlo simulation
    int n[] = {
        10, 35, 65, 100, 350, 650, 
        1000, 3500, 6500, 10000, 
        35000, 65000, 100000, 
        350000, 650000, 1000000, 
        3500000, 6500000, 10000000, 
        35000000, 65000000, 100000000, 
        350000000, 650000000, 1000000000
    }; 
    
    long long count; // Count of points that fall inside the unit circle
    long long total; // Total number of random points generated

    // Loop through each sample size
    for (int j = 0; j < 25; j++) {
        count = 0; // Reset the count for each sample size
        total = n[j]; // Get the total points for this iteration
        
        for (int i = 0; i < total; i++) {
            double x = (double)rand() / RAND_MAX; // Generate random x coordinate in [0, 1]
            double y = (double)rand() / RAND_MAX; // Generate random y coordinate in [0, 1]
            double z = x * x + y * y;

            // Check if the point is inside the unit circle
            if (z <= 1) {
                count++; // Increment count if the point is inside the circle
            }
        }
        
        // Estimate the value of π based on the ratio of points inside the circle
        double pi_estimate = 4.0 * count / total; 
        
        // Write the total number of points and the estimated π value to the file
        fprintf(file, "%lld %lf\n", total, pi_estimate);
    }

    fclose(file);
    return 0;
}
