#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int my_sleep(int argc, char *argv[]){

    if (argc < 3){
            printf("No time provided\n");
            return 1;
    }
    else{
        int seconds = atoi(argv[2]);
        if (seconds<0){
            seconds *= -1;
        }
        if (seconds>100){
            seconds = 100;
        }
        printf("Sleeping for %d seconds...\n", seconds);
        sleep(seconds);
        printf("Waking up!\n");
        return 0;
    }

    

}

