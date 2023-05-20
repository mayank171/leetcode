class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int ct=1;
        string temp=a;
        while(a.length()<b.length())
        {
            ct++;
            a+=temp;
        }
        
        int l1=a.length();
        int l2=b.length();
        
        vector<int> pi(l2,0);
        int j=0;
        for(int i=1;i<l2;i++)
        {
            if(b[i]==b[j])
            {
                pi[i]=j+1;
                j++;
            }
            else
            {
                int flag=0;
                j=(j-1>=0)?pi[j-1]:flag=1;
                
                while(j>=0 && flag==0)
                {
                    if(b[i]==b[j])
                    {
                        break;
                    }
                    else
                    {
                        j=(j-1>=0)?pi[j-1]:flag=1;
                        
                        if(flag==1)
                            break;
                    }
                }
                
                if(flag==0)
                {
                    pi[i]=j+1;
                    j++;
                }
                else
                {
                    pi[i]=0;
                    j=0;
                }
            }
            
        }
        
        cout<<"ofoefoe"<<endl;
        
        
        j=0;
        int i=0;
        
        while(i<l1 && j<l2)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
                
                if(j==l2)
                    return ct;
            }
            else
            {
                int flag=0;
                j=(j-1>=0)?pi[j-1]:flag=1;
                
                while(j>=0 && flag==0)
                {
                    if(a[i]==b[j])
                    {
                        break;
                    }
                    else
                    {
                        j=(j-1>=0)?pi[j-1]:flag=1;
                        
                        if(flag==1)
                            break;
                    }
                }
                
                if(flag==0)
                {
                    j++;
                    i++;
                    if(j==l2)
                    {
                        return ct;
                    }
                }
                else
                {
                    j=0;
                    i++;
                }
            }
        }
        
        cout<<"cdcdv"<<endl;
        
        ct++;
        a+=temp;
        
        l1+=temp.size();
        
        j=0;
        i=0;
        
        while(i<l1 && j<l2)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
                
                if(j==l2)
                    return ct;
            }
            else
            {
                int flag=0;
                j=(j-1>=0)?pi[j-1]:flag=1;
                
                while(j>=0 && flag==0)
                {
                    if(a[i]==b[j])
                    {
                        break;
                    }
                    else
                    {
                        j=(j-1>=0)?pi[j-1]:flag=1;
                        
                        if(flag==1)
                            break;
                    }
                }
                
                if(flag==0)
                {
                    j++;
                    i++;
                    if(j==l2)
                    {
                        return ct;
                    }
                }
                else
                {
                    j=0;
                    i++;
                }
            }
        }
        
        return -1;
    }
};