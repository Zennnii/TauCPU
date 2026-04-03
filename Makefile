CC = gcc
CFLAGS = -Wall -Wextra -g

DEBUG ?= 1

ifeq ($(DEBUG),1)
CFLAGS += -O0
else
CFLAGS += -O2
endif

SRC = src/main.c \
      src/cpu/cpu.c \
      src/loader/loader.c \
      src/util/util.c \
      src/cpu/instr/arithmetic.c \
      src/cpu/instr/data_transfer.c \
      src/cpu/instr/program_flow.c \
      src/cpu/instr/io.c

OBJ = $(SRC:.c=.o)

TARGET = taucpu

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)