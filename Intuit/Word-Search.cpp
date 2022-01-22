// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(int i,int j,int ind,vector<vector<char>>& board, string word,vector<vector<bool>> &vis)
    {
        int n=board.size();
        int m=board[0].size();
        if(i>=n || i<0 || j>=m || j<0 ||vis[i][j]==true || board[i][j]!=word[ind])
        {
            return false;
        }
        if(ind == word.length()-1)
        {
            return true;
        }
        vis[i][j]=true;
       if(helper(i+1,j,ind+1,board,word,vis))
       {
           return true;
       }
       if(helper(i,j+1,ind+1,board,word,vis))
       {
           return true;
       }
       if(helper(i,j-1,ind+1,board,word,vis))
       {
           return true;
       }
       if(helper(i-1,j,ind+1,board,word,vis))
       {
           return true;
       }
       vis[i][j]=false;
       return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0]&&helper(i,j,0,board,word,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
