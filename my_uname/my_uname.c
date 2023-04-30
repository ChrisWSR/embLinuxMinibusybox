#include "my_uname.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

int my_uname(struct utsname *buf) {
    if (buf == NULL) {
        errno = EFAULT;
        return -1;
    }

    int ret = uname(buf);

    if (ret == -1) {
        perror("uname");
    }

    return ret;
}
