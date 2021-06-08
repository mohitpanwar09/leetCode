class Solution {
public:
    #define bb "\n"
    string frequencySort(string s) {
        
        string ans;
        map<char,string>mp;
        priority_queue<pair<int,string>>pq;
        
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]+=s[i];
        }
        
        for(auto itr:mp)
        {
            //cout<<itr.second<<bb;
            pq.push(make_pair(itr.second.length(),itr.second));
        }
        
        while(!pq.empty())
        {
            pair<int,string> itr=pq.top();
//             int no=itr.first;
            
//             while(no--)
            ans=ans+itr.second;
            
            pq.pop();
        }
        return ans;
    }
};