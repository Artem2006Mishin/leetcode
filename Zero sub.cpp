#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map> 
#include <unordered_set> 

using namespace std;

bool subArrayExists(int arr[], int N)
{
	unordered_set<int> res;
	
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
		if (sum == 0 || res.find(sum) != res.end())
		{
			return true;
		}
		res.insert(sum);
	}
	return false;
}

int main() 
{
	int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);

	cout << subArrayExists(arr, N);
}
