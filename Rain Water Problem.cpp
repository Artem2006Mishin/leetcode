#include <iostream>       
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map>
#include <unordered_set>

using namespace std;

int maxWater(vector<int>& arr)
{
    int left = 1, right = arr.size() - 2;
    int lMax = arr[left - 1], rMax = arr[right + 1];
    
    int res = 0;
    while (left <= right)
    {
        if (lMax >= rMax)
        {
            res += max(0, rMax - arr[right]);
            rMax = max(rMax, arr[right]);
            right--;
        }
        else
        {
            res += max(0, lMax - arr[left]);
            lMax = max(lMax, arr[left]);
            left++;
        }
    }
    return res;
}


int main()
{
    vector <int> arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << maxWater(arr) << endl;
}
