NAME 	= libasm.a
SRCS 	= ft_strlen.s 
SRCS_B 	= ft_.s 
OBJS 	= ${SRCS:.s=.o}
OBJS_B	= ${SRCS_B:.s=.o}

AS = nasm
ASFLAGS =
RM = rm -f

LD = ar
LDFLAGS = rcs

.s.o:
	@echo Compiling.. $<
	${AS} ${ASFLAGS} -I. -c $< -o ${<:.s=.o}

$(NAME): $(OBJS)
	@echo Creating library.. ${NAME}
	${LD} ${LDFLAGS} $@ $^

all: ${NAME}
	@echo Done.

bonus: ${OBJS} ${OBJS_B} 
	@echo Bonus..
	${LD} ${LDFLAGS} ${NAME} $^

clean:
	@echo Deleting.. ${OBJS}
	@${RM} ${OBJS}
	@echo Deleting.. ${OBJS_B}
	@${RM} ${OBJS_B}

fclean: clean
	@echo Deleting.. ${NAME}
	@${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re bonus
