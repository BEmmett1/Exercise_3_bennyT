# A simple Makefile
# Benjamin Thompson G01282798
# CS 262, Lab Section 210
# Lab 3
# The compiler: gcc for C programs, g++ for C++ programs, etc
CC = gcc
CFLAGS=-g -Wall -std=c89 -pedantic-errors
TARGET = lab3_bthomp5_210

LIBS=-lm

# all: $(TARGET)


all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LIBS)
clean:
	rm $(TARGET)
