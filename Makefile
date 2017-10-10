CC=gcc
CFLAGS=-Wall
TARGET=src-shifter

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

clean:
	$(RM) $(TARGET)
