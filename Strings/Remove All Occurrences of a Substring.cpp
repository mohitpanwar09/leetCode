class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(1)
        {
            size_t f=s.find(part);
            if(f==string::npos)
            {
                break;
            }
            s=s.substr(0,f)+s.substr(f+part.length());
        }
        
        return s;
    }
};