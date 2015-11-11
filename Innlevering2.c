/* Innlevering 2 by Paul Hasfjord
	ENCODER / DECODER 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "secretCoder.h"
#include "secret.h"
#include "fileList.h"
#include "textColor.h"	

#define MAX_FILES_SIZE 850


static bool CLOSEDFILE = false;

bool alphabetic( const char letter);
bool space( const char letter);
int countLetter( const char string[]);

int readFromFile(  char filename[], const char *mode, char *testKey);
bool closeFile( char *fileKey, FILE* filePtr );

int decoder(char *key,char *message, int counter);
char alphabeticHigherCase(const char letter);
//char convertToArray(int aNumber, char character);
void encoderMenu(char printOut[], char filename[], int menuChoice, int menuChoice2, char inputFileName[], const char *mode, char *testKey);

// PRINT OUT
void printOut(int index, int numbersOfFile[], int numChoice, int totalSum, char filename[]);
void printQuit();

int main(void ){	
	
	

		char printOut[45] = "------------------------------------------";
        char filename[1000] = "";
        int menuChoice =0, menuChoice2 =0;
        char inputFileName[100];
	
        encoderMenu(printOut, filename, menuChoice, menuChoice2, inputFileName, "r", SECRETSTRING);

		//readFromFile(FILENAME3, "r", SECRETSTRING);
		return 0;		
}

// MENU
void encoderMenu(char printOut[], char filename[], int menuChoice, int menuChoice2, char inputFileName[], const char *mode, char *testKey){
                mode = "r";
                do{    //MENU CHOICE
                	
                    printf(KCYN"\n%s\nVELKOMMEN TIL INNLEVERING 2.0\n\t<<'Kodeknekker'n'>>"RESET KYEL"\n%s\nVelg et av valgene under fra menyen:\n(Tast inn et tall mellom [1-3] +Trykk 'Enter')\n%s\n"RESET, printOut, printOut, printOut);
                    printf("[Tast 1]\tSkriv navet på filen du vil kryptere fra keyboard.\n");
                    printf("[Tast 2]\tVelg en fil fra en ferdig liste.\n%s", printOut);
                    printf(KYEL"\n([Tast 3] for å 'avslutt programmet')\n:"RESET);
                    scanf("%d", &menuChoice);
                    
                    switch( menuChoice){

                            case 1:
                                    //READ FILE FROM KEYBOARD INPUT    
                                    printf(KCYN"\nSKRIV INN NAVNET PÅ FILEN DU ØNSKER Å ÅPNE."RESET "\n(F.eks tast:  songLibrary/allThatSheWants.txt   +'Trykk Enter'  )\n:");
                                    scanf(" %s", inputFileName);
                                    strcat(filename, inputFileName);
                                    readFromFile(filename, "r", testKey);

                                    break;

                            case 2:
                                    do{
                                        // READ FILE FROM LIST
                                        printf(KCYN "\n%s\nVelg en av filene fra listen: \n(Tast inn et tall mellom [1-121] + Trykk 'Enter')\n%s\n"RESET ,printOut, printOut);
                               //TODO!!
                                        printf("[Tast 1]: %s\n",   FILENAME1 );
                                        printf("[Tast 2]: %s\n",   FILENAME2 );
                                        printf("[Tast 3]: %s\n",   FILENAME3 );
                                       	printf("[Tast 4]: %s\n",   FILENAME4 );
                                        printf("[Tast 5]: %s\n",   FILENAME5 );
                                        printf("[Tast 6]: %s\n",   FILENAME6 );
                                        printf("[Tast 7]: %s\n",   FILENAME7 );
                                        printf("[Tast 8]: %s\n",   FILENAME8 );
                                        printf("[Tast 9]: %s\n",   FILENAME9 );
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
                                                                    
                                        printf(KYEL"\n([Tast 0]: For å 'avslutte')\n\n:"RESET );
                                        scanf(" %d", &menuChoice2);
                            
                                        switch( menuChoice2 ){

                                                case 1:                                                                                                    
                                                        strcat(filename, FILENAME1);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 2:
                                                        strcat(filename, FILENAME2);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;                                                  
                                                case 3:
                                                        strcat(filename, FILENAME3);
                                                        readFromFile(filename, mode, testKey);  
                                                        break;
                                                case 4:
                                                        strcat(filename, FILENAME4);
                                                        readFromFile(filename, mode, testKey);  
                                                        break;
 												case 5:
                                                        strcat(filename, FILENAME5);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 6:
                                                        strcat(filename, FILENAME6);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                               
                                                case 7:
                                                        strcat(filename, FILENAME7);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 8:
                                                        strcat(filename, FILENAME8);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 9:
                                                        strcat(filename, FILENAME9);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;    
                                                case 10:
                                                        strcat(filename, FILENAME10);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 11:
                                                        strcat(filename, FILENAME11);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 12:
                                                        strcat(filename, FILENAME12);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 13:
                                                        strcat(filename, FILENAME13);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 14:
                                                	    strcat(filename, FILENAME14);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 15:
                                                	    strcat(filename, FILENAME15);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 16:
                                                        strcat(filename, FILENAME16);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 17:
                                                        strcat(filename, FILENAME17);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                  
                                                case 18:
                                                        strcat(filename, FILENAME18);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 19:
                                                        strcat(filename, FILENAME19);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
 												case 20:
                                                        strcat(filename, FILENAME20);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 21:
                                                        strcat(filename, FILENAME21);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                               
                                                case 22:
                                                        strcat(filename, FILENAME22);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 23:
                                                        strcat(filename, FILENAME23);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 24:
                                                        strcat(filename, FILENAME24);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;    
                                                case 25:
                                                        strcat(filename, FILENAME25);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 26:
                                                        strcat(filename, FILENAME26);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 27:
                                                        strcat(filename, FILENAME27);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 28:
                                                        strcat(filename, FILENAME28);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 29:
                                                	    strcat(filename, FILENAME29);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 30:
                                                	    strcat(filename, FILENAME30);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 31:
                                                        strcat(filename, FILENAME31);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 32:
                                                        strcat(filename, FILENAME32);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                  
                                                case 33:
                                                        strcat(filename, FILENAME33);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 34:
                                                        strcat(filename, FILENAME34);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
 												case 35:
                                                        strcat(filename, FILENAME35);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 36:
                                                        strcat(filename, FILENAME36);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                               
                                                case 37:
                                                        strcat(filename, FILENAME37);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 38:
                                                        strcat(filename, FILENAME38);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 39:
                                                        strcat(filename, FILENAME39);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;    
                                                case 40:
                                                        strcat(filename, FILENAME40);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 41:
                                                        strcat(filename, FILENAME41);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 42:
                                                        strcat(filename, FILENAME42);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 43:
                                                        strcat(filename, FILENAME43);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 44:
                                                	    strcat(filename, FILENAME44);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 45:
                                                	    strcat(filename, FILENAME45);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 46:
                                                        strcat(filename, FILENAME46);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 47:
                                                        strcat(filename, FILENAME47);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                  
                                                case 48:
                                                        strcat(filename, FILENAME48);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 49:
                                                        strcat(filename, FILENAME49);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
 												case 50:
                                                        strcat(filename, FILENAME50);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 51:
                                                        strcat(filename, FILENAME51);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                               
                                                case 52:
                                                        strcat(filename, FILENAME52);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 53:
                                                        strcat(filename, FILENAME53);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 54:
                                                        strcat(filename, FILENAME54);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;    
                                                case 55:
                                                        strcat(filename, FILENAME55);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 56:
                                                        strcat(filename, FILENAME56);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 57:
                                                        strcat(filename, FILENAME57);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 58:
                                                        strcat(filename, FILENAME58);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 59:
                                                	    strcat(filename, FILENAME59);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 60:
                                                	    strcat(filename, FILENAME60);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 61:
                                                        strcat(filename, FILENAME61);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 62:
                                                        strcat(filename, FILENAME62);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 63:
                                                        strcat(filename, FILENAME63);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 64:
                                                        strcat(filename, FILENAME64);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 65:
                                                	    strcat(filename, FILENAME65);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 66:
                                                	    strcat(filename, FILENAME66);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 67:
                                                        strcat(filename, FILENAME67);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 68:
                                                        strcat(filename, FILENAME68);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                  
                                                case 69:
                                                        strcat(filename, FILENAME69);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 70:
                                                        strcat(filename, FILENAME70);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
 												case 71:
                                                        strcat(filename, FILENAME71);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 72:
                                                        strcat(filename, FILENAME72);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                               
                                                case 73:
                                                        strcat(filename, FILENAME73);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 74:
                                                        strcat(filename, FILENAME74);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 75:
                                                        strcat(filename, FILENAME75);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;    
                                                case 76:
                                                        strcat(filename, FILENAME76);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 77:
                                                        strcat(filename, FILENAME77);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 78:
                                                        strcat(filename, FILENAME78);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 79:
                                                        strcat(filename, FILENAME79);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 80:
                                                	    strcat(filename, FILENAME80);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 81:
                                                	    strcat(filename, FILENAME81);
                                                        readFromFile(filename, mode, testKey);
                                                        break;        	
                                                case 82:
                                                        strcat(filename, FILENAME82);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 83:
                                                        strcat(filename, FILENAME83);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 84:
                                                        strcat(filename, FILENAME84);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 85:
                                                	    strcat(filename, FILENAME85);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 86:
                                                	    strcat(filename, FILENAME86);
                                                        readFromFile(filename, mode, testKey);
                                                        break;    
                                                case 87:
                                                        strcat(filename, FILENAME87);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 88:
                                                        strcat(filename, FILENAME88);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 89:
                                                        strcat(filename, FILENAME89);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;    
                                                case 90:
                                                        strcat(filename, FILENAME90);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 91:
                                                        strcat(filename, FILENAME91);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 92:
                                                        strcat(filename, FILENAME92);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 93:
                                                        strcat(filename, FILENAME93);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 94:
                                                	    strcat(filename, FILENAME94);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 95:
                                                	    strcat(filename, FILENAME95);
                                                        readFromFile(filename, mode, testKey);
                                                        break;        	
                                                case 96:
                                                        strcat(filename, FILENAME96);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 97:
                                                        strcat(filename, FILENAME97);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 98:
                                                        strcat(filename, FILENAME98);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 99:
                                                	    strcat(filename, FILENAME99);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 100:
                                                	    strcat(filename, FILENAME86);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                  	
                                                case 101:
                                                        strcat(filename, FILENAME101);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 102:
                                                        strcat(filename, FILENAME102);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 103:
                                                	    strcat(filename, FILENAME103);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 104:
                                                	    strcat(filename, FILENAME104);
                                                        readFromFile(filename, mode, testKey);
                                                        break;        	
                                                case 105:
                                                        strcat(filename, FILENAME105);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 106:
                                                        strcat(filename, FILENAME106);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 107:
                                                        strcat(filename, FILENAME107);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 108:
                                                	    strcat(filename, FILENAME108);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 109:
                                                	    strcat(filename, FILENAME109);
                                                        readFromFile(filename, mode, testKey);
                                                        break;    
                                                case 110:
                                                        strcat(filename, FILENAME110);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 111:
                                                        strcat(filename, FILENAME111);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 112:
                                                        strcat(filename, FILENAME112);
                                                        readFromFile(filename, mode, testKey);    
                                                        break;    
                                                case 113:
                                                        strcat(filename, FILENAME113);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 114:
                                                        strcat(filename, FILENAME114);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 115:
                                                        strcat(filename, FILENAME115);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 116:
                                                        strcat(filename, FILENAME116);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 117:
                                                	    strcat(filename, FILENAME117);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 118:
                                                	    strcat(filename, FILENAME118);
                                                        readFromFile(filename, mode, testKey);
                                                        break;        	
                                                case 119:
                                                        strcat(filename, FILENAME119);
                                                        readFromFile(filename, mode, testKey);
                                                        break;                                                
                                                case 120:
                                                        strcat(filename, FILENAME120);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                                case 121:
                                                        strcat(filename, FILENAME121);
                                                        readFromFile(filename, mode, testKey);
                                                        break;
                                            	
                                            	/// END OF FILE LIST
                                                       		
                                                case 0:
                                    					printf(KCYN"\nProgrammet avsluttes!\n\t\tØnsker deg en fin dag videre!\n\n"RESET);
                                                		printQuit();
														break;
                                                     

                                                default:        
                                                        printf(KRED"En ugyldig inputverdi har blitt registret.\n --> Velg en verdi mellom [1-121] <--\n\n"RESET);
                                                    
                                        }
                            
                                    }while( menuChoice2 < 0 && menuChoice2 >121 && menuChoice2 != 0 && !isdigit(menuChoice2)  && !CLOSEDFILE);
                                                break;
                            case 3:

                                    printf(KCYN"\nProgrammet avsluttes!\n\t\tØnsker deg en fin dag videre!\n\n" RESET);
                                    printQuit();                        
                                    break;
                            
                            default:
                                printf(KRED"En ugyldig inputverdi har blitt registret.\t\t --> Velg en verdi mellom [1..3] <--\n\n"RESET);                            
                    }

                }while( menuChoice !=3 && menuChoice !=0 && !isdigit(menuChoice) && !CLOSEDFILE );
            
}// END OF READFILE MENU        


// ALPHABETIC CHECK IF INPUT-KEY CONTAINS LETTERS
bool alphabetic( const char letter){
	if( ( letter >= 'a' && letter <= 'z') || ( letter >= 'A' && letter <= 'Z'))
		return true;
	else
		return false;
}
// ALPHABETIC CHECK IF INPUT-KEY CONTAINS CAPTIAL LETTERS
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

// GET A CHARACTER WITH ITS POSITION IN THE ARRAY
int getCharPosition(char *fileArray, int arrayLength, char charTarget){

	for( int i = 0 ; i < arrayLength; i++){

		if(fileArray[i] == charTarget ){
			return i;
		}
	}
	return -1;
}

// CLOSE FILE
bool closeFile( char *message, FILE* filePtr ){
	int inputValue;
	
	printf(KYEL"\nØnsker du og fortsette programmet?\n" RESET "JA = '1' \tNEI = '2': " );
	scanf("%d", &inputValue);

	if(inputValue == 1){
			return false;
	}
	else if( inputValue == 2) {
			free(message);
			message = NULL;
			fclose (filePtr);
			CLOSEDFILE = true;
			printQuit();
			return true;
	}
	else
		printf(KRED"%d Error wrong key pressed!"RESET, inputValue);
		return false;		
}	


// COMPARE TO CHAR SEE IF ITS A NEIGHBOR
bool compareToChar( char xInput, char yInput ) {

	if(xInput != yInput  )
		return true;			
	else
		return false;
		
}

// CONVERT A CHAR TO INT WITH MINUS
char convertToArray(int aNumber, char character){
	
		character = aNumber + '0';
		return character;

}

// DECODE A MESSAGE WITH A KEY AND LOOP THROUGH ALL CHECKS
int decoder(char *key, char *message, int counter){
		char *messageArray = '\0';
		char bufferTempValue[64];
		messageArray = malloc(sizeof(char)*10000);
		//messageArray ='\0';

		if( key == NULL ){
			printf(KRED"Error filekey was not found, or where unable to open.\n" RESET);
		    return -1;
		}

		for(unsigned int j = 0; j < strlen(key); j++) {

		//	printf("%c", key[j] );  // change name to message
			if( alphabetic (key[j] )){
				
				int charPos = getCharPosition(message, counter, key[j]);
				
				sprintf(bufferTempValue, "[%d]", charPos );
				printf("%s\n", bufferTempValue );
				messageArray = strcat(messageArray, bufferTempValue);
				printf("%s\n", messageArray );

				if( compareToChar(key[j], key[j+1] )){


			//		printf("[%d] ", charPos);
					//str[j] = convertToArray(charPos, test[j] );
					//printf("%c\n", str[j]);
				}
			}else{
				sprintf(bufferTempValue, "%c", key[j] );
				messageArray = strcat(messageArray, bufferTempValue);
			//	printf("%s\n", messageArray );

			}
		}

		free(messageArray);
		return 0;
}

//READ FROM A FILE WITH INPUT MODE AND KEY
int readFromFile( char filename[], const char *mode, char *key){

	
		printf("%s\n", filename );

		FILE* filePtr = NULL;
		int index = 0;
		
		char *message = malloc(sizeof(char)*2);
		int length = 2;
		int counter = 0 ;

		filePtr = fopen(filename, mode);

		if(filePtr == NULL ){
			printf(KRED " Error file '%s' does not exist, or could not be open...\n"RESET, filename );
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
	    printf(KGRN"%s\n\n"RESET, message ); // change name to key

	    // KEY MESSAGE PRINT OUT
		printf(KGRN"\n%s\n\n"RESET,key );   // change name to message
		decoder(key ,message, counter);

		// ASK FOR EXIT
		CLOSEDFILE = closeFile(message, filePtr);
		
		return 0;
}

// PRINT OUT ASCII ART
void printQuit(){   
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
printf("                          ::::'       @      :                             \n"); 
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
printf("                  @````                      +      +                      \n");  
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
printf(KYEL" \t\t\t\tGOOD BYE! \n\n"RESET);

exit(0);
 }
/*    
	   
	   
		char* decodedMessage;
		int status;
		
		decodedMessage = decode("secretCoder.txt", FILENAME1, 1);
		status = decode("secretCoder.txt", FILENAME1, decodedMessage);
	
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

		 example usage :
		[1] decodedMessage = decode("myCode.txt", "hotelCalifornia.txt", &status);
		[2] status = decode("myCode.txt", "hotelCalifornia.txt", decodedMessage);

	*/

