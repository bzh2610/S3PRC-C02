//----------------------------------------------------------------------------

#include "mathematics.h"

double
Math_sqrt(double x)
{
if(x<=0.0)
  { return 0.0; }
double y=x;
for(;;)
  {
  const double prev=y;
  y=0.5*(y+x/y);
  if(prev==y)
    { break; }
  }
return y;
}

double
Math_sin(double x)
{
while(x>=MATH_PI)
  { x-=2.0*MATH_PI; }
while(x<-MATH_PI)
  { x+=2.0*MATH_PI; }
const double x2=x*x;
double numerator=x;
double denominator=1.0;
double y=numerator/denominator;
for(int k=3;;k+=2)
  {
  const double prev=y;
  numerator*=-x2;
  denominator*=(k-1.0)*k;
  y+=numerator/denominator;
  if(prev==y)
    { break; }
  }
return y;
}

double
Math_log(double x)
{
if(x<=0.0)
  { return -1.0; }
const double s=(x-1.0)/(x+1.0);
const double s2=s*s;
double numerator=2.0*s;
double denominator=1.0;
double y=numerator/denominator;
for(int k=3;;k+=2)
  {
  const double prev=y;
  numerator*=s2;
  denominator+=2.0;
  y+=numerator/denominator;
  if(prev==y)
    { break; }
  }
return y;
}

//----------------------------------------------------------------------------
