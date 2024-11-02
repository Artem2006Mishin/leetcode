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
	int n = 10;
	vector<int> prime(n + 1, true);

	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p * p; i <= n; i += p)
			{
				prime[i] = false;
			}
		}
	}

	for (int p = 2; p <= n; p++)
	{
		if (prime[p])
		{
			cout << p << " ";
		}
	}

}
