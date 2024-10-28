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
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {     
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int curr_sum = arr[i] + arr[left] + arr[right];
            if (curr_sum == sum)
            {
                cout << arr[i] << " " << arr[left] << " " << arr[right];
                return true;
            }
            
            if (sum > curr_sum)
            {
                left++;
            }
            else
            {
                right--;
            }
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
