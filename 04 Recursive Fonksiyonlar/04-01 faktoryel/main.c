#include <stdio.h>
#include <stdlib.h>

int faktoryel(int n)
{
	int sonuc;
	if(n==1) return 1;
	sonuc = n * faktoryel(n-1);
	return sonuc;
}

int main(int argc, char *argv[])
{
 	int sayi, cevap;
	printf("Faktoryel : ");
	scanf("%d", &sayi);
	
	cevap = faktoryel(sayi);
	
	printf("Cevap = %d\n", cevap);
	
  return 0;
}
