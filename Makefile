CC = gcc
CFLAGS = -Wall -Wextra -g

DEBUG ?= 1

ifeq ($(DEBUG),1)
CFLAGS += -O0
else
CFLAGS += -O2
endif

SRC = main.c \
      cpu/cpu.c \
      loader/loader.c \
      util/util.c \
      cpu/instr/arithmetic.c \
      cpu/instr/data_transfer.c \
      cpu/instr/program_flow.c \
      cpu/instr/io.c

OBJ = $(SRC:.c=.o)

TARGET = taucpu

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)