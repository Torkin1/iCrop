CC=gcc
OUT=bin/Debug/iCrop
IM_VERSION:=$(shell convert -version | grep Version | awk '{print $$3}' | awk -F . '{print $$1}')

all: *.c
	$(CC) -g -Wall -Wextra *.c -o $(OUT) -DIM_VERSION=$(IM_VERSION) `pkg-config --cflags --libs MagickWand`
