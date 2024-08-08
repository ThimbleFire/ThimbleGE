CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lSDL2
TARGET = sdl_app
SOURCES = main.c

all: $(TARGET)

$(TARGET): $(SOURCES)
  $(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
  rm -f $(TARGET)
