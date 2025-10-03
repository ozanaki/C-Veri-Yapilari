/*************************************************************************
* Proje : cost graph - dijkstra algoritmasiyla en kisa yol
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 6

int graf[N][N];
char rota[N][256];
int ekm[N];

void komsuyap(char x, char y, int cost)
{
	if(x<'A' || x>='A'+N) return;
	if(y<'A' || y>='A'+N) return;
	graf[x-'A'][y-'A']=cost;
}

void Dijkstra(char basla)
{
	char tmp[16], ok[N]={0};
	int i,j,ead,ek;
	
	if(basla<'A' || basla>='A'+N) return;
		
	for(i=0; i<N; ++i)
		for(j=0; j<N; ++j)		
			rota[i][j]=0;

	for(i=0; i<N; ++i) ekm[i]=INT_MAX;
	ead=basla-'A';
	ekm[ead]=0;
		
	for(i=0; i<N; ++i)
	{
		for(j=0; j<N; ++j)
		{
			if(!ok[j])
			{
				if(graf[ead][j]>0)
				{
					if(ekm[j]>graf[ead][j]+ekm[ead])
					{
						ekm[j]=graf[ead][j]+ekm[ead];
						strcpy(rota[j],rota[ead]);
						sprintf(tmp,"%c->",'A'+ead);
						strcat(rota[j],tmp);
					}
				}
			}
		}
		ek=INT_MAX;
		for(j=0; j<N; j++)
		{
			if(!ok[j])
			{
				if(ekm[j]<ek)
				{
					ek=ekm[j];
					ead=j;
				}
			}
		}
		ok[ead]=1;
	}
	for(i=0; i<N; ++i)
	{
		sprintf(tmp,"%c",'A'+i);
		strcat(rota[i],tmp);
	}
}

void git(char basla, char hedef)
{
	if(basla<'A' || basla>='A'+N) return;
	if(hedef<'A' || hedef>='A'+N) return;
	
	Dijkstra(basla);
	
	printf("En kisa rota: %s\n",rota[hedef-'A']);
	printf("En kisa rota maliyeti: %d\n",ekm[hedef-'A']);
}

int main(int argc, char *argv[]) 
{
	int i,j;
	char konum,hedef;
		
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			graf[i][j]=0;

	komsuyap('A','C',3);
	komsuyap('A','D',5);
	komsuyap('B','C',2);
	komsuyap('B','E',10);
	komsuyap('B','F',3);
	komsuyap('C','A',3);
	komsuyap('C','B',2);
	komsuyap('C','D',8);
	komsuyap('D','A',5);
	komsuyap('D','C',8);
	komsuyap('D','E',4);
	komsuyap('E','D',4);
	komsuyap('E','B',10);
	komsuyap('E','F',6);
	komsuyap('F','B',3);
	komsuyap('F','E',6);
	
	printf("Komsuluk Matrisi: \n");
	printf("\t");
	for(i=0;i<N;i++)
	{
		printf("%c\t",'A'+i);
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		printf("%c\t",'A'+i);
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

	printf("\nDijkstra en kucuk maliyet tablosu:\n");
	for(i=0; i<N; i++)
	{
		printf("ekm[%c]=%d\n",'A'+i,ekm[i]);
	}

	printf("\nDijkstra en kisa rotalar:\n");
	for(i=0; i<N; i++)
	{
		printf("rota[%c]=%s\n",'A'+i,rota[i]);
	}
	printf("\n");

	return 0;
}

