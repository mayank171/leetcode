class Solution {
public:
    int maximumSwap(int num) {
        
        string s=to_string(num);
        
        int n=s.length();
        
        vector<int> maxi(n);
        maxi[n-1]=-1;
        
        int largest=n-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<=s[largest])
            {
                maxi[i]=largest;
            }
            else
            {
                largest=i;
                maxi[i]=-1;
            }
        }
        
        for(auto &it:maxi)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
        int ind1=0;
        int ind2=0;
        for(int i=0;i<n;i++)
        {
            if(maxi[i]!=-1 && s[maxi[i]]!=s[i])
            {
                ind1=i;
                ind2=maxi[i];
                break;
            }
        }
        
        swap(s[ind1],s[ind2]);
        
        int k=0;
        int j=0;
        while(j<n)
        {
            k=k*10+(s[j]-'0');
            j++;
        }
        
        
        return k;
        
    }
};