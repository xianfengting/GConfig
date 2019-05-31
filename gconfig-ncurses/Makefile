# SPDX-License-Identifier: GPL-3.0-or-later
# This project is licensed under the Anti-996 License.

CC = cc
CFLAGS = 
ifeq ($(DEBUG),1)
    CC_ARGS := -lpthread -lncurses -g -D _DEBUG=1
else
    CC_ARGS := -lpthread -lncurses
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

include ./parser/Makefile

object_files = main.o screen.o

all : recompile
PHONY := all

c-compile : $(object_files)
	make c-compile-parser
	cd ./$(OUT_DIR_NAME) && $(CC) -o $(PROGRAM_NAME) $(object_files) $(CC_ARGS)
PHONY += c-compile

$(object_files) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $(OUT_DIR_NAME)/$@ $(CC_ARGS)

compile : c-compile
PHONY += compile

clean : 
	-cd ./$(OUT_DIR_NAME) && rm $(PROGRAM_NAME)
	-cd ./$(OUT_DIR_NAME) && rm $(object_files)

recompile : clean compile
PHONY += recompile

.PHONY : $(PHONY)
