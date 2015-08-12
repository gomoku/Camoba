#include <string>
#include <vector>
#include "Array.h"

class ujjatek
{
	public:
          ujjatek(); //konstruktor
          ujjatek operator+();
          void startjatek();
		  void tablaki(); // Játéktábla kirajzolása
		  void priorki(); //prioritástábla Kiiratása a képernyõre
		  void priornul(); //prioritástábla nullázása
          void DoMove();
          int WinsGame(int i0,int j0);
          int WinsGame2(int i0,int j0);
          int WinsGame3(int i0,int j0);
          int WinsGame4(int i0,int j0);
          int WinsGame5(int i0,int j0);
		  int ellenrak(); //ellenség lerakja a prioritastabla alapjan a 'O'-t
    private:
           int x1;
           int y1;
           int tabla[15][15];
 };
