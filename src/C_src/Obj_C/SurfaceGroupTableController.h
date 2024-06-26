//
//  SurfaceGroupTableController.h
//  Kemoview_Cocoa
//
//  Created by Hiroaki Matsui on 10/09/29.
//  Copyright 2010 Department of Geophysical Sciences, University of Chicago. All rights reserved.
//

@import Cocoa;

#import "KemoViewerMetalView.h"
#import "KemoViewerObject.h"
#include "Kemoviewer.h"


@interface SurfaceGroupTableController : NSObject {
	
    IBOutlet KemoViewerMetalView * _metalView;
    IBOutlet KemoViewerObject *_kmv;
	IBOutlet id _surfaceTableView;
	
	NSInteger  NumSurfaceGroup;
	NSMutableArray *SurfaceGroupDisplayNames;
	NSMutableArray *SurfaceGroupDisplayPatchFlags;
	NSMutableArray *SurfaceGroupDisplayWireFlags;
	NSMutableArray *SurfaceGroupDisplayNodeFlags;
	
    CGFloat surfGrpAlpha;
    
	NSString *selectedSurfaceGroupObjectType;

	IBOutlet id _SurfGrpPatchColorItem;
	IBOutlet id _SurfGrpLineColorItem;
	IBOutlet id _SurfGrpNodeColorItem;
	
	IBOutlet NSColorWell *surfGrpPatchColorWell;
	IBOutlet NSColorWell *surfGrpGridColorWell;
	IBOutlet NSColorWell *surfGrpNodeColorWell;
    NSColor *nsSurfGrpPatchColor;
    NSColor *nsSurfGrpGridColor;
    NSColor *nsSurfGrpNodeColor;
}
@property CGFloat surfGrpAlpha;

- (id) init;
- (id) dealloc;

- (void) SetSurfaceGroupLabels:(id)pId;
- (IBAction) ShowAllSurfaceGroupAction:(id)pId;
- (IBAction) HideAllSurfaceGroupAction:(id)pId;

- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView;

- (id)tableView:(NSTableView *)aTableView
objectValueForTableColumn:(NSTableColumn *)aTableColumn
			row:(int)rowIndex;

- (void)tableView:(NSTableView *)atableView
   setObjectValue:(id)object 
   forTableColumn:(NSTableColumn *)tableColumn 
			  row:(int)rowIndex;

- (void)tableView:(NSTableView *)aTableView didClickTableColumn:(NSTableColumn *)tableColumn;

- (void) UpdateSurfaceTable:(struct kemoviewer_type *) kemo_sgl;

- (IBAction)ChooseSurfGrpPatchColorAction:(id)sender;
- (IBAction)ChooseSurfGrpLineColorAction:(id)sender;
- (IBAction)ChooseSurfGrpNodeColorAction:(id)sender;

- (IBAction)SetSurfGrpPatchColorAction:(id)sender;
- (IBAction)SetSurfGrpLineColorAction:(id)sender;
- (IBAction)SetSurfGrpNodeColorAction:(id)sender;

@end
