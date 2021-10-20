
PROGRAM_NAME    = blink

.PHONY:	all \
	help \
	init \
	info \
	load \
	reboot \
	clean

help:
	@echo "Usage:"
	@echo "    make clean all"
	@echo "    make info"
	@echo "    make load"
	@echo "    make reboot"

all: init
	cd build && cmake ..
	cd build && make -j4

init:
	mkdir -p build

info:
	sudo picotool info -a

load:
	cd build && sudo picotool load -v $(PROGRAM_NAME).uf2

reboot:
	sudo picotool reboot

clean:
	rm -rf build
