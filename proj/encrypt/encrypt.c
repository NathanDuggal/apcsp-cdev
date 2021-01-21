
//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"

// I couldn't figure out a way to do it with the base code
// I hope my method is acceptable
int CHARS_LEN = 94;

char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'
  int ind = c;
  if(direction){
    ind+=shift;
  }else{
    ind-=shift;
  }
  while( ind < 32 || ind > 126 ){
    if(ind >= 126){
      ind-=CHARS_LEN;
    }else if(ind < 32){
      ind+=CHARS_LEN;
    }
  }
  return ind;
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}

void vEncrypt(char str[], char shift[])
{
  int key[strlen(shift)];
  for (int i=0; i<strlen(shift); i++){
    key[i] = shift[i];
  }
  encrypt(str, key, strlen(shift));
}

void vDecrypt(char str[], char shift[])
{
  int key[strlen(shift)];
  for (int i=0; i<strlen(shift); i++){
    key[i] = shift[i];
  }
  decrypt(str, key, strlen(shift));
}


