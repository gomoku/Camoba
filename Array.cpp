#include <iostream>
#include "Array.h"
using namespace std; 
int Array::operator()(const int nCol, const int nRow)
{
    return adData[nRow][nCol];
}
void Array::operator()(const int nCol, const int nRow, int value)
{
    adData[nRow][nCol]=value;     
}


void Array::operator()()
{
    // reset all elements of the Array to 0
    for (int nCol=0; nCol<15; nCol++)
        for (int nRow=0; nRow<15; nRow++)
            adData[nRow][nCol] = 0;
}
