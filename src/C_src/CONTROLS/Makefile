#
#
#

KEMO_CTL_C_DIR = $$(C_SRCDIR)/CONTROLS
CURRENTDIR = $(shell pwd)
SRC_CTL_C = $(shell ls *.c)
INC_CTL_C = $(addsuffix .h,$(basename $(SRC_CTL_C)) )
OBJ_CTL_C = $(addsuffix .o,$(basename $(SRC_CTL_C)) )

#
#  ------------------------------------------------------------------
#

dir_list:
	@echo 'KEMO_CTL_C_DIR =  $(KEMO_CTL_C_DIR)'      >> $(MAKENAME)

lib_name:

libtarget:

lib_archve: libtarget
	@echo '	''$$(AR)' '$$(ARFLUGS)' rcsv '$$@' '$$(OBJ_CTL_C)' >> $(MAKENAME)


mod_list:
	@echo  OBJ_CTL_C=  \\ >> $(MAKENAME)
	@echo  $(OBJ_CTL_C)   >> $(MAKENAME)
	@echo   >> $(MAKENAME)


depends:
	@echo 'Construct compile list in C_src/CONTROLS'
	@echo '#' > $(MAKENAME).tmp
	@for sources in $(SRC_CTL_C) ; do \
		( \
		cd $(MAKEDIR); \
		$(CC) $(DEPFLAGS) $(OPTFLAGS_GL) $(C_INCLUDE) $(CURRENTDIR)/$$sources >> $(MAKENAME).tmp; \
		echo '	''$$(CC)' -c '$$(OPTFLAGS) $$(C_INCLUDE) $$<' >> $(MAKENAME).tmp \
		) \
	done
	@sed -e 's@'$(MHDDIR)/C_src'@'$$\(C_SRCDIR\)'@g' $(MAKENAME).tmp >> $(MAKENAME).depends
	@rm $(MAKENAME).tmp

clean:
	rm -f *.o $(TARGET) *.mod *~
