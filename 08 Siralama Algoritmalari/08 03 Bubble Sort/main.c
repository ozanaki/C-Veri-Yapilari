/*************************************************************************
* Proje : Siralama algoritmalari - Bubble Sort
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *numbers, int array_size)
{
  int i, j, temp;
 
  for (i = (array_size - 1); i > 0; i--)
  {
    for (j = 1; j <= i; j++)
    {
      if (numbers[j-1] > numbers[j])
      {
        temp = numbers[j-1];
        numbers[j-1] = numbers[j];
        numbers[j] = temp;
      }
    }
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
	
	printf("\nDizi siralaniyor (Bubble Sort)...\n");
	start=clock();
  bubble_sort(dizi,len);
  end=clock();
  
  printf("\nSirali dizi...\n");
  for(i=0; i<len; i++)
	{
		 printf("%5d   ",dizi[i]);
	}

  diff=(double)(end-start)/CLOCKS_PER_SEC;
  printf("\nSiralama %.2lf saniye surdu.\n", diff);
	
  return 0;
}
