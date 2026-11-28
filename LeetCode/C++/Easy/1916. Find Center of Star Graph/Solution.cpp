class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> fst=edges[0];
        vector<int> sec=edges[1];
        return fst[0]==sec[0]||fst[0]==sec[1] ? fst[0]:fst[1];
    }
};