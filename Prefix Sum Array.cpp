#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <math.h> 
#include <unordered_map> 

using namespace std;

int find(int m, vector<pair<int, int> > q)
{    
    vector<int> pre(5, 0);

    for (int i = 0; i < m; i++) 
    {        
        int a = q[i].first, b = q[i].second;
        pre[a - 1] += 100;
        pre[b] -= 100;
    }

    int mx = pre[0];
    for (int i = 1; i < 5; i++) 
    {
        pre[i] += pre[i - 1];
        mx = max(mx, pre[i]);
    }

    return mx;
}

int main() 
{
    int m = 3;
    vector<pair<int, int> > q
        = { { 1, 2 }, { 1, 3 }, { 1, 2 } };

    cout << find(m, q);
}
