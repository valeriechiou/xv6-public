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
	int	pid2=0;
	int status;
	int	i=3;
	
	pid1=fork();
	
	if(	pid1	!=		0)	{
		
		printf(1, "parent");
		printf(1,"%d\n",	++i);
		
		pid2	=	fork();
		
		if(pid2	!=	0)	{
			waitpid(pid1,	&status, 0);
			printf(1, "parentparent");
			printf(1,"%d\n",	++i);
			
			waitpid(pid2, &status,	0);
			printf(1,"%d\n",	++i);
			
			exit(0);
		}
		printf(1, "parentchild");
		printf(1,"%d\n",i);
	}
	printf(1, "child");
	printf(1,"%d\n",	++i);
	
	
	
	exit(0);
	return 0;
}



