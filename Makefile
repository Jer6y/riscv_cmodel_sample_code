
SRC:=./src
BUILD:=./build


CROSS_COMPILE:= riscv64-unknown-elf-
CFLAGS:= -I./include	-mcmodel=medany\
	 -O3 -g -ggdb3 -Wall -Werror -fno-builtin -fno-stack-protector \
                  -ffreestanding -fno-common -nostdlib

CC:= ${CROSS_COMPILE}gcc
LD:= ${CROSS_COMPILE}ld
OBJCOPY := ${CROSS_COMPILE}objcopy

SRC_FILE := $(shell find ${SRC} -name "*.S")
SRC_FILE += $(shell find ${SRC} -name "*.c")

OBJS := $(patsubst ${SRC}/%.c,${BUILD}/%.o,${SRC_FILE})
OBJS := $(patsubst ${SRC}/%.S,${BUILD}/%.o,${OBJS})


dumpbin: all
	${OBJCOPY} -O binary main main.bin



all : ${OBJS} riscv.lds
	${LD} -T riscv.lds ${OBJS} -o main

run : dumpbin
	qemu-system-riscv64 -nographic -smp 1 -kernel main.bin -m 128M -machine virt

${BUILD}/%.o:${SRC}/%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@
	

${BUILD}/%.o:${SRC}/%.S
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

debug:
	@echo ${OBJS}

clean:
	@rm -rf ${BUILD}
	@rm -rf main*

.PHONY: clean all dumpbin run
