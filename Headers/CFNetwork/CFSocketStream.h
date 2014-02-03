/* CoreFoundation.h
   
   Copyright (C) 2014 Free Software Foundation, Inc.
   
   Written by: Lubos Dolezel
   Date: February, 2014
   
   This file is part of CoreNetwork.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.         See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/ 

#ifndef __CFNETWORK_CFSOCKETSTREAM_H__
#define __CFNETWORK_CFSOCKETSTREAM_H__

#include <CoreFoundation/CFStream.h>

// TODO: many more declarations

#if OS_API_VERSION(MAC_OS_X_VERSION_10_2, GS_API_LATEST)
CF_EXPORT const CFStringRef kCFStreamPropertyShouldCloseNativeSocket;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_3, GS_API_LATEST)
CF_EXPORT void
CFStreamCreatePairWithSocket (CFAllocatorRef alloc, CFSocketNativeHandle sock,
                              CFReadStreamRef *readStream,
                              CFWriteStreamRef *writeStream);
#endif

#endif /* __CFNETWORK_CFSOCKETSTREAM_H__ */

