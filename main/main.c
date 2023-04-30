#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include "my_sleep.h"

#define BUF_SIZE 1024

int main(int argc, char *argv[]){

    const char *command = argv[1];
    const char *argument = argv[2];

    int ret_code = 0;

    printf("Command: %s\n", command);
    printf("Argument: %s\n", argument);

    if (strcmp( command, "my_sleep" ) == 0){     
        ret_code = my_sleep(argc, argv);
    }
    /*
    else if (strcmp( command, "my_uname" ) == 0){
        printf("my_uname\n");
        read_file_verSign();
        read_file_proc();
    }
    else if (strcmp( command, "my_ls" ) == 0){
        printf("my_ls\n");
        const char *directory = argv[1];

        if (directory == NULL){
            directory = ".";
        }

        my_ls(directory);
    }
    else if (strcmp( command, "my_lsmod" ) == 0){
        printf("my_lsmod\n");
        read_file_kernelMod();
    }
    else if (strcmp( command, "my_uptime" ) == 0){
        printf("my_uptime\n");
        read_file_uptime();
    }
    else if (strcmp( command, "my_cat" ) == 0){
        printf("my_cat\n");
        const char *file = argv[1];

        if (file == NULL){
            printf("No file was provided!\n");
        }
        else{
            my_cat(file);
        }
    }
    else if (strcmp( command, "my_mkdir" ) == 0){
        printf("my_mkdir\n");
        char *directory = argv[1];

        if (directory == NULL){
            printf("No directory to be created was provided!\n");
        }
        else{
            my_mkdir(directory);
        }
    }*/
    else{
        printf("The functionality has not been implemented!\n");
    }   
    return ret_code;
}
