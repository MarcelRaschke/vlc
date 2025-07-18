/*****************************************************************************
 * VLCApplication.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2002-2016 VLC authors and VideoLAN
 *
 * Authors: Derk-Jan Hartman <hartman at videolan dot org>
 *          Felix Paul Kühne <fkuehne at videolan dot org>
 *          David Fuhrmann <david dot fuhrmann at googlemail dot com>
 *          Pierre d'Herbemont <pdherbemont # videolan org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#import <Cocoa/Cocoa.h>

typedef struct intf_thread_t intf_thread_t;

/*****************************************************************************
 * VLCApplication interface
 *****************************************************************************/

@interface VLCApplication : NSApplication

/**
 * The current VLC App icon image
 * 
 * This is adjusted accordingly to return the special
 * image on occasions like christmas. Contrary to the
 * applicationIconImage property though, the image is
 * not scaled down, so it remains suitable when it is
 * displayed for example in the About window.
 * 
 * Must be called from the main thread only.
 */
@property(strong, readonly) NSImage *vlcAppIconImage;
@property(assign, readonly) BOOL winterHolidaysTheming;

- (void)setIntf:(intf_thread_t *)intf;
@end
