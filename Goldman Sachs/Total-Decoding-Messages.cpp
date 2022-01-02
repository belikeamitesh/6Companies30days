Class solution {	
public:
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    long long dp[n+1];
		    dp[0]=1;
		    dp[1]=1;
		    if(str[0]=='0')
		    {
		        return 0;
		    }
		    long long mod=1e9+7;
		    for(int i=2;i<=n;i++)
		    {
		        dp[i]=0;
		        if(str[i-1]>'0')
		        {
		            dp[i]=dp[i-1];
		        }
		        int b=(str[i-2]-'0')*10+(str[i-1]-'0');
		        if(10<=b && b<=26)
		        {
		            dp[i]=(dp[i]%mod+dp[i-2]%mod)%mod;
		        }
		        if(b==0)
		        {
		            return 0;
		        }
		    }
		    return (int)dp[n];
		}

};
