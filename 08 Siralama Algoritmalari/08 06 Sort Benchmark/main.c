/*************************************************************************
* Proje : Siralama algoritmalari - Algoritmalarin karsilastirilmasi (Benchmark)
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 03.11.2013
* Derleyici : Orwell Dev C++ / TDM GCC 4.8.1 32 bit Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//-------------------------------------------------------------
void insertion_sort(int *a, int n);
void selection_sort(int *p, int size);
void bubble_sort(int *numbers, int array_size);
void merge_sort(int *numbers, int left, int right);
void quick_sort(int *x, int first, int last);
//-------------------------------------------------------------

int main(int argc, char *argv[])
{
  int i,len,say,*dizi,*test;
	clock_t start,end;
	double diff;
	
  printf("Test dizisi kac elemanli olsun: ");
  scanf("%d", &len);
  
  dizi = (int*)malloc(sizeof(int)*len);
  if(dizi==NULL)
	{
		printf("Yeterli bellek yok!\n");
		return 0;
	}
  test = (int*)malloc(sizeof(int)*len);
  if(test==NULL)
	{
		printf("Yeterli bellek yok!\n");
		return 0;
	}

	printf("\nDizi rasgele sayilarla dolduruluyor... ");
	srand(time(NULL));
	for(i=0; i<len; i++) dizi[i] = rand();
	printf("Ok. \n");
	
	printf("=============================\n");
	printf("%d elemanli dizi icin deneme \n",len);
  printf("-----------------------------\n");
  
	printf("Insertion Sort : ");
	memcpy(test,dizi,len);
	start=clock();
  insertion_sort(test,len);
  end=clock();
  diff=(double)(end-start)/CLOCKS_PER_SEC;
  printf("%2.2lf sn.\n", diff);  

	printf("Selection Sort : ");
	memcpy(test,dizi,len);
	start=clock();
  selection_sort(test,len);
  end=clock();
  diff=(double)(end-start)/CLOCKS_PER_SEC;
  printf("%2.2lf sn.\n", diff);  
  
	printf("Bubble Sort    : ");
	memcpy(test,dizi,len);
	start=clock();
  bubble_sort(test,len);
  end=clock();
  diff=(double)(end-start)/CLOCKS_PER_SEC;
  printf("%2.2lf sn.\n", diff);  
  
	printf("Merge Sort     : ");
	memcpy(test,dizi,len);
	start=clock();
  merge_sort(test,0,len-1);
  end=clock();
  diff=(double)(end-start)/CLOCKS_PER_SEC;
  printf("%2.2lf sn.\n", diff);  
  
	printf("Quick Sort     : ");
	memcpy(test,dizi,len);
	start=clock();
  quick_sort(test,0,len-1);
  end=clock();
  diff=(double)(end-start)/CLOCKS_PER_SEC;
  printf("%2.2lf sn.\n", diff);  
  
 	printf("=============================\n");

  free(test);  
  free(dizi);
  
  return 0;
}
//-------------------------------------------------------------
void insertion_sort(int *a, int n)
{
  int k;
  for (k = 1; k < n; ++k) {
    int key = a[k];
    int i = k - 1;
    while ((i >= 0) && (key < a[i])) {
      a[i + 1] = a[i];
      --i;
    }
    a[i + 1] = key;
  }
}
//-------------------------------------------------------------
void selection_sort(int *p, int size)
{
   int   i, j, temp, min;
 
   for (i = 0; i < size - 1; i++) {
      min = i;
      for (j = i + 1; j < size; j++)
         if (p[min] > p[j])
            min = j;
      temp = p[min];
      p[min] = p[i];
      p[i] = temp;
   }
}
//-------------------------------------------------------------
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
//-------------------------------------------------------------
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
//-------------------------------------------------------------
void quick_sort(int *x, int first, int last)
{
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quick_sort(x,first,j-1);
         quick_sort(x,j+1,last);

    }
}
//-------------------------------------------------------------
