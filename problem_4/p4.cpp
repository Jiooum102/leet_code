#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int Len1, Len2;
    cout << "Enter length of first array: ";
    cin >> Len1;
    int Arr1[Len1];
    cout << "Enter elements of first array: " << endl;
    for (int i = 0; i < Len1; i++)
    {
        cout << "Arr1[" << i << "]: ";
        cin >> Arr1[i];
    }
    sort(Arr1, Arr1 + Len1);
    cout << endl << "Enter length of second array: ";
    cin >> Len2;
    int Arr2[Len2];
    cout << "Enter elements of second array: " << endl;
    for (int i = 0; i < Len2; i++)
    {
        cout << "Arr2[" << i << "]: ";
        cin >> Arr2[i];
    }
    sort(Arr2, Arr2 + Len2);
    int combinedLen = Len1 + Len2;
    int combinedArr[combinedLen];
    int i1, i2, i3;
    i1 = i2 = i3 = 0;
    while (i1 < Len1 || i2 < Len2)
    {
        while (i1 < Len1 && ((i2 < Len2 && Arr1[i1] < Arr2[i2]) || i2 >= Len2))
        {
            combinedArr[i3] = Arr1[i1];
            i1++;
            i3++;
        }
        while (i2 < Len2 && ((i1 < Len1 && Arr1[i1] >= Arr2[i2]) || i1 >= Len1))
        {
            combinedArr[i3] = Arr2[i2];
            i2++;
            i3++;
        }
    }
    cout << "Combined sorted array: " << endl;
    i3 = 0;
    while (i3 < combinedLen)
    {
        cout << combinedArr[i3++] << " ";
    }
    cout << endl << "Median of combined array: ";
    if (combinedLen % 2 != 0)
    {
        cout << combinedArr[combinedLen / 2] << endl;
    }
    else
    {
        cout << (combinedArr[combinedLen / 2 - 1] + combinedArr[combinedLen / 2]) / 2.0 << endl;
    }
    return 0;
}