class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> store;
public:
    TimeMap() {
        store = unordered_map<string, vector<pair<string, int>>> ();
    }

    void set(string key, string value, int timestamp) {
        store[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp) {
        string res = "";
        auto& values = store[key];

        int l = 0, r = values.size() - 1;
        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (values[m].second <= timestamp) {
                res = values[m].first;
                l = m + 1;
            }
            else r = m - 1;
        }
        return res;
    }    
};
