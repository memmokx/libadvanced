NAME = libad.a
CC ?= cc

CFLAGS = -std=c23 -Wall -Wextra -Werror -Wno-unknown-warning-option -Wno-error=old-style-declaration

INCLUDE = -Iinclude

LIBAD_USE_LIBC ?= 0

MEMORY_SRC 		= memcpy memmove memset calloc
STRING_SRC 		= string strlen strcmp strcpy strchr strdup
COLLECTIONS_SRC = vector

SRC = $(addprefix src/memory/, $(addsuffix .c, $(MEMORY_SRC))) \
	  $(addprefix src/string/, $(addsuffix .c, $(STRING_SRC))) \
	  $(addprefix src/collections/, $(addsuffix .c, $(COLLECTIONS_SRC)))

OBJ = $(SRC:.c=.o)

COLOUR_GREEN=$(shell tput setaf 2)
COLOUR_GRAY=$(shell tput setaf 254)
COLOUR_RED=$(shell tput setaf 1)
COLOUR_BLUE=$(shell tput setaf 4)
BOLD=$(shell tput bold)
COLOUR_END=$(shell tput sgr0)

ifeq ($(LIBAD_USE_LIBC),1)
	CFLAGS += -D LIBAD_USE_LIBC=$(LIBAD_USE_LIBC)
endif

ifdef OPT
	CFLAGS += -march=native -O3 -flto
endif

ifdef DEBUG
	CFLAGS += -g2
endif

ifdef SANITIZE
	CFLAGS += -g -fsanitize=address,undefined,leak
endif

ifndef NO_SILENT
.SILENT:
endif

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(COLOUR_GREEN)Compiled:$(COLOUR_END) $(BOLD)$@$(COLOUR_END)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(COLOUR_BLUE)Compiled:$(COLOUR_END) $< $(COLOUR_GRAY)$(CC) $(CFLAGS)$(COLOUR_END)"

format:
	clang-format -i $(SRC) $(TEST_SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re : fclean all


.PHONY: re all fclean clean format 
