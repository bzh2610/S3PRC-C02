//----------------------------------------------------------------------------

#include "mathematics.h"

#include <stdlib.h>
#include <time.h>

double // random value in [0.0,1.0)
Random_uniform(void)
{
static unsigned int seed=0;
if(!seed)
  { seed=(unsigned int)time(NULL); srand(seed); }
return rand()/(RAND_MAX+1.0);
}

double // random value with mean 0.0 and standard-deviation 1.0
Random_gaussian(void)
{
const double r1=Random_uniform();
const double r2=Random_uniform();
return Math_sin(2.0*MATH_PI*r1)*
       Math_sqrt(-2.0*Math_log(1.0-r2)); // Box-Muller method
}

//----------------------------------------------------------------------------
