CC=gcc
OUT=bin/Debug/iCrop

all: *.c
	$(CC) -g -Wall -Wextra *.c -o $(OUT)  `pkg-config --cflags --libs MagickWand`
