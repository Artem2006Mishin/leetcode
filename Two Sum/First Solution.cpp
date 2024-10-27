#include <iostream>       
#include <vector> 
#include <iostream>       
#include <vector> 
#include <unordered_map> 

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map <int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (hash.find(complement) != hash.end() &&
            hash[complement] != i)
        {
            return { i, hash[complement] };
        }
    }

    return {};
}

int main()
{
    vector<int> nums = { 3,3 };
    int target = 6;

    auto v = twoSum(nums, target);
    cout << v[0] << " " << v[1];
}