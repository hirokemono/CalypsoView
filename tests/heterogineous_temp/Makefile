#
#  Makefile for Kemo's Dynamo toolkit
#    Written by H. Matsui
#
SHELL           = /bin/sh
#
#  directories of Kemo's Dynamo toolkit
#
SRCDIR = /Users/matsui/src_kemo
#
MHDDIR =  $(SRCDIR)/MHD
BUILDDIR= $(SRCDIR)/bin
TESTDIR=  $(SRCDIR)/tests
#
# MPI settings
#
MPICHDIR =    
MPICHLIBDIR = $(MPICHDIR)/lib
MPICHBINDIR = $(MPICHDIR)/bin
MPICHINCDIR = 
MPILIBS =      
#

all: test

test: 
	rm -f *.dat
	$(MPIRUN) -np 2 $(BUILDDIR)/sph_mhd
	echo 'Compare with reference mean square data'
	$(BUILDDIR)/sph_ene_check

clean:
	rm -f *.dat rst_2/rst.*  sph_lm4r64c_2/in.*

distclean: clean
