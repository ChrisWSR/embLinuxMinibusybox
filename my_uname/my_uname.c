#include "my_uname.h"

int my_uname() {
    struct utsname buf;
    int ret = uname(&buf);

    if (ret == -1) {
        perror("uname");
        return ret;
    }

    printf("System name: %s\n", buf.sysname);
    printf("Node name: %s\n", buf.nodename);
    printf("Release: %s\n", buf.release);
    printf("Version: %s\n", buf.version);
    printf("Machine: %s\n", buf.machine);

    return ret;
}
