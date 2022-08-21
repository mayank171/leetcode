class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.length();
        int l2=num2.length();
        
        if(num1=="0" || num2=="0")
            return "0";
        
        vector<int> ans(l1+l2,0);
        
        int i=l2-1;
        int pf=0;
        while(i>=0)
        {
            int ival=num2[i]-'0';
            
            int carry=0;
            int k=l1+l2-1-pf;
            int j=l1-1;
            
            while(j>=0 || carry!=0)
            {
                int jval=(j>=0) ? num1[j]-'0':0;
                int prod=(ival*jval)+carry+ans[k];
                ans[k]=prod%10;
                carry=prod/10;
                k--;
                j--;
                
            }
            i--;
            pf++;
            
        }
        
        string res="";
        
        for(int i=0;i<l1+l2;i++)
        {
            cout<<ans[i]<<" ";
             res+=(ans[i]+'0');
        }
        
        int flag=0;
        int ind=-1;
        for(int i=0;i<l1+l2;i++)
        {
            if(res[i]!='0')
            {
                ind=i;
                break;
            }
        }
        
        cout<<res<<endl;
        
        string s="";
        if(ind!=-1)
        {
            s=res.substr(ind,l1+l2);
        }
        
        return s;
    }
};