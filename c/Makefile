CC = gcc
INC_DIR = ./libs
CFLAGS = -Wall -I$(INC_DIR)

obj-y := libs/*.c
obj-y +=main.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(obj-y)
	 $(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o test

