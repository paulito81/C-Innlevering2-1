// Innlevering 2 by Paul Hasfjord
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "secretCoder.h"
#include "fileList.h"

#define MAX_FILES_SIZE 850

int readFromFile(  char filename[], const char *mode);
bool alphabetic( const char letter);
bool space( const char letter);
int  countLetter( const char string[]);
void closeFile( char *fileArray, FILE* filePtr );


int main(void){	

		readFromFile(FILENAME3, "r");
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

int readFromFile( char filename[], const char *mode){
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

	     printf("%s\n\n", fileArray );

		char *test = "hei dette er en testqz";
		printf("\n%s\n",test );
		for(int j = 0; j < strlen(test); j++){
			printf("%c", test[j] );
			if( alphabetic (test[j])){
				int charPos = getCharPosition(fileArray, counter, test[j]);
				printf("%d ", charPos);
			}
			printf("\n");
			
		}

		closeFile(fileArray, filePtr);

		return 0;
}
/*
	   	free(fileArray);
	   	fileArray = NULL;

	    printf("\n\n");

	    fclose (filePtr);

*/	    
	   
	   

