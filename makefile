# Makefile for Linux

CFLAGS += -std=c99 -Wall -Wextra -pedantic -Werror
CFLAGS += -fsanitize=address,undefined
CFLAGS += -Wmissing-declarations -g


all: euler-001 euler-002 euler-003 euler-004 euler-005 euler-006 euler-007 euler-008 euler-009 euler-010 euler-011 euler-012 euler-013 euler-014 euler-015 euler-016


setup:
	@mkdir -p bin


euler-001: setup src/euler-001.c
	$(CC) $(CFLAGS) src/euler-001.c -o bin/euler-001.bin


euler-002: setup src/euler-002.c
	$(CC) $(CFLAGS) src/euler-002.c -o bin/euler-002.bin


euler-003: setup src/euler-003.c
	$(CC) $(CFLAGS) src/euler-003.c -o bin/euler-003.bin -lm


euler-004: setup src/euler-004.c
	$(CC) $(CFLAGS) src/euler-004.c -o bin/euler-004.bin


euler-005: setup src/euler-005.c
	$(CC) $(CFLAGS) src/euler-005.c -o bin/euler-005.bin


euler-006: setup src/euler-006.c
	$(CC) $(CFLAGS) src/euler-006.c -o bin/euler-006.bin


euler-007: setup src/euler-007.c
	$(CC) $(CFLAGS) src/euler-007.c -o bin/euler-007.bin -lm


euler-008: setup src/euler-008.c
	$(CC) $(CFLAGS) src/euler-008.c -o bin/euler-008.bin


euler-009: setup src/euler-009.c
	$(CC) $(CFLAGS) src/euler-009.c -o bin/euler-009.bin


euler-010: setup src/euler-010.c
	$(CC) $(CFLAGS) src/euler-010.c -o bin/euler-010.bin -lm


euler-011: setup src/euler-011.c
	$(CC) $(CFLAGS) src/euler-011.c -o bin/euler-011.bin


euler-012: setup src/euler-012.c
	$(CC) $(CFLAGS) src/euler-012.c -o bin/euler-012.bin -lm


euler-013: setup src/euler-013.c
	cp src/euler-013.txt bin/
	$(CC) $(CFLAGS) src/euler-013.c -o bin/euler-013.bin


euler-014: setup src/euler-014.c
	$(CC) $(CFLAGS) src/euler-014.c -o bin/euler-014.bin


euler-015: setup src/euler-015.c
	$(CC) $(CFLAGS) src/euler-015.c -o bin/euler-015.bin


euler-016: setup src/euler-016.c
	$(CC) $(CFLAGS) src/euler-016.c -o bin/euler-016.bin


clang-001: setup src/euler-001.c
	clang $(CFLAGS) src/euler-001.c -o bin/euler-001.bin


lint:
	@cpplint --quiet \
		--linelength=120 \
		--filter=-legal/copyright,-whitespace/braces,-whitespace/comments,-whitespace/newline,-readability/casting,-runtime/int \
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
	@cppcheck --std=c99 --quiet src/


# Formats all *.c files based on the format specified in .clang-format
format:
	clang-format -i src/*.c


clean:
	@rm *.bin -f
	@rm *.exe -f
	@rm *.obj -f
	@rm bin/* -fr
