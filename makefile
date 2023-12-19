# Makefile for Linux


all: euler-001 euler-002 euler-003 euler-004 euler-005 euler-006 euler-007 euler-008 euler-009 euler-010 euler-011 euler-012 euler-013


euler-001: euler-001.c
	c99 euler-001.c -o euler-001.bin -Wall -Wextra -pedantic


euler-002: euler-002.c
	c99 euler-002.c -o euler-002.bin -Wall -Wextra -pedantic


euler-003: euler-003.c
	c99 euler-003.c -o euler-003.bin -Wall -Wextra -pedantic -lm


euler-004: euler-004.c
	c99 euler-004.c -o euler-004.bin -Wall -Wextra -pedantic


euler-005: euler-005.c
	c99 euler-005.c -o euler-005.bin -Wall -Wextra -pedantic


euler-006: euler-006.c
	c99 euler-006.c -o euler-006.bin -Wall -Wextra -pedantic


euler-007: euler-007.c
	c99 euler-007.c -o euler-007.bin -Wall -Wextra -pedantic -lm


euler-008: euler-008.c
	c99 euler-008.c -o euler-008.bin -Wall -Wextra -pedantic


euler-009: euler-009.c
	c99 euler-009.c -o euler-009.bin -Wall -Wextra -pedantic


euler-010: euler-010.c
	c99 euler-010.c -o euler-010.bin -Wall -Wextra -pedantic -lm


euler-011: euler-011.c
	c99 euler-011.c -o euler-011.bin -Wall -Wextra -pedantic


euler-012: euler-012.c
	c99 euler-012.c -o euler-012.bin -Wall -Wextra -pedantic -lm


euler-013: euler-013.c
	c99 euler-013.c -o euler-013.bin -Wall -Wextra -pedantic -lm


lint:
	@cpplint --quiet \
		--linelength=120 \
		--filter=-legal/copyright,-whitespace/braces,-whitespace/comments,-readability/casting \
		euler-001.c \
		euler-002.c \
		euler-003.c \
		euler-004.c \
		euler-005.c \
		euler-006.c \
		euler-007.c \
		euler-009.c \
		euler-010.c \
		euler-011.c \
		euler-012.c \
		euler-013.c


clean:
	@rm *.bin -f
	@rm *.exe -f
	@rm *.obj -f
