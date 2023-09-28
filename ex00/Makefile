# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elias <elias@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 17:08:00 by elias             #+#    #+#              #
#    Updated: 2023/09/28 13:50:41 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_SRC		= main.cpp

S_TMP		= ${addprefix ${D_SRC}, ${S_SRC}}
O_SRC		= $(patsubst %.cpp, ${D_OBJS}%.o, $(S_TMP))

# VARIABLES
NAME		= btc
CC			= c++ -std=c++98

# FLAGS
MAKEFLAGS	+= --no-print-directory -s
CFLAGS		= -Wall -Wextra -Werror -g3

# COMMANDS
RM			= rm -rf
PRINT		= printf

# DIRECTORIES
D_OBJS		= .objs/
D_SRC		= ./
D_INC		= includes/

# COLORS
C_R			= \033[1;31m
C_G			= \033[1;32m
C_B			= \033[1;34m
C_Y			= \033[1;33m
C_C			= \033[1;36m
C_RST		= \033[0m
C_DEL		= \r\033[2K

all:		ascii ${NAME}

${D_OBJS}%.o:%.cpp		Makefile
			@mkdir		-p $(shell dirname $@)
			@${PRINT}	"${C_Y}${C_DEL}Creating ${NAME}'s objects : $@"
			@${CC}		${CFLAGS} -I${D_INC} -c $< -o $@

${NAME}:	${O_SRC}
			@${PRINT}	"${C_G}${C_DEL}Creating ${NAME}'s objects : DONE\n"
			@${PRINT}	"${C_Y}Compiling ${NAME}...${C_RST}"
			@${CC}		${O_SRC} -o ${NAME}
			@${PRINT}	"${C_G}${C_DEL}Compiling ${NAME} : DONE ${C_RST}\n\n"

ascii:
			@${PRINT}	"$$ASCII\n"

clean:		ascii
			@${PRINT}	"${C_R}Deleting objects : DONE\n"
			@${RM}		${D_OBJS}

fclean:		clean
			@${PRINT}	"${C_R}Deleting executable : DONE${C_RST}\n\n"
			@${RM}		${NAME}

re:			fclean all

define		ASCII
${C_C}  ___   _      _   
 / __)_| |_  _| |_ 
( (__(_   _)(_   _)
 \___) |_|    |_|  
${C_RST}
endef

export		ASCII

.PHONY:		all re clean fclean ascii