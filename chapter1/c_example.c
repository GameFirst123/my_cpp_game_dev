#include <stdio.h>

int main(int argc, char const *argv[])
{
  /* code */
  int a=12;
  char* name="song";
  name[0]='S';
  const char* name2="piggy";
  name2="alpha";
  printf("my name is %s \n",name);
  printf("my name is %s",name2);
  return 0;
}
