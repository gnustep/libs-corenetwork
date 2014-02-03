/* GSPrivate.h
   
   Copyright (C) 2014 Free Software Foundation, Inc.
   
   This file is part of GNUstep CoreNetwork library.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef __GSPRIVATE_H__
#define __GSPRIVATE_H__

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFRuntime.h>
#include "CoreFoundation/CFLocale.h"
#include "CoreFoundation/CFString.h"
#include "CoreFoundation/CFStringEncodingExt.h"



#if (defined(__GNUC__) && (__GNUC__ >= 4)) || defined(__clang__)
# define GS_PRIVATE __attribute__ ((visibility ("hidden")))
#else
# define GS_PRIVATE
#endif

struct __CFConstantString
{
  CFRuntimeBase  _parent;
  void          *_contents;
  CFIndex        _count;
  CFHashCode     _hash;
  CFAllocatorRef _deallocator;
};

#if defined (_WIN32)
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#define CONST_STRING_DECL(var, str) \
  static struct __CFConstantString __ ## var ## __ = \
    { {0, 0, {1, 0, 0}}, (void*)str, sizeof(str) - 1, 0, NULL }; \
  DLL_EXPORT const CFStringRef var = (CFStringRef) & __ ## var ## __;

#endif /* __GSPRIVATE_H__ */
