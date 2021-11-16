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

.PHONY:	all \
	help \
	compile \
	compiledb \
	upload \
	flash-firmware \
	list-targets \
	list-boards \
	clean \
	cleanall

help:
	@echo "Usage:"
	@echo "    make all"
	@echo "    make compile"
	@echo "    make compiledb"
	@echo "    make upload"
	@echo "    make flash-firmware"
	@echo "    make PORT=device upload"
	@echo "    make PORT=device BIN=file.bin flash-firmware"
	@echo "    make list-targets"
	@echo "    make clean"
	@echo "    make cleanall"

all:
	make clean compile upload

list-boards:
	pio boards

compile:
	pio run

compiledb:
	pio run --target $@

flash-firmware: upload

upload:
    ifneq ($(PORT),)
	pio run --upload-port $(PORT) --target $@
    else
	pio run --target $@
    endif

list-targets:
	pio run --list-targets

clean:
	pio run --target clean

cleanall:
	pio run --target cleanall
