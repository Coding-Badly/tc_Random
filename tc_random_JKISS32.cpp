#include <Arduino.h>

// http://www.cs.ucl.ac.uk/staff/d.jones/GoodPracticeRNG.pdf

/* Implementation of a 32-bit KISS generator which uses no multiply
instructions */


static unsigned long x=123456789, y=234567891, z=345678912, w=456789123, c=0;

unsigned long tc_RandomGenerate_JKISS32( void )
{
  long t;

  y ^= (y<<5); y ^= (y>>7); y ^= (y<<22);
  t = z+w+c; z = w; c = t < 0; w = t&2147483647;
  x += 1411392427;

  return x + y + w;
}

/* A poor way to maange the seed but, in the Arduino world, simple is paramount. */

void tc_RandomSeed_JKISS32( unsigned long newseed )
{
  if ( newseed != 0 )
  {
    x = 123456789;
    y = newseed;
    z = 345678912;
    w = 456789123;
    c = 0;
  }
}

