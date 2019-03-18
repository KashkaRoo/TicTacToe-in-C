#
# Makefile
# Tic Tac Toe in C
# Heather Rosa
# March 17, 2019
#

# my variables
EXEC = main
FUNCS = board
OBJS = ${EXEC}.o ${FUNCS}.o
HDRS = ${FUNCS}.h

# implicit rules variables
CFLAGS = -g -Wall
# LDFLAGS = 
CC = gcc 

all : ${EXEC}

${EXEC} : ${OBJS}

${OBJS} : ${HDRS}

clean :
	rm -rf ${EXEC} ${OBJS} core 
