
class Array
{
private:
    int adData[15][15];
public:
    Array()
    {
        // Set all elements of the Array to 0
        for (int nCol=0; nCol<15; nCol++)
            for (int nRow=0; nRow<15; nRow++)
                adData[nRow][nCol] = 0;
    }
    int operator()(const int nCol, const int nRow);
    void operator()(const int nCol, const int nRow, int value);
    void operator()();
};
