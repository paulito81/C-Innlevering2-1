/* Innlevering 2 by Paul Hasfjord
	encodeMessage -DECODER A PROGRAM THAT CONVERT A TEKST INTO A NUMBER STRING FROM FILE.
	+added feature switch menu, color and ascii art.
	+automatic and manual feature
*/

//IMPORT LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//IMPORT FILES	
#include "secretCoder.h"
#include "secret.h"
#include "fileList.h"
#include "textColor.h"	
	
//PRINT OUT AND MENU-OPTIONS
static bool CLOSEDFILE = false;
void mainMenu( char filename[], int menuChoice, int menuChoice2, const char *modePtr, char *keyPtr, char inputConverter );
void decoderMenu(char filename[], int menuChoice, int menuChoice2, const char *modePtr, char *keyPtr, char inputConverter);
void encoderMenu(char filename[], int menuChoice, int menuChoice2, const char *modePtr, char *keyPtr, char inputConverter);
bool quitProgram( char *fileKey, FILE* filePtr );
void printQuit();
//STATIC CLOSE PARAMTER TO SWITCH

//encodeMessage
int encodeMessage(char *key,char *message, int counter, int dDistance );
bool encodeFileManually(char inputFileName[], const char *modePtr, char *keyPtr );
/*
 READ AND CLOSE FILE
*/
// AUTOMATIC INPUT
int readFromFile(  char filename[], const char *modePtr, char *keyPtr);
// WRITE TO FILE
int writeToFile(char *messageArray);

// MANUAL INPUT
bool decodeFileManually( char inputFileName[], const char *modePtr, char manualKey[]  );
int readManualFile(char filename[], const char *modePtr, char *manualFilePtr,  char *manualKeyPtr, int dDistance);
bool closeManualFile( char *message, FILE* filePtr, char *manualFilePtr, char *manualKeyPtr );

// DECODER AND PARAMETERS
int decodeMessage(char *key,char *message, int counter, int d );
bool compareTwoCharPtr( int xInput, int yInput );
bool alphabetic( const char letter);
int countLetter( const char string[]);
int chooseDistanceD();
int getCharPosition(char *fileArray, int arrayLength, char charTarget);

int main(void ){	

		//INIT MENU
        char filename[1000] = "";
        int menuChoice = 0, menuChoice2 =0;
       // char inputFileName[100] ="";
        char *modePtr = "r";
        char *keyPtr = SECRETSTRING;
        char inputConverter ='0';
		//char manualKey[100] = ""; 
        // RUN PROGRAM
        mainMenu( filename, menuChoice, menuChoice2, modePtr, keyPtr, inputConverter );
		return 0;		
}


// MENU
void mainMenu( char filename[], int menuChoice, int menuChoice2, const char *modePtr, char *keyPtr, char inputConverter ){
                
         do{ //START OF MAIN MENU
                	
                    printf( KBLU MENUL"\nVELKOMMEN TIL INNLEVERING 2.0 "KMAG"\t'Kodeknekker'n"RESET KBLU"\n\t[MAIN MENY]]\n"MENUL RESET KCYN"\nVelg et av valgene under fra menyen:\n(Tast inn et tall mellom [1-3] +Trykk 'Enter')\n"MENUL RESET );
                    printf( "\n[Tast 1]\tDecoding Menu\n" );
                    printf( "[Tast 2]\tEncoding Menu\n" );
                    printf(KYEL "\n[Tast 3]\tAvslutte programmet\n"MENUL"\n:" RESET);

                    scanf( "%d", &menuChoice );
               
                    switch( menuChoice) { // SWITCH MAIN MENU

                    		case 0:  //ERROR MESSAGE IF A INVALID INPUT
                    				inputConverter = menuChoice + '0';
                    				printf(KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret en default feilmelding : '%s' og vil nå avsluttes!\n" MENUL "\n"RESET, &inputConverter);
                    				exit(0);
                    				break;  
                            case 1: // GO TO DECODE MENU  
                            		decoderMenu( filename, menuChoice, menuChoice2, modePtr, keyPtr, inputConverter );                                                          
                                    break;                                  
                            case 2: // GO TO ENCODE MENU 
                            		encoderMenu( filename, menuChoice, menuChoice2, modePtr, keyPtr, inputConverter );
                            		break;
                            case 3: // QUIT PROGRAM
                                	printQuit();                        
                                	break; 
                            default:                                                         
                                    printf( KRED"En ugyldig inputverdi '%d' har blitt registret.\n(Velg en verdi mellom [1-121])\n\n"RESET, menuChoice );
                  	 				break;      

                    } // END OF SWITCH - MAIN MENU
                            
        }while( (menuChoice > 0 && menuChoice <=3) ||  isalpha(menuChoice)  || !CLOSEDFILE);	
        // END OF WHILE - MAIN MENU
}

// DECODE MENU
void decoderMenu(char filename[], int menuChoice, int menuChoice2, const char *modePtr, char *keyPtr, char inputConverter ){
		 
    	 do{ //START OF DECODING MENU
				 	printf( KBLU MENUL"\nVELKOMMEN TIL DECODING MENY"KMAG"\t'kryptering'"RESET KBLU"\n\t[MAIN MENY]]\n"MENUL RESET KCYN"\nVelg et av valgene under fra menyen:\n(Tast inn et tall mellom [1-3] +Trykk 'Enter')\n"MENUL RESET );
			        printf( "\n[Tast 1]\tSkriv inn navn på fil manuelt fra keyboard\n" );
			        printf( "[Tast 2]\tHent en fil fra en ferdig liste\n" );
			        printf(KYEL "\n[Tast 3]\tAvslutte programmet\n"MENUL"\n:" RESET);
										   
                    scanf( "%d", &menuChoice );

                    switch( menuChoice) { // SWITCH DECODING MENU

                    		case 0:  //ERROR MESSAGE IF INPUT IS A INVALID INPUT
                    				inputConverter = menuChoice + '0';
                    				printf(KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret en default feilmelding : '%s' og vil nå avsluttes!\n" MENUL "\n"RESET, &inputConverter);
                    				exit(0);
                    				break;
                            case 1: //READ FILE FROM KEYBOARD INPUT   
                            		decodeFileManually( filename, modePtr, keyPtr);                                
                                    break;
                            case 2: //START OF MENU 2 AUTOMATIC DECODER

                                    do{  
                                        
                                        printf(KCYN LINE"\nVelg en av filene fra listen: \n(Tast inn et tall mellom [1-121] + Trykk 'Enter')\n"LINE "\n"RESET );
                             
                                        printf("[Tast 1]:  %s\n",   FILENAME1 );
                                        printf("[Tast 2]:  %s\n",   FILENAME2 );
                                        printf("[Tast 3]:  %s\n",   FILENAME3 );
                                       	printf("[Tast 4]:  %s\n",   FILENAME4 );
                                        printf("[Tast 5]:  %s\n",   FILENAME5 );
                                        printf("[Tast 6]:  %s\n",   FILENAME6 );
                                        printf("[Tast 7]:  %s\n",   FILENAME7 );
                                        printf("[Tast 8]:  %s\n",   FILENAME8 );
                                        printf("[Tast 9]:  %s\n",   FILENAME9 );
                                        printf("[Tast 10]: %s\n",  FILENAME10 );
                                        printf("[Tast 11]: %s\n",  FILENAME11 );
                                        printf("[Tast 12]: %s\n",  FILENAME12 );
                                        printf("[Tast 13]: %s\n",  FILENAME13 );
                                        printf("[Tast 14]: %s\n",  FILENAME14 );
                                        printf("[Tast 15]: %s\n",  FILENAME15 );
                                        printf("[Tast 16]: %s\n",  FILENAME16 );
                                        printf("[Tast 17]: %s\n",  FILENAME17 );
                                        printf("[Tast 18]: %s\n",  FILENAME18 );
                                        printf("[Tast 19]: %s\n",  FILENAME19 );
                                        printf("[Tast 20]: %s\n",  FILENAME20 );
                                        printf("[Tast 21]: %s\n",  FILENAME21 );
                                        printf("[Tast 22]: %s\n",  FILENAME22 );
                                        printf("[Tast 23]: %s\n",  FILENAME23 );
                                        printf("[Tast 24]: %s\n",  FILENAME24 );
                                        printf("[Tast 25]: %s\n",  FILENAME25 );
                                        printf("[Tast 26]: %s\n",  FILENAME26 );
                                        printf("[Tast 27]: %s\n",  FILENAME27 );
                                        printf("[Tast 28]: %s\n",  FILENAME28 );
                                        printf("[Tast 29]: %s\n",  FILENAME29 );
                                        printf("[Tast 30]: %s\n",  FILENAME30 );
                                        printf("[Tast 31]: %s\n",  FILENAME31 );
                                        printf("[Tast 32]: %s\n",  FILENAME32 );
                                        printf("[Tast 33]: %s\n",  FILENAME33 );
                                        printf("[Tast 34]: %s\n",  FILENAME34 );
                                        printf("[Tast 35]: %s\n",  FILENAME35 );
                                        printf("[Tast 36]: %s\n",  FILENAME36 );
                                        printf("[Tast 37]: %s\n",  FILENAME37 );
                                        printf("[Tast 38]: %s\n",  FILENAME38 );
                                        printf("[Tast 39]: %s\n",  FILENAME39 );
                                        printf("[Tast 40]: %s\n",  FILENAME40 );
                                        printf("[Tast 41]: %s\n",  FILENAME41 );
                                        printf("[Tast 42]: %s\n",  FILENAME42 );
                                        printf("[Tast 43]: %s\n",  FILENAME43 );
                                        printf("[Tast 44]: %s\n",  FILENAME44 );
                                        printf("[Tast 45]: %s\n",  FILENAME45 );
                                        printf("[Tast 46]: %s\n",  FILENAME46 );
                                        printf("[Tast 47]: %s\n",  FILENAME47 );
                                        printf("[Tast 48]: %s\n",  FILENAME48 );
                                        printf("[Tast 49]: %s\n",  FILENAME49 );
                                        printf("[Tast 50]: %s\n",  FILENAME50 );
                                        printf("[Tast 51]: %s\n",  FILENAME51 );
                                        printf("[Tast 52]: %s\n",  FILENAME52 );
                                        printf("[Tast 53]: %s\n",  FILENAME53 );
                                        printf("[Tast 54]: %s\n",  FILENAME54 );
                                        printf("[Tast 55]: %s\n",  FILENAME55 );
                                        printf("[Tast 56]: %s\n",  FILENAME56 );
                                        printf("[Tast 57]: %s\n",  FILENAME57 );
                                        printf("[Tast 58]: %s\n",  FILENAME58 );
                                       	printf("[Tast 59]: %s\n",  FILENAME59 );
                                        printf("[Tast 60]: %s\n",  FILENAME60 );
                                        printf("[Tast 61]: %s\n",  FILENAME61 );
                                        printf("[Tast 62]: %s\n",  FILENAME62 );
                                        printf("[Tast 63]: %s\n",  FILENAME63 );
                                        printf("[Tast 64]: %s\n",  FILENAME64 );
                                        printf("[Tast 65]: %s\n",  FILENAME65 );
                                        printf("[Tast 66]: %s\n",  FILENAME66 );
                                        printf("[Tast 67]: %s\n",  FILENAME67 );
                                        printf("[Tast 68]: %s\n",  FILENAME68 );
                                        printf("[Tast 69]: %s\n",  FILENAME69 );
                                        printf("[Tast 70]: %s\n",  FILENAME70 );
                                        printf("[Tast 71]: %s\n",  FILENAME71 );
                                        printf("[Tast 72]: %s\n",  FILENAME72 );
                                        printf("[Tast 73]: %s\n",  FILENAME73 );
                                        printf("[Tast 74]: %s\n",  FILENAME74 );
                                        printf("[Tast 75]: %s\n",  FILENAME75 );
                                        printf("[Tast 76]: %s\n",  FILENAME76 );
                                        printf("[Tast 77]: %s\n",  FILENAME77 );
                                        printf("[Tast 78]: %s\n",  FILENAME78 );
                                        printf("[Tast 79]: %s\n",  FILENAME79 );
                                        printf("[Tast 80]: %s\n",  FILENAME80 );
                                        printf("[Tast 81]: %s\n",  FILENAME81 );
                                        printf("[Tast 82]: %s\n",  FILENAME82 );
                                        printf("[Tast 83]: %s\n",  FILENAME83 );
                                        printf("[Tast 84]: %s\n",  FILENAME84 );
                                        printf("[Tast 85]: %s\n",  FILENAME85 );
                                        printf("[Tast 86]: %s\n",  FILENAME86 );
                                        printf("[Tast 87]: %s\n",  FILENAME87 );
                                        printf("[Tast 88]: %s\n",  FILENAME88 );
                                        printf("[Tast 89]: %s\n",  FILENAME89 );
                                        printf("[Tast 90]: %s\n",  FILENAME90 );
                                        printf("[Tast 91]: %s\n",  FILENAME91 );
                                        printf("[Tast 92]: %s\n",  FILENAME92 );
                                        printf("[Tast 93]: %s\n",  FILENAME93 );
                                        printf("[Tast 94]: %s\n",  FILENAME94 );
                                        printf("[Tast 95]: %s\n",  FILENAME95 );
                                        printf("[Tast 96]: %s\n",  FILENAME96 );
                                        printf("[Tast 97]: %s\n",  FILENAME97 );
                                        printf("[Tast 98]: %s\n",  FILENAME98 );
                                        printf("[Tast 99]: %s\n",  FILENAME99 );
                                        printf("[Tast 100]: %s\n", FILENAME100 );
                                        printf("[Tast 101]: %s\n", FILENAME101 );
                                        printf("[Tast 102]: %s\n", FILENAME102 );
                                        printf("[Tast 103]: %s\n", FILENAME103 );
                                        printf("[Tast 104]: %s\n", FILENAME104 );
                                        printf("[Tast 105]: %s\n", FILENAME105 );
                                        printf("[Tast 106]: %s\n", FILENAME106 );
                                        printf("[Tast 107]: %s\n", FILENAME107 );
                                        printf("[Tast 108]: %s\n", FILENAME108 );
                                        printf("[Tast 109]: %s\n", FILENAME109 );
                                        printf("[Tast 110]: %s\n", FILENAME110 );
                                        printf("[Tast 111]: %s\n", FILENAME111 );
                                        printf("[Tast 112]: %s\n", FILENAME112 );
                                        printf("[Tast 113]: %s\n", FILENAME113 );
                                        printf("[Tast 114]: %s\n", FILENAME114 );
                                        printf("[Tast 115]: %s\n", FILENAME115 );
                                        printf("[Tast 116]: %s\n", FILENAME116 );
                                        printf("[Tast 117]: %s\n", FILENAME117 );
                                        printf("[Tast 118]: %s\n", FILENAME118 );
                                        printf("[Tast 119]: %s\n", FILENAME119 );
                                        printf("[Tast 120]: %s\n", FILENAME120 );
                                        printf("[Tast 121]: %s\n", FILENAME121 );
                                                                    
                                        printf( KYEL"\n([Tast -1]: For å 'avslutte')\n\n:"RESET );
                                        scanf( "%d", &menuChoice2 );
                            
                                        switch( menuChoice2 ) { //SWITCH AUTOMATIC DECODER MENU

					                    		case -1: 
					                                	printQuit();                        
					                                	break;                       	
					                    		case 0:
					                    				inputConverter = menuChoice2 + '0';
					                    				printf( KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret default feilmelding: '%s' og vil nå avsluttes!\n"MENUL "\n"RESET, &inputConverter );
					                    				exit(0);
					                    				break;                                       	
                                                case 1:                                                                                                    
                                                        strcat(filename, FILENAME1);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 2:
                                                        strcat(filename, FILENAME2);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;                                                  
                                                case 3:
                                                        strcat(filename, FILENAME3);
                                                        readFromFile(filename, modePtr, keyPtr);  
                                                        break;
                                                case 4:
                                                        strcat(filename, FILENAME4);
                                                        readFromFile(filename, modePtr, keyPtr);  
                                                        break;
 												case 5:
                                                        strcat(filename, FILENAME5);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 6:
                                                        strcat(filename, FILENAME6);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 7:
                                                        strcat(filename, FILENAME7);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 8:
                                                        strcat(filename, FILENAME8);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 9:
                                                        strcat(filename, FILENAME9);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 10:
                                                        strcat(filename, FILENAME10);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 11:
                                                        strcat(filename, FILENAME11);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 12:
                                                        strcat(filename, FILENAME12);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 13:
                                                        strcat(filename, FILENAME13);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 14:
                                                	    strcat(filename, FILENAME14);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 15:
                                                	    strcat(filename, FILENAME15);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 16:
                                                        strcat(filename, FILENAME16);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 17:
                                                        strcat(filename, FILENAME17);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 18:
                                                        strcat(filename, FILENAME18);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 19:
                                                        strcat(filename, FILENAME19);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 20:
                                                        strcat(filename, FILENAME20);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 21:
                                                        strcat(filename, FILENAME21);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 22:
                                                        strcat(filename, FILENAME22);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 23:
                                                        strcat(filename, FILENAME23);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 24:
                                                        strcat(filename, FILENAME24);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 25:
                                                        strcat(filename, FILENAME25);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 26:
                                                        strcat(filename, FILENAME26);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 27:
                                                        strcat(filename, FILENAME27);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 28:
                                                        strcat(filename, FILENAME28);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 29:
                                                	    strcat(filename, FILENAME29);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 30:
                                                	    strcat(filename, FILENAME30);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 31:
                                                        strcat(filename, FILENAME31);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 32:
                                                        strcat(filename, FILENAME32);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 33:
                                                        strcat(filename, FILENAME33);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 34:
                                                        strcat(filename, FILENAME34);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 35:
                                                        strcat(filename, FILENAME35);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 36:
                                                        strcat(filename, FILENAME36);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 37:
                                                        strcat(filename, FILENAME37);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 38:
                                                        strcat(filename, FILENAME38);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 39:
                                                        strcat(filename, FILENAME39);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 40:
                                                        strcat(filename, FILENAME40);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 41:
                                                        strcat(filename, FILENAME41);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 42:
                                                        strcat(filename, FILENAME42);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 43:
                                                        strcat(filename, FILENAME43);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 44:
                                                	    strcat(filename, FILENAME44);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 45:
                                                	    strcat(filename, FILENAME45);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 46:
                                                        strcat(filename, FILENAME46);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 47:
                                                        strcat(filename, FILENAME47);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 48:
                                                        strcat(filename, FILENAME48);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 49:
                                                        strcat(filename, FILENAME49);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 50:
                                                        strcat(filename, FILENAME50);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 51:
                                                        strcat(filename, FILENAME51);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 52:
                                                        strcat(filename, FILENAME52);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 53:
                                                        strcat(filename, FILENAME53);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 54:
                                                        strcat(filename, FILENAME54);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 55:
                                                        strcat(filename, FILENAME55);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 56:
                                                        strcat(filename, FILENAME56);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 57:
                                                        strcat(filename, FILENAME57);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 58:
                                                        strcat(filename, FILENAME58);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 59:
                                                	    strcat(filename, FILENAME59);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 60:
                                                	    strcat(filename, FILENAME60);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 61:
                                                        strcat(filename, FILENAME61);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 62:
                                                        strcat(filename, FILENAME62);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 63:
                                                        strcat(filename, FILENAME63);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 64:
                                                        strcat(filename, FILENAME64);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 65:
                                                	    strcat(filename, FILENAME65);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 66:
                                                	    strcat(filename, FILENAME66);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 67:
                                                        strcat(filename, FILENAME67);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 68:
                                                        strcat(filename, FILENAME68);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 69:
                                                        strcat(filename, FILENAME69);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 70:
                                                        strcat(filename, FILENAME70);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 71:
                                                        strcat(filename, FILENAME71);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 72:
                                                        strcat(filename, FILENAME72);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 73:
                                                        strcat(filename, FILENAME73);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 74:
                                                        strcat(filename, FILENAME74);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 75:
                                                        strcat(filename, FILENAME75);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 76:
                                                        strcat(filename, FILENAME76);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 77:
                                                        strcat(filename, FILENAME77);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 78:
                                                        strcat(filename, FILENAME78);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 79:
                                                        strcat(filename, FILENAME79);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 80:
                                                	    strcat(filename, FILENAME80);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 81:
                                                	    strcat(filename, FILENAME81);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 82:
                                                        strcat(filename, FILENAME82);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 83:
                                                        strcat(filename, FILENAME83);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 84:
                                                        strcat(filename, FILENAME84);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 85:
                                                	    strcat(filename, FILENAME85);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 86:
                                                	    strcat(filename, FILENAME86);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;    
                                                case 87:
                                                        strcat(filename, FILENAME87);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 88:
                                                        strcat(filename, FILENAME88);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 89:
                                                        strcat(filename, FILENAME89);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 90:
                                                        strcat(filename, FILENAME90);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 91:
                                                        strcat(filename, FILENAME91);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 92:
                                                        strcat(filename, FILENAME92);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 93:
                                                        strcat(filename, FILENAME93);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 94:
                                                	    strcat(filename, FILENAME94);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 95:
                                                	    strcat(filename, FILENAME95);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 96:
                                                        strcat(filename, FILENAME96);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 97:
                                                        strcat(filename, FILENAME97);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 98:
                                                        strcat(filename, FILENAME98);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 99:
                                                	    strcat(filename, FILENAME99);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 100:
                                                	    strcat(filename, FILENAME86);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                  	
                                                case 101:
                                                        strcat(filename, FILENAME101);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 102:
                                                        strcat(filename, FILENAME102);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 103:
                                                	    strcat(filename, FILENAME103);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 104:
                                                	    strcat(filename, FILENAME104);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 105:
                                                        strcat(filename, FILENAME105);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 106:
                                                        strcat(filename, FILENAME106);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 107:
                                                        strcat(filename, FILENAME107);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 108:
                                                	    strcat(filename, FILENAME108);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 109:
                                                	    strcat(filename, FILENAME109);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;    
                                                case 110:
                                                        strcat(filename, FILENAME110);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 111:
                                                        strcat(filename, FILENAME111);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 112:
                                                        strcat(filename, FILENAME112);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 113:
                                                        strcat(filename, FILENAME113);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 114:
                                                        strcat(filename, FILENAME114);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 115:
                                                        strcat(filename, FILENAME115);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 116:
                                                        strcat(filename, FILENAME116);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 117:
                                                	    strcat(filename, FILENAME117);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 118:
                                                	    strcat(filename, FILENAME118);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 119:
                                                        strcat(filename, FILENAME119);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 120:
                                                        strcat(filename, FILENAME120);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 121:
                                                        strcat(filename, FILENAME121);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                                                   
                                                default:                                                         
                                                  		printf( KRED"En ugyldig inputverdi '%d' har blitt registret.\n(Velg en verdi mellom [1-121])\n\n"RESET, menuChoice2 );
                  	 									break;      

                                        } // END OF SWITCH - AUTOMATIC DECODER MENU
                            
                                    }while( (menuChoice2 > 0 && menuChoice2 <=121) ||  isalpha(menuChoice2)  || !CLOSEDFILE);
                                    
                                     break; // END OF WHILE - AUTOMATIC DECODER MENU

                        default:                  
		                        printf( KRED"En ugyldig inputverdi '%d' har blitt registret.\n(Velg en verdi mellom [0-2])\n\n"RESET, menuChoice );   
        		                break;
                    } // END OF SWITCH ENCODER - MAIN MENU
                    
                    
                }while( (menuChoice > 0 && menuChoice <=2) || isalpha(menuChoice) || !CLOSEDFILE); //END OF WHILE ENCODER - MAIN MENU    
                  
}

// ENCODER MENU
void encoderMenu(char filename[], int menuChoice, int menuChoice2, const char *modePtr, char *keyPtr, char inputConverter){
		 
    	 do{ //START OF DECODING MENU
				 	printf( KBLU MENUL"\nVELKOMMEN TIL ENCODER MENY"KMAG"\t'Dekryptering'"RESET KBLU"\n\t[MAIN MENY]]\n"MENUL RESET KCYN"\nVelg et av valgene under fra menyen:\n(Tast inn et tall mellom [1-3] +Trykk 'Enter')\n"MENUL RESET );
			        printf( "\n[Tast 1]\tSkriv inn navn på fil manuelt fra keyboard\n" );
			        printf( "\n[Tast 2]\tHent en fil fra en ferdig liste\n\n" );
			        printf(KYEL "\n[Tast 3]\tAvslutte programmet" RESET);
										   
                    scanf( "%d", &menuChoice );

                    switch( menuChoice) { // SWITCH DECODING MENU

                    		case 0:  //ERROR MESSAGE IF INPUT IS A INVALID INPUT
                    				inputConverter = menuChoice + '0';
                    				printf(KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret en default feilmelding : '%s' og vil nå avsluttes!\n" MENUL "\n"RESET, &inputConverter);
                    				exit(0);
                    				break;
                            case 1: //READ FILE FROM KEYBOARD INPUT   
                            		encodeFileManually(filename , modePtr, keyPtr);                              
                                    break;
                            case 2: //START OF MENU 2 AUTOMATIC ENCODER

                                    do{  
                                        
                                        printf(KCYN LINE"\nVelg en av filene fra listen: \n(Tast inn et tall mellom [1-121] + Trykk 'Enter')\n"LINE "\n"RESET );
                             
                                        printf("[Tast 1]:  %s\n",   FILENAME1 );
                                        printf("[Tast 2]:  %s\n",   FILENAME2 );
                                        printf("[Tast 3]:  %s\n",   FILENAME3 );
                                       	printf("[Tast 4]:  %s\n",   FILENAME4 );
                                        printf("[Tast 5]:  %s\n",   FILENAME5 );
                                        printf("[Tast 6]:  %s\n",   FILENAME6 );
                                        printf("[Tast 7]:  %s\n",   FILENAME7 );
                                        printf("[Tast 8]:  %s\n",   FILENAME8 );
                                        printf("[Tast 9]:  %s\n",   FILENAME9 );
                                        printf("[Tast 10]: %s\n",  FILENAME10 );
                                        printf("[Tast 11]: %s\n",  FILENAME11 );
                                        printf("[Tast 12]: %s\n",  FILENAME12 );
                                        printf("[Tast 13]: %s\n",  FILENAME13 );
                                        printf("[Tast 14]: %s\n",  FILENAME14 );
                                        printf("[Tast 15]: %s\n",  FILENAME15 );
                                        printf("[Tast 16]: %s\n",  FILENAME16 );
                                        printf("[Tast 17]: %s\n",  FILENAME17 );
                                        printf("[Tast 18]: %s\n",  FILENAME18 );
                                        printf("[Tast 19]: %s\n",  FILENAME19 );
                                        printf("[Tast 20]: %s\n",  FILENAME20 );
                                        printf("[Tast 21]: %s\n",  FILENAME21 );
                                        printf("[Tast 22]: %s\n",  FILENAME22 );
                                        printf("[Tast 23]: %s\n",  FILENAME23 );
                                        printf("[Tast 24]: %s\n",  FILENAME24 );
                                        printf("[Tast 25]: %s\n",  FILENAME25 );
                                        printf("[Tast 26]: %s\n",  FILENAME26 );
                                        printf("[Tast 27]: %s\n",  FILENAME27 );
                                        printf("[Tast 28]: %s\n",  FILENAME28 );
                                        printf("[Tast 29]: %s\n",  FILENAME29 );
                                        printf("[Tast 30]: %s\n",  FILENAME30 );
                                        printf("[Tast 31]: %s\n",  FILENAME31 );
                                        printf("[Tast 32]: %s\n",  FILENAME32 );
                                        printf("[Tast 33]: %s\n",  FILENAME33 );
                                        printf("[Tast 34]: %s\n",  FILENAME34 );
                                        printf("[Tast 35]: %s\n",  FILENAME35 );
                                        printf("[Tast 36]: %s\n",  FILENAME36 );
                                        printf("[Tast 37]: %s\n",  FILENAME37 );
                                        printf("[Tast 38]: %s\n",  FILENAME38 );
                                        printf("[Tast 39]: %s\n",  FILENAME39 );
                                        printf("[Tast 40]: %s\n",  FILENAME40 );
                                        printf("[Tast 41]: %s\n",  FILENAME41 );
                                        printf("[Tast 42]: %s\n",  FILENAME42 );
                                        printf("[Tast 43]: %s\n",  FILENAME43 );
                                        printf("[Tast 44]: %s\n",  FILENAME44 );
                                        printf("[Tast 45]: %s\n",  FILENAME45 );
                                        printf("[Tast 46]: %s\n",  FILENAME46 );
                                        printf("[Tast 47]: %s\n",  FILENAME47 );
                                        printf("[Tast 48]: %s\n",  FILENAME48 );
                                        printf("[Tast 49]: %s\n",  FILENAME49 );
                                        printf("[Tast 50]: %s\n",  FILENAME50 );
                                        printf("[Tast 51]: %s\n",  FILENAME51 );
                                        printf("[Tast 52]: %s\n",  FILENAME52 );
                                        printf("[Tast 53]: %s\n",  FILENAME53 );
                                        printf("[Tast 54]: %s\n",  FILENAME54 );
                                        printf("[Tast 55]: %s\n",  FILENAME55 );
                                        printf("[Tast 56]: %s\n",  FILENAME56 );
                                        printf("[Tast 57]: %s\n",  FILENAME57 );
                                        printf("[Tast 58]: %s\n",  FILENAME58 );
                                       	printf("[Tast 59]: %s\n",  FILENAME59 );
                                        printf("[Tast 60]: %s\n",  FILENAME60 );
                                        printf("[Tast 61]: %s\n",  FILENAME61 );
                                        printf("[Tast 62]: %s\n",  FILENAME62 );
                                        printf("[Tast 63]: %s\n",  FILENAME63 );
                                        printf("[Tast 64]: %s\n",  FILENAME64 );
                                        printf("[Tast 65]: %s\n",  FILENAME65 );
                                        printf("[Tast 66]: %s\n",  FILENAME66 );
                                        printf("[Tast 67]: %s\n",  FILENAME67 );
                                        printf("[Tast 68]: %s\n",  FILENAME68 );
                                        printf("[Tast 69]: %s\n",  FILENAME69 );
                                        printf("[Tast 70]: %s\n",  FILENAME70 );
                                        printf("[Tast 71]: %s\n",  FILENAME71 );
                                        printf("[Tast 72]: %s\n",  FILENAME72 );
                                        printf("[Tast 73]: %s\n",  FILENAME73 );
                                        printf("[Tast 74]: %s\n",  FILENAME74 );
                                        printf("[Tast 75]: %s\n",  FILENAME75 );
                                        printf("[Tast 76]: %s\n",  FILENAME76 );
                                        printf("[Tast 77]: %s\n",  FILENAME77 );
                                        printf("[Tast 78]: %s\n",  FILENAME78 );
                                        printf("[Tast 79]: %s\n",  FILENAME79 );
                                        printf("[Tast 80]: %s\n",  FILENAME80 );
                                        printf("[Tast 81]: %s\n",  FILENAME81 );
                                        printf("[Tast 82]: %s\n",  FILENAME82 );
                                        printf("[Tast 83]: %s\n",  FILENAME83 );
                                        printf("[Tast 84]: %s\n",  FILENAME84 );
                                        printf("[Tast 85]: %s\n",  FILENAME85 );
                                        printf("[Tast 86]: %s\n",  FILENAME86 );
                                        printf("[Tast 87]: %s\n",  FILENAME87 );
                                        printf("[Tast 88]: %s\n",  FILENAME88 );
                                        printf("[Tast 89]: %s\n",  FILENAME89 );
                                        printf("[Tast 90]: %s\n",  FILENAME90 );
                                        printf("[Tast 91]: %s\n",  FILENAME91 );
                                        printf("[Tast 92]: %s\n",  FILENAME92 );
                                        printf("[Tast 93]: %s\n",  FILENAME93 );
                                        printf("[Tast 94]: %s\n",  FILENAME94 );
                                        printf("[Tast 95]: %s\n",  FILENAME95 );
                                        printf("[Tast 96]: %s\n",  FILENAME96 );
                                        printf("[Tast 97]: %s\n",  FILENAME97 );
                                        printf("[Tast 98]: %s\n",  FILENAME98 );
                                        printf("[Tast 99]: %s\n",  FILENAME99 );
                                        printf("[Tast 100]: %s\n", FILENAME100 );
                                        printf("[Tast 101]: %s\n", FILENAME101 );
                                        printf("[Tast 102]: %s\n", FILENAME102 );
                                        printf("[Tast 103]: %s\n", FILENAME103 );
                                        printf("[Tast 104]: %s\n", FILENAME104 );
                                        printf("[Tast 105]: %s\n", FILENAME105 );
                                        printf("[Tast 106]: %s\n", FILENAME106 );
                                        printf("[Tast 107]: %s\n", FILENAME107 );
                                        printf("[Tast 108]: %s\n", FILENAME108 );
                                        printf("[Tast 109]: %s\n", FILENAME109 );
                                        printf("[Tast 110]: %s\n", FILENAME110 );
                                        printf("[Tast 111]: %s\n", FILENAME111 );
                                        printf("[Tast 112]: %s\n", FILENAME112 );
                                        printf("[Tast 113]: %s\n", FILENAME113 );
                                        printf("[Tast 114]: %s\n", FILENAME114 );
                                        printf("[Tast 115]: %s\n", FILENAME115 );
                                        printf("[Tast 116]: %s\n", FILENAME116 );
                                        printf("[Tast 117]: %s\n", FILENAME117 );
                                        printf("[Tast 118]: %s\n", FILENAME118 );
                                        printf("[Tast 119]: %s\n", FILENAME119 );
                                        printf("[Tast 120]: %s\n", FILENAME120 );
                                        printf("[Tast 121]: %s\n", FILENAME121 );
                                                                    
                                        printf( KYEL"\n([Tast -1]: For å 'avslutte')\n\n:"RESET );
                                        scanf( "%d", &menuChoice2 );
                            
                                        switch( menuChoice2 ) { //SWITCH AUTOMATIC ENCODER MENU

					                    		case -1: 
					                                	printQuit();                        
					                                	break;                       	
					                    		case 0:
					                    				inputConverter = menuChoice2 + '0';
					                    				printf( KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret default feilmelding: '%s' og vil nå avsluttes!\n"MENUL "\n"RESET, &inputConverter );
					                    				exit(0);
					                    				break;                                       	
                                                case 1:                                                                                                    
                                                        strcat(filename, FILENAME1);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 2:
                                                        strcat(filename, FILENAME2);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;                                                  
                                                case 3:
                                                        strcat(filename, FILENAME3);
                                                        readFromFile(filename, modePtr, keyPtr);  
                                                        break;
                                                case 4:
                                                        strcat(filename, FILENAME4);
                                                        readFromFile(filename, modePtr, keyPtr);  
                                                        break;
 												case 5:
                                                        strcat(filename, FILENAME5);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 6:
                                                        strcat(filename, FILENAME6);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 7:
                                                        strcat(filename, FILENAME7);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 8:
                                                        strcat(filename, FILENAME8);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 9:
                                                        strcat(filename, FILENAME9);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 10:
                                                        strcat(filename, FILENAME10);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 11:
                                                        strcat(filename, FILENAME11);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 12:
                                                        strcat(filename, FILENAME12);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 13:
                                                        strcat(filename, FILENAME13);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 14:
                                                	    strcat(filename, FILENAME14);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 15:
                                                	    strcat(filename, FILENAME15);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 16:
                                                        strcat(filename, FILENAME16);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 17:
                                                        strcat(filename, FILENAME17);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 18:
                                                        strcat(filename, FILENAME18);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 19:
                                                        strcat(filename, FILENAME19);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 20:
                                                        strcat(filename, FILENAME20);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 21:
                                                        strcat(filename, FILENAME21);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 22:
                                                        strcat(filename, FILENAME22);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 23:
                                                        strcat(filename, FILENAME23);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 24:
                                                        strcat(filename, FILENAME24);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 25:
                                                        strcat(filename, FILENAME25);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 26:
                                                        strcat(filename, FILENAME26);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 27:
                                                        strcat(filename, FILENAME27);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 28:
                                                        strcat(filename, FILENAME28);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 29:
                                                	    strcat(filename, FILENAME29);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 30:
                                                	    strcat(filename, FILENAME30);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 31:
                                                        strcat(filename, FILENAME31);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 32:
                                                        strcat(filename, FILENAME32);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 33:
                                                        strcat(filename, FILENAME33);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 34:
                                                        strcat(filename, FILENAME34);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 35:
                                                        strcat(filename, FILENAME35);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 36:
                                                        strcat(filename, FILENAME36);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 37:
                                                        strcat(filename, FILENAME37);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 38:
                                                        strcat(filename, FILENAME38);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 39:
                                                        strcat(filename, FILENAME39);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 40:
                                                        strcat(filename, FILENAME40);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 41:
                                                        strcat(filename, FILENAME41);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 42:
                                                        strcat(filename, FILENAME42);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 43:
                                                        strcat(filename, FILENAME43);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 44:
                                                	    strcat(filename, FILENAME44);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 45:
                                                	    strcat(filename, FILENAME45);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 46:
                                                        strcat(filename, FILENAME46);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 47:
                                                        strcat(filename, FILENAME47);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 48:
                                                        strcat(filename, FILENAME48);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 49:
                                                        strcat(filename, FILENAME49);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 50:
                                                        strcat(filename, FILENAME50);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 51:
                                                        strcat(filename, FILENAME51);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 52:
                                                        strcat(filename, FILENAME52);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 53:
                                                        strcat(filename, FILENAME53);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 54:
                                                        strcat(filename, FILENAME54);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 55:
                                                        strcat(filename, FILENAME55);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 56:
                                                        strcat(filename, FILENAME56);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 57:
                                                        strcat(filename, FILENAME57);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 58:
                                                        strcat(filename, FILENAME58);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 59:
                                                	    strcat(filename, FILENAME59);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 60:
                                                	    strcat(filename, FILENAME60);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 61:
                                                        strcat(filename, FILENAME61);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 62:
                                                        strcat(filename, FILENAME62);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 63:
                                                        strcat(filename, FILENAME63);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 64:
                                                        strcat(filename, FILENAME64);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 65:
                                                	    strcat(filename, FILENAME65);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 66:
                                                	    strcat(filename, FILENAME66);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 67:
                                                        strcat(filename, FILENAME67);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 68:
                                                        strcat(filename, FILENAME68);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                  
                                                case 69:
                                                        strcat(filename, FILENAME69);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 70:
                                                        strcat(filename, FILENAME70);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
 												case 71:
                                                        strcat(filename, FILENAME71);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 72:
                                                        strcat(filename, FILENAME72);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                               
                                                case 73:
                                                        strcat(filename, FILENAME73);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 74:
                                                        strcat(filename, FILENAME74);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 75:
                                                        strcat(filename, FILENAME75);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 76:
                                                        strcat(filename, FILENAME76);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 77:
                                                        strcat(filename, FILENAME77);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 78:
                                                        strcat(filename, FILENAME78);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 79:
                                                        strcat(filename, FILENAME79);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 80:
                                                	    strcat(filename, FILENAME80);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 81:
                                                	    strcat(filename, FILENAME81);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 82:
                                                        strcat(filename, FILENAME82);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 83:
                                                        strcat(filename, FILENAME83);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 84:
                                                        strcat(filename, FILENAME84);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 85:
                                                	    strcat(filename, FILENAME85);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 86:
                                                	    strcat(filename, FILENAME86);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;    
                                                case 87:
                                                        strcat(filename, FILENAME87);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 88:
                                                        strcat(filename, FILENAME88);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 89:
                                                        strcat(filename, FILENAME89);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 90:
                                                        strcat(filename, FILENAME90);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 91:
                                                        strcat(filename, FILENAME91);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 92:
                                                        strcat(filename, FILENAME92);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 93:
                                                        strcat(filename, FILENAME93);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 94:
                                                	    strcat(filename, FILENAME94);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 95:
                                                	    strcat(filename, FILENAME95);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 96:
                                                        strcat(filename, FILENAME96);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 97:
                                                        strcat(filename, FILENAME97);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 98:
                                                        strcat(filename, FILENAME98);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 99:
                                                	    strcat(filename, FILENAME99);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 100:
                                                	    strcat(filename, FILENAME86);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                  	
                                                case 101:
                                                        strcat(filename, FILENAME101);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 102:
                                                        strcat(filename, FILENAME102);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 103:
                                                	    strcat(filename, FILENAME103);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 104:
                                                	    strcat(filename, FILENAME104);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 105:
                                                        strcat(filename, FILENAME105);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 106:
                                                        strcat(filename, FILENAME106);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 107:
                                                        strcat(filename, FILENAME107);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 108:
                                                	    strcat(filename, FILENAME108);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 109:
                                                	    strcat(filename, FILENAME109);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;    
                                                case 110:
                                                        strcat(filename, FILENAME110);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 111:
                                                        strcat(filename, FILENAME111);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 112:
                                                        strcat(filename, FILENAME112);
                                                        readFromFile(filename, modePtr, keyPtr);    
                                                        break;    
                                                case 113:
                                                        strcat(filename, FILENAME113);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 114:
                                                        strcat(filename, FILENAME114);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 115:
                                                        strcat(filename, FILENAME115);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 116:
                                                        strcat(filename, FILENAME116);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 117:
                                                	    strcat(filename, FILENAME117);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 118:
                                                	    strcat(filename, FILENAME118);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;        	
                                                case 119:
                                                        strcat(filename, FILENAME119);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                
                                                case 120:
                                                        strcat(filename, FILENAME120);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;
                                                case 121:
                                                        strcat(filename, FILENAME121);
                                                        readFromFile(filename, modePtr, keyPtr);
                                                        break;                                                                                   
                                                default:                                                         
                                                  		printf( KRED"En ugyldig inputverdi '%d' har blitt registret.\n(Velg en verdi mellom [1-121])\n\n"RESET, menuChoice2 );
                  	 									break;      

                                        } // END OF SWITCH AUTOMATIC ENCODER MENU
                            
                                    }while( (menuChoice2 > 0 && menuChoice2 <=121) ||  isalpha(menuChoice2)  || !CLOSEDFILE);
                                    
                                     break; // END OF WHILE -AUTOMATIC ENCODER MENU

                        default:                  
		                        printf( KRED"En ugyldig inputverdi '%d' har blitt registret.\n(Velg en verdi mellom [0-2])\n\n"RESET, menuChoice );   
        		                break;
                    } // END OF SWITCH ENCODER MAIN MENU
                    
                    
                }while( (menuChoice > 0 && menuChoice <=2) || isalpha(menuChoice) || !CLOSEDFILE); //END OF WHILE ENCODER MAIN MENU    
                  
}

// END OF READFILE MENU 
bool decodeFileManually( char inputFileName[], const char *modePtr, char manualKey[] ){

	int dDistance = 0;
	char *manualKeyPtr = '\0';
	char *manualFilePtr = '\0';
	
	manualKeyPtr  = malloc(sizeof(char) *1024);
	manualFilePtr = malloc(sizeof(char) *1024);

	if( manualKeyPtr == NULL ){
		printf(KRED "Out of memory\n"RESET);
		return false;
	}

	// INPUT FILE NAME
	printf(KCYN"\nSKRIV INN NAVNET PÅ FILEN DU ØNSKER Å DECODE."RESET "\n(F.eks tast:  songLibrary/allThatSheWants.txt   +'Trykk Enter'  )\n:");
    scanf(" %s", inputFileName);
    manualFilePtr = strcat(manualFilePtr, inputFileName);
    printf("%s\n", manualFilePtr );

    // INPUT KEY 
    printf(KCYN"\nSKRIV INN TEKSTEN DU ØNSKER Å KRYPTERE."RESET "\n(F.eks tast:  Dette er en hemmlighet  +'Trykk Enter'  )\n:");
    scanf(" %[^\n]", manualKey);
	manualFilePtr = strcpy(manualKeyPtr, manualKey);

	// INPUT D DISTANCE
	printf(KCYN"\nSKRIV INN AVSTANDEN TIL '-d': ."RESET "\n(F.eks tast: '5' (betyr avstand d = 5) 'Trykk Enter'  )\n:");
	scanf("%d", &dDistance);
	printf("DU VALGTE d=%d\n", dDistance);
	// INPUT INTO READFILE
	readManualFile(inputFileName, modePtr, manualFilePtr, manualKeyPtr, dDistance ); 
    
    return true;
}

// READ FILE MANUAL
int readManualFile(char filename[], const char *modePtr, char *manualFilePtr,  char *manualKeyPtr, int dDistance){

		FILE* filePtr = NULL;
		int index = 0;
		
		char *message = malloc(sizeof(char)*2);
		int length = 2;
		int counter = 0 ;

		filePtr = fopen(filename, modePtr);
			
		if(filePtr == NULL ){
			filename[0] = '\0';
			printf(KRED "Error file '%s' does not exist, or could not be open...\n"RESET, filename );
		    return (-1);
		}
		// RESET FILENAME ARRAY
		if(filename != NULL){
			filename[0] = '\0';
		}
		
	 do{
	   		index = fgetc(filePtr);
	 
	   		if( alphabetic( index)){

	   			if( counter == length){
	   				length *=2;
	   				message = realloc( message, length*sizeof(char) );
	   			}
	   			message[counter++] = tolower(index);
	   		}

	   		if( feof(filePtr) ){
	   			break;
	   		}

	    }while(true);
	   
	   	//RESET  MESSAGE
	    message[counter]='\0';

	   	// PRINT OUT FILTRET OUTPUT AND KEY
	    printf(KMAG"\nFILTRET OUTPUT:\t" KGRN"%s\n"RESET, message ); 
		printf( KMAG"\nKEY"RESET KCYN":  %s\n\n"RESET, manualKeyPtr ); 
		decodeMessage(manualKeyPtr ,message, counter, dDistance);

		// RESET KEY
		if( manualKeyPtr !=NULL ){
			manualKeyPtr[0] = '\0';
		}
		
		CLOSEDFILE = closeManualFile( message, filePtr, manualFilePtr, manualKeyPtr );
		
		return 0;
}

// CLOSE FILE MANUAL
bool closeManualFile( char *message, FILE* filePtr, char *manualFilePtr, char *manualKeyPtr ) {

	int inputValue = 0 ;
	
	do {

		printf(KCYN "\nQUIT MENU\nVELG ET AV TRE VALG\n" MENUL RESET "\n[Tast '1' + enter]\tTilbake til DECODING\n[Tast '2' + enter]\tGÅ TIL ECNODING\n"KYEL"[Tast '3' + enter]\tAVSLUTTE PROGRAM)"RESET"\n" KCYN MENUL "\n:" RESET);
		scanf("%d", &inputValue);
	
		switch(inputValue){

			case 0: 
                    printf( KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret en default feilmelding : '%d' og vil nå avsluttes!\n" MENUL "\n"RESET, inputValue );
                  	exit(0);
                    break;
			case 1:
					CLOSEDFILE = false;
					return false;
					break;
			case 2:
					CLOSEDFILE = false;
					return false;
					//encoderMenu("", 0, 0, "r", "");
					break;		
			case 3: 
					printQuit();
					free(message);
					message = NULL;
					free(manualKeyPtr);
				    free(manualFilePtr);
				 	manualKeyPtr = NULL;
				 	manualFilePtr = NULL;
					fclose (filePtr);
					CLOSEDFILE = true;				
					break;
			default:
			 		printf( KRED"Error wrong key pressed: '%d'"RESET, inputValue );
			 		break;
		}


	} while(  inputValue !=3 && !CLOSEDFILE && !isalpha(inputValue)  ); 

	return false;
}

// ALPHABETIC CHECK IF INPUT-KEY CONTAINS lOWERCASE LETTERS
bool alphabetic( const char letter){

	if( ( letter >= 'a' && letter <= 'z') || ( letter >= 'A' && letter <= 'Z'))
		return true;
	else
		return false;
}

// ALPHABETIC CHECK IF INPUT-KEY CONTAINS UPPERCASE LETTERS
int alphabeticHigh( const char letter){

	if(  letter >= 'A' && letter <= 'Z'){
	
		 if( letter == 'A'){
		 	return A_LETTER;
		 }
		 if( letter == 'B'){
		 	return B_LETTER;
		 }
		 if( letter == 'C'){
		 	return C_LETTER;
		 }
		 if( letter == 'D'){
		 	return D_LETTER;
		 }
		 if( letter == 'E'){
		 	return E_LETTER;
		 }
		 if( letter == 'F'){
		 	return F_LETTER;
		 }
		 if( letter == 'G'){
		 	return G_LETTER;
		 }
		 if( letter == 'H'){
		 	return H_LETTER;
		 }
		 if( letter == 'I'){
		 	return I_LETTER;
		 }
		 if( letter == 'J'){
		 	return J_LETTER;
		 }
		 if( letter == 'K'){
		 	return K_LETTER;
		 }
		 if( letter == 'L'){
		 	return L_LETTER;
		 }
		 if( letter == 'M'){
		 	return M_LETTER;
		 }
		 if( letter == 'N'){
		 	return N_LETTER;
		 }
		 if( letter == 'O'){
		 	return O_LETTER;
		 }
		 if( letter == 'P'){
		 	return P_LETTER;
		 }
		 if( letter == 'Q'){
		 	return Q_LETTER;
		 }
		 if( letter == 'R'){
		 	return R_LETTER;
		 }
		 if( letter == 'S'){
		 	return S_LETTER;
		 }
		 if( letter == 'T'){
		 	return T_LETTER;
		 }
		 if( letter == 'U'){
		 	return U_LETTER;
		 }
		 if( letter == 'V'){
		 	return V_LETTER;
		 }
		 if( letter == 'W'){
		 	return W_LETTER;
		 }
		 if( letter == 'X'){
		 	return X_LETTER;
		 }
		 if( letter == 'Y'){
		 	return Y_LETTER;
		 }
		 if( letter == 'Z'){
		 	return Z_LETTER;
		 }
		 else
		 	return 1;
	}
	else
		return 0;
}

// COMPARE TO CHAR SEE IF ITS A NEIGHBOR
bool compareTwoCharPtr( int xInput, int yInput ) {

	if(xInput != yInput ){
		printf("TRUE  y= %.3d\n",  yInput );
		return true;	
	}	
	else
		printf("FALSE x= %.3d ", xInput  );
		return false;
}

// GET A CHARACTER WITH ITS POSITION IN THE ARRAY
int getCharPosition(char *fileArray, int arrayLength, char charTarget){
	
	char newCharTarget ='0';

	for( int i = 0 ; i < arrayLength; i++){

		if(fileArray[i] == charTarget ){
			return i;
		}
	}
	
	newCharTarget = tolower(charTarget);
	for(int j = 0 ; j < arrayLength; j++){

		if(fileArray[j] == newCharTarget ){
			j = j*UPPERCASE;
			return j;
		}
	}
	return newCharTarget;
}

// DECODE A MESSAGE WITH A KEY AND LOOP THROUGH ALL CHECKS
int decodeMessage(char *key, char *message, int counter, int dDistance) {

		if(dDistance == 0 || dDistance == 1){
			printf( KRED"Error D distance '%d' is to low!\n"RESET, dDistance);
		    return -1;		
		}

		char *messageArray = '\0';
		char bufferTempValue[64];
		int charPos = 0;
		messageArray = malloc( sizeof(char)*1000 );

		if( key == NULL ){
			printf( KRED"Error keyFile was not found, or where unable to open.\n" RESET);
		    return -1;
		}

		for(unsigned int j = 0; j < strlen(key); j++) {

			if( alphabetic (key[j]) ) {
					charPos = getCharPosition( message, counter, key[j] );		
					sprintf( bufferTempValue, "[%d]", charPos );
					messageArray = strcat( messageArray, bufferTempValue );				
			}
			else{
				sprintf(bufferTempValue, "%c", key[j] );
				messageArray = strcat(messageArray, bufferTempValue);
			}
		}
		printf(LINE"\n" KMAG"DIN KRYPTERTE KODE:  "RESET "%s\n" LINE "\n",messageArray );
		//writeToFile(messageArray);    //TODO READ FROM FILE

	    dDistance = 0;

		return 0;
}

bool encodeFileManually(char inputFileName[], const char *modePtr, char *keyPtr ){
	
	int dDistance = 0;
	char manualKey[100] = ""; 
		 modePtr = NULL;
	char *manualFilePtr = '\0';
	
	keyPtr  = malloc(sizeof(char) *1024);
	manualFilePtr = malloc(sizeof(char) *1024);

	if( keyPtr == NULL ){
		printf(KRED "Out of memory\n"RESET);
		return false;
	}

	// INPUT FILE NAME
	printf(KCYN"\nSKRIV INN NAVNET PÅ FILEN DU ØNSKER Å BRUKE TIL Å ENCODE."RESET "\n(F.eks tast:  songLibrary/allThatSheWants.txt   +'Trykk Enter'  )\n:");
    scanf(" %s", inputFileName);
    manualFilePtr = strcat(manualFilePtr, inputFileName);
    printf("%s\n", manualFilePtr );

    // INPUT KEY 
    printf(KCYN"\nSKRIV INN TEKSTEN DU ØNSKER Å ENCODE."RESET "\n(F.eks tast:  secret.txt  +'Trykk Enter'  )\n:");
    scanf(" %[^\n]", manualKey);
	keyPtr = strcpy(keyPtr, manualKey);

	// INPUT D DISTANCE
	printf(KCYN"\nSKRIV INN AVSTANDEN TIL '-d': ."RESET "\n(F.eks tast: '5' (betyr avstand d = 5) 'Trykk Enter'  )\n:");
	scanf("%d", &dDistance);
	printf("DU VALGTE d=%d\n", dDistance);
	// INPUT INTO READFILE
	readManualFile(inputFileName, modePtr, manualFilePtr, keyPtr, dDistance );   
	//TODO!!!
    
    return true;
}

int encodeMessage(char *key,char *message, int counter, int dDistance ){

	if(dDistance == 0 || dDistance == 1){
			printf( KRED"Error D distance '%d' is to low!\n"RESET, dDistance);
		    return -1;		
		}

		char *messageArray = '\0';
		char bufferTempValue[64];
		int charPos = 0;
		messageArray = malloc( sizeof(char)*1000 );

		if( key == NULL ){
			printf( KRED"Error keyFile was not found, or where unable to open.\n" RESET);
		    return -1;
		}

		for(unsigned int j = 0; j < strlen(key); j++) {

			if( alphabetic (key[j]) ) {
					charPos = getCharPosition( message, counter, key[j] );		
					sprintf( bufferTempValue, "[%d]", charPos );
					messageArray = strcat( messageArray, bufferTempValue );				
			}
			else{
				sprintf(bufferTempValue, "%c", key[j] );
				messageArray = strcat(messageArray, bufferTempValue);
			}
		}
		printf(LINE"\n" KMAG"DIN KRYPTERTE KODE:  "RESET "%s\n" LINE "\n",messageArray );
		writeToFile(messageArray);

	    dDistance = 0;

		return 0;
		// TODO!!
	return 0;
}

int writeToFile(char *messageArray ){
		FILE *filePtr = NULL;
		filePtr = fopen(SECRETFILE, "w");

		if( messageArray == NULL){
			printf( KRED"Error encryptet code was not found, or where unable to open.\n" RESET);
		    return -1;
		}
	
		if( messageArray != NULL){
			fprintf(filePtr,"%s", messageArray);
			printf(KMAG"<<<SUCCESSFULL COPY TEXT TO FILE>>\n" RESET);
			fclose(filePtr);
			messageArray =NULL;
			messageArray = '\0';
		}
		return 0;
}

// INSERT D DISTANCE
int chooseDistanceD(){

		int dDistance = 0;
		printf( KCYN MENUL "\nSKRIV INN AVSTANDEN TIL '-d':\n[Velg mellom]:" RESET" \nLow: d=2\t(Trykk '1')\nMed: d=4\t(Trykk '2')\nHig: d=6\t(Trykk '3')\n" KYEL MENUL "\n(Trykk '-1' for å avslutte programmet)\n" RESET"\n:");
		scanf("%d", &dDistance);

		do{
			switch(dDistance)
			{	
				case -1:
					printQuit();                        
					break;        
				case 0:
					printf( KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret default feilmelding: '%d' og vil nå avsluttes!\n"MENUL "\n"RESET, dDistance );
					exit(0);
					break;
				case 1:
					dDistance = DISTANCEL;
					break;
				case 2:
					dDistance = DISTANCEM;
					break;
				case 3:
					dDistance = DISTANCEL;
					break;
				default:
					printf(KRED "Error d is incorrect '%d' try again...\n"RESET, dDistance );
					break;
			}
		}while( (dDistance > 0 && dDistance <=3) || isalpha(dDistance) );

		return dDistance;
}

//READ FROM A FILE 'FILENAME, MODE, KEY'
int readFromFile( char filename[], const char *modePtr, char *key){

		int dDistance = 0;
		dDistance = chooseDistanceD();
		printf("%d\n", dDistance);
		printf("%s\n", filename );

		FILE* filePtr = NULL;
		int index = 0;
		
		char *message = malloc(sizeof(char)*2);
		int length = 2;
		int counter = 0 ;

		filePtr = fopen(filename, modePtr);

		if(filePtr == NULL ){
			printf(KRED "Error file '%s' does not exist, or could not be open...\n"RESET, filename );
			filename[0] = '\0';
		    return (-1);
		}
		// RESET FILENAME ARRAY
		if(filename != NULL){
			filename[0] = '\0';
		}
		
	   do{
	   		index = fgetc(filePtr);
	 
	   		if( alphabetic( index)){

	   			if( counter == length){
	   				length *=2;
	   				message = realloc( message, length*sizeof(char) );
	   			}
	   			message[counter++] = tolower(index);
	   		}
	   		if( feof(filePtr) ){
	   			break;
	   		}

	   }while(true);
	   
	   	//RESET  MESSAGE
	    message[counter]='\0';

	   	// PRINT OUT TEST OF FILE ARRAY
	    printf(KMAG"\nFILTRET OUTPUT:\t"RESET KGRN"%s\n\n"RESET, message ); 

	    // KEY MESSAGE PRINT OUT
		printf(KMAG"KEY:  "RESET KCYN"%s\n\n"RESET,key );  
		decodeMessage(key ,message, counter, dDistance);

		// CLOSE PROGRAM MENU
		CLOSEDFILE = quitProgram(message, filePtr);
		return 0;
}

// CLOSE FILE
bool quitProgram( char *message, FILE* filePtr) {

	int inputValue =0;
	
	do {

		printf(KCYN "\n[QUIT MENU]\nVELG ET AV TRE VALG\n" MENUL RESET "\n[Tast '1' + enter]\tTilbake til DECODING\n[Tast '2' + enter]\tGÅ TIL ENCODING\n"KYEL"[Tast '3' + enter]\tAVSLUTTE PROGRAM)"RESET"\n" KCYN MENUL "\n:" RESET);
		scanf("%d", &inputValue);
	
		switch(inputValue){

			case 0: 
                    printf( KRED MENUL"\nVerdien du tastet inn har skapt en feil.\nProgrammet har registret en default feilmelding : '%d' og vil nå avsluttes!\n" MENUL "\n"RESET, inputValue );
                  	exit(0);
                    break;
			case 1:
					CLOSEDFILE = false;
					return false;
					break;
			case 2:
					CLOSEDFILE = false;
					return false;
					//encoderMenu("", 0, 0, "r", "");
					break;
			case 3: 
					free(message);
					message = NULL;
					fclose (filePtr);
					CLOSEDFILE = true;
					printQuit();
					return true;
					break;
			default:
			 		printf(KRED"Error wrong key pressed: '%d'"RESET, inputValue);
			 		break;
		}

	} while(  inputValue !=2 && !CLOSEDFILE   ); 

	return false;
}

// PRINT OUT ASCII ART
void printQuit() {   
printf(KCYN"\nProgrammet avsluttes!\n\t\tØnsker deg en fin dag videre!\n\n"RESET);
unsigned int sleep();
printf(KYEL"                                                                 \n");
printf("                                                                 \n");
printf("                               : @+@                             \n");           
printf("                           : ' ;   @                            \n");          
printf("                           :   :@#@@;`                            \n");         
printf("                            .@::,,,,,,@                            \n");        
printf("                           :@:#:,,,,,,,,`                             \n");      
printf("                           @::@,,,,,,,,,,`                              \n");    
printf("          	         '::::,,,,,,,,,,.@                              \n");    
printf("                         :::::,,,,,,,,,,,`                               \n");  
printf("                         ::::::,,,,,,,,,,,.#                               \n");  
printf("                         @:::::,,,,,,,,,,,,;                               \n"); 
sleep(1);
printf("                         #:::::,,,,,,,,,,,,.                               \n"); 
printf("                         #:::::,,,,,,,,,,,,.;                              \n"); 
printf("                         @:::::,,@'@:,,,@'@:`                              \n");    
printf("                         ;:::::@     +:     @                              \n"); 
printf("                         ::::'       @      :                             \n"); 
printf("       @#,               ::::,              '               ,;;:          \n"); 
printf("    ':+:,,,              @:::  ;@         `.'              .:::';'        \n");   
printf("   :,,,;,,,              ::@:`          :'  +              +',:::,:       \n");  
printf("  @:,,,'@+@:            @ ::;@       @`..`@:              ;:,,@:,,:'      \n");  
printf(" .,,,;,,:,,,,`           @@::@:,     ',,,,,:+             ;:,,,,','::#     \n");  
printf(" +,,,,:;,,,,,@           @ @::::#,`:+,,,,,:+.             @::,,,.+:,,,,    \n");  
printf(" ;+,,,':,,.:,+           ; @::::,,,:'#+'#@,.@             +:,;,,`:,,,,@    \n");  
printf(" ;@:,,,,.`@,,'            ,+#:::,#:::::::,,,,.`           #:,,@.+:,;:,;    \n");  
printf("  @::::@,++,,,,            ,:,:::@:,,,,,,,,,,,,#..        @::,,:,,+:',.     \n");  
printf("  ::';:,,@,,,.@          ::'+::+:,,,,,,,,,,,,,,,,`      @:::,:,,,,,,.@     \n");  
printf("   ':::::,,,,,,.@          :::::;,,,,,,,,,,,,,,+,+      @:::,,,,,,,,.+      \n");  
printf("   @::::,,,,,,,.@          @@:::,,,,,,,,,,,,,,@,      #:::,,,,,,,,`@       \n");  
printf("    @:::,,,,,,,,.@          #:;:,,,,,,,,,,,,,,,.    `':::,,,,,,,,.'        \n");  
sleep(1); 									
printf("     #:::,,,,,,,,.;         @:::,,,,,,,,,,,,,;.@   .::::,,,,,,,,.@         \n"); 
printf("      ;:::,,,,,,,,,.        @:::,,,,,,,,,,,,,     #::::,,,,,,,,.:          \n");  
printf("      .:::,,,,,,,,,,`,      @::@:,,,,,,,,,,,     @::::,,,,,,,,,`           \n");  
printf("       #:::,,,,,,,,,,.@     @:::@,,,,,,,,,'    `;::::,,,,,,,,,`.           \n");  
printf("        @:::,,,,,,,,,,,'.:  @::::@,,,,,,,@   ++':::,,,,,,,,,,`@            \n");  
printf("         +:::,,,,,,,,,,,,@@ #::::,,;@@@:.@ `@```+:,,,,,,,,,,`@             \n");  
printf("          ;:::,,,,,,,,,,,@`@#:``    .,,,.@;::```` ,,,,,,,,,.+              \n");  
printf("           ::::,,,,,,,,,,  `@```     .,,,@` .```   :,,,,,,.,               \n");  
printf("           `::::,,,,,,,,+   `:`    ,  @,,''  ``     ,,,,,..                \n");  
printf("            ,::::,,,,,,,`    ,`    @   +,'#  '       ,,,,`                 \n");  
printf("             :::::,,,,,#     `;    :    .    +       @,,``                 \n");  
printf("              :::::,,,,       :@@@@        ; :        ,``                  \n");  
printf("               ,::::,,:                     .         '.                   \n");  
printf("                ,::::@         ,            +                              \n");  
printf("                 `;:@                                 @                    \n");  
printf("                  `@``                       '       @                     \n");  
printf("                   @````                      +      +                      \n");  
printf("                   '`````                         @                        \n");  
printf("                     @````                   ':@.                          \n");  
sleep(1); 
printf("                       .@@##                  '                            \n");  
printf("                        '``                    `                           \n");  
printf("                       @``                                                 \n");  
printf("                       ````                       ,                        \n");    
printf("                      ```                         @                        \n");   
printf("                     ;```                          `                       \n");   
printf("                    @````                          ;                       \n");   
printf("                   .````                            `                      \n");   
printf("                   :````                            @                      \n");   
printf("                  +`````                                                   \n");   
printf("                  ,`````                             .                     \n");   
printf("                 :``````                             @                     \n");   
printf("                 @``````        .:'+@@@@':.          @                     \n");   
printf("                 .`````   ,@+:::::,,,,,,:,:::;@'     '                     \n");   
printf("                 ``````@+::::,,,,,,,,,,'#,,,,,,::;@  ;                     \n");   
printf("                 ```:#;;:::'@@':,,,,,,,,,,,,,,,,:+@:++                     \n");   
printf("                 @@;;;;;:::::::::::::;;;;;;;::::::::@+					   \n");   	
sleep(1); 
printf("																			\n");  
printf("																			\n"RESET);  
printf(KCYN" \t\t\t\tØNSKER DEG EN RIKTIG GOD KVELD! \n\n"RESET);

exit(0);
 }


