PORT		:= /dev/ttyACM0
SRCDIR		:= $(wildcard src)

.PHONY:	all \
	help \
	upload \
	reset \
	check \
	list-ports \
	ls \
	$(PORTS) \
	clean


help:
	@echo Usage:
	@echo "    make check"
	@echo "    make ls"
	@echo "    make reset"
    ifneq ($(SRCDIR),)
	@echo "    make upload"
	@echo "    make PORT=/dev/ttyUSB0 upload"
    endif

all:

$(PORTS):
	@echo $@

ls:
	ampy -p $(PORT) ls -l -r

reset:
	ampy -p $(PORT) reset --hard

check:
	rshell --list

upload:
    ifneq ($(SRCDIR),)
	ampy -p $(PORT) put src /
    endif

clean:
