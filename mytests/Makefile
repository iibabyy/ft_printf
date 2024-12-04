
MAKEFLAGS += --no-print-directory

TEST_FILE 	= test.c
SRC_DIR 	= s1

CC = clang

ifneq (,$(filter debug,$(MAKECMDGOALS)))
	CFLAGS 	+= -Wall -Wextra -Werror -pedantic -g3 -O0 -fdiagnostics-color=always -fno-omit-frame-pointer -fsanitize-recover \
			-Wshadow -fstack-protector-strong -fsanitize=alignment,pointer-overflow
	DMAKE	:= -j debug
	ifneq (,$(filter a1,$(MAKECMDGOALS)))
		CFLAGS 	+= -fsanitize=address,undefined,leak,bounds
		DMAKE 	+= a1
	endif
	ifneq (,$(filter a2,$(MAKECMDGOALS)))
		CFLAGS 	+= -fsanitize=signed-integer-overflow -Weverything
		DMAKE 	+= a2
	endif
	ifneq (,$(filter m1,$(MAKECMDGOALS)))
		CFLAGS 	+= -fsanitize=undefined,memory,bounds
		DMAKE 	+= m1
	endif
	ifneq (,$(filter m2,$(MAKECMDGOALS)))
		CFLAGS 	+= -fsanitize=signed-integer-overflow -Weverything
		DMAKE 	+= m2
	endif	
	ifneq (,$(filter t,$(MAKECMDGOALS)))
		CFLAGS 	+= -fsanitize=thread,signed-integer-overflow,undefined,leak,bounds -Weverything
		DMAKE 	+= t
	endif	
	export CFLAGS
endif


all: makelib
	@$(CC) $(CFLAGS) $(TEST_FILE) -L../ -lftprintf -o test.out

test: all
	./test.out

makelib:
	clear
	@$(MAKE) -C ../

bonus: all

fclean:
	@$(MAKE) -C ../$(SRC_DIR) fclean

asm:
	@$(MAKE) -C ../$(SRC_DIR) -j asm

info:
	@echo "\n\n=============== STRINGS ==============="
	strings ./test.out | grep -i 'asan\|msan'
	@echo "\n\n=============== NM ==============="
	nm ./test.out | grep '__asan\|__msan'
	@echo "\n\n=============== OBJDUMP ==============="
	objdump -h ./test.out
	@echo "\n\n=============== OBJDUMP ASan / MSan ==============="
	objdump -s ./test.out | grep -i 'asan\|msan'
	@echo "\n\n=============== LDD ==============="
	ldd ./test.out


.SILENT: debug
debug:
	@echo ""

.PHONY:
a1 a2 m1 m2 t:
	@echo "\n===================== [debug test : Fin] =====================\n"	
