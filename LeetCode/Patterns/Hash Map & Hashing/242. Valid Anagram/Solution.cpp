class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        vector<int> frq(26,0);
        for(int i=0;i<n;i++){
            frq[s[i]-'a']++;
            frq[t[i]-'a']--;
        }
        for(int i=0;i<frq.size();i++){
            if(frq[i]!=0){
                return false;
            }
        }
        return true;
    }
};