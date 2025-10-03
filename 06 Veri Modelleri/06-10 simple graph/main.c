/*************************************************************************
* Proje : simple graph
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define N 6

int graf[N][N];
int ok[N];

void komsuyap(char x, char y)
{
	if(x<'A' || x>='A'+N) return;
	if(y<'A' || y>='A'+N) return;
	graf[x-'A'][y-'A']=1;
}

int dolas(int dugum,int hedef)
{
	int i,t;
	if(dugum<0 || dugum>=N) return 0;
	if(hedef<0 || hedef>=N) return 0;
	ok[dugum]=1;
	if(dugum==hedef)
	{
		printf("%c. ",'A'+hedef);
		return 1;
	} else printf("%c -> ",'A'+dugum);
	
	for(i=0; i<N; i++)
	{
		if(graf[dugum][i]>0 && ok[i]==0)
		{
			if(dolas(i,hedef)) break;
		}
	}
	return 0;
}

// DFS (Depth-First Search) Algoritmasi
void git(char basla, char hedef)
{
	int i;
	if(basla<'A' || basla>='A'+N) return;
	if(hedef<'A' || hedef>='A'+N) return;
		
	for(i=0;i<N;i++) ok[i]=0;
	ok[basla-'A']=1;
	
	printf("\nRota: ");
	dolas(basla-'A',hedef-'A');
	printf("\n");
}

int main(int argc, char *argv[]) 
{
	int i,j;
	char konum,hedef;
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			graf[i][j]=0;

	komsuyap('A','C');
	komsuyap('A','D');
	komsuyap('B','C');
	komsuyap('B','E');
	komsuyap('B','F');
	komsuyap('C','A');
	komsuyap('C','B');
	komsuyap('C','D');
	komsuyap('D','A');
	komsuyap('D','C');
	komsuyap('D','E');
	komsuyap('E','D');
	komsuyap('E','B');
	komsuyap('E','F');
	komsuyap('F','B');
	komsuyap('F','E');
	
	printf("\t");
	for(i=0;i<N;i++)
	{
		printf("%c\t",i+'A');
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		printf("%c\t",i+'A');
		for(j=0;j<N;j++)
		{
			printf("%d\t",graf[i][j]);
		}
		printf("\n");
	}

	fflush(stdin);
	printf("\nNereden: ");
	konum=getchar();
	fflush(stdin);
	printf("Nereye: ");
	hedef=getchar();
	
	git(konum,hedef);

	return 0;
}
