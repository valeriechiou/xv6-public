#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int main(int argc, char ** argv){
	int	pid1=0;
	int	i=0;
	int	pid2=0;
	//int	pid3=0;
	
	int status;
	
	pid1=fork();
	
	if(	pid1	!=		0)	{
		
		//pid11 = getpid();
		//printf(1, "parent");
		//printf(1,"second parent[%d]\n",	2);

		pid2 =fork();
		pid2 =fork();
		pid2 =fork();
		pid2 =fork();
		pid2 =fork();
		
		i++;
		
		waitpid(pid1, &status, 0);
		printf(1,"[%d]\n",	i);
		
		
	}
	else {
		
		//printf(1, "child");
		for ( i = 0; i < 300000; i++) {}
		sleep(1000);
		printf(1,"first child[%d]\n",	1);
		
	}
	
	exit(0);
	return 0;
}



