ASM= nasm
AFLAGS= -f macho64
LINKER= ld
LFLAGS= -macosx_version_min 10.8 -lSystem

CC= gcc
SRC_NAME= ft_puts.s ft_toupper.s ft_tolower.s ft_isalpha.s \
          ft_isdigit.s ft_isalnum.s ft_isprint.s ft_bzero.s \
		  ft_strcat.s ft_strlen.s ft_memset.s ft_memcpy.s \
		  ft_strdup.s
OBJ_NAME= $(SRC_NAME:.s=.o)
OBJ_PATH= ./obj/
SRC_PATH= ./sources/
DEFINE_LIBFT= 'LIB(x)=ft_ \#\# x'
DEFINE_LIBC= 'LIB(x)=x'
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME=libfts.a

CSRC= checker.c
C_OBJ= $(addprefix c_, $(CSRC:.c=.o))
FT_OBJ= $(addprefix ft_, $(CSRC:.c=.o))
FT_CHECKER=ft_checker
C_CHECKER=c_checker


.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ) 
	@ranlib $(NAME)
	@printf "\n$(NAME) successfully create\n"
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(ASM) $(AFLAGS) $< -o $@
	@printf "\033[2K[ \033[31mcompiling\033[0m ] $< \r"

.PHONY: checker
checker: ft_checker c_checker

ft_checker: $(OBJ) $(FT_OBJ)
	$(LINKER) $(OBJ) $(FT_OBJ) $(LFLAGS) -o $(FT_CHECKER)

c_checker: $(OBJ) $(C_OBJ)
	$(LINKER) $(OBJ) $(C_OBJ) $(LFLAGS) -o $(C_CHECKER)

ft_%.o: %.c
	$(CC) -D $(DEFINE_LIBFT) -c -o $@ $<

c_%.o: %.c
	$(CC) -D $(DEFINE_LIBC) -c -o $@ $<

.PHONY: clean
clean:
	@printf "[ \033[36mdelete\033[0m ] objects from $(NAME)\n"
	@rm -rf $(OBJ_PATH)
	@rm -f $(C_OBJ)
	@rm -f $(FT_OBJ)

.PHONY: fclean
fclean: clean
	@printf "[ \033[36mdelete\033[0m ] $(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(C_CHECKER)
	@rm -f $(FT_CHECKER)

.PHONY: re
re: fclean all
