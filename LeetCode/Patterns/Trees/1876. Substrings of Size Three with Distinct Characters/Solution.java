class Solution {
    public int countGoodSubstrings(String s) {
        int ans=0;
        int l=0;
        HashSet<Character> set=new HashSet();
        for(int r=0;r<s.length();r++){
            char ch=s.charAt(r);
            while(set.contains(ch)){
                set.remove(s.charAt(l));
                l++;
            }
            set.add(ch);
            if(r-l+1==3){
                ans++;
            }
        }
        return ans;
    }
}