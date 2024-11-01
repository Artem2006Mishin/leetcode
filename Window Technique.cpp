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
	vector<int> arr = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int k = 4;

	int max_sum = 0;
	for (int i = 0; i < k; i++)
	{
		max_sum += arr[i];
	}

	int window_sum = max_sum;
	for (int i = k; i < arr.size(); i++)
	{
		window_sum += arr[i] - arr[i - k];
		max_sum = max(window_sum, max_sum);
	}

	cout << max_sum;
}
