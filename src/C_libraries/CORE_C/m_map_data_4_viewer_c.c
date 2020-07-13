
/*  m_map_data_4_viewer_c.c */

#include <stdlib.h>
#include "m_map_data_4_viewer_c.h"


void alloc_map_data_s(struct psf_map_data *psf_map_s){
	int i;
	/* allocate memory  xx_map[node #][direction]*/
	psf_map_s->xx_map = (double **)calloc(psf_map_s->nnod_map,sizeof(double *));
	for (i = 0; i < psf_map_s->nnod_map; i++){
		psf_map_s->xx_map[i] = (double *)calloc(3,sizeof(double));
	};
	
	psf_map_s->inod_map = (int *)calloc(psf_map_s->nnod_map,sizeof(int));
	
	/* allocate memory  ie_map[patch #][connection]*/
	psf_map_s->ie_map = (int **)calloc(psf_map_s->nele_map,sizeof(int *));
	for (i = 0; i < psf_map_s->nele_map; i++){
		psf_map_s->ie_map[i] = (int *)calloc(3,sizeof(int));
	};
	
	/* allocate memory  inod_org_map[added #][interpolate #]*/
	psf_map_s->inod_org_map = (int **)calloc(psf_map_s->nnod_add_map,sizeof(int *));
	for (i = 0; i < psf_map_s->nnod_add_map; i++){
		psf_map_s->inod_org_map[i] = (int *)calloc(2,sizeof(int));
	};
	
	/* allocate memory  coef_itp_map[added #][interpolate #]*/
	psf_map_s->coef_itp_map = (double **)calloc(psf_map_s->nnod_add_map,sizeof(double *));
	for (i = 0; i < psf_map_s->nnod_add_map; i++){
		psf_map_s->coef_itp_map[i] = (double *)calloc(2,sizeof(double));
	};
	
	/* allocate memory  d_nod_map[node #][component]*/
	psf_map_s->d_nod_map = (double **)calloc(psf_map_s->nnod_map,sizeof(double *));
	for (i = 0; i < psf_map_s->nnod_map; i++){
		psf_map_s->d_nod_map[i] = (double *)calloc(psf_map_s->ncomptot_map,sizeof(double));
	};
	
	return;
};

void dealloc_map_data_s(struct psf_map_data *psf_map_s){
	int i;
	/* deallocate memory*/
	free(psf_map_s->inod_map);
	
	for (i = 0; i < psf_map_s->nnod_map; i++) free(psf_map_s->xx_map[i]);
	free(psf_map_s->xx_map);
	for (i = 0; i < psf_map_s->nele_map; i++) free(psf_map_s->ie_map[i]);
	free(psf_map_s->ie_map);
	for (i = 0; i < psf_map_s->nnod_map; i++) free(psf_map_s->inod_org_map[i]);
	free(psf_map_s->inod_org_map);
	for (i = 0; i < psf_map_s->nnod_map; i++) free(psf_map_s->coef_itp_map[i]);
	free(psf_map_s->coef_itp_map);
	
	for (i = 0; i < psf_map_s->nnod_map; i++) free(psf_map_s->d_nod_map[i]);
	free(psf_map_s->d_nod_map);
	
	return;
};

