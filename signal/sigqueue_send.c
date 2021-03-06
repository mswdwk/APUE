/*************************************************************************
	> File Name: process_.c
	> Author: Simba
	> Mail: dameng34@163.com 
	> Created Time: Sat 23 Feb 2013 02:34:02 PM CST
 ************************************************************************/
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<signal.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)



int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage %s pid\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pid_t pid = atoi(argv[1]); //字符串转换为整数
	union sigval val;
	val.sival_int = 100;
	sigqueue(pid, SIGINT, val); // 只可以发信号给某个进程，而不能是进程组

	return 0;

}




