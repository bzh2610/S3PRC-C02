//----------------------------------------------------------------------------

#include "module_C02_L02.h"
#include "random.h"

#include <stdio.h>

void
uniformFill(double *data,
            int count,
            double low,
            double high)
{
const double range=high-low;
for(int i=0;i<count;++i)
  { data[i]=low+Random_uniform()*range; }
}

void
gaussianFill(double *data,
             int count,
             double mean,
             double standardDeviation)
{
for(int i=0;i<count;++i)
  { data[i]=mean+Random_gaussian()*standardDeviation; }
}

void
showHistogram(const int *histo,
              int classCount)
{
int maxH=histo[0];
for(int i=1;i<classCount;++i)
  {
  int h=histo[i];
  if(h>maxH)
    { maxH=h; }
  }
for(int i=0;i<classCount;++i)
  {
  const int h=histo[i], count=h*76/maxH;
  printf("|");
  for(int j=0;j<count;++j)
    { printf("="); }
  printf(h ? ">\n" : "\n");
  }
}

void
test_Real_swap(void)
{
printf("\n~~~~ test_Real_swap() ~~~~\n");
double a=1.1,b=2.2;
printf("before: a=%g b=%g\n",a,b);
Real_swap(&a,&b);
printf("after: a=%g b=%g\n",a,b);
}

void
test_RealArray_show(void)
{
printf("\n~~~~ test_RealArray_show() ~~~~\n");
const double values[]={ 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
const int count=(int)(sizeof(values)/sizeof(values[0]));
printf("values: "); RealArray_show(values,count); printf("\n");
}

void
test_RealArray_reverse(void)
{
printf("\n~~~~ test_RealArray_reverse() ~~~~\n");
double values[]={ 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
const int count=(int)(sizeof(values)/sizeof(values[0]));
printf("before: "); RealArray_show(values,count); printf("\n");
RealArray_reverse(values,count);
printf("after: "); RealArray_show(values,count); printf("\n");
}

void
test_RealArray_copy(void)
{
printf("\n~~~~ test_RealArray_copy() ~~~~\n");
const double values1[10]={ 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
double values2[10];
const int count=(int)(sizeof(values1)/sizeof(values1[0]));
printf("values1: "); RealArray_show(values1,count); printf("\n");
RealArray_copy(values2,values1,count);
printf("values2: "); RealArray_show(values2,count); printf("\n");
}

void
test_RealArray_reverseCopy(void)
{
printf("\n~~~~ test_RealArray_reverseCopy() ~~~~\n");
const double values1[10]={ 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
double values2[10];
const int count=(int)(sizeof(values1)/sizeof(values1[0]));
printf("values1: "); RealArray_show(values1,count); printf("\n");
RealArray_reverseCopy(values2,values1,count);
printf("values2: "); RealArray_show(values2,count); printf("\n");
}

void
test_RealArray_max(void)
{
printf("\n~~~~ test_RealArray_max() ~~~~\n");
double values[10];
const int count=(int)(sizeof(values)/sizeof(values[0]));
uniformFill(values,count,0.0,20.0);
printf("values: "); RealArray_show(values,count); printf("\n");
double maxValue;
int maxIndex;
RealArray_max(values,count,&maxValue,&maxIndex);
printf("max: %g at index %d\n",maxValue,maxIndex);
}

void
test_RealArray_min(void)
{
printf("\n~~~~ test_RealArray_min() ~~~~\n");
double values[10];
const int count=(int)(sizeof(values)/sizeof(values[0]));
uniformFill(values,count,0.0,20.0);
printf("values: "); RealArray_show(values,count); printf("\n");
double minValue;
int minIndex;
RealArray_min(values,count,&minValue,&minIndex);
printf("min: %g at index %d\n",minValue,minIndex);
}

void
test_RealArray_ascendingSort(void)
{
printf("\n~~~~ test_RealArray_ascendingSort() ~~~~\n");
double values[10];
const int count=(int)(sizeof(values)/sizeof(values[0]));
uniformFill(values,count,0.0,20.0);
printf("before: "); RealArray_show(values,count); printf("\n");
printf("ascending: %d    descending: %d\n",
       RealArray_sortedAscending(values,count),
       RealArray_sortedDescending(values,count));
RealArray_ascendingSort(values,count);
printf("after: "); RealArray_show(values,count); printf("\n");
printf("ascending: %d    descending: %d\n",
       RealArray_sortedAscending(values,count),
       RealArray_sortedDescending(values,count));
}

void
test_RealArray_descendingSort(void)
{
printf("\n~~~~ test_RealArray_descendingSort() ~~~~\n");
double values[10];
const int count=(int)(sizeof(values)/sizeof(values[0]));
uniformFill(values,count,0.0,20.0);
printf("before: "); RealArray_show(values,count); printf("\n");
printf("ascending: %d    descending: %d\n",
       RealArray_sortedAscending(values,count),
       RealArray_sortedDescending(values,count));
RealArray_descendingSort(values,count);
printf("after: "); RealArray_show(values,count); printf("\n");
printf("ascending: %d    descending: %d\n",
       RealArray_sortedAscending(values,count),
       RealArray_sortedDescending(values,count));
}

void
test_RealArray_histogram(void)
{
printf("\n~~~~ test_RealArray_histogram() ~~~~\n");
double values[1000];
const int count=(int)(sizeof(values)/sizeof(values[0]));
uniformFill(values,count,0.0,20.0);
int histo[20];
const int classCount=(int)(sizeof(histo)/sizeof(histo[0]));
RealArray_histogram(values,count,histo,classCount,0.0,20.0);
printf("uniform:\n");
showHistogram(histo,classCount);
gaussianFill(values,count,10.0,3.0);
RealArray_histogram(values,count,histo,classCount,0.0,20.0);
printf("gaussian:\n");
showHistogram(histo,classCount);
}

int
main(void)
{
test_Real_swap();
test_RealArray_show();
test_RealArray_reverse();
test_RealArray_copy();
test_RealArray_reverseCopy();
test_RealArray_max();
test_RealArray_min();
test_RealArray_ascendingSort();
test_RealArray_descendingSort();
test_RealArray_histogram();
return 0;
}

//----------------------------------------------------------------------------
