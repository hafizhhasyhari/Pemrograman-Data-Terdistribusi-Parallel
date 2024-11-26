#include <stdio.h>
#include <omp.h>

int main() {
    int i, n = 1000;
    double sum = 0.0, a[1000];

    // Inisialisasi array
    for (i = 0; i < n; i++) {
        a[i] = i * 1.0;
    }

    // Paralelisasi loop dengan OpenMP
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < n; i++) {
        sum += a[i];
    }

    printf("Sum = %f\n", sum);
    return 0;
}
