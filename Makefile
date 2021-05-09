CC = gcc
CFLAGS = -W -Wall
TARGET = ledger
DTARGET = ledger_debug
OBJECTS = main.c record.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm -f *.o $(TARGET) $(DTARGET)
