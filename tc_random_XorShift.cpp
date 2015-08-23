#include <Arduino.h>
#include <inttypes.h>

// http://www.jstatsoft.org/v08/i14/paper
// ...Marsaglia's favourite


static uint32_t Seed = 1;

static const int TupleA =  5;  
static const int TupleB = 17;  
static const int TupleC = 13;

unsigned long tc_RandomGenerate_XorShift( void )
{
  uint32_t Y;
  
  Y = Seed;
  
  Y = Y ^ (Y << TupleC);
  Y = Y ^ (Y >> TupleB);
  Y = Y ^ (Y << TupleA);

  Seed = Y;
  
  return( Y );
}

void tc_RandomSeed_XorShift( unsigned long newseed )
{
  if ( newseed != 0 )
    Seed = newseed;
}

