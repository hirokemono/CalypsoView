/*
//  tree_view_4_ele_group_viewer.h
//  
//
//  Created by Hiroaki Matsui on 2018/08/19.
*/

#ifndef TREE_VIEW_4_ELE_GROUP_VIEWER_
#define TREE_VIEW_4_ELE_GROUP_VIEWER_

#include "calypso_GTK.h"
#include "kemoviewer_gl.h"
#include "kemoview_gtk_routines.h"
#include "kemoview_gtk_colorsel.h"
#include "tree_views_4_fixed_lists_GTK.h"
#include "t_control_chara_int3_IO.h"
// #include "tree_view_chara_int3_GTK.h"
#include "tree_view_4_viewer_mesh.h"
#include "quicksort_c.h"

#include "view_modifier_glfw.h"

/* prototypes */
void set_ele_group_draw_box(struct kemoviewer_gl_type *kemo_gl,
                            struct group_gtk_menu *ele_group_gmenu);
void init_ele_group_draw_box(struct kemoviewer_gl_type *kemo_gl, GtkWidget *window,
                             struct group_gtk_menu *ele_group_gmenu);
GtkWidget * pack_ele_group_menu_box(struct group_gtk_menu *ele_group_gmenu);

#endif /* tree_view_4_ele_group_viewer */
