# Makefile

SRC	= $(NAME)/$(NAME).cpp
CC 	= g++
CFLAGS 	= -g -Wall -Wunused-value `pkg-config --cflags opencv4`
LIBS	= `pkg-config --libs opencv4`
LDFLAGS = -lm
TARGET = $(NAME)/$(NAME).a

$(TARGET):
	$(CC) $(SRC) $(LDFLAGS) -o $(TARGET) $(CFLAGS) $(LIBS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(TARGET)
