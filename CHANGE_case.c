#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main() {
   int pipefds1[2], pipefds2[2];
  
   int pid;
   char pipe1writemessage[100] = "CSE  MINOR assignment";
   char pipe2writemessage[100];
   char readmessage[100];
  
   
   if (pipe(pipefds1) == -1) {
      printf("Unable to create pipe 1 \n");
      return 1;
   }
   
   
   if (pipe(pipefds2)== -1) {
      printf("Unable to create pipe 2 \n");
      return 1;
   }
   pid = fork();
   
   if (pid != 0) // Parent process 
   {
      close(pipefds1[0]); // Close the unwanted pipe1 read side
      close(pipefds2[1]); // Close the unwanted pipe2 write side
      printf("In Parent: Writing to pipe 1 – Message is %s\n", pipe1writemessage);
      write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage));
      wait(NULL);
      read(pipefds2[0], readmessage, sizeof(readmessage));
      
      printf("In Parent: Reading from pipe 2 – Message is %s\n", readmessage);
   } 
   else 
   { //child process
      close(pipefds1[1]); // Close the unwanted pipe1 write side
      close(pipefds2[0]); // Close the unwanted pipe2 read side
      read(pipefds1[0], readmessage, sizeof(readmessage));
      printf("In Child: Reading from pipe 1 – Message is %s\n", readmessage);
      for(int i=0;i<strlen(readmessage);i++)
      {
          if((int)readmessage[i]>=65 && (int)readmessage[i]<=90)
           pipe2writemessage[i]=(int)readmessage[i]+32;
          else if((int)readmessage[i]>=97 && (int)readmessage<=122)
           pipe2writemessage[i]=(int)readmessage[i]-32;
          else
             pipe2writemessage[i]=readmessage[i];
           
      }
      printf("In Child: Writing to pipe 2 – Message is %s\n", pipe2writemessage);
      printf("In Child: Writing to pipe 2 – Message is %s\n", pipe2writemessage);
      printf("In Child: Writing to pipe 2 – Message is %s\n", pipe2writemessage);
      printf("mission unsuccessful");
      write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage));

   }
   return 0;
}