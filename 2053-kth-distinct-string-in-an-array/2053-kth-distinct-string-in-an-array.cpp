class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (string& s: arr)
            mp[s]++;    // Mapping string with its count.
        for (string& s: arr) {  // Traversing the string to get the kth distinct string
            if (mp[s] == 1) {   // Count of a string is 1
                k--;    // Decrease k
                if (k == 0)
                    return s;   // When k is 0 we return the string
            }
        }
        return "";  // If k is more than all the distinct string
    }
};