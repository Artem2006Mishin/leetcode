#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map> 
#include <unordered_set> 
 
using namespace std;

void Atkin(int limit)
{
	vector<bool> sieve(limit + 1, false);

	if (limit > 2) {
		sieve[2] = true;
	}
	if (limit > 3) {
		sieve[3] = true;
	}

	for (int x = 1; x * x <= limit; x++)
	{
		for (int y = 1; y * y <= limit; y++)
		{
			int n = (4 * x * x) + (y * y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
				sieve[n] = sieve[n] ^ true;
			}

			n = (3 * x * x) + (y * y);
			if (n <= limit &&  n % 12 == 7) {
				sieve[n] = sieve[n] ^ true;
			}

			n = (3 * x * x) - (y * y);
			if (x > y && n <= limit && n % 12 == 11) {
				sieve[n] = sieve[n] ^ true;
			}
		}
	}

	for (int r = 5; r * r <= limit; r++)
	{
		if (sieve[r])
		{
			for (int i = r * r; i <= limit; i += r * r) {
				sieve[i] = false;
			}		
		}
	}

	for (int a = 1; a <= limit; a++)
		if (sieve[a])
			cout << a << " ";
	cout << "\n";
}


int main() 
{
	int limit = 100;
	Atkin(limit);

}
