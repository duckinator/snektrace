CFLAGS :=
LDFLAGS := -lpython3.8
INCLUDES := -I/usr/include/python3.8

all: snektrace

run: snektrace
	@./snektrace testmod

snektrace:
	@clang ${CFLAGS} ${LDFLAGS} ${INCLUDES} snektrace.c -o snektrace

compile_flags.txt: Makefile
	echo ${CFLAGS} ${LDFLAGS} ${INCLUDES} | sed 's/ /\n/g' > compile_flags.txt

clean:
	@rm -f snektrace

.PHONY: clean
