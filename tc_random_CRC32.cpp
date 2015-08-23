#include <Arduino.h>

// http://burtleburtle.net/bob/rand/talksmall.html


static uint32_t Seed = 1;

unsigned long tc_RandomGenerate_CRC32( void )
{
  uint32_t Next;
  unsigned char i;

  Next = Seed;

  for ( i=32; i > 0; --i )
  {
    if ( Next & 1 )
      Next = (Next >> 1) ^ 0xEDB88320;
    else
      Next = (Next >> 1) ^ 0x00000000;
  }

  Seed = Next;

  return( Next );
}

void tc_RandomSeed_CRC32( unsigned long newseed )
{
  if ( newseed != 0 )
    Seed = newseed;
}

