/*************************************************************************
* Proje : Siralama algoritmalari - Selection Sort
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *p, int size)
{
   int   i, j, temp, min;
 
   for (i = 0; i < size - 1; i++)
	 {
      min = i;
      for (j = i + 1; j < size; j++)
      {
         if (p[min] > p[j]) min = j;
			}
      temp = p[min];
      p[min] = p[i];
      p[i] = temp;
   }
}

int main(int argc, char *argv[])
{
	int i,len,*dizi;
	clock_t start,end;
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
	
	printf("\nDizi siralaniyor (Selection Sort)...\n");
	start=clock();
  selection_sort(dizi,len);
  end=clock();
  
  printf("\nSirali dizi...\n");
  for(i=0; i<len; i++)
	{
		 printf("%5d   ",dizi[i]);
	}

  diff=(double)(end-start)/CLOCKS_PER_SEC;
  printf("\nSiralama %.2lf saniye surdu.\n", diff);
	
	free(dizi);
	
  return 0;
}
