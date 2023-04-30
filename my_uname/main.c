#include "my_uname.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    struct utsname buf;

    if (my_uname(&buf) == 0) {
        printf("System name: %s\n", buf.sysname);
        printf("Node name: %s\n", buf.nodename);
        printf("Release: %s\n", buf.release);
        printf("Version: %s\n", buf.version);
        printf("Machine: %s\n", buf.machine);
    } else {
        fprintf(stderr, "Error al obtener la información del sistema.\n");
        return 1;
    }

    return 0;
}
