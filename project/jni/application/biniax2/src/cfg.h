/******************************************************************************
BINIAX CONFIG DEFINITIONS
COPYRIGHT JORDAN TUZSUZOV, (C) 2005-2009

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

LICENSE ORIGIN : http://www.gzip.org/zlib/zlib_license.html

For complete product license refer to LICENSE.TXT file

******************************************************************************/

#ifndef _BNX_CFG_H
#define _BNX_CFG_H

/******************************************************************************
INCLUDES
******************************************************************************/

#include "inc.h"

/******************************************************************************
FUNCTIONS
******************************************************************************/

BNX_BOOL cfgInit();

BNX_BOOL cfgGetSound();
BNX_BOOL cfgGetMusic();
BNX_BOOL cfgGetFullscreen();
BNX_BOOL cfgGetTouch();

void cfgSetSound( BNX_BOOL v );
void cfgSetMusic( BNX_BOOL v );
void cfgSetFullscreen( BNX_BOOL v );
void cfgSetTouch( BNX_BOOL v );

#endif
