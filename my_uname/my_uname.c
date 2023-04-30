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

int main(int argc, char *argv[]) {
    struct utsname buf;

    if (my_uname(&buf) == 0) {
        printf("System name: %s\n", buf.sysname);
        printf("Node name: %s\n", buf.nodename);
        printf("Release: %s\n", buf.release);
        printf("Version: %s\n", buf.version);
        printf("Machine: %s\n", buf.machine);
    } else {
        fprintf(stderr, "Error getting system information.\n");
        return 1;
    }

    return 0;
}
