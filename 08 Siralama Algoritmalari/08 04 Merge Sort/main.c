/*************************************************************************
* Proje : Siralama algoritmalari - Merge Sort
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
void merge(int *numbers, int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos; 	
	int *temp;

  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;
 
  temp=(int*)malloc(sizeof(int)*(left+num_elements));
	if(temp==NULL) return;
 
  while ((left <= left_end) && (mid <= right))
  {
    if (numbers[left] <= numbers[mid])
    {
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }
 
  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }
 
  for (i=0; i < num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
  
  free(temp);
}

void merge_sort(int *numbers, int left, int right)
{
  int mid;
  
  if (right > left)
  {	  
    mid = (right + left) / 2;
    merge_sort(numbers, left, mid);
    merge_sort(numbers, mid+1, right);

    merge(numbers, left, mid+1, right);
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
	
	printf("\nDizi siralaniyor (Merge Sort)...\n");
	start=clock();
  merge_sort(dizi,0,len-1);
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
