ASM= nasm
AFLAGS= -f macho64
LINKER= ld
LFLAGS= -macosx_version_min 10.8 -lSystem

CC= gcc
SRC_NAME= ft_puts.s
OBJ_NAME= $(SRC_NAME:.s=.o)
OBJ_PATH= ./obj/
SRC_PATH= ./sources/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME=libfts.a

CSRC= checker.c
COBJ= $(CSRC:.c=.o)
CHECKER=checker


.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ) 
	@ranlib $(NAME)
	@printf "\n$(NAME) successfully create\n"
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(ASM) $(AFLAGS) $< -o $@
	@printf "\033[2K[ \033[31mcompiling\033[0m ] $< \r"

$(CHECKER): $(OBJ) $(COBJ)
	$(LINKER) $(OBJ) $(COBJ) $(LFLAGS) -o $(CHECKER)

%.o: %.c
	@$(CC) -c -o $@ $<

.PHONY: clean
clean:
	@printf "[ \033[36mdelete\033[0m ] objects from $(NAME)\n"
	@rm -rf $(OBJ_PATH)
	@rm -f $(COBJ)

.PHONY: fclean
fclean: clean
	@printf "[ \033[36mdelete\033[0m ] $(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(CHECKER)

.PHONY: re
re: fclean all
