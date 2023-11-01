#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include "simple_crypto.h"



int main(void){
	int c,i,j;
	char* userInput;
	char* userInputkey;
	char* outArgs;
	int randomChar = open("/dev/urandom", O_RDONLY);
//OTP Cipher-------------------------------------------
//Obtain user input
	userInput = (char*)malloc(1);
	printf("[OTP]input: ");
  i = 0;
//Read characters until found an EOF or newline character.
  while((c = getchar()) != '\n' && c != EOF){
    userInput[i++] = c;
// Add space for another character to be read.
    userInput = (char*)realloc(userInput, i+1);
  }
// Null terminate the string
  userInput[i] = '\0';
	int inputLength = i;
//generate random characters
	char buffer[BUFFERSIZE];
  char key[inputLength];
	read(randomChar, buffer, BUFFERSIZE);
//keep only alphanumeric
	i,j=0;
	while(i<inputLength){
		if((isalpha(buffer[j]) != 0) || (isdigit(buffer[j])!= 0)){
			key[i]=buffer[j];
			i++;
		}
		j++;
	}
	close(randomChar);
//call OTP function
	outArgs = OTP(userInput,key);
//print encrypted
	printf("[OTP] encrypted : ");
	i=0;
	while(i<inputLength){
		printf("%c",outArgs[i]);
		i++;
	}
//print decrypted
	printf("\n[OTP] decrypted : ");
	while(i<inputLength*2){
		printf("%c",outArgs[i]);
		i++;
	}
//Clean Memmory
	printf("\n");
	free(userInput);
	free(outArgs);
	outArgs = NULL;
//Ceasar's cipher---------------------------------------
//Obtain user input
	userInput = (char*)malloc(1);
	printf("[Ceasars]input: ");
	i = 0;
//Read characters until found an EOF or newline character.
  while((c = getchar()) != '\n' && c != EOF){
    userInput[i++] = c;
// Add space for another character to be read.
    userInput = (char*)realloc(userInput, i+1);
  }
// Null terminate the string
  userInput[i] = '\0';
	inputLength = i;

//Call Ceasar's cipher function
	outArgs = Ceasars(userInput);
//Print Ceasar's key
	printf("[Ceasars] key : %d\n",CEASARSKEY);
//print encrypted
	printf("[Ceasars] encrypted : ");
	i=0;
	while(i<inputLength){
		printf("%c",outArgs[i]);
		i++;
	}
//print decrypted
	printf("\n[Ceasars] decrypted : ");
	while(i<inputLength*2){
		printf("%c",outArgs[i]);
		i++;
	}
//Clean Memmory
	printf("\n");
	free(userInput);
	free(outArgs);
	outArgs = NULL;
//Vigenere Cipher----------------------------------
//Obtain user input
	userInput = (char*)malloc(1);
	printf("[Vigenere]input: ");
	i = 0;
//Read characters until found an EOF or newline character.
	while((c = getchar()) != '\n' && c != EOF){
		userInput[i++] = c;
// Add space for another character to be read.
		userInput = (char*)realloc(userInput, i+1);
	}
// Null terminate the string
	userInput[i] = '\0';
	inputLength = i;
//Obtain user key
	userInputkey = (char*)malloc(1);
	printf("[Vigenere]key: ");
	i = 0;
//Read key characters until found an EOF or newline character.
	while((c = getchar()) != '\n' && c != EOF){
		userInputkey[i++] = c;
// Add space for another character to be read.
		userInputkey = (char*)realloc(userInputkey, i+1);
	}
// Null terminate the key
	userInputkey[i] = '\0';
//Call Vigenere cipher function
	outArgs = Vigenere(userInput,userInputkey);
//Print encrypted
	printf("[Vigenere] encrypted : ");
	i=0;
	while(i<inputLength){
		printf("%c",outArgs[i]);
		i++;
	}
//print decrypted
	printf("\n[Vigenere] decrypted : ");
	while(i<inputLength*2){
		printf("%c",outArgs[i]);
		i++;
	}
//Clean Memmory
	printf("\n");
	free(userInput);
	free(userInputkey);
	free(outArgs);
	return 0;

}
