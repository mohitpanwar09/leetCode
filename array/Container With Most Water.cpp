class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0,w=0;
        int start=0,end=h.size()-1;
        
        while(start<end)
        {
            w=min(h[start],h[end])*(end-start);
            ans=max(ans,w);
            
            if(h[start]<h[end])
                start++;
            else
                end--;
        }
        return ans;
    }
};