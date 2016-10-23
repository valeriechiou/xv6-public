// #include "param.h"
// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"
// #include "memlayout.h"

// int main(int argc, char ** argv){
// 	int	pid1=0;
// 	int	pid2=0;
// 	int status;
// 	int	i=3;
	
// 	pid1=fork();
	
// 	if(	pid1	!=		0)	{
		
// 		//printf(1, "parent");
// 		printf(1,"%d\n",	++i);
		
// 		pid2	=	fork();
		
// 		if(pid2	!=	0)	{
// 			waitpid(pid1,	&status, 0);
// 			//printf(1, "parentparent");
// 			printf(1,"%d\n",	++i);
			
// 			waitpid(pid2, &status,	0);
// 			printf(1,"%d\n",	++i);
			
// 			exit(0);
// 		}
// 		//printf(1, "parentchild");
// 		printf(1,"%d\n",i);
// 	}
// 	//printf(1, "child");
// 	printf(1,"%d\n",	++i);
	
// 	exit(0);
// 	return 0;
// }



// #include "param.h"
// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"
// #include "memlayout.h"

// int main(int argc, char ** argv){

//     int begin = getpid();
//     int pid = fork();
//     int i;
//     int status;
//     if(pid > 0){
//         for(i = 0; i < 15 && pid > 0; i++){
//             pid = fork();
//             if(pid < 0)
//                 printf(1,"errors occur!\n");
//         }
//         if (pid == 0){
//             int j = 0;
//             while(j++ < 1000);
//             if(getpid() == begin+5) sleep(30);

//             printf(1,"pid = %d\n",getpid());
//             if(getpid() == begin+10){
//                 printf(1,"pid %d waiting for %d\n",begin+10,begin+5);
//                 int wpid = waitpid(begin+5,&status,0);
//                 printf(1,"success clean %d, status is %d\n",wpid,status);
//             }
//             if(getpid() == begin+5){
//                 exit(5);
//             }
//             exit(0);
//         }
//     }else if(pid == 0){
//         int j = 0;
//         while(j++ < 1000);
//         exit(0);
//     }
//     int going = 1;
//     while(going >= 0){
//         going = wait(&status);
//         printf(1,"kill %d\n",going);
//     }
//     exit(0);
//     return 0;
// }


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

    int begin = getpid();
    int pid = fork();
    int i;
    int status;
    if(pid > 0){
        for(i = 0; i < 15 && pid > 0; i++){
            pid = fork();
            if(pid < 0)
                printf(1,"errors occur!\n");
        }
        if (pid == 0){
            int j = 0;
            while(j++ < 1000);
            if(getpid() == begin+5) sleep(50);

            printf(1,"pid = %d\n",getpid());
            if(getpid() == begin+10){
                printf(1,"pid %d waiting for %d\n",begin+10,begin+5);
                int wpid = waitpid(begin+5,&status,0);
                printf(1,"success clean %d\n",wpid);
            }
            if(getpid() == begin+12){
                printf(1,"pid %d waiting for %d\n",begin+12,begin+5);
                int wpid = waitpid(begin+5,&status,0);
                if(wpid == -1)
                    printf(1,"no more waiting for %d\n",begin+5);
            }
            if(getpid() == begin+5)
                exit(5);
            exit(0);
        }
    }else if(pid == 0){
        int j = 0;
        while(j++ < 1000);
        exit(0);
    }
    int going = 1;
    while(going >= 0){
        going = wait(&status);
        printf(1,"kill %d process\n",going);
    };
    exit(0);
    return 0;
}


