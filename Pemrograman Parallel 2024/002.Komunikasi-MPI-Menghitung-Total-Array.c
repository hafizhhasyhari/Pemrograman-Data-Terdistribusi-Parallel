// Komunikasi MPI (Menghitung Total Array)

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_sum = rank + 1; // Tiap proses menghitung nilai lokal
    int global_sum = 0;

    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Global sum: %d\n", global_sum);
    }

    MPI_Finalize();
    return 0;
}
