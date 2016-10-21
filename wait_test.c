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
	pid_t	pid1=0,	pid2=0;
	int	i=3;
	
	pid1=fork();
	
	if(	pid1	!=		0)	{
		
		//printf("parent");
		printf("%d\n",	++i);
		
		pid2	=	fork();
		
		if(pid2	!=	0)	{
			waitpid(pid1,	NULL, 0);
			//printf("parentparent");
			printf("%d\n",	++i);
			
			waitpid(pid2,NULL,	0);
			printf("%d\n",	++i);
			
			exit(0);
		}
		//printf("parentchild");
		printf("%d\n",i);
	}
	//printf("child");
	printf("%d\n",	++i);
}



