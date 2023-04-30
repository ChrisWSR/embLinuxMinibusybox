LIB_NAME =
APP_NAME = demoApp

LIB_PATH = lib
INC_PATH = include

CFLAGS = -Wall -O2
CROSS_COMPILE = arm-linux-gnueabihf-
CC = gcc
LDFLAGS = -shared -fPIC

.PHONY: all install clean

all: ./main/main.c libmysleep.so
	$(CROSS_COMPILE)$(CC) $(CFLAGS) ./main/main.c -I./my_sleep -L. -lmysleep -o $(APP_NAME)

libmysleep.so: ./my_sleep/my_sleep.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(LDFLAGS) ./my_sleep/my_sleep.c -o ./libmysleep.so
	#when program runs on host
	#sudo cp ./libmysleep.so  /usr/lib/libmysleep.so

clean:
	rm -f *.so
	rm -f $(APP_NAME)
	#when program runs on host
	#sudo rm -f /usr/lib/libmysleep.so

install:
	scp $(APP_NAME) debian@192.168.7.2:/home/debian/
	scp ./libmysleep.so debian@192.168.7.2:/home/debian/


