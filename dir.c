#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main(){
  struct stat buffer;
  printf("Statistics for this directory: \n");
  printf("Total directory size: %lld \n\n", buffer.st_size);
  printf("Directories:\n");
  DIR * dir = opendir(".");
  struct dirent * f;
  while(f = readdir(dir)){
    if(f -> d_type == DT_DIR){
      stat(f ->d_name, &buffer);
      printf("     %s \n", f->d_name);
    }
  }
  closedir(dir);
  printf("Files:\n");
  dir = opendir(".");
  f = readdir(dir);
  while(f){
    if(f -> d_type == DT_REG){
      printf("     %s\n", f->d_name);
    }
    f = readdir(dir);
  }
  closedir(dir);
}
