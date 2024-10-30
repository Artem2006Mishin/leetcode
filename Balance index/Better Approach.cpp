#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map> 

using namespace std;

int equilibriumPoint(vector<int>& arr)
{
	int n = arr.size();
	if (n == 1)
	{
		return 0;
	}

	vector<int> prefix(n, 0);
	vector<int> suffix(n, 0);

	prefix[0] = arr[0];
	suffix[n - 1] = arr[n - 1];

	for (int i = 1; i < n; i++)
	{
		prefix[i] = prefix[i - 1] + arr[i];
	}

	for (int i = n - 2; i >= 0; i--)
	{
		suffix[i] = suffix[i + 1] + arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (prefix[i] == suffix[i])
		{
			return i;
		}
	}
	return -1;
}

int main() 
{
	vector<int> arr = { -7, 1, 5, 2, -4, 3, 0 };
	cout << equilibriumPoint(arr);

}
