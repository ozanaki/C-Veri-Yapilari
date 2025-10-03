#include <stdio.h>
#include <stdlib.h>

int disk;
int move;

void hanoi(int disk, char From, char Temp, char To)
{
	if(disk==1)
	{
		move++;
		printf("%d. %c -> %c\n", move, From, To);
	}
	else
	{
		hanoi(disk-1,From,To,Temp);
		move++;
		printf("%d. %c -> %c\n", move, From, To);
		hanoi(disk-1,Temp,From,To);
	}
}

int main(int argc, char *argv[])
{
	printf("Disk sayisi: ");
	scanf("%d", &disk);

	hanoi(disk,'A','B','C');

	system("pause");
	return 0;
}