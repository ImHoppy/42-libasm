NAME 	= libasm.a
SRCS 	= ft_strlen.s \
ft_strcpy.s \
ft_strcmp.s \
ft_write.s \
ft_read.s \
ft_strdup.s
SRCS_B 	=
OBJS 	= ${SRCS:.s=.o}
OBJS_B	= ${SRCS_B:.s=.o}

AS = nasm
ASFLAGS = -f elf64 -g -F dwarf
RM = rm -f

LD = ar
LDFLAGS = rcs

BLUE = \033[0;34m
RESET = \033[0m\n

.s.o:
	@printf "${BLUE}Compiling.. $< ${RESET}"
	${AS} ${ASFLAGS} $< -o ${<:.s=.o}

$(NAME): $(OBJS)
	@printf "${BLUE}Creating library... ${NAME} ${RESET}"
	${LD} ${LDFLAGS} $@ $^

all: ${NAME}
	@printf "${BLUE}Done. ${RESET}"

bonus: ${OBJS} ${OBJS_B}
	@printf "${BLUE}Bonus.. ${RESET}"
	${LD} ${LDFLAGS} ${NAME} $^

clean:
	@printf "${BLUE}Deleting.. ${OBJS} ${RESET}"
	@${RM} ${OBJS}
	@printf "${BLUE}Deleting.. ${OBJS_B} ${RESET}"
	@${RM} ${OBJS_B}

fclean: clean
	@printf "${BLUE}Deleting.. ${NAME} ${RESET}"
	@${RM} ${NAME}

test: all
	gcc main.c -o main -g3 -L. -lasm

re: fclean all

.DEFAULT_GOAL = all
.PHONY: all clean fclean re bonus
