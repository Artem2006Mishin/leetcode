#include <iostream>       
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct hashFunction
{
    size_t operator()(const vector<int>
        & myVector) const
    {
        hash<int> hasher;
        size_t answer = 0;

        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};

auto find3Numbers(vector<int>& arr)
{
    int sum = 0;
    unordered_set<vector<int>, hashFunction> res;

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
                vector<int> temp = { arr[i], arr[left], arr[right] };
                res.insert(temp);
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
    return res;
}

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4 };
    auto result = find3Numbers(arr);
    for (auto n : result)
    {
        for (auto m : n)
        {
            cout << m << " ";
        }
        cout << endl;
    }

}
