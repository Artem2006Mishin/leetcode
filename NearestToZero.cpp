#include <iostream>       
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map>

using namespace std;

int closestToZero(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;
    int sum = arr[left] + arr[right];

    while (left < right)
    {
        if (arr[left] + arr[right] == 0) {
            return 0;
        }

        if (abs(arr[left] + arr[right]) < abs(sum)) {
            sum = arr[left] + arr[right];
        }
        else if (abs(arr[left] + arr[right]) == abs(sum)) {
            sum = max(sum, arr[left] + arr[right]);
        }

        if (arr[left] + arr[right] > 0) {
            right--;
        }
        else {
            left++;
        }
    }
    return sum;
}

int main()
{
    vector<int> arr = { 1, 60, -10, 70, -80, 85 };
    cout << closestToZero(arr) << endl;

}