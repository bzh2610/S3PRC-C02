//----------------------------------------------------------------------------

#include "module_C02_L02.h"
#include <stdio.h>
#include <float.h>

void
Real_swap(double *inout_a,
          double *inout_b)
{
//-- load inout-parameters --
const double a=*inout_a;
const double b=*inout_b;
//-- store out-parameters --
*inout_a=b;
*inout_b=a;
}

void
RealArray_show(const double *data,
               int count)
{
printf("[ ");
for(int i=0;i<count;++i)
  {
  if(i)
    { printf(", "); }
  printf("%g",data[i]);
  }
printf(" ]");
}

void
RealArray_reverse(double *data,
                  int count)
{
const int mid=count/2;
for(int i=0;i<mid;++i)
  { Real_swap(data+i,data+count-1-i); }
}

void
RealArray_copy(double *destination,
               const double *source,
               int count)
{
for(int i=0;i<count;++i)
  { destination[i]=source[i]; }
}

void
RealArray_reverseCopy(double *destination,
                      const double *source,
                      int count)
{
for(int i=0;i<count;++i)
  { destination[count-1-i]=source[i]; }
}

void
RealArray_max(const double *data,
              int count,
              double *out_value,
              int *out_index)
{
double maxValue=-DBL_MAX;
int maxIndex=-1;
for(int i=0;i<count;++i)
  {
  const double value=data[i];
  if(value>maxValue)
    { maxValue=value; maxIndex=i; }
  }
//-- store out-parameters --
*out_value=maxValue;
*out_index=maxIndex;
}

void
RealArray_min(const double *data,
              int count,
              double *out_value,
              int *out_index)
{
double minValue=DBL_MAX;
int minIndex=-1;
for(int i=0;i<count;++i)
  {
  const double value=data[i];
  if(value<minValue)
    { minValue=value; minIndex=i; }
  }
//-- store out-parameters --
*out_value=minValue;
*out_index=minIndex;
}

void
RealArray_ascendingSort(double *data,
                        int count)
{
for(int i=0;i<count;++i)
  {
  double value;
  int index;
  RealArray_min(data+i,count-i,&value,&index);
  if(index)
    { Real_swap(data+i,data+i+index); }
  }
}

void
RealArray_descendingSort(double *data,
                         int count)
{
for(int i=0;i<count;++i)
  {
  double value;
  int index;
  RealArray_max(data+i,count-i,&value,&index);
  if(index)
    { Real_swap(data+i,data+i+index); }
  }
}

bool // the array is sorted in ascending order
RealArray_sortedAscending(const double *data,
                          int count)
{
double prev=data[0];
for(int i=0;i<count;++i)
  {
  const double value=data[i];
  if(value<prev)
    { return false; }
  prev=value;
  }
return true;
}

bool // the array is sorted in descending order
RealArray_sortedDescending(const double *data,
                           int count)
{
double prev=data[0];
for(int i=0;i<count;++i)
  {
  const double value=data[i];
  if(value>prev)
    { return false; }
  prev=value;
  }
return true;
}

void
RealArray_histogram(const double *data,
                    int count,
                    int *histo,
                    int classCount,
                    double low,
                    double high)
{
for(int i=0;i<classCount;++i)
  { histo[i]=0; }
const double step=(high-low)/classCount;
for(int i=0;i<count;++i)
  {
  int cls=(int)((data[i]-low)/step);
  if(cls<0)
    { cls=0; }
  else if(cls>=classCount)
    { cls=classCount-1; }
  ++histo[cls];
  }
}

//----------------------------------------------------------------------------
