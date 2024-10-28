#include <iostream>       
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool find3Numbers(vector<int>& arr, int sum)
{
    int n = arr.size();

    for (int i = 0; i < n - 2; i++)
    {
        unordered_set<int> s;
        int curr_sum = sum - arr[i];

        for (int j = i + 1; j < n; j++)
        {
            int required_value = curr_sum - arr[j];
            if (s.find(required_value) != s.end())
            {
                cout << arr[i] << " " << arr[j] << " " << required_value;
                return true;
            }
            s.insert(arr[j]);
        }
    }
    return false;
}

int main() 
{
    vector<int> arr = { 4, 12, 3, 1, 6, 9 };
    int sum = 24;

    find3Numbers(arr, sum);
}
