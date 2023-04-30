#ifndef MY_UNAME_H
#define MY_UNAME_H

#include <sys/utsname.h>

int my_uname(struct utsname *buf);

#endif // MY_UNAME_H
