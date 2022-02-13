class Solution {
public:
    
    
//     string form_binary(string s1,int c,int n)
//     {
//         if(c==n)
//             return s1;
//         else
//         {
//             string s=s1;
//             int l=s1.length();
//             for(int i=0;i<l;i++)
//             {
//                 if(s[i]=='0')
//                     s[i]='1';
//                 else
//                     s[i]='0';
//             }
            
//             for(int i=0,j=l-1;i<=j;i++,j--)
//             {
//                 swap(s[i],s[j]);
//             }
            
//             s1=s1+'1'+s;
            
//             c++;
            
//             return form_binary(s1,c,n);
            
//         }
        
//         return s1;
            
//     }
    
//     void check(string &s,int n,int k,long long ind)
//     {
//         if(n==0)
//             return;
        
//         if(k==1)
//         {
//             ind=s.length()-1;
//             k=-1;
//             check(s,n,k,ind);
//             return ;
//         }
//         else if(k==-1)
//         {
//             if(ind<0)
//             {
//                 reverse(s.begin(),s.end());
//                 return ;
//             }
//             if(s[ind]=='0')
//                 s[ind]='1';
//             else
//                 s[ind]='0';
//             check(s,n,k,ind-1);
//             // if(ind-1<0)
//                 return;
//         }
        
        
//         string str="";
//         str=s;
//         k=1;
//         check(str,n,k,ind);
//         cout<<str<<endl;
//         k=0;
//         s=s+'1'+str;
//         cout<<s<<endl;
//         check(s,n-1,k,ind);
        
//     }
    
    char func(int n,int k,int &ct)
    {
        
        if(n==0)
        {
            cout<<ct<<endl;
            if(ct&1)
            {
                return '1';
            }
            else
            {
                return '0';
            }
        }
        
        if(n==0)
           return '1';
        
        n/=2;
        
        if(k>n)
        {
            int temp=k-n;
            k=n-temp;
            ct++;
            return func(n,k,ct);
            
        }
        else
        {
            return func(n,k,ct);
        }
        
        
    }
    
    
    char findKthBit(int n, int k) {
        
//         string s="0";
        
//         if(n==1)
//         {
//             return s[0];
//         }
        
//         int ki=0;
//         int ind;
//         check(s,n-1,ki,ind);
        
//         cout<<s<<endl;
        
//         return s[k-1];
        
        k--;
         n=pow(2,n)-2;
        
        
        
        
        
//         string s1="0";
//         int c=1;
//         string a=form_binary(s1,c,n);
        
//         cout<<a<<endl;
        
//         return a[k-1];
        
    
        
        
        int ct=0;
        return func(n,k,ct);
        
        
        
        
        
        
        
        
        
       
        
//        if(n==1)
//            return '0';
        
//        int len=pow(2,n)-1; 
        
//        if(k-1==len/2)
//            return '1';
//        else if(k-1<len/2)
//             return findKthBit(n-1,k);
//        else
//             return findKthBit(n-1,len-k+1)=='0'?'1':'0';
        
    }
};