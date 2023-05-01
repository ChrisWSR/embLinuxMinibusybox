LIB_NAME =
APP_NAME = demoApp

LIB_PATH = lib
INC_PATH = include

CFLAGS = -Wall -O2
CROSS_COMPILE = arm-linux-gnueabihf-
CC = gcc
LDFLAGS = -shared -fPIC

.PHONY: all install clean

all: ./main/main.c libmysleep.so libmyuname.so libmyuptime.so
	$(CROSS_COMPILE)$(CC) $(CFLAGS) ./main/main.c -I./my_sleep -I./my_uname -I./my_uptime -L. -lmysleep -lmyuname -lmyuptime -o $(APP_NAME)

libmysleep.so: ./my_sleep/my_sleep.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(LDFLAGS) ./my_sleep/my_sleep.c -o ./libmysleep.so

libmyuname.so: ./my_uname/my_uname.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(LDFLAGS) ./my_uname/my_uname.c -o ./libmyuname.so

libmyuptime.so: ./my_uptime/my_uptime.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(LDFLAGS) ./my_uptime/my_uptime.c -o ./libmyuptime.so

clean:
	rm -f *.so
	rm -f $(APP_NAME)

install:
	scp $(APP_NAME) debian@192.168.7.2:/home/debian/
	scp ./libmysleep.so debian@192.168.7.2:/home/debian/
	scp ./libmyuname.so debian@192.168.7.2:/home/debian/
	scp ./libmyuptime.so debian@192.168.7.2:/home/debian/
