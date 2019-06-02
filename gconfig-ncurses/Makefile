# SPDX-License-Identifier: GPL-3.0-or-later
# This project is licensed under the Anti-996 License.

CC = cc
CFLAGS = 
ifeq ($(DEBUG),1)
    CC_ARGS = -lpthread -lncurses -g -D _DEBUG=1
else
    CC_ARGS = -lpthread -lncurses
endif
#ifeq ($(ENABLE_SECOND_LEVEL_CODE),1)
#    CC_ARGS += -D _ENABLE_SECOND_LEVEL_CODE=1
#endif
ifndef PROGRAM_NAME
    PROGRAM_NAME = gconfig-ncurses
endif
ifndef OUT_DIR_NAME
    OUT_DIR_NAME = out
endif
object_files :=
out_sub_dirs :=
export CC
export CFLAGS
export CC_ARGS
export PROGRAM_NAME
export OUT_DIR_NAME
export object_files

# define call-sub-makefile-find-object-files
# 	make -C $(1)
# endef

PHONY :=

include ./code-parser/Makefile
object_files += main.o screen.o util.o

all : recompile
PHONY += all

# find-object-files :
# 	$(call call-sub-makefile-find-object-files, parser/)
# 	object_files += main.o screen.o
# 	found_object_files = 1
# PHONY += find-object-files

before-c-compile :
PHONY += before-c-compile

make-out-dirs :
	-mkdir ./$(OUT_DIR_NAME)
	-cd ./$(OUT_DIR_NAME) && mkdir $(out_sub_dirs)
PHONY += make-out-dirs

c-compile : $(object_files)
	cd ./$(OUT_DIR_NAME) && $(CC) -o $(PROGRAM_NAME) $(object_files) $(CC_ARGS)
PHONY += c-compile

$(object_files) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $(OUT_DIR_NAME)/$@ $(CC_ARGS)

compile : make-out-dirs before-c-compile c-compile
PHONY += compile

clean :
	-cd ./$(OUT_DIR_NAME) && rm $(PROGRAM_NAME)
	-cd ./$(OUT_DIR_NAME) && rm $(object_files)
	-rm -r ./$(OUT_DIR_NAME)
PHONY += clean

recompile : clean compile
PHONY += recompile

.PHONY : $(PHONY)
