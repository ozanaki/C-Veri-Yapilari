/*************************************************************************
* Proje : finite state machines - trafik isiklari
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int state;

int main(int argc, char *argv[]) 
{
	char c;
	state=0;

	printf("Sonraki duruma gecmek icin SPACE, cikmak icin ESC tusuna basiniz.\n");
	for(;;)
	{
		do {
			c=getch();
			if(c==27) return; //ESC tusuna basildiysa cik.
		} while(c!=32);
		
			
		switch(state)
		{
			case 0: {
				printf("KIRMIZI ->");
				state=1;
				break;
			}			
			case 1: {
				printf("KIRMIZI ve SARI-> ");
				state=2;
				break;
			}			
			case 2: {
				printf("YESIL -> ");
				state=3;
				break;
			}			
			case 3: {
				printf("SARI -> ");
				state=0;
				break;
			}			
		}

	}
	return 0;
}
