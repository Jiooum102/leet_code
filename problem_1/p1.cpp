#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int Len,Sum;
    cout << "Nhap do dai mang: ";
    cin >> Len;
    cout << "Nhap tong: ";
    cin >> Sum;
    int Arr[Len];
    cout << "Nhap cac phan tu: " << endl;
    for(int i = 0; i < Len; i++)
    {
        cout << "Arr[" << i << "]: ";
        cin >> Arr[i];
    }
    map<int, int> Map;
    for(int i = 0; i < Len; i++)
    {
        int temp = Sum - Arr[i];
        if(Map.find(temp) != Map.end())
        {
            cout << "Da tim thay cap so: " << endl;
            cout << "[" << Map[temp] << ", " << i << "]" << endl;
            return 0;
        }
        else
        {
            Map[Arr[i]]=i;
        }
    }
    cout << "Khong tim thay cap so nao co tong bang " << Sum << "." << endl;
    return 0;
}