#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int Len,Target;
    cout << "Enter array length: ";
    cin >> Len;
    cout << "Enter target: ";
    cin >> Target;
    int Arr[Len];
    cout << "Enter array elements: " << endl;
    for(int i = 0; i < Len; i++)
    {
        cout << "Arr[" << i << "]: ";
        cin >> Arr[i];
    }
    map<int, int> Map;
    for(int i = 0; i < Len; i++)
    {
        int temp = Target - Arr[i];
        if(Map.find(temp) != Map.end())
        {
            cout << "Found indices of two numbers that have sum of " << Target << ": " << endl;
            cout << "[" << Map[temp] << ", " << i << "]" << endl;
            return 0;
        }
        else
        {
            Map[Arr[i]]=i;
        }
    }
    cout << "Can't find indices of two number that have sum of " << Target << "." << endl;
    return 0;
}