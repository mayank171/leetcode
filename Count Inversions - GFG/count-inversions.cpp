// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
void MergeSortedIntervals(vector<long long int>& v,long long int s, long long int m, long long int e,long long &ct) {
	
    vector<long long int> temp;

	long long int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
		    ct+=m-i+1;
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (long long int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

void MergeSort(vector<long long int>& v, long long int s, long long int e,long long int &ct) {
	if (s < e) {
		long long int m = (s + e) / 2;
		MergeSort(v, s, m,ct);
		MergeSort(v, m + 1, e,ct);
		MergeSortedIntervals(v, s, m, e,ct);
	}
}

    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ct=0;
        vector<long long> v;
        
        for(long long int i=0;i<N;i++)
        {
            v.push_back(arr[i]);
        }
        
        MergeSort(v,0,N-1,ct);
        
        return ct;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends