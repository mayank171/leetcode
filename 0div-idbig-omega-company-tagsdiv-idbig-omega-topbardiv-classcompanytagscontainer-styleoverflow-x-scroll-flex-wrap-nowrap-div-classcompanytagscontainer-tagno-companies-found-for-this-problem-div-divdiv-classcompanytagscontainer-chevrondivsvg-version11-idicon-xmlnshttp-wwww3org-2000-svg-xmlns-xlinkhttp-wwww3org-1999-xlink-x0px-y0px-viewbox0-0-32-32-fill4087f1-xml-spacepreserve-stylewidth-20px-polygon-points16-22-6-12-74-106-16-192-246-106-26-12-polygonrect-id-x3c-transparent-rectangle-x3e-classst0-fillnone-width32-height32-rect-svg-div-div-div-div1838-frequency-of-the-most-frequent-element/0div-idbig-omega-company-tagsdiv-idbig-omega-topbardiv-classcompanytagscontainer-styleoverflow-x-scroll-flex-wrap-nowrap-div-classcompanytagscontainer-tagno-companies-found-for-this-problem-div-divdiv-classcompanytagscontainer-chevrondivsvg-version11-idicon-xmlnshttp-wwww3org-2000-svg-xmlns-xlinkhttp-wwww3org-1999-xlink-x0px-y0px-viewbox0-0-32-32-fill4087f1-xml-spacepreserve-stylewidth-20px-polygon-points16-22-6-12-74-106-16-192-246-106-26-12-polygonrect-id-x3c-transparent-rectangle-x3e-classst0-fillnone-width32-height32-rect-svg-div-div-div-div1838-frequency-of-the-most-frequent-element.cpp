class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        int i = 0, j;
        sort(A.begin(), A.end());
        long long kk=k;
        for (j = 0; j < A.size(); ++j) {
            kk += A[j];
            if (kk < (long)A[j] * (j - i + 1))
                kk -= A[i++];
        }
        return j - i;
    }
};