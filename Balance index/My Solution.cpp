#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map> 

using namespace std;

int main() 
{
    vector<int> arr = { 3, 5, 1, -3, 4, 5 };
    int len = arr.size();
    
    vector<int> pref(len, 0);
    pref[0] = arr[0];
    for (int i = 1; i < len; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }

    int last = pref[len - 1];
    for (int i = 0; i < len - 1; i++)
    {
        if (pref[i] == (last - pref[i + 1]))
        {
            cout << i + 1;
            break;
        }
    }
}
