/*
//  t_control_data_PVR_ctl_list.c
//  
//
//  Created by Hiroaki Matsui on 2018/08/07.
*/

#include "t_control_data_PVR_ctl_list.h"


struct volume_rendering_ctl_c * init_volume_rendering_ctl_c(){
    struct volume_rendering_ctl_c *v_render_c;
    if((v_render_c = (struct volume_rendering_ctl_c *) malloc(sizeof(struct volume_rendering_ctl_c))) == NULL) {
        printf("malloc error for volume_rendering_ctl_c \n");
        exit(0);
    }
	v_render_c->fname_pvr_ctl = (char *)calloc(KCHARA_C, sizeof(char));
	v_render_c->pvr_c = init_pvr_ctl_c();
	return v_render_c;
};

void dealloc_volume_rendering_ctl_c(struct volume_rendering_ctl_c *v_render_c){
	dealloc_pvr_ctl_c(v_render_c->pvr_c);
	free(v_render_c->fname_pvr_ctl);
	return;
};

int read_volume_rendering_ctl_c(FILE *fp, char buf[LENGTHBUF], 
			const char *label, struct volume_rendering_ctl_c *v_render_c){
	
	if(right_begin_flag_c(buf, label) > 0){
		read_pvr_ctl_c(fp, buf, label, v_render_c->pvr_c);
	} else if(right_file_flag_c(buf, label)){
		v_render_c->iflag_pvr_ctl = read_file_flag_c(buf, v_render_c->fname_pvr_ctl);
	} else {
		v_render_c->iflag_pvr_ctl = 0;
	};
	return abs(v_render_c->iflag_pvr_ctl);
};

int write_volume_rendering_ctl_c(FILE *fp, int level, const char *label, 
			struct volume_rendering_ctl_c *v_render_c){
	
	if(v_render_c->iflag_pvr_ctl == 1){
		level = write_pvr_ctl_c(fp, level, label, v_render_c->pvr_c);
		fprintf(fp, "!\n");
	} else if(v_render_c->iflag_pvr_ctl == -1){
		write_file_flag_for_ctl_c(fp, level, label, v_render_c->fname_pvr_ctl);
	};
	return level;
};

void read_volume_rendering_ctl_file_c(char buf[LENGTHBUF], struct volume_rendering_ctl_c *v_render_c){
	if(v_render_c->iflag_pvr_ctl == -1){
		read_pvr_ctl_file_c(v_render_c->fname_pvr_ctl, buf, v_render_c->pvr_c);
	};
 	return;
};

void write_volume_rendering_ctl_file_c(struct volume_rendering_ctl_c *v_render_c){
	if(v_render_c->iflag_pvr_ctl == -1){
		write_pvr_ctl_file_c(v_render_c->fname_pvr_ctl, v_render_c->pvr_c);
	};
 	return;
};



void init_PVR_ctl_list(struct PVR_ctl_list *head){
    head->v_render_c = NULL;
	head->_prev = NULL;
	head->_next = NULL;
	return;
};

struct PVR_ctl_list *add_PVR_ctl_list_after(struct PVR_ctl_list *current){
	struct PVR_ctl_list *added;
	struct PVR_ctl_list *old_next;
	
	if ((added = (struct PVR_ctl_list *) malloc(sizeof(struct PVR_ctl_list))) == NULL) {
	printf("malloc error\n");
	exit(0);
	}
	added->v_render_c = init_volume_rendering_ctl_c();
	
	/* replace from  current -> next to current -> new -> next */
	old_next= current->_next;
	current->_next = added;
	added->_next = old_next;		
	if (old_next != NULL) old_next->_prev = added;
	added->_prev = current;
	
	return added;
};

void delete_PVR_ctl_list(struct PVR_ctl_list *current){
    struct PVR_ctl_list *old_prev = current->_prev;
	struct PVR_ctl_list *old_next = current->_next;
	
	dealloc_volume_rendering_ctl_c(current->v_render_c);
    free(current->v_render_c);
	free(current);
	
    old_prev->_next = old_next;
    if (old_next != NULL) old_next->_prev = old_prev;
	return;
};
void clear_PVR_ctl_list(struct PVR_ctl_list *head){
	while (head->_next != NULL) {
		delete_PVR_ctl_list(head->_next);
	}
	return;
};


int count_PVR_ctl_list(struct PVR_ctl_list *head){
	int num = 0;
	head = head->_next;
	while (head != NULL){
		head = head->_next;
		num = num + 1;
	};
	return num;
};

struct PVR_ctl_list *set_PVR_ctl_list_pointer(int index, struct PVR_ctl_list *head){
    int num = 0;
    head = head->_next;
    while (head != NULL){
        if(num == index) break;
        head = head->_next;
        num = num + 1;
    };
    if(head == NULL) printf("array does not exist at index %d of %d.\n", index, num);
    return head;
};


void rename_PVR_subfile_list(struct PVR_ctl_list *head){
    head = head->_next;
	while (head != NULL){
        if(head->v_render_c->iflag_pvr_ctl == -1){
            strcat(head->v_render_c->fname_pvr_ctl, "_2");
        };
		rename_pvr_ctl_subfiles(head->v_render_c->pvr_c);
		head = head->_next;
	};
	return;
};

void read_PVR_subfile_list(char buf[LENGTHBUF], struct PVR_ctl_list *head){
    head = head->_next;
	while (head != NULL){
		read_volume_rendering_ctl_file_c(buf, head->v_render_c);
		head = head->_next;
	};
	return;
};

void write_PVR_subfile_list(struct PVR_ctl_list *head){
    head = head->_next;
	while (head != NULL){
		write_volume_rendering_ctl_file_c(head->v_render_c);
		head = head->_next;
	};
	return;
};

int read_PVR_ctl_list(FILE *fp, char buf[LENGTHBUF], const char *label, 
			struct PVR_ctl_list *head){
	int iflag = 0;
	int icou = 0;
	
    if(find_control_array_flag_c(buf, label) == 0) return 0;
    if(head->v_render_c != NULL) return 0;
	
	skip_comment_read_line(fp, buf);
	while(find_control_end_array_flag_c(buf, label) == 0){
		head = add_PVR_ctl_list_after(head);
		iflag = read_volume_rendering_ctl_c(fp, buf, label, head->v_render_c);
		icou = icou + iflag;
		skip_comment_read_line(fp, buf);
	};
	return icou;
};

int write_PVR_ctl_list(FILE *fp, int level, const char *label, 
			struct PVR_ctl_list *head){
	if(count_PVR_ctl_list(head) == 0) return level;
	fprintf(fp, "!\n");
	level = write_array_flag_for_ctl_c(fp, level, label);
    head = head->_next;
	
	while (head != NULL) {	/* Go through null pointer*/
		level = write_volume_rendering_ctl_c(fp, level, label, head->v_render_c);
		head = head->_next;
	}
	level = write_end_array_flag_for_ctl_c(fp, level, label);
	return level;
};
