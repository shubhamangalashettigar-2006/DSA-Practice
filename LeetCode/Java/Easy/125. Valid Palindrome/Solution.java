// class Solution {
//     public boolean isPalindrome(String s) {
//         StringBuilder cleaned=new StringBuilder();
//         for(int i=0;i<s.length();i++){
//             char ch=s.charAt(i);
//             if(Character.isLetterOrDigit(ch)){
//                 ch=Character.toUpperCase(ch);
//                 cleaned.append(ch);
//             }
//         }
//         int i=0;
//         int j=cleaned.length()-1;
//         while(i<j){
//             if(cleaned.charAt(i)!=cleaned.charAt(j)){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
// }

class Solution {
    public boolean isPalindrome(String s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            while(i<j&&!Character.isLetterOrDigit(s.charAt(i))){
                i++;
            }
            while(i<j&&!Character.isLetterOrDigit(s.charAt(j))){
                j--;
            }
            if(Character.toUpperCase(s.charAt(i))!=Character.toUpperCase(s.charAt(j))){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}