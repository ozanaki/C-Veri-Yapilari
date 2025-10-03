/*************************************************************************
* Proje : Bir Kripto
* Dosya : main.c
* Yazar : M. Ozan AKI
* Tarih : 01.10.2012
* Derleyici : Orwell Dev C++ & TDM GCC 4.8.1 Compiler
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void bit_rotate_left(char *ch, int kaydir)
{
	int i;
	char bit;
	for(i=0; i<kaydir; i++)
	{
		bit = (*ch&0x80)>>7;
		*ch <<= 1;
		*ch |= bit;
	}
}

void bit_rotate_right(char *ch, int kaydir)
{
	int i;
	char bit;
	for(i=0; i<kaydir; i++)
	{
		bit = (*ch&0x01)<<7;
		*ch >>= 1;
		*ch &= 0x7f; //neden?
		*ch |= bit;
	}
}

void bit_reverse(char *ch)
{
	int i;
	char rev=0x00;
	for(i=0; i<8; i++)
	{
		rev|=(*ch&(1<<i))?1<<(8-i):0;
	}
}

void bit_swap(char *ch)
{
	char swap = *ch;
	*ch = ((swap<<4)&0xf0)|((swap>>4)&0x0f);
}

void kriptola(char *str, int key)
{
	while(*str)
	{
		bit_rotate_left(str,key);
		bit_reverse(str);
		bit_swap(str);
		*str=~*str;
		str++;
	}
}

void kripto_coz(char *str, int key)
{
	while(*str)
	{
		bit_rotate_right(str,key);
		bit_reverse(str);
		bit_swap(str);
		*str=~*str;
		str++;
	}
}

int main(int argc, char* argv[])
{
	char cumle[255];
	int anahtar;

	printf("Bir cumle giriniz: ");
	fgets(cumle,255,stdin);

	printf("anahtar sayiyi giriniz: ");
	scanf("%d", &anahtar);

	kriptola(cumle,anahtar);
	printf("Kriptolu cumle: %s\n", cumle);

	kripto_coz(cumle, anahtar);
	printf("Cozulmus cumle: %s\n", cumle);

	return 0;
}

