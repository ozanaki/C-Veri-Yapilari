/*************************************************************************
* Proje : Arama algoritmalari - ikili arama
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a, int n);

int main(int argc, char *argv[])
{
	int i,len,*dizi;
	int aranan,indis,iter;
	int sol,orta,sag;
	double diff;
	
  printf("Kac elemanli dizi olsun: ");
  scanf("%d", &len);
  dizi = (int*)malloc(sizeof(int)*len);
  if(dizi==NULL)
	{
		printf("Yeterli bellek yok!\n");
		return 0;
	}
	
	printf("\nDizi rasgele sayilarla dolduruluyor...\n");
	srand(time(NULL));
	for(i=0; i<len; i++)
	{
		 dizi[i] = rand();
		 printf("%5d   ",dizi[i]);
	}

	printf("\nDizi siralaniyor...\n");
  insertion_sort(dizi,len);
    
	printf("Aranan sayiyi girin:");
	scanf("%d",&aranan);
	
	printf("%d sayisi sirali dizide araniyor...\n",aranan);
	iter=0; indis=-1;
	sol=0; sag=len-1;
	while(sol<=sag)
	{
		iter++;
		orta=(sol+sag)/2;
		if(aranan==dizi[orta])
		{
			indis=orta;
			break;
		}
		else if(aranan>dizi[orta])
		{
			sol=orta+1;
		}
		else
		{
			sag=orta-1;	
		}
	}
	if(indis>=0)
		printf("Sayi %d iterasyonda %d indiside bulundu.\n",iter,indis);
	else
		printf("Sayi %d iterasyonda bulunamadi.\n",iter);	

	free(dizi);
	
  return 0;
}
//-----------------------------------------------
void insertion_sort(int *a, int n)
{
  int k;
  for (k = 1; k < n; ++k)
	{
    int key = a[k];
    int i = k - 1;
    while ((i >= 0) && (key < a[i]))
		{
      a[i + 1] = a[i];
      --i;
    }
    a[i + 1] = key;
  }
}

