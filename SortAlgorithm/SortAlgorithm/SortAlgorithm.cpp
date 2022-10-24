#include <iostream>
#include <vector>
#include <random>


using namespace std;

using nombre = int;
using Table = vector<nombre>;

Table bubbleSort(Table& myTable,int indexLeft,  int indexPiv )
{
    int tempLeft, tempPiv;
    if (indexPiv > 0) {
        if (indexLeft < indexPiv) {
            if (myTable[indexPiv] <= myTable[indexLeft])
            {
                tempPiv = myTable[indexPiv];
                myTable[indexPiv] = myTable[indexLeft];
                tempLeft = myTable[indexPiv - 1];
                myTable[indexPiv - 1] = tempPiv;
                myTable[indexLeft] = tempLeft;

                return bubbleSort(myTable, indexLeft + 1, indexPiv);

            }
            else return bubbleSort(myTable, indexLeft + 1, indexPiv);

        }
        else
        {
            return bubbleSort(myTable, 0, indexPiv - 1);
        }
    }
    else
    {
        return myTable;
    }
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

    mySortedTable = bubbleSort(myTable, 0, myTable.size()-1);

    tableDisplay(mySortedTable);

    cout << " ------------------------------- || END OF SIMULATION || ------------------------------- " << endl;


    return 0;

}
