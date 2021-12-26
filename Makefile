################################################################################
# MIT License
#
# Copyright (c) 2021 Alvin Abad
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
################################################################################

# Creat a symlink to this Makefile from a project directory

# Set projects here
PROJECTS	:= ScanNetworks Blink

PLATFORM_INI		:= $(wildcard platformio.ini)
BOARD_ID_FILE		:= $(wildcard BOARD_ID)

.PHONY:	all \
	help \
	create \
	compile \
	compiledb \
	upload \
	monitor \
	flash-firmware \
	list-targets \
	list-boards \
	$(PROJECT_NAME) \
	$(PROJECTS) \
	clean \
	cleanall

help:
	@echo "Usage:"
    ifeq ($(PLATFORM_INI),)
	@echo "    make PROJECT_NAME=projectname create"
	@echo "    make list-boards"
    else
	@echo "    make all"
	@echo "    make compile"
	@echo "    make compiledb"
	@echo "    make upload"
	@echo "    make monitor"
	@echo "    make PORT=device upload"
	@echo "    make PORT=device BIN=file.bin flash-firmware"
	@echo "    make list-targets"
	@echo "    make clean"
	@echo "    make cleanall"
    endif

all:
    ifneq ($(PLATFORM_INI),)
	make clean compile upload
    endif

list-boards:
    ifeq ($(PLATFORM_INI),)
	pio boards
    endif

create:
    ifneq ($(PLATFORM_INI),)
	@echo Project already exists
    else
	@mkdir $(PROJECT_NAME)
	cd $(PROJECT_NAME) && \
		ln -sf ../Makefile && \
		pio project init --board `grep -v '^#' ../BOARD_ID` 
	@echo
	@echo Project '$(PROJECT_NAME)' created
	@echo "    cd to $(PROJECT_NAME)/ and run make"
    endif

compile:
    ifneq ($(PLATFORM_INI),)
	pio run
    endif

compiledb:
    ifneq ($(PLATFORM_INI),)
	pio run --target $@
    endif

flash-firmware: upload

upload:
    ifneq ($(PLATFORM_INI),)
    ifneq ($(PORT),)
	pio run --upload-port $(PORT) --target $@
    else
	pio run --target $@
    endif
    endif

monitor:
	pio device monitor

list-targets:
    ifneq ($(PLATFORM_INI),)
	pio run --list-targets
    endif

clean:
    ifneq ($(PLATFORM_INI),)
	pio run --target clean
    else
	@for app in $(PROJECTS); do \
	    make -C $$app $@; \
	done
    endif

cleanall:
    ifneq ($(PLATFORM_INI),)
	pio run --target cleanall
    else
	@for app in $(PROJECTS); do \
	    make -C $$app $@; \
	done
    endif
