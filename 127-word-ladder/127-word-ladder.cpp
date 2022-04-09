class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordList) {
        
        int size=wordList.size();
        
        unordered_set<string> s;
        
        for(int i=0;i<size;i++)
        {
            s.insert(wordList[i]);
        }
        
        if(s.find(endWord)==s.end())
        {
            return 0;
        }
        
        queue<string> q;
        q.push(startWord);
        
        int depth=0;
        
        while(!q.empty())
        {
            int size=q.size();
            depth++;
            
            for(int i=0;i<size;i++)
            {
                string str1=q.front();
                q.pop();
                
                for(int i=0;i<str1.length();i++)
                {
                    string temp=str1;
                    
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        
                        if(temp.compare(str1)==0)
                            continue;
                        if(endWord.compare(temp)==0)
                            return depth+1;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
        
    }
};