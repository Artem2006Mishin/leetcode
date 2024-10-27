#include <iostream>       
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map> 

using namespace std;

vector<int> twoSum(vector<int> numbers, int target)
{
    int left = 0, right = numbers.size() - 1;
    while (left < right)
    {
        int current_sum = numbers[left] + numbers[right];
        if (current_sum == target)
        {
            return { left, right };
        }
        else if (target > current_sum)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}

int main()
{
    vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> result = twoSum(numbers, target);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}