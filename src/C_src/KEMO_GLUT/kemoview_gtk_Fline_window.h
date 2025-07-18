/*
 *  kemoview_gtk_Fline_window.h
 *  Kemoview_Cocoa
 *
 *  Created by Hiroaki Matsui on 12/03/04.
 *  Copyright 2012 Dept. of Earth and Planetary Science, UC Berkeley. All rights reserved.
 *
 */
#ifndef KEMOVIEW_GTK_FLINE_WINDOW_
#define KEMOVIEW_GTK_FLINE_WINDOW_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calypso_GTK.h"
#include "kemoviewer_gl.h"
#include "m_kemoviewer_data.h"
#include "kemoview_gtk_fline_selectors.h"
#include "tree_views_4_fixed_lists_GTK.h"
#include "tree_view_viewer_colormap.h"
#include "kemoview_gtk_fileselector.h"
#include "kemoview_gtk_fieldline_menu.h"
#include "kemoview_gtk_evolution_menu.h"

/* prototypes */

void init_fline_window(struct kemoviewer_gl_type *kemo_gl,
                       struct fieldline_gtk_menu *fline_gmenu,
                       GtkWidget *main_window, GtkWidget *itemTEvo);
void replace_fline_frame(struct kemoviewer_gl_type *kemo_gl,
                         struct fieldline_gtk_menu *fline_gmenu,
                         GtkWidget *itemTEvo);
 
void init_tracer_window(struct kemoviewer_gl_type *kemo_gl,
                        struct fieldline_gtk_menu *fline_gmenu,
                        GtkWidget *main_window, GtkWidget *itemTEvo);
void replace_tracer_frame(struct kemoviewer_gl_type *kemo_gl,
                          struct fieldline_gtk_menu *tracer_gmenu,
                          GtkWidget *itemTEvo);

#endif /*  KEMOVIEW_GTK_FLINE_WINDOW_  */
