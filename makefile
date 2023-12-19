# Makefile for Linux


all: euler-001 euler-002 euler-003 euler-004 euler-005 euler-006 euler-007 euler-008 euler-009 euler-010 euler-011 euler-012 euler-013 euler-014 euler-015 euler-016


setup:
	@mkdir -p bin


euler-001: setup src/euler-001.c
	c99 src/euler-001.c -o bin/euler-001.bin -Wall -Wextra -pedantic


euler-002: setup src/euler-002.c
	c99 src/euler-002.c -o bin/euler-002.bin -Wall -Wextra -pedantic


euler-003: setup src/euler-003.c
	c99 src/euler-003.c -o bin/euler-003.bin -Wall -Wextra -pedantic -lm


euler-004: setup src/euler-004.c
	c99 src/euler-004.c -o bin/euler-004.bin -Wall -Wextra -pedantic


euler-005: setup src/euler-005.c
	c99 src/euler-005.c -o bin/euler-005.bin -Wall -Wextra -pedantic


euler-006: setup src/euler-006.c
	c99 src/euler-006.c -o bin/euler-006.bin -Wall -Wextra -pedantic


euler-007: setup src/euler-007.c
	c99 src/euler-007.c -o bin/euler-007.bin -Wall -Wextra -pedantic -lm


euler-008: setup src/euler-008.c
	c99 src/euler-008.c -o bin/euler-008.bin -Wall -Wextra -pedantic


euler-009: setup src/euler-009.c
	c99 src/euler-009.c -o bin/euler-009.bin -Wall -Wextra -pedantic


euler-010: setup src/euler-010.c
	c99 src/euler-010.c -o bin/euler-010.bin -Wall -Wextra -pedantic -lm


euler-011: setup src/euler-011.c
	c99 src/euler-011.c -o bin/euler-011.bin -Wall -Wextra -pedantic


euler-012: setup src/euler-012.c
	c99 src/euler-012.c -o bin/euler-012.bin -Wall -Wextra -pedantic -lm


euler-013: setup src/euler-013.c
	c99 src/euler-013.c -o bin/euler-013.bin -Wall -Wextra -pedantic


euler-014: setup src/euler-014.c
	c99 src/euler-014.c -o bin/euler-014.bin -Wall -Wextra -pedantic


euler-015: setup src/euler-015.c
	c99 src/euler-015.c -o bin/euler-015.bin -Wall -Wextra -pedantic


euler-016: setup src/euler-016.c
	c99 src/euler-016.c -o bin/euler-016.bin -Wall -Wextra -pedantic


lint:
	@cpplint --quiet \
		--linelength=120 \
		--filter=-legal/copyright,-whitespace/braces,-whitespace/comments,-readability/casting,-runtime/int \
		src/euler-001.c \
		src/euler-002.c \
		src/euler-003.c \
		src/euler-004.c \
		src/euler-005.c \
		src/euler-006.c \
		src/euler-007.c \
		src/euler-008.c \
		src/euler-009.c \
		src/euler-010.c \
		src/euler-011.c \
		src/euler-012.c \
		src/euler-013.c \
		src/euler-014.c \
		src/euler-015.c \
		src/euler-016.c


clean:
	@rm *.bin -f
	@rm *.exe -f
	@rm *.obj -f
	@rm bin/*
