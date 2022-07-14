NAME = minitalk

NAME_SERVER = server

NAME_CLIENT = client

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

PRINTF_PATH = ft_printf

PRINTF = libftprintf.a

FT_PRINTF = ft_printf/libftprintf.a

INCLUDE = client.h

C_FILES_CLIENT = client_resources/client.c \
				client_resources/client_utils.c \

C_FILES_SERVER = server_resources/server.c

O_FILES_SERVER = ${C_FILES_SERVER:.c=.o}

O_FILES_CLIENT = ${C_FILES_CLIENT:.c=.o}


all: ${NAME}

${NAME}: ${NAME_SERVER} ${NAME_CLIENT}

%.o: server_resources/%.c
	${CC} ${CFLAGS} -c $< -o $@

%.o: client_resources/%.c
	${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

${NAME_SERVER}: ${O_FILES_SERVER} $(PRINTF)
	${CC} ${CFLAGS} ${O_FILES_SERVER} ${FT_PRINTF} -o ${NAME_SERVER}

${NAME_CLIENT}: ${O_FILES_CLIENT} $(PRINTF)
	${CC} ${CFLAGS} -I ${INCLUDE} ${O_FILES_CLIENT} ${FT_PRINTF} -o ${NAME_CLIENT}

$(PRINTF) :
	(cd $(PRINTF_PATH) && $(MAKE))
	cp $(PRINTF_PATH)/$(PRINTF) .

clean:
	${RM} ${O_FILES_CLIENT} ${O_FILES_SERVER}

fclean: clean
	${RM} ${NAME_SERVER} ${NAME_CLIENT} $(PRINTF)
	cd $(PRINTF_PATH) && $(MAKE) $@

re: fclean all
