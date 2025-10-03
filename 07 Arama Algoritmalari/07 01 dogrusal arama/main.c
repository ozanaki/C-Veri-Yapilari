/*************************************************************************
* Proje : Arama algoritmalari - dogrusal arama
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

	printf("Aranan sayiyi girin:");
	scanf("%d",&aranan);
	
	printf("%d sayisi sirasiz dizide araniyor...\n");
	iter=0; indis=-1;
	for(i=0; i<len; i++)
	{
		iter++;
		if(dizi[i]==aranan)
		{
			indis=i;
			break;
		} 
	}
	if(indis>=0)
		printf("Sayi %d iterasyonda %d indiside bulundu.\n",iter,indis);
	else
		printf("Sayi %d iterasyonda bulunamadi.\n",iter);	

	printf("\nDizi siralaniyor...\n");
  insertion_sort(dizi,len);
  
	printf("%d sayisi sirali dizide araniyor...\n",aranan);
	iter=0; indis=-1;
	for(i=0; i<len; i++)
	{
		iter++;
		if(dizi[i]==aranan)
		{
			indis=i;
			break;
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
