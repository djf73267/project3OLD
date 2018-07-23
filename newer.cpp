#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <cctype>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

#define BUFFSIZE 4096


using namespace std;
//main accepting arguments from commnand line
//@param int argc char * argv
int main(int argc, char * argv[]) {

  //letterOne is the argument 'letter' that determines which commands run
  char letterOne =  argv[1][1]; 
  
  char** argument = argv;
  int total = 0;
  
  //seperate integers which will store the value after the foor loop rather than updating and overidding 
  int n1, n2;
  char buff[BUFFSIZE];

  //seperate file descriptors which will store the fd after the for loop to prevent overridding 
  int fd1, fd2;
  //seperate struct 
  struct stat buf1;
  struct stat buf2;
  
  //if a condition to prevent too many arugments from being inputted 
  if(argc > 1 && argc < 5){ 
    //switch case to determine which character for the 3 seperate commands used 
    switch(letterOne) {
    case 'a':
      //for loop that will start at the first file argument and iterate through to the second argument 
      for(int i = 2; i < argc; i++){
	//if conditional to determine if for loop iteration is the first and not the second 
	if(i == 2){
	  fd1 = open (argument[i],O_RDONLY);
	  if(fd1 == -1){
	    perror("Doesn't exist");
	    exit(1);
	  }//if
	  n1 = fstat(fd1, &buf1);
	  if (n1==-1){
	    cout << "error" << endl;
	    exit(1);
	  }
	  int file1Time = buf1.st_atime; 
	}//if
	
	if(i == 3){
	  fd2 = open (argument[i],O_RDONLY);
	  if(fd2 == -1){
	    perror("Doesn't exist");
	    exit(1);
	  }//if
	  n2 = fstat(fd2, &buf2);
	  if (n2==-1){
	    cout << "error" << endl;
	    exit(2);
	  }
	  int file2Time = buf1.st_atime; 
	}//if
      }//for

      if(buf1.st_atime > buf2.st_atime){
	cout <<argument[2] <<" was most recently accessed." << endl;
      }else if(buf1.st_atime == buf2.st_atime){
	cout << argument[2] << " and " <<argument[3] <<" were accessed at the same time." << endl;
      } else{
	cout <<argument[3] <<" was most recently accessed." << endl;
      }
      break;//case a 

    case 'm':
      for(int i = 2; i < argc; i++){
	if(i == 2){
	  fd1 = open (argument[i],O_RDONLY);
	  if(fd1 == -1){
	    perror("Doesn't exist");
	    exit(1);
	  }//if
	  n1 = fstat(fd1, &buf1);
	  if (n1==-1){
	    cout << "error" << endl;
	    exit(1);
	  }
	  int file1Time = buf1.st_mtime; 
	}//if
	
	if(i == 3){
	  fd2 = open (argument[i],O_RDONLY);
	  if(fd2 == -1){
	    perror("Doesn't exist");
	    exit(1);
	  }//if
	  n2 = fstat(fd2, &buf2);
	  if (n2==-1){
	    cout << "error" << endl;
	    exit(2);
	  }
	  int file2Time = buf1.st_mtime; 
	}//if
      }//for

      if(buf1.st_mtime > buf2.st_mtime){
	cout <<argument[2] <<" was most recently modified." << endl;
      }else if(buf1.st_mtime == buf2.st_mtime){
	cout << argument[2] << " and " <<argument[3] <<" were modified at the same time." << endl;
      } else{
	cout <<argument[3] <<" was most recently modified." << endl;
      }
      break; //case m
    case 'c':
      for(int i = 2; i < argc; i++){
	if(i == 2){
	  fd1 = open (argument[i],O_RDONLY);
	  if(fd1 == -1){
	    perror("Doesn't exist");
	    exit(1);
	  }//if
	  n1 = fstat(fd1, &buf1);
	  if (n1==-1){
	    cout << "error" << endl;
	    exit(1);
	  }
	  int file1Time = buf1.st_ctime; 
	}//if
	
	if(i == 3){
	  fd2 = open (argument[i],O_RDONLY);
	  if(fd2 == -1){
	    perror("Doesn't exist");
	    exit(1);
	  }//if
	  n2 = fstat(fd2, &buf2);
	  if (n2==-1){
	    cout << "error" << endl;
	    exit(2);
	  }
	  int file2Time = buf1.st_ctime; 
	}//if
      }//for

      if(buf1.st_ctime > buf2.st_ctime){
	cout <<argument[2] <<" was most recently changed." << endl;
      }else if(buf1.st_ctime == buf2.st_ctime){
	cout << argument[2] << " and " <<argument[3] <<" were changed at the same time." << endl;
      } else{
	cout <<argument[3] <<" was most recently changed." << endl;
      }
      break; //case c 
      
    }//switch
  }//outer if
  else{
    perror("Too many arguments");
  }
}//main




