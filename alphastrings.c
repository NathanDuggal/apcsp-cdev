#include <stdio.h>
#include <string.h>

int main(){
  // string 1
  char str1[26];
  for(int i = 0; i < 26; i++){
    str1[i]='a'+i;
  }
  str1[26] = '\0';
  // string 2
  char str2[27] = "abcdefghijklmnopqrstuvwxyz\0";

  // string compare
  if(strcmp(str1, str2) == 0)
    printf("The strings are identical\n");
  else
    printf("The strings are different\n");
  
  // str1 to uppercase
  for(int i = 0; i < 26; i++){
    str1[i]-=32;
  }

  // string compare
  if(strcmp(str1, str2) == 0)
    printf("The strings are identical\n");
  else
    printf("The strings are different\n");
  
  // string concatination
  char str3[26];
  char strtemp[26];
  strcpy(str3, str1);
  // for some reason str2 breaks after the concat so I had to make a temp
  strcpy(strtemp, str2);
  strcat(str3, str2); 
  // printing strings
  printf("str1: %s \n",str1);
  printf("str2: %s \n",strtemp);
  printf("str3: %s \n",str3);
}
