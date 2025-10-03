/*************************************************************************
* Proje : finite state machines
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
				printf("(State %d) -> ",state);
				state=3;
				break;
			}			
			case 1: {
				printf("State %d -> ",state);
				state=4;
				break;
			}			
			case 2: {
				printf("State %d -> ",state);
				state=0;
				break;
			}			
			case 3: {
				printf("State %d -> ",state);
				state=1;
				break;
			}			
			case 4: {
				printf("State %d -> ",state);
				state=2;
				break;
			}			
		}

	}
	return 0;
}
