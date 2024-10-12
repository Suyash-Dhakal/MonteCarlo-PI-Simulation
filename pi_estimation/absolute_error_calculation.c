#include <stdio.h>
#include <math.h>

int main() {
    // Define the actual value of pi
    const double actual_pi = 3.14159265;

    // Define the number of sample points and corresponding estimated pi values
    int points[] = {
        10, 35, 65, 100, 350, 650, 1000, 
        3500, 6500, 10000, 35000, 65000, 
        100000, 350000, 650000, 1000000, 
        3500000, 6500000, 10000000, 35000000, 
        65000000, 100000000, 350000000, 650000000, 
        1000000000
    };
    
    double estimated_pi[] = {
        3.600000, 2.514286, 2.830769, 3.280000, 3.280000,
        3.175385, 3.160000, 3.117714, 3.153231, 3.133200,
        3.131200, 3.146769, 3.147840, 3.144514, 3.139711,
        3.139056, 3.142008, 3.141666, 3.140785, 3.141362,
        3.141671, 3.141643, 3.141613, 3.141568, 3.141577
    };

    int n = sizeof(points) / sizeof(points[0]); // Calculate the number of entries

    // File for writing the absolute errors
    FILE *file = fopen("absolute_errors.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "%-15s %-15s\n", "Absolute Error", "Sample Size/Points");
    fprintf(file, "---------------------------------------------------------\n");

    // Calculate and write absolute errors to the file
    for (int i = 0; i < n; i++) {
        double absolute_error = fabs(estimated_pi[i] - actual_pi);
        fprintf(file, "%-15f %-15d\n", absolute_error, points[i]);
    }

    fclose(file);
    printf("Data saved to absolute_errors.txt\n");

    return 0;
}
