#include <iostream>
#include <vector>
#include <random>
#include <bitset>

using namespace std;

using Index = int;
using Nombre = int;
using Table = vector<nombre>;


//-----------------------------------------------------------------------------------------------------------------


int bitGap(int N) {

    const int size = 24;
    std::bitset<size> myBitset(N);
    int bitCount = 0;

    if (myBitset.all()) return 0;
    if (N == 0) return 0;

    std::size_t index = 0; int max = 0; int count = 0;
    while (index < size)
    {
        if (myBitset.test(index))
        {
            if (max < count) max = count;
            count = 0; bitCount++;
        }
        else
        {
            count++;
        }

        index++;
    }

    if (bitCount > 1) return max;
    else return 0;

}


//--------------------------------------------------------------------------------------------------------------


Table recBubbleSort(Table& myTable,Index indexLeft, Index indexPiv )
{
    Nombre tempLeftVal, tempPivVal;
    if (indexPiv > 0) {
        if (indexLeft < indexPiv) {
            if (myTable[indexPiv] <= myTable[indexLeft])
            {
                tempPivVal = myTable[indexPiv];
                myTable[indexPiv] = myTable[indexLeft];
                tempLeftVal = myTable[indexPiv - 1];
                myTable[indexPiv - 1] = tempPivVal;
                myTable[indexLeft] = tempLeftVal;

                return recBubbleSort(myTable, indexLeft + 1, indexPiv);

            }
            else return recBubbleSort(myTable, indexLeft + 1, indexPiv);

        }
        else
        {
            return recBubbleSort(myTable, 0, indexPiv - 1);
        }
    }
    else
    {
        return myTable;
    }
}


//--------------------------------------------------------------------------------------------------------------


Table itBubbleSort(Table& myTable)
{
    Nombre tempLeftVal, tempPivVal;
    Index indexLeft, indexPiv;

    tempPivVal = myTable[myTable.size()];
    Index = myTable[0];

   while(tempPiv != )
}

//bool isSorted(Table myTable)
//{
//
//}

void tableDisplay(Table& myTable)
{
    for (unsigned int i = 0; i < myTable.size() ; i++)
    {
        cout << i+1 << " - " << myTable[i] << endl;
    }
}

int main()
{
    cout << "Let's pick 6 random numbers..." << endl;
    cout << " . . . " << endl << endl;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist20(0, 19);

    Table myTable; for (int i = 0; i < 20; i++) myTable.push_back(dist20(rng));
    Table mySortedTable;

    cout << " ------------------------------- || UNSORTED TABLE ||----------------------------------- " << endl << endl;

    tableDisplay(myTable);

    cout << " Fine! Now we are gonna bubble sort them ! " << endl << endl;

    cout << " ------------------------------- || SORTED TABLE ||----------------------------------- " << endl << endl;

    mySortedTable = recBubbleSort(myTable, 0, myTable.size()-1);

    tableDisplay(mySortedTable);

    cout << " ------------------------------- || END OF SIMULATION || ------------------------------- " << endl;


    return 0;

}
