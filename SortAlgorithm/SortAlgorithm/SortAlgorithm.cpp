#include <iostream>
#include <vector>
#include <random>


using namespace std;

using Index = int;
using Nombre = int;
using Table = vector<Nombre>;

//------------------------------------------------- || TAPE EQUILIBRIUM || -------------------------------------------------------

// non fonctionnel 

#include <math.h>

int tapeEquilibrium(vector<int>& A) {
    if (A.size() <= 1) return 0;
    if (A.size() == 2) return static_cast<int>(static_cast<double>(std::fabs(A[0] - A[1])));

    std::sort(A.begin(), A.end());

    int sizeA = static_cast<int>(A.size()); int split{ 0 };
    if (sizeA % 2 == 0)
    {
        split = (sizeA / 2);
    }
    else split = (sizeA / 2) + 1;

    int sumLeft{ 0 };
    auto ite = A.begin();

    while (ite - A.begin() < split)
    {
        sumLeft += *ite;
        ite++;
    }

    int sumRight{ 0 };

    while (ite < A.end())
    {
        sumRight += *ite;
        ite++;
    }

    ite -= split;
    int pivVal = sumRight - sumLeft; int minRes{ pivVal };
    int tempVal{ pivVal };


    while (ite < A.end())
    {
        if (minRes > tempVal) minRes = tempVal;

        sumRight -= *ite;
        sumLeft += *ite;
        tempVal = sumLeft - sumRight;
        tempVal = static_cast<int>(std::fabs(static_cast<double>(tempVal)));
        ite++;
    }

    return minRes;
}


//---------------------------------------------- || PERM MISSING ELEMENT || --------------------------------------------------------


#include <algorithm>

int permMissingElem(vector<int>& A) {

    if (A.size() < 1) return 1;
    std::sort(A.begin(), A.end());

    auto ite1 = A.begin(); auto ite2 = A.begin();

    if (A[0] != 1) return 1;
    else
    {
        while (ite1 < A.end())
        {
            ite2++;
            if (*ite1 == (*ite2) - 1) ite1++;
            else return (*ite1) + 1;
        }

        return 1;
    }
}


//---------------------------------------------------------- || FROG JUMP || ----------------------------------------------------------
// 100%

#include <cmath>
int frogJumps(int X, int Y, int D) {

    if ((Y - X) <= 0) return 0;
    int gap = Y - X;
    int remainer = gap % D;
    int calc = gap / D; int res = 0;

    if (remainer != 0)
        res = static_cast<int>(std::round(calc) + 1);
    else
    {
        res = static_cast<int>(std::round(calc));
    }

    return res;

}


//----------------------------------------------------- || DETECT UNAPAIRED INT || -------------------------------------------------------
//100%

#include <algorithm>
int detectUnpairedInt(vector<int>& A) {

    std::sort(A.begin(), A.end());
    auto ite = A.begin(); auto iteTemp = ite;
    while (ite < A.end())
    {
        if (ite + 1 < A.end()) iteTemp = ite + 1;
        else return *ite;
        if (*ite == *iteTemp)
        {
            ite += 2;
        }
        else
        {
            break;
        }

    }

    return *ite;

}



//--------------------------------------------- || ROTAT ARRAY || ---------------------------------------------------
// 66%

vector<int> rotateArray(vector<int>& A, int K) {

    if (A.size() <= 1) return A;
    if (static_cast<int>(A.size()) == 2)
    {
        if (K % 2 != 0) {
            int p1 = A[1]; A[1] = A[0]; A[0] = p1;
            return A;
        }
        else return A;
    }

    int sizeA{ static_cast<int>(A.size()) };
    int newPosition{ 0 };
    int modPos = K % sizeA;

    if (modPos == 0)
    {
        return A;
    }
    else
    {
        newPosition = modPos;
    }
        vector<int> rotatedA(A.size());
        auto iteRA{ rotatedA.begin() };
        auto iteA{ A.begin() };
        int rSize{ static_cast<int>(rotatedA.size()) };

        while (iteA < A.end())
        {
            rotatedA[newPosition] = *iteA;
            if (newPosition < rSize - 1)
            {
                newPosition++;
            }
            else
            {
                newPosition = 0;
            }

            iteA++;
        }
        return rotatedA;
}


//---------------------------------------------------- || BIT GAP || -------------------------------------------------------------
//100%

#include <bitset>
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


//---------------------------------------------------|| NON OPTI REC QUICK SORT || -----------------------------------------------------------
// Crashes above 76 random draws of elements (but i find my algo quite elegant)

Table recQuickSort(Table& myTable,Index indexLeft, Index indexPiv )
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

                return recQuickSort(myTable, indexLeft + 1, indexPiv);

            }
            else return recQuickSort(myTable, indexLeft + 1, indexPiv);

        }
        else
        {
            return recQuickSort(myTable, 0, indexPiv - 1);
        }
    }
    else
    {
        return myTable;
    }
}


//--------------------------------------------------------------------------------------------------------------


void tableDisplay(Table& myTable)
{
    for (unsigned int i = 0; i < myTable.size() ; i++)
    {
        cout << i+1 << " - " << myTable[i] << endl;
    }
}

int main()
{
    //------------------------------- || QUICK SORT TEST || -----------------------------\\

    cout << "Let's pick 6 random numbers..." << endl;
    cout << " . . . " << endl << endl;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1, 20);

    Table myTable; for (int i = 0; i < 19; i++) myTable.push_back(dist(rng));
    Table mySortedTable;

    cout << " ------------------------------- || UNSORTED TABLE ||----------------------------------- " << endl << endl;

    tableDisplay(myTable);

    cout << " Fine! Now we are gonna bubble sort them ! " << endl << endl;

    cout << " ------------------------------- || SORTED TABLE ||----------------------------------- " << endl << endl;

    mySortedTable = recQuickSort(myTable, 0, myTable.size()-1);

    tableDisplay(mySortedTable);

    cout << " ------------------------------- || END OF SIMULATION || ------------------------------- " << endl << endl;;


    //---------------------------------------------- || CODILITY TESTS || -------------------------------------------------\\


    // -----------  BIT GAP : 
    int test = 110;
    // int = 110 --> bit = 0 1 1 0 1 1 1 0
    //expected answer = 1
    int res1 = bitGap(test);
    cout << " ------------ TEST BIT GAP ------------ " << endl;
    cout << "Test : " << test << " bit gap = " << res1 << endl << endl;
    //---------------------------------------------------------



    // -----------  ARRAY ROTATE :
    cout << " ------------ TEST ARRAY ROTATE ------------ " << endl;
    vector<int> testArray1{ 3, 8, 9, 7, 6 };
    int KTEST = 3;
    vector<int> resArray = rotateArray(testArray1, KTEST);
    cout << "[";
    for (auto it = resArray.begin(); it < resArray.end(); it++)
    {
        cout << *it << ",";
    }
    cout << "]" << endl << endl;
    //---------------------------------------------------------



    // -----------  DETECT UNAPAIRED INT :
    cout << " ------------ TEST DETECT UNPAIRED INT ------------ " << endl;
    vector<int> testArray2{ 2, 4, 2, 3, 4, 3, 66};
    int res2 = detectUnpairedInt(testArray2);
    cout << " Intru = " << res2 << endl << endl;;
    //---------------------------------------------------------



    // -----------  FROG JUMP :
    int X{ 15 }; int Y{ 82 }; int D{ 7 };
    int res3 = frogJumps(X, Y, D);
    cout << " ------------ TEST FROG ------------ " << endl;
    cout << "Pour aller a " << Y << " en partant de " << X << " avec des bon de " << D << ", la grenouille fera au minimum " << res3 << " bonds." << endl << endl;
    //---------------------------------------------------------



    // -----------  PERM MISSING ELEMENT :
    cout << " ------------ TEST PERM MISSING ELEM ------------ " << endl;
    vector<int> testArray3{1,2,3,4,5,6,8,9};
    int res4 = permMissingElem(testArray3);
    cout << "Pour 1,2,3,4,5,6,8,9 , l'element manquant est " << res4 << endl << endl;
    //---------------------------------------------------------




    // -----------  TAPE EQUILIBRIUM :
    cout << " ------------ TEST TAPE EQUILIBRIUM ------------ " << endl;
    vector<int> testArray4{ 1,1,2,3,2,7,3,4,4,1,1 };
    int res5 = tapeEquilibrium(testArray4);
    cout << "Le plus petit ecart est : " << res5 << endl;
    //---------------------------------------------------------   


    //------------------------------------------------- || FIN DES TEST || ---------------------------------------------\\

    return 0;

}
