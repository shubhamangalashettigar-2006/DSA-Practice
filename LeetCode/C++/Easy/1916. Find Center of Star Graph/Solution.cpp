// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         vector<int> fst=edges[0];
//         vector<int> sec=edges[1];
//         return fst[0]==sec[0]||fst[0]==sec[1] ? fst[0]:fst[1];
//     }
// };
//This is optimal solution TC and SC: O(1)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      unordered_map<int,int> mp;
      for(vector<int> edge:edges){
        mp[edge[0]]++;
        mp[edge[1]]++;
      } 
      for(pair<int,int> nodes:mp){
        int node=nodes.first;
        int degree=nodes.second;
        if(degree==edges.size()){
            return node;
        }
      } 
      return -1;
    }
};

//[[1,2],[5,1],[1,3],[1,4]]
// //k  v
// 1  4
// 2  1
// 3  1
// 4  1
// 5  1

