// Innlevering 2 by Paul Hasfjord
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "secretCoder.h"
#include "secret.h"
#include "fileList.h"

#define MAX_FILES_SIZE 850

bool alphabetic( const char letter);
bool space( const char letter);
int  countLetter( const char string[]);
int readFromFile(  char filename[], const char *mode, char *testKey);
void closeFile( char *fileArray, FILE* filePtr );
int decoder(char *test,char *fileArray, int counter);
char alphabeticHigherCase(const char letter);

int main(void){	

		readFromFile(FILENAME3, "r", SECRETSTRING);
	//	char* decodedMessage;
	//	int status;
		//decodedMessage = decode("secretCoder.txt", FILENAME1, 1);
	//	status = decode("secretCoder.txt", FILENAME1, decodedMessage);
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
char alphabeticHigherCase( const char letter){
	char tempLetter = '-';

	if( letter >= 'A' && letter <= 'Z'){
		tempLetter += letter;
		return tempLetter;
	}else
		return letter;
}

bool space( const char letter){
	if(( letter == '\0')){
		return false;
	}
	else
		return true;
}

int getCharPosition(char *fileArray, int arrayLength, char charTarget){

	for( int i = 0 ; i < arrayLength; i++){

		if(fileArray[i] == charTarget ){
			return i;
		}
	}
	return -1;
}

void closeFile( char *fileArray, FILE* filePtr ){

		free(fileArray);
		fileArray = NULL;

		printf("\n\n");

		fclose (filePtr);
}
bool compareToChar( char xInput, char yInput) {

		if(xInput != yInput  )
			return true;			
		else
			return false;
		
}
int decoder(char *test, char *fileArray, int counter){
		if( test == NULL ){
			printf("Error filekey was not found, or where unable to open.\n" );
		    return -1;
		}
		for(int j = 0; j < strlen(test); j++){
			printf("%c", test[j] );
			if( alphabetic (test[j])){
				
				int charPos = getCharPosition(fileArray, counter, test[j]);
				if( compareToChar(test[j], test[j+1] )){
					printf("[%d] ", charPos);

				}
			}
			printf("\n");
		}
		return 0;
}

int readFromFile( char filename[], const char *mode, char *test){
		FILE* filePtr;
		int index ;
		
		char *fileArray = malloc(sizeof(char)*2);
		int length = 2;
		int counter = 0 ;

		filePtr = fopen(filename, "r");

		if(filePtr == NULL ){
			printf("Error file does not exist, or file could not be open..\n" );
		    return (-1);
		}
 
		
	   do{
	   		index = fgetc(filePtr);
	 
	   		if( alphabetic( index)){

	   			if( counter == length){
	   				length *=2;
	   				fileArray = realloc( fileArray, length*sizeof(char) );
	   			}
	   			fileArray[counter++] = tolower(index);
	   		}

	   		if( feof(filePtr) ){
	   			break;
	   		}

	   }while(true);


	   	// PRINT OUT TEST OF FILE ARRAY
	    printf("%s\n\n", fileArray );
	    // KEY MESSAGE PRINT OUT
		printf("\n%s\n\n",test );

		decoder(test ,fileArray, counter);
	
		closeFile(fileArray, filePtr);

		return 0;
}
    
	   
	   

