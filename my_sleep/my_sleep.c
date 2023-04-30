#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int my_sleep(int num_seconds){

   
    if (num_seconds<0){
        num_seconds *= -1;
    }
    if (num_seconds>100){
        num_seconds = 100;
    }
    printf("Sleeping for %d seconds...\n", num_seconds);
    sleep(num_seconds);
    printf("Waking up!\n");
    return 0;    

}

