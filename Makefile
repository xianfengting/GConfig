
ifndef OUT_DIR_NAME
    OUT_DIR_NAME = out
endif
export OUT_DIR_NAME

out_sub_dirs := gconfig-ncurses

PHONY :=

all : clean gconfig-ncurses
PHONY += all

gconfig-ncurses :
	make -C ./gconfig-ncurses
	cp -r ./gconfig-ncurses/$(OUT_DIR_NAME) ./$(OUT_DIR_NAME)/gconfig-ncurses
PHONY += gconfig-ncurses

clean :
	-rm -r ./$(OUT_DIR_NAME)
	mkdir ./$(OUT_DIR_NAME)
	-cd ./$(OUT_DIR_NAME) && mkdir $(out_sub_dirs)
PHONY += clean

.PHONY : $(PHONY)

