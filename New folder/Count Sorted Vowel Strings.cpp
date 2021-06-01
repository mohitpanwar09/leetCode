class Solution {
public:
    
    int find(int k,int n)
    {
        if(n==0)
        {
            return 1;
        }
        int no=0;
        for(int i=k;i<5;i++)
        {
            
            no+=find(i,n-1);
        
        }
        return no;
    }
    
    int countVowelStrings(int n) {
        
        int ans=find(0,n);
        
        return ans;
    }
};