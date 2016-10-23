// #include "param.h"
// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"
// #include "memlayout.h"

// int main(/*int argc, char ** argv8*/){
//     int i, z, y;
//     int begin = getpid();
//     int pid = fork();
//     if(pid > 0){
//         for(i = 0; i < 10 && pid > 0; i++){
//             pid = fork();
//             if(pid == 0){
//                 break;
//             }
//             if(pid < 0)
//                 printf(1,"errors occur!\n");
//         }
//         if (pid == 0){
//             int j = 0;
//             if(getpid() == begin+8){
//                 printf(1," pid = %d, get higher priority\n\n",getpid());
//                 y = getpri();
//                 // z = getpid();
//                 //printf(1," [%d] is my pid \n\n", z);
//                 printf(1," [%d] is my priority\n\n", y);
//                 z = setnewpriority(40);
//                 // printf(1, "priority wtf is z[%d] \n\n", z);
//                 y = getpri();
//                 // printf(1, "priority wtf is y[%d] \n\n", y);
                
//                 if ( z == 40)
//                 {
//                     printf(1, "priority set\n");
//                     printf(1," [%d] proc [%d] is my priority\n\n",getpid(), y);
//                 }
//                 else if ( z == -1)
//                 {
//                     printf(1, "priority set wrong\n");
//                     printf(1," [%d] is my priority\n\n", y);
//                 }
//                 else 
//                 {
//                     printf(1, "priority [%d] fail \n", z);
//                     printf(1," [%d] is my priority\n\n", y);
//                 }
                
//             }
//             while(j++ < 30000000);
//             exit(0);
//         }
//     }else if(pid == 0){
//        // sleep(100);
//         int j = 0;
//         while(j++ < 30000000);
//         exit(0);
//     }
    
    
//     int ki = 1;
//     int status;
//     while(ki >= 0){
//         ki = wait(&status);
//         y = getpid();
//         //printf(1," [%d] my fking pid[%d] : ", y);
        
        
//         y = getpri();
//         if(ki == begin+8)
//             printf(1," [%d] I should be done first[%d]\n",ki, y);
        
//         else
//             printf(1," [%d] done runing[%d]\n",ki, y);
            
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

int main(/*int argc, char ** argv8*/){
    int i;
    int begin = getpid();
    int pid = fork();
    if(pid > 0) {
        for(i = 0; i < 10 && pid > 0; i++){
            pid = fork();
            if(pid == 0){
                break;
            }
 
            if(pid < 0)
                printf(1,"errors occur!\n");
        }
        if (pid == 0){
            //int j = 0;
            if(getpid() == begin+8){
                printf(1," pid = %d, get higher priority\n\n",getpid());
                printf(1," priority of [%d] is %d\n", getpid(), getpri());
                setnewpriority(40);
                printf(1," new priority of [%d] is %d\n", getpid(), getpri());

                //~ if ( z == 40)
                //~ {
                    //~ printf(1, "priority set\n");
                //~ }
                //~ else if ( z == -1)
                //~ {
                    //~ printf(1, "priority set wrong\n");
                //~ }
                //~ else 
                //~ {
                    //~ printf(1, "priority [%d] fail \n", z);
                //~ }
                
            }
            sleep(500);
            exit(0);
        }
    }else if(pid == 0){
        sleep(1000);
        int j = 0;
        while(j++ < 30000000);
        exit(0);
    }
    
    
    int ki = 1;
    int status;
    while(ki >= 0){
        ki = wait(&status);
        if(ki == begin+8){
            printf(1," [%d] I should be done first [%d]\n",ki, getpid());
            printf(1," priority %d\n", getpri());
        }
        else{
            printf(1," [%d] done runing [%d} \n",ki, getpid());
            printf(1," priority %d\n", getpri());
        }
    }
    exit(0);
    return 0;
}




// #include "param.h"
// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"
// #include "fcntl.h"
// #include "syscall.h"
// #include "traps.h"
// #include "memlayout.h"

// int main(){
//     int i;
//     int begin = getpid();
//     int pid = fork();
//     if(pid > 0){
//         for(i = 0; i < 10 && pid > 0; i++){
//             pid = fork();
//             if(pid == 0){
//                 break;
//             }
//             if(pid < 0)
//                 printf(1,"errors occur!\n");
//         }
//         if (pid == 0){
//             int j = 0;
//             if(getpid() == begin + 5){
//                 printf(1," pid = %d, get higher priority\n\n",getpid());
//                 setnewpriority(33);
//             }
//             if(getpid() == begin + 8){
//                 printf(1," pid = %d, get higher priority\n\n",getpid());
//                 setnewpriority(33);
//             }
//             while(j++ < 30000000);
//             exit(0);
//         }
//     }else if(pid == 0){
//        // sleep(100);
//         int j = 0;
//         while(j++ < 30000000);
//         exit(0);
//     }
//     int ki = 1;
//     int status;
//     while(ki >= 0){
//         ki = wait(&status);
//         if(ki == begin+5)
//             printf(1," [%d] I should be done first two\n",ki);
//         else if(ki == begin+8)
//             printf(1," [%d] I should be done first two\n",ki);
//         else
//             printf(1," [%d] done runing\n",ki);

//     }
//     exit(0);
//     return 0;
// }