#include <Arduino.h>
#include <inttypes.h>

// http://www.arklyffe.com/main/2010/08/29/xorshift-pseudorandom-number-generator/


static uint16_t Seed = 1;

unsigned long tc_RandomGenerate_XorShift16( void )
{
  uint16_t Next;

  Next = Seed;
  Next = Next ^ (Next <<  1);
  Next = Next ^ (Next >>  1);
  Next = Next ^ (Next << 14);
  Seed = Next;

  return( Next );
}

void tc_RandomSeed_XorShift16( unsigned long newseed )
{
  if ( newseed != 0 )
    Seed = newseed;
}

