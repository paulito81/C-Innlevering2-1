// Innlevering 2 by Paul Hasfjord
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "secretCoder.h"
#include "fileList.h"

#define MAX_FILES_SIZE 200000

int readFromFile(  char filename[], const char *mode);

char *encode(const char *inputMessageFile, const char *keyFile, int *status);       // koder beskjed
int encode2(const char *inputMessageFile, const char *keyFile, char *encodedStream);
char *decode(const char *inputCodeFile, const char *keyFile, int status);			// tilbake til normal
int decode2(const char *inputCodeFile, const char *keyFile, char *decodedMessage);

bool alphabetic( const char letter);
bool space( const char letter);
int  countLetter( const char string[]);

int main(void){	

		readFromFile(FILENAME1, "r");

		//decodedMessage = decode("secretCoder.txt", FILENAME1, 1);
		//status = decode("secretCoder.txt", FILENAME1, decodedMessage);
	/*
		TODO Encoding and Decoding reverse process 
		-> convert code symbols back into understable form.

		The message can be decode only with the help of a key 
		which is assumed to be known at both ends.
		Only the holder of the key is able to decode the true message.
	
		The idea is to use your code to create a library and distribute
		the library to your friends.

		Your friends can try to use your library against their code to verify the standard functionality
		In the final edition , include the names of the library creators you tested your code against.

		Develop interface that is linked with the library

		// example usage :
		//[1] decodedMessage = decode("myCode.txt", "hotelCalifornia.txt", &status);
		//[2] status = decode("myCode.txt", "hotelCalifornia.txt", decodedMessage);

	*/
		return 0;
	
		
}

bool alphabetic( const char letter){
	if( ( letter >= 'a' && letter <= 'z') || ( letter >= 'A' && letter <= 'Z'))
		return true;
	else
		return false;
}

bool space( const char letter){
	if(( letter == '\0')){
		return false;
	}
	else
		return true;
}
int countLetter( const char string[] ) {
	int countLetter = 0;	
		
	for(int i = 0 ; i < sizeof(*string); i++ ) {
		++countLetter;
	}
	return countLetter;
}
int readFromFile( char filename[], const char *mode){
		FILE* filePtr;
		int count =0;
		int index ;
		int i = 0;
		//char *x[1000];
		char c[ MAX_FILES_SIZE ];

		//x = malloc(100 * sizeof(char));
		filePtr = fopen(filename, "r");
			

		if(filePtr == NULL ){
			printf("Error file does not exist, or file could not be open..\n" );
		    return (-1);
		}

		
	   do{

	   		index = fgetc(filePtr);
	   		c[i] = index;
	   		++i;

	   		if( feof(filePtr) ){
	   			c[i] = index;
	   			break;
	   		}

	   }while(true);

	   printf("\n");
	   for( int j = 0; j < 2500; ++j){

	   		if( alphabetic( c[j] )){
	   			if(  space( c[j] )){
	   				 printf("%c", tolower( c[j] ) );
	   				 count++;				
	   			}
	   		}     	   
	   	}
	 	//long unsigned int s = countLetter(c);
	    printf("\n\n");
	  	printf("%d\n", count);
	    // printf("%d words\n", countWords(c) );
	  //  free(filePtr);
	  //	free(filePtr);
	    fclose (filePtr);
	    return 0;
	   
	   
}
