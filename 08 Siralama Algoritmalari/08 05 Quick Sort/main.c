/*************************************************************************
* Proje : Siralama algoritmalari - Quick Sort
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
void quick_sort(int *x, int first, int last)
{
    int pivot,j,temp,i;

     if(first<last)
		 {
         pivot=first;
         i=first;
         j=last;

         while(i < j)
				 {
             while(x[i] <= x[pivot] && i < last) i++;
             while(x[j] > x[pivot]) j--;
             if(i < j)
						 {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
             }
         }

         temp = x[pivot];
         x[pivot] = x[j];
         x[j] = temp;
         quick_sort(x, first, j-1);
         quick_sort(x, j+1, last);
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
	
	printf("\nDizi siralaniyor (Quick Sort)...\n");
	start=clock();
  quick_sort(dizi,0,len-1);
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
