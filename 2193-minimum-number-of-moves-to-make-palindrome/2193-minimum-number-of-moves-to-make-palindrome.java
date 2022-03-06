class Solution {
    
    static boolean isPalindrome(char[] s){
        int[] count = new int[26];
        for(int i = 0; i < s.length; i++){
        count[s[i] - 'a']++;
        }
       
        
        boolean flag = false;
        
        for(int i = 0; i < 26; i++)
        {
           if(count[i] % 2 != 0 && !flag)
           {
              flag = true;
           }
           else if (count[i] % 2 != 0 && flag)
           {
              return false;
           }
        }
        return true;
        }
    
    static void swap(char[] s , int i, int j) {
char temp = s[i];
s[i] = s[j];
s[j] = temp;
}
    
    public int minMovesToMakePalindrome(String str) {
        
     
        // Legth of string
        int n = str.length();
        int count = 0;
        char s[] = str.toCharArray();
        if(!isPalindrome(s)){
        return -1;
        }
        int left = 0;
        int right = n - 1;
        while(left < right){
        int k = right;
        while(s[k] != s[left]){
        k--;
        }
        if(k == left){
        swap(s, left , left + 1);
        count++;
        }else{
        for(int i = k; i < right; i++){
        swap(s, i, i + 1);
        count++;
        }
        left++;
        right--;
        }
       // System.out.println(new String(s));
        }
        return count;
        }

}