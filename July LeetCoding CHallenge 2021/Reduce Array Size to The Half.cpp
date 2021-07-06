class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int arrSize=arr.size(); 
        int ans=0,sum=0;
        
        vector<int>setVector;
        map<int,int>mp_freq;
        
        for(int itr=0;itr<arrSize;itr++)
        {
            mp_freq[arr[itr]]++;
        }
        
        for(auto itr:mp_freq)
        {
            setVector.push_back(itr.second);
        }
        
        sort(setVector.rbegin(),setVector.rend());
        
        arrSize/=2;
        
        for(int itr=0;itr<setVector.size();itr++)
        {
            sum+=setVector[itr];
            ans++;
            if(sum>=arrSize)
            {
                break;
            }
        }
        
        return ans;
    }
};