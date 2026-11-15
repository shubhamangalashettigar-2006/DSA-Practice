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

// class Solution {
//     public int countGoodSubstrings(String s) {
//         int ans=0;
//         int l=0;
//         HashMap<Character,Integer> map=new HashMap<>();
//         for(int r=0;r<s.length();r++){
//             char ch=s.charAt(r);
//             map.put(ch,map.getOrDefault(ch,0)+1);
//             if(r-l+1>3){
//                 char leftch=s.charAt(l);
//                 map.put(leftch,map.get(leftch)-1);
//                 if(map.get(leftch)==0){
//                     map.remove(leftch);
//                 }
//                 l++;
//             }
//             if(map.size()==3&& r-l+1==3){
//                 ans++;
//             }    
//         }
//         return ans;
//     }
// }