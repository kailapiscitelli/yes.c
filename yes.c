//Kaila Piscitelli
//September 22nd 2018
//CMSC 226
//yes part II

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 65536

int main(int argc, char *argv[]){

	char array[BUFF_SIZE];
	array[0]='\0';
	int sz;

	if(argc==1){
		char yes[]={"y\n"};

		int currentIndx = 1;
		
		while (currentIndx<BUFF_SIZE-2){
			strcat(array, yes);
			currentIndx += 2;
		}
	
		while(1){
			
			write(1, array, BUFF_SIZE);
		}
	}
	else {

		 if (strcmp(argv[1], "--help")==0){
				printf("%s\n", "Display a help message, and exit.");
				return 0;
			}
		else if (strcmp(argv[1], "--version")==0){
				printf("%s\n", "Display version information, and exit.");
				return 0;
			}

		else {

			// argv = ["yes.c", "hello", "world"]

			// "hello world\n"

			/* calculate length of all arguments */
			int exactLength = 0;
			for (int i=1; i<argc; i++){
				exactLength += strlen(argv[i]) +1;
			}

			exactLength += 2;   // for \n and \0

			/* make a char array to hold all arguments*/
			char fullString[exactLength];
			fullString[0]='\0';

			for (int i=1; i<argc; i++){
				strcat(fullString, argv[i]);
				strcat(fullString, " ");
			}

			strcat(fullString, "\n");


			/*loop through each index of buffer concatenating string*/
			int currentIndx = 1;
			while (currentIndx < BUFF_SIZE-exactLength){
				strcat(array, fullString);
				currentIndx += exactLength;
			}

			while(1){

				sz= write(1, array, BUFF_SIZE); 

				}
			}
		return 0;
	}
}
