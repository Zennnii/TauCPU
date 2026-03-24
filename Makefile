CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC = main.c \
      cpu/cpu.c \
      loader/loader.c \
	  util/util.c \
	  cpu/instr/arithmetic.c \
	  cpu/instr/data_transfer.c \
	  cpu/instr/program_flow.c \
	  cpu/instr/io.c \

OBJ = $(SRC:.c=.o)

TARGET = taucpu

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
