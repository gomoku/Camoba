#include <string>
#include <vector>
#include "Array.h"

class ujjatek
{
	public:
          ujjatek(); //konstruktor
          ujjatek operator+();
          void startjatek();
		  void tablaki(); // J�t�kt�bla kirajzol�sa
		  void priorki(); //priorit�st�bla Kiirat�sa a k�perny�re
		  void priornul(); //priorit�st�bla null�z�sa
          void DoMove();
          int WinsGame(int i0,int j0);
          int WinsGame2(int i0,int j0);
          int WinsGame3(int i0,int j0);
          int WinsGame4(int i0,int j0);
          int WinsGame5(int i0,int j0);
		  int ellenrak(); //ellens�g lerakja a prioritastabla alapjan a 'O'-t
    private:
           int x1;
           int y1;
           int tabla[15][15];
 };
