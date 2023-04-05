// link :  https://leetcode.com/problems/optimal-partition-of-string/

class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<int> lastSeen(26,-1);
        int count =0;
        int start =0;
        for(int i=0; i<n;i++){
            char ch = s[i];
            if(lastSeen[ch-'a'] >= start){
                count++;
                start = i;
            }
            lastSeen[ch-'a']=i;
        }
        return count + 1;
         
    }
};
