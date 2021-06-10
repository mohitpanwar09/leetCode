class MyCalendar {
public:
    #define bb "\n"
    #define ll long long int
    map<int,int>mp;
    MyCalendar() {
        mp.clear();
    }
    bool book(int start, int end) {
        
        for(auto it:mp)
        {
            if(start>=it.first && start<it.second)
            {
                //cout<<bb;
                return false;
            }
            if(end>it.first && end<=it.second)
            {
                //cout<<bb;
                return false;
            }
            if(it.first>=start && it.first<end)
            {
                return false;
            }
            
        }
        //cout<<bb;
        mp[start]=end;
        // for(auto it:mp)
        // {cout<<it.first<<" "<<it.second<<bb;}
        // cout<<bb;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */