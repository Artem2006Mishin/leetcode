class Solution {
public:
    vector<int> partitionLabels(string s) 
{
	map<char, int> lastIndex;

	for (int i = 0; i < s.length(); i++)
		lastIndex[s[i]] = i;

	vector<int> res;
	int end = 0, size = 0;
	for (int i = 0; i < s.length(); i++)
	{
		size++;
		end = max(end, lastIndex[s[i]]);
		if (i == end) {			
			res.push_back(size);
			size = 0;
		}
	}

	return res;
}
};
