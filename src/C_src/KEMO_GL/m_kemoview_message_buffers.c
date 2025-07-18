/*
//  m_kemoview_message_buffers.c
//  
//
//  Created by Hiroaki Matsui on 11/26/23.
*/

#include "m_kemoview_message_buffers.h"

struct MESSAGE_buffers * init_MESSAGE_buffers(void)
{
    struct MESSAGE_buffers *MESSAGE_bufs = (struct MESSAGE_buffers *) malloc(sizeof(struct MESSAGE_buffers));
    if(MESSAGE_bufs == NULL){
        printf("malloc error in MESSAGE_buffers \n");
        exit(0);
    };

    int n_point = count_colorbar_box_buffer(IONE, 128);
    MESSAGE_bufs->cbar_buf =      init_strided_buffer(n_point);

    MESSAGE_bufs->cbar_min_buf =  alloc_line_text_image(IWIDTH_TXT, IHIGHT_TXT, (ITWO * ITHREE), NCHARA_CBOX);
    MESSAGE_bufs->cbar_max_buf =  alloc_line_text_image(IWIDTH_TXT, IHIGHT_TXT, (ITWO * ITHREE), NCHARA_CBOX);
    MESSAGE_bufs->cbar_zero_buf = alloc_line_text_image(IWIDTH_TXT, IHIGHT_TXT, (ITWO * ITHREE), NCHARA_CBOX);

    MESSAGE_bufs->timelabel_buf = alloc_line_text_image(IWIDTH_TLABEL, IHIGHT_TXT, (ITWO * ITHREE), NCHARA_CBOX);
    MESSAGE_bufs->message_buf =   alloc_line_text_image(IWIDTH_MSG, IHIGHT_MSG,    (ITWO * ITHREE), NCHARA_MSG);
    return MESSAGE_bufs;
}

void dealloc_MESSAGE_buffers(struct MESSAGE_buffers *MESSAGE_bufs)
{
    dealloc_strided_buffer(MESSAGE_bufs->cbar_buf);
    dealloc_line_text_image(MESSAGE_bufs->cbar_min_buf);
    dealloc_line_text_image(MESSAGE_bufs->cbar_max_buf);
    dealloc_line_text_image(MESSAGE_bufs->cbar_zero_buf);

    dealloc_line_text_image(MESSAGE_bufs->timelabel_buf);
    dealloc_line_text_image(MESSAGE_bufs->message_buf);
    free(MESSAGE_bufs);
};


void select_colorbar_box_buffer(int iflag_retina, int nx_win, int ny_win,
                                float text_color[4], float bg_color[4],
                                struct kemoview_mul_psf *kemo_mul_psf,
                                struct kemoview_fline *kemo_fline,
                                struct kemoview_tracer *kemo_tracer,
                                struct MESSAGE_buffers *MESSAGE_bufs,
                                struct cbar_work *cbar_wk){
    int i;
    MESSAGE_bufs->cbar_buf->num_nod_buf = 0;
    MESSAGE_bufs->cbar_min_buf->vertex->num_nod_buf =  0;
    MESSAGE_bufs->cbar_max_buf->vertex->num_nod_buf =  0;
    MESSAGE_bufs->cbar_zero_buf->vertex->num_nod_buf = 0;
    
    if(kemo_fline->fline_m->iflag_draw_cbar > 0){
        const_colorbar_box_buffer(iflag_retina, nx_win, ny_win,
                                  text_color, bg_color,
                                  kemo_fline->fline_m, cbar_wk,
                                  MESSAGE_bufs->cbar_buf,
                                  MESSAGE_bufs->cbar_min_buf,
                                  MESSAGE_bufs->cbar_max_buf,
                                  MESSAGE_bufs->cbar_zero_buf);
        return;
    }
    
    if(kemo_tracer->tracer_m->iflag_draw_cbar > 0){
        const_colorbar_box_buffer(iflag_retina, nx_win, ny_win,
                                  text_color, bg_color,
                                  kemo_tracer->tracer_m, cbar_wk,
                                  MESSAGE_bufs->cbar_buf,
                                  MESSAGE_bufs->cbar_min_buf,
                                  MESSAGE_bufs->cbar_max_buf,
                                  MESSAGE_bufs->cbar_zero_buf);
        return;
    }
    
    for(i=0; i< kemo_mul_psf->psf_a->nmax_loaded; i++){
        if(kemo_mul_psf->psf_a->iflag_loaded[i] != 0
           && kemo_mul_psf->psf_m[i]->iflag_draw_cbar > 0) {
            const_colorbar_box_buffer(iflag_retina, nx_win, ny_win,
                                      text_color, bg_color,
                                      kemo_mul_psf->psf_m[i], cbar_wk,
                                      MESSAGE_bufs->cbar_buf,
                                      MESSAGE_bufs->cbar_min_buf,
                                      MESSAGE_bufs->cbar_max_buf,
                                      MESSAGE_bufs->cbar_zero_buf);
            break;
        };
    };
    return;
};

void const_message_buffers(int iflag_retina, int nx_win, int ny_win,
                           float text_color[4], float bg_color[4],
                           struct kemoview_mul_psf *kemo_mul_psf,
                           struct kemoview_fline *kemo_fline,
                           struct kemoview_tracer *kemo_tracer,
                           struct kemoview_mesh *kemo_mesh,
                           struct view_element *view_s,
                           struct MESSAGE_buffers *MESSAGE_bufs){
    struct cbar_work *cbar_wk = (struct cbar_work *) malloc(sizeof(struct cbar_work));
    if(cbar_wk == NULL){
        printf("malloc error for cbar_work\n");
        exit(0);
    }

    select_colorbar_box_buffer(iflag_retina, nx_win, ny_win,
                               text_color, bg_color,
                               kemo_mul_psf, kemo_fline, kemo_tracer,
                               MESSAGE_bufs, cbar_wk);
    
    const_timelabel_buffer(view_s->iflag_retina,
                           view_s->nx_frame, view_s->ny_frame,
                           kemo_mesh->text_color, kemo_mesh->bg_color,
                           kemo_mul_psf->psf_a, 
                           MESSAGE_bufs->timelabel_buf);
    
    const_message_buffer(view_s->iflag_retina,
                         view_s->nx_frame, view_s->ny_frame,
                         MESSAGE_bufs->message_buf->vertex,
                         MESSAGE_bufs->message_buf);

    free(cbar_wk);
    return;
};


