class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int ind=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        
        if(ind==letters.size())
        {
            return letters[0];
        }
        
        return letters[ind];
    }
};