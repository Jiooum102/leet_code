#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int Len = s.length();
        int* Arr = new int[Len];
        for(int i=0; i<Len; i++){
            switch(s[i]){
                case 'I': Arr[i] = 1; break;
                case 'V': Arr[i] = 5; break;
                case 'X': Arr[i] = 10; break;
                case 'L': Arr[i] = 50; break;
                case 'C': Arr[i] = 100; break;
                case 'D': Arr[i] = 500; break;
                case 'M': Arr[i] = 1000; break;
            }
        }
        int result = 0;
        for(int i=0; i<Len; i++){
            if(i+1<Len && Arr[i]<Arr[i+1]){
                result -= Arr[i];
            }else{
                result += Arr[i];
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;
    int result = sol.romanToInt(roman);
    cout << "The integer value of " << roman << " is " << result << endl;
    return 0;
}