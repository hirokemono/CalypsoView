/*
 *  kemoview_gtk_mesh_menu.h
 *  Kemoview_Cocoa
 *
 *  Created by Hiroaki Matsui on 12/03/04.
 *  Copyright 2012 Dept. of Earth and Planetary Science, UC Berkeley. All rights reserved.
 *
 */
#ifndef KEMOVIEW_GTK_MESH_MENU_
#define KEMOVIEW_GTK_MESH_MENU_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calypso_GTK.h"
#include "kemoviewer.h"
#include "m_kemoviewer_data.h"
#include "tree_view_4_viewer_mesh.h"
#include "tree_view_4_domain_viewer.h"
#include "tree_view_4_nod_group_viewer.h"
#include "tree_view_4_ele_group_viewer.h"
#include "tree_view_4_surf_group_viewer.h"

#ifdef GLFW3
	#include "view_modifier_glfw.h"
#else
	#include "view_modifier_gtk.h"
#endif


/*  prototypes */
void init_gtk_mesh_menu(struct kemoviewer_type *kemo_sgl, 
                        struct kemoview_mesh_view *mesh_vws, 
                        GtkWidget *window);
GtkWidget *  pack_gtk_mesh_menu(struct kemoview_mesh_view *mesh_vws, GtkWidget *window);

#endif
