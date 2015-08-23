/*==============================================================================

  tc_random.h - Random number generators for tiny processors

  Copyright 2015 Rowdy Dog Software.

  This file is part of Arduino-Tiny.

  Arduino-Tiny is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or (at your
  option) any later version.

  Arduino-Tiny is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
  License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Arduino-Tiny.  If not, see <http://www.gnu.org/licenses/>.

==============================================================================*/

#ifndef tc_random_h
#define tc_random_h


/*=============================================================================
  Random number generation
=============================================================================*/

__attribute__((always_inline, unused)) static inline 
unsigned long tc_RandomGenerate_Libc( void ) 
{ 
  return( random() ); 
}

__attribute__((always_inline, unused)) static inline 
void tc_RandomSeed_Libc( unsigned long newseed )
{
  srandom( newseed );
}

unsigned long tc_RandomGenerate_XorShift( void );
void tc_RandomSeed_XorShift( unsigned long newseed );

unsigned long tc_RandomGenerate_XorShift16( void );
void tc_RandomSeed_XorShift16( unsigned long newseed );

unsigned long tc_RandomGenerate_CRC32( void );
void tc_RandomSeed_CRC32( unsigned long newseed );

unsigned long tc_RandomGenerate_JKISS32( void );
void tc_RandomSeed_JKISS32( unsigned long newseed );


#endif
