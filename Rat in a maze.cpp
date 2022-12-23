class Solution{

    public:

    void solve(vector<string>&ans,vector<vector<int>>&visited,vector<vector<int>> &m,int n,string v,int x,int y){

        

        if(x>n-1 || x<0 || y<0 || y>n-1 || visited[x][y]==1 || m[x][y]==0){

            v.pop_back();

            return;

        }

        if(x==n-1 && y==n-1){

            ans.push_back(v);

            return;

        }        

       visited[x][y]=1;

       v.push_back('D');

        solve(ans,visited,m,n,v,x+1,y);

        v.pop_back();

 

        v.push_back('R');

        solve(ans,visited,m,n,v,x,y+1);

        v.pop_back();

         

         v.push_back('L');

        solve(ans,visited,m,n,v,x,y-1);

        v.pop_back();

         

          v.push_back('U');

        solve(ans,visited,m,n,v,x-1,y);

        v.pop_back();

        visited[x][y]=0;

    }

    vector<string> findPath(vector<vector<int>> &m, int n) {

        // Your code goes here

        vector<string>ans;

        vector<vector<int>>visited(n,vector<int>(n,0));

        solve(ans,visited,m,n,"",0,0);

        return ans;

    }

};
