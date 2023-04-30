#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <sys/sysinfo.h>

long my_uptime(void) {
	struct sysinfo s_info;
	int error = sysinfo(&s_info);
	if(error != 0) {
		printf("code error = %d\n", error);
	}
	//return s_info.uptime;                                                 No longer needed.
    printf("Update is: %ld\n", uptime);
	printf("System up for %ld seconds, %ld minutes, %ld hours, %ld days\n", uptime, uptime / 60, uptime / 3600, uptime / 86400);
}