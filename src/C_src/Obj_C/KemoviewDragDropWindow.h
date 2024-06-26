//
//  KemoviewDragDropWindow.h
//  Kemoview_Cocoa
//
//  Created by Hiroaki Matsui on 12/03/03.
//  Copyright 2012 Dept. of Earth and Planetary Science, UC Berkeley. All rights reserved.
//

@import Cocoa;

#import "Kemoview_IO_Controller.h"
#import "KemoViewerObject.h"
#include "Kemoviewer.h"

@interface KemoviewDragDropWindow : NSWindow {
	IBOutlet Kemoview_IO_Controller * _kemoviewIOControl;
    IBOutlet KemoViewerObject *_kmv;
//    int id_window;
}


- (id)init;
- (void) awakeFromNib;
- (BOOL)performDragOperation:(id<NSDraggingInfo>)sender;

- (unsigned int)draggingEntered:(id <NSDraggingInfo>)sender;
- (void)draggingExited:(id <NSDraggingInfo>)sender;

- (void)windowWillClose:(NSNotification *)aNotofication;
- (void)windowDidBecomeKey:(NSNotification *)aNotofication;
@end
