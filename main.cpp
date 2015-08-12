#include <cstdlib>
#include <iostream>
#include <string>
#include "ujjatek.h"

using namespace std;


int main(void)
 {
	char ertek;
	do
	{
 	puts("++++++++++++++++++++++++++++++++");
	puts("+ Amoba Jatek kotelezo program +");
	puts("++++++++++++++++++++++++++++++++");
	puts("+ Keszitette: Mester Gabor     +");
	puts("++++++++++++++++++++++++++++++++");
	puts("+ Menu valasztas:              +");
	puts("+        1. Jatek inditasa     +");
	puts("+        2. Info               +");
	puts("+        q. Kilepes            +");
	puts("++++++++++++++++++++++++++++++++");
	ujjatek a = ujjatek();
	cin >> ertek;
	 switch(ertek)
	 {
		 case '1':
			 puts("A jatek indul");
		 	 a.startjatek();
			 //ujjatek::startjatek();	
             break;				
		  case '2':
			  puts("Szimpla amoba(Five-in-a-row, Gomoku) Jatek\n A human Jatekos az 'X', a gep 'O', a Jatekban az nyer aki elobb kirak 5-ot vizszintes, fuggoleges vagy atlos iranyban\nKilepni a 'q' betu lenyomasaval lehet.\n Jo Jatekot!");
					 break;
          default: puts("Hibás karakter!"); 	
             break;
    
    }
	}
	while(ertek!='q');
	return 0;
}
