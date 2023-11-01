#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "simple_crypto.h"

//OTP Cipher function-----------------------------------------
char* OTP(char* input,char* key){
  int inputLength = strlen(input);
  char enc[inputLength];
  char dec[inputLength];
  char *output = NULL;
  output = malloc(inputLength*2*sizeof(char));
//encrypt&decrypt
  int i= 0;
  while(i<inputLength){
    enc[i] = ((int)input[i]) ^ (int)key[i];
    dec[i] = ((int)enc[i]) ^ (int)key[i];
    i++;
  }
//return Arguments
  i = 0;
  while (i<inputLength) {
    output[i] = enc[i];
    output[inputLength+i] = dec[i];
    i++;
  }
  return output;
}
//Ceasar's cipher function--------------------------------------
char* Ceasars(char* input){
  int inputLength = strlen(input);
  char enc[inputLength];
  char dec[inputLength];
  char* output;
  output = malloc(inputLength*2*sizeof(char));
//encrypt&decrypt
  int i=0;
  while (i<inputLength) {
    enc[i] = input[i]+CEASARSKEY;
    dec[i] = enc[i]-CEASARSKEY;
    i++;
  }
  i=0;
//return Arguments
  while (i<inputLength) {
    output[i] = (char)enc[i];
    output[inputLength+i] = (char)dec[i];
    i++;
  }
  return output;
}
//Vigenere cipher function-------------------------------------
char* Vigenere(char* input,char*key){
  int inputLength = strlen(input);
  int keyLength = strlen(key);
  char enc[inputLength];
  char dec[inputLength];
  char temp[inputLength];
  int i;
  char* output;
  output = malloc(inputLength*2*sizeof(char));
//Encrypt&Decrypt
  for (i=0;i<inputLength;i++) {
    enc[i] = (((int)input[i]-65)+((int)key[i%keyLength]-65))%26+65;
    temp[i] = ((int)enc[i]-65)-((int)key[i%keyLength]-65);
    if (temp[i]<0) {
      dec[i]=(26+temp[i])%26+65;
    } else {
      dec[i]=(temp[i])%26+65;
    }
  }
//Return Arguments
  i=0;
  while (i<inputLength) {
    output[i] = (char)enc[i];
    output[inputLength+i] = (char)dec[i];
    i++;
  }
  return output;
}
