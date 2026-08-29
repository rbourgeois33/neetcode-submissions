


class Solution {
public:
    bool isPalindrome(string s) {
        
        auto lptr = s.begin();
        auto rptr = s.end()-1;

        while(lptr<rptr){
            
            if (!std::isalnum(*lptr)){lptr++; continue;}
            if (!std::isalnum(*rptr)){rptr--; continue;}

            if (std::tolower(*lptr)!=std::tolower(*rptr)) return false;
            lptr++;
            rptr--;
        }

        return true;
    }
};
