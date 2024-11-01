#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map> 
#include <unordered_set> 
 
using namespace std;

int main() 
{
	vector<int> arr = { 1, 4, 2, 10, 2, 3, 1 };
	int k = 16;

	int st = 0, sum = 0, ans = arr.size();
	for (int end = 0; end < arr.size(); end++)
	{
		sum += arr[end];
		while (sum > k)
		{
			sum -= arr[st];
			st++;
			ans = min(ans, end - st + 1);
		}
	}

	cout << ans;

}
