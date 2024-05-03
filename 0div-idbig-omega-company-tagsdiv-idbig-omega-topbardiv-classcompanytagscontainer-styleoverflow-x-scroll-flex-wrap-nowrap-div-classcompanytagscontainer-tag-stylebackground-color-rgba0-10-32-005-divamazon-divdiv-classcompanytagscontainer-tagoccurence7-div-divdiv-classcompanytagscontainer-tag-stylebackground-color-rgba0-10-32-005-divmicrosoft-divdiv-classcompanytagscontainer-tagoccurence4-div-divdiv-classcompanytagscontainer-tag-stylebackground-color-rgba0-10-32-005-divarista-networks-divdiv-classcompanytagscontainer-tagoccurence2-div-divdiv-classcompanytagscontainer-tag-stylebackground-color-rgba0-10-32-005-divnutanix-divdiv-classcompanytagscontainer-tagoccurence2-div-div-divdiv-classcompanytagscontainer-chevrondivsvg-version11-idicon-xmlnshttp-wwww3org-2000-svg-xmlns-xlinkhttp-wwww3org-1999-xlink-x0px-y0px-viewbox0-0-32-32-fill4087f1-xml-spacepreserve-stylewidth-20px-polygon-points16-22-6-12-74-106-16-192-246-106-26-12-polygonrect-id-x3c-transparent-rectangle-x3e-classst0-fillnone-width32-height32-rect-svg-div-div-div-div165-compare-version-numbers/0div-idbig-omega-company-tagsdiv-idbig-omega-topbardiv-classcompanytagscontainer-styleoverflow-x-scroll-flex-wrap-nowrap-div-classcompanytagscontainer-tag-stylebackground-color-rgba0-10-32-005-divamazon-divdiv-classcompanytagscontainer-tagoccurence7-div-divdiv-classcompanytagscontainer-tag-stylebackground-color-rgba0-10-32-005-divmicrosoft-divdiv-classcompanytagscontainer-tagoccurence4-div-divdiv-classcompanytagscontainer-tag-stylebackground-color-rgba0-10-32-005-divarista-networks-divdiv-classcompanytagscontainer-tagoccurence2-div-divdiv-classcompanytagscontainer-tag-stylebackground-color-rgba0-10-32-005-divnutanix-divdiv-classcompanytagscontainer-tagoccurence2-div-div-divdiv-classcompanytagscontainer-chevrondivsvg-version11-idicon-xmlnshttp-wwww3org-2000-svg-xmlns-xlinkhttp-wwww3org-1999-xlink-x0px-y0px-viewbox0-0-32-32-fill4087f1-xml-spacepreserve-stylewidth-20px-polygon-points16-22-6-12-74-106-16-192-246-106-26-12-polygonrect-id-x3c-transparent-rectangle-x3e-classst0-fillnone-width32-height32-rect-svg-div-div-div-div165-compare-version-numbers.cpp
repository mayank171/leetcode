class Solution {
public:
    
    int comp(string s1,string s2)
    {
        cout<<s1<<" "<<s2<<endl;
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1<n2)
            return -1;
        else if(n1>n2)
            return 1;
        else
        {
            for(int i=0;i<n1;i++)
            {
                if(s1[i]>s2[i])
                    return 1;
                else if(s1[i]<s2[i])
                    return -1;
            }
        }
        
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        
        int n1=version1.size();
        int n2=version2.size();
        
        int i=0;
        int j=0;
        
        while(i<n1 && j<n2)
        {
            string str1="";
            int ii=i;
            int flag=0;
            while(ii<n1 && version1[ii]!='.')
            {
                if(version1[ii]=='0')
                {
                    if(flag==1)
                    {
                         str1+=version1[ii];
                    }
                }
                else
                {
                    str1+=version1[ii];
                    flag=1;
                }
                    
                ii++;
            }
            i=ii;
            i++;
            
            if(str1.size()==0)
                str1="0";
            
            string str2="";
            int jj=j;
            flag=0;
            while(jj<n2 && version2[jj]!='.')
            {
                if(version2[jj]=='0')
                {
                    if(flag==1)
                    {
                         str2+=version2[jj];
                    }
                }
                else
                {
                    str2+=version2[jj];
                    flag=1;
                }
                    
                jj++;
            }
            j=jj;
            j++;
            
            if(str2.size()==0)
                str2="0";
            
            if(comp(str1,str2)==1)
            {
                return 1;
            }
            else if(comp(str1,str2)==-1)
            {
                return -1;
            }
        }
        
        if(i>=n1)
        {
            while(j<n2)
            {
                string str2="";
                int jj=j;
                int flag=0;
                while(jj<n2 && version2[jj]!='.')
                {
                    if(version2[jj]=='0')
                    {
                        if(flag==1)
                        {
                             str2+=version2[jj];
                        }
                    }
                    else
                    {
                        str2+=version2[jj];
                        flag=1;
                    }
                        
                    jj++;
                }
                j=jj;
                j++;
                
                if(str2.size()==0)
                str2="0";
            
                
                if(comp("0",str2)==-1)
                    return -1;
            }
        }
        
        if(j>=n2)
        {
            cout<<"vdvd"<<endl;
            while(i<n1)
            {
                string str1="";
                int ii=i;
                int flag=0;
                while(ii<n1 && version1[ii]!='.')
                {
                    if(version1[ii]=='0')
                    {
                        if(flag==1)
                        {
                             str1+=version1[ii];
                        }
                    }
                    else
                    {
                        str1+=version1[ii];
                        flag=1;
                    }
                        
                    ii++;
                }
                i=ii;
                i++;
                
                if(str1.size()==0)
                str1="0";
            
                cout<<str1<<endl;
                if(comp(str1,"0")==1)
                    return 1;
            }
        }
        
        
        return 0;
    }
};