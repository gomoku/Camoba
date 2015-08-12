#include "ujjatek.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
Array prior;
//int prior[15][15];
ujjatek::ujjatek()
{
    x1 = 0;
    y1 = 0;
    
    int i = 0;
    int j = 0;
    for ( i = 0; i < 9; i++)
        {
        for ( j = 0; j < 9; j++)
            {
                 tabla[i][j] = 0;
               //  display_tabla[i][j] = ' ';
            }
        }
}
void ujjatek::startjatek()
{
string topbe="          ";
/*	for(int cv=0; cv<12; cv++)
	{
		for(int cv2=0; cv2<12; cv2++)
		{
			tabla[cv][cv2]=0;
		}
	}
*/
char kilep1[3], kilep2[3];
int vege=1, lepesszam=0, lszam=0;
do
{
	lszam++;
	//char xx1;
	//char yy1;
	//int x1, y1;
	ujjatek::tablaki();
	//priorki(); //prioritástábla
	puts("Kerem az X kordinata erteket:");
	cin >> kilep1;
	puts("Kerem az Y kordinata erteket:");
	cin >> kilep2;
	//x1=Kiirat::integerre(xx1);
	//y1=Kiirat::integerre(yy1);
	x1=atoi(kilep1);
	y1=atoi(kilep2);
    x1=x1-1;
	y1=y1-1;
	cout << "X: " << x1+1 << " Y: " << y1+1 << "\n";
	if(!strcmp(kilep1,"q") || !strcmp(kilep2,"q"))
	{
		vege=0;
	} 
	if(x1<9 && x1>=0 && y1<9 && y1>=0)
	{
		if(tabla[y1][x1]==1 || tabla[y1][x1]==2)
		{
			puts("Ide nem tehetsz X-et");
}
		else
		{   //puts("tablaxy=1");  
			tabla[y1][x1]=1;
			//puts("if winsgame");  
			if(ujjatek::WinsGame4(y1,x1)!=1)
			{   //puts("priornullázás");                                
				ujjatek::priornul();
				ujjatek::DoMove();
				lepesszam++;
				if(ujjatek::ellenrak()==1)
				{
					ujjatek::tablaki();
					puts("Vesztettel!");
					vege=0;
				}
			}
			else
			{
				vege=0;
				ujjatek::tablaki();
				puts("Nyertel!");
				return;
				}
		}
	}
		else
		{
			if(x1==113 || y1==113)
			{
				vege=0;
			}
			puts("Kerem a megadott szamok 1-9-ig legyenek");
		}
		if(lepesszam>=40)
		{
			vege=0;
			ujjatek::tablaki();
			puts("A tabla betelt, dontetlen!");
		}
}
	while(vege!=0);
}

void ujjatek::tablaki()
{
	int osz;
	puts("0 1 2 3 4 5 6 7 8 9");
	for(int cv=0; cv<9; cv++)
	{
		osz=cv+1;
		for(int cv2=0; cv2<9; cv2++)
		{
			if(tabla[cv][cv2]==0)
				if(cv2==0)
				{
					cout << osz << "   ";
				}
				else
				{
					cout << "  ";
				}
			if(tabla[cv][cv2]==1)
				if(cv2==0)
				{
					cout << osz << " X ";
				}
				else
				{
					cout << "X ";
			}
			if(tabla[cv][cv2]==2)
				if(cv2==0)
				{
					cout << osz << " O ";
				}
				else
				{
					cout << "O ";
				}
			}
			cout << "\n";
		}
	}

void ujjatek::priorki()
{
	for(int cv=0; cv<9; cv++)
	{
		for(int cv2=0; cv2<9; cv2++)
		{
			cout << prior(cv,cv2) << " ";
		}
		cout << " ";
	}
}

void ujjatek::priornul()
{
	prior();
    /*for(int cv=0; cv<9; cv++)
	{
		for(int cv2=0; cv2<9; cv2++)
		{
			prior(cv,cv2,0);
		}
	}*/
}

int ujjatek::ellenrak()
{
int maxy=0, maxx=0, maxo=-1;
for(int cv=0; cv<9; cv++)
{
	for(int cv2=0; cv2<9; cv2++)
	{
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			if(maxo<prior(cv,cv2))
			{
				maxo=prior(cv,cv2);
				maxy=cv;
				maxx=cv2;
			}
		}
	}
}
tabla[maxy][maxx]=2;
if(ujjatek::WinsGame4(maxy,maxx)==1)
	return 1;
return 0;
}
void ujjatek::DoMove()
{
int i, j, cv, cv2, Player=2, muveveg=1;
//         DoMove: Megnézi a számítógép számára hogy ha ide tenne hány X illetve O lenne mellette
//		ez alapján tölti fel adatokkal a prioritás táblázatot
for(cv=0;cv<9;cv++)
	for(cv2=0;cv2<9;cv2++)
	{
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=2;
			if(ujjatek::WinsGame2(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+20);
			}
			tabla[cv][cv2]=0;
		}
		else
			prior(cv,cv2,-1);
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=1;
			if(ujjatek::WinsGame2(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+9);
			}
			tabla[cv][cv2]=0;
		}
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=2;
			if(ujjatek::WinsGame(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+3);
			}
			tabla[cv][cv2]=0;
		}
		else
			prior(cv,cv2,-1);
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=1;
			if(ujjatek::WinsGame(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+4);
			}
			tabla[cv][cv2]=0;
		}
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=2;
			if(ujjatek::WinsGame3(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+1);
			}
			tabla[cv][cv2]=0;
		}
		else
			prior(cv,cv2,-1);
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=1;
			if(ujjatek::WinsGame3(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+2);
			}
			tabla[cv][cv2]=0;
		}
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=2;
			if(ujjatek::WinsGame4(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+21);
			}
			tabla[cv][cv2]=0;
		}
		else
			prior(cv,cv2,-1);
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=1;
			if(ujjatek::WinsGame4(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+20);
			}
			tabla[cv][cv2]=0;
		}
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=2;
			if(ujjatek::WinsGame5(cv, cv2)==1)
			{
					prior(cv,cv2,prior(cv,cv2)+1);
				}
				tabla[cv][cv2]=0;
			}
		else
			prior(cv,cv2,-1);
		if(tabla[cv][cv2]!=1 && tabla[cv][cv2]!=2)
		{
			tabla[cv][cv2]=1;
			if(ujjatek::WinsGame5(cv, cv2)==1)
			{
				prior(cv,cv2,prior(cv,cv2)+1);
			}
			tabla[cv][cv2]=0;
		}
	}
} //DoMove vége

int ujjatek::WinsGame(int i0, int j0)
{
	int i, j;
	// lenne-e 3 egymás mellett
	i = i0;
	j = j0-3;
	if(j < 0)
		j = 0;
	while((j <= j0))
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i][j+1] == tabla[i0][j0]) && (tabla[i][j+2] == tabla[i0][j0]) && (tabla[i][j+3] == tabla[i0][j0]))
			return 1;
		j++;
	}
	j = j0;
	i = i0-3;
	if(i < 0)
		i = 0;
	while(i<=i0)
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j] == tabla[i0][j0]) && (tabla[i+2][j] == tabla[i0][j0]) && (tabla[i+3][j] == tabla[i0][j0]))
			return 1;
		i++;
	}
	j = j0-3;
	i = i0-3;
	while(i<0 || j<0)
	{
		j++;
		i++;
	}
	while((i <= i0) && (j <= j0))
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j+1] == tabla[i0][j0]) && (tabla[i+2][j+2] == tabla[i0][j0]) && (tabla[i+3][j+3] == tabla[i0][j0]))
			return 1;
		j++;
		i++;
	}
	j = j0+3;
	i = i0-3;
	if(i<0)
		i=0;
	while(j<0 || i<0)
	{
		j--;
		i++;
	}
	while((i <= i0) && (j >= j0) && (j >= 3))
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j-1] == tabla[i0][j0]) && (tabla[i+2][j-2] == tabla[i0][j0]) && (tabla[i+3][j-3] == tabla[i0][j0]))
			return 1;
		j--;
		i++;
	}
	return 0;
}

int ujjatek::WinsGame2(int i0, int j0)
{
	int i, j;
	// Lenne-e 4 darab egymás mellett?
	i = i0;
	j = j0-3;
	if(j < 0)
		j = 0;
	while((j <= j0))
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i][j+1] == tabla[i0][j0]) && (tabla[i][j+2] == tabla[i0][j0]) && (tabla[i][j+3] == tabla[i0][j0]))
			return 1;
		j++;
	}
	j = j0;
	i = i0-3;
	if(i < 0)
		i = 0;
	while((i <= i0))
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j] == tabla[i0][j0]) && (tabla[i+2][j] == tabla[i0][j0]) && (tabla[i+3][j] == tabla[i0][j0]))
			return 1;
		i++;
	}
	j = j0-3;
	i = i0-3;
	while(j<0 || i<0)
	{
		i++;
		j++;
	}
	while((i <= i0) && (j <= j0))
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j+1] == tabla[i0][j0]) && (tabla[i+2][j+2] == tabla[i0][j0]) && (tabla[i+3][j+3] == tabla[i0][j0]))
			return 1;
		j++;
		i++;
	}
	j = j0+3;
	i = i0-3;
	while(i<0)
	{
		i++;
		j--;
	}
	while((i <= i0) && (j >= j0) && (j >= 3))
	{
		if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j-1] == tabla[i0][j0]) && (tabla[i+2][j-2] == tabla[i0][j0]) && (tabla[i+3][j-3] == tabla[i0][j0]))
			return 1;
		j--;
		i++;
	}
	return 0;
}
int ujjatek::WinsGame4(int i0, int j0)
{
	int i, j;
			// Nyertne-e? kijött-e 5 darab egymás mellett?
			i = i0;
			j = j0-4;
			if(j < 0)
				j = 0;
			while((j <= j0)) //függõlegesen kijön-e
			{
				if((tabla[i][j] == tabla[i0][j0]) && (tabla[i][j+1] == tabla[i0][j0]) && (tabla[i][j+2] == tabla[i0][j0]) && (tabla[i][j+3] == tabla[i0][j0]) && (tabla[i][j+4] == tabla[i0][j0]))
					return 1;
				j++;
			}
			j = j0;
			i = i0-4;
			if(i < 0)
				i = 0;
			while((i <= i0)) //vízszintesen kijön-e
			{
				if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j] == tabla[i0][j0]) && (tabla[i+2][j] == tabla[i0][j0]) && (tabla[i+3][j] == tabla[i0][j0]) && (tabla[i+4][j] == tabla[i0][j0]))
					return 1;
								i++;
			}
			j = j0-4;
			i = i0-4;
			while(i<0 || j<0)
			{
				i++;
				j++;
			}
			//if(i<0) i=0; if(j<0) j=0;
			while((i <= i0) && (j <= j0)) //jobbra le átlósan kijön-e
			{
				if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j+1] == tabla[i0][j0]) && (tabla[i+2][j+2] == tabla[i0][j0]) && (tabla[i+3][j+3] == tabla[i0][j0]) && (tabla[i+4][j+4] == tabla[i0][j0]))
					return 1;
				j++;
				i++;
			}
			j = j0+4;
			i = i0-4;
			while(i<0)
			{
				i++;
				j--;
			}
			//if(i<0) i=0; //bal lentrõl átlósan jobbra fel
			while((i <= i0) && (j >= j0) && (j >= 4))
			{
				if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j-1] == tabla[i0][j0]) && (tabla[i+2][j-2] == tabla[i0][j0]) && (tabla[i+3][j-3] == tabla[i0][j0]) && (tabla[i+4][j-4] == tabla[i0][j0]))
					return 1;
				j--;
				i++;
			}
			return 0;

	}

int ujjatek::WinsGame3(int i0, int j0)
{
		int i, j;
		// Tesztelés: ha 3 darab lenne egymás mellett
		i = i0;
		j = j0-2;
		if(j < 0)
			j = 0;
		while((j <= j0))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i][j+1] == tabla[i0][j0]) && (tabla[i][j+2] == tabla[i0][j0]))
				return 1;
			j++;
		}
		j = j0;
		i = i0-2;
		if(i < 0)
			i = 0;
		while((i <= i0))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j] == tabla[i0][j0]) && (tabla[i+2][j] == tabla[i0][j0]))
				return 1;
			i++;
		}
		j = j0-2;
		i = i0-2;
		while(i<0 || j<0)
		{
			i++;
			j++;
		}
		while((i <= i0) && (j <= j0))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j+1] == tabla[i0][j0]) && (tabla[i+2][j+2] == tabla[i0][j0]))
				return 1;
			j++;
			i++;
		}
		j = j0+2;
		i = i0-2;
		while(j<0 || i<0)
		{
			i++;
			j--;
		}
		while((i <= i0) && (j >= j0) && (j>=2))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j-1] == tabla[i0][j0]) && (tabla[i+2][j-2] == tabla[i0][j0]))
				return 1;
			j--;
			i++;
		}
		return 0;
	}
int ujjatek::WinsGame5(int i0, int j0)
{
		int i, j;
		// Tesztelés hogy ha ide tesz van-e mellette másik
		i = i0;
		j = j0-1;
		if(j < 0)
			j = 0;
		while((j <= j0))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i][j+1] == tabla[i0][j0]))
				return 1;
				j++;
		}
		j = j0;
		i = i0-1;
		if(i < 0)
			i = 0;
		while((i <= i0))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j] == tabla[i0][j0]))
				return 1;
			i++;
		}
		j = j0-1;
		i = i0-1;
		while(i<0 || j<0)
		{
			i++;
			j++;
		}
		while((i <= i0) && (i <= 9) && (j <= j0) && (j <= 9))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j+1] == tabla[i0][j0]))
				return 1;
			j++;
			i++;
		}
		j = j0+1; //if(i<0) i=0;
		i = i0-1;
		while(i<0)
		{
			j--;
			i++;
		}
		while((i <= i0) && (i <= 9) && (j >= j0) && (j >= 1))
		{
			if((tabla[i][j] == tabla[i0][j0]) && (tabla[i+1][j-1] == tabla[i0][j0]))
				return 1;
			// ha nemsikerül tovább próbáljon
			j--;
			i++;
		}
		// Ha nincs ilyen sorozat
		return 0;
}
