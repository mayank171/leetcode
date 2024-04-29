class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
//             010
//             001
//             011
//             100
            
                
//             k=001
                
//                 1 1 1 1 0 0 0      1 1 0 0 0 0
//                 1 1 1 0 0 0 0      0 0 0 1 1 1 1 
//                 1 1 1 0 0 0 
//                 1 1 1 1 0 0 0 0
//                 0 0 0 0 1 1 1 
//                 0 0 0 1 1 1 1
//                 0 0 0 1 1 1 1 1 
                
//            need 1 , 0 even 1 even ==> 1
//            need 1 , 0 even 1 odd  ==> 0
//            need 1 , 0 odd 1 even  ==> 1
//            need 1 , 0 odd 1 odd  ==> 0
           
//            need 0 , 0 even 1 even  ==> 0
//            need 0 , 0 even 1 odd  ==> 1
//            need 0 , 0 odd 1 even  ==> 0
//            need 0 , 0 odd 1 odd  ==> 1
           
           int n=nums.size();
           int ans=0;
           for(int i=31;i>=0;i--)
           {
               int x=k&(1<<i);
               int ct0=0;
               int ct1=0;
               for(int j=0;j<n;j++)
               {
                   int y=nums[j]&(1<<i);
                   if(y>0)
                       ct1++;
                   else
                       ct0++;
               }
               
              // cout<<ct1<<" "<<ct0<<endl;
               
               if(x>0)
               {
                   if((ct0%2==0 && ct1%2==0)||(ct0%2!=0 && ct1%2==0))
                   {
                       ans++;
                       cout<<i<<" "<<endl;
                   }    
               }
               else
               {
                   if((ct0%2==0 && ct1%2!=0)||(ct0%2!=0 && ct1%2!=0))
                   {
                       ans++;    
                       cout<<i<<","<<endl;
                   }   
               }
           }
           
           return ans;
    }
};