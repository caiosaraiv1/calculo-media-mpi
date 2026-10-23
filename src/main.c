#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include "stats.h"

int main(int argc, char **argv)
{
      int rank, size;

      MPI_Init(&argc, &argv);
      MPI_Comm_rank(MPI_COMM_WORLD, &rank);
      MPI_Comm_size(MPI_COMM_WORLD, &size);

      int n = atoi(argv[1]);
      float *values = malloc(n * sizeof(float));

      srand(time(NULL) + rank);
      fill_random(values, n);

      double local_sum = compute_sum(values, n);
      double local_mean = local_sum / n;

      printf("[Processo %d] Soma local: %.3f, Média local: %.4f\n", rank, local_sum, local_mean);

      double global_sum = 0.0;
      MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

      if (rank == 0) {
            double global_mean = global_sum / ((double)n * size);
            printf("\n[Soma global] %.3f\n", global_sum);
            printf("[Media global] %.4f\n", global_mean);
      }

      free(values);
      MPI_Finalize();
      return 0;
}
