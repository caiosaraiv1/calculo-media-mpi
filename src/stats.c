#include <stdlib.h>
#include "stats.h"

void fill_random(float *values, int n)
{
      for (int i = 0; i < n; i++)
            values[i] = rand() / (float)RAND_MAX;
}

double compute_sum(const float *values, int n)
{
      double sum = 0.0;
      for (int i = 0; i < n; i++)
            sum += values[i];
      return sum;
}
