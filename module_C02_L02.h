//----------------------------------------------------------------------------

#ifndef MODULE_C02_L02_H
#define MODULE_C02_L02_H 1

#include <stdbool.h>

void
Real_swap(double *inout_a,
          double *inout_b);

void
RealArray_show(const double *data,
               int count);

void
RealArray_reverse(double *data,
                  int count);

void
RealArray_copy(double *destination,
               const double *source,
               int count);

void
RealArray_reverseCopy(double *destination,
                      const double *source,
                      int count);

void
RealArray_max(const double *data,
              int count,
              double *out_value,
              int *out_index);

void
RealArray_min(const double *data,
              int count,
              double *out_value,
              int *out_index);

void
RealArray_ascendingSort(double *data,
                        int count);

void
RealArray_descendingSort(double *data,
                         int count);

bool // the array is sorted in ascending order
RealArray_sortedAscending(const double *data,
                          int count);

bool // the array is sorted in descending order
RealArray_sortedDescending(const double *data,
                           int count);

void
RealArray_histogram(const double *data,
                    int count,
                    int *histo,
                    int classCount,
                    double low,
                    double high);

#endif // MODULE_C02_L02_H

//----------------------------------------------------------------------------
