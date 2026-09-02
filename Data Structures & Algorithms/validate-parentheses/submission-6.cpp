bool isClosing(const char c){
    return (c=='}'||c==')'||c==']');
}

bool isClosingAndMatches(const char c, const std::stack<char>& stack){
     if ((c==')') && (stack.top()=='(')) return true;
     if ((c==']') && (stack.top()=='[')) return true;
     if ((c=='}') && (stack.top()=='{')) return true;

     return false;
}

class Solution {
public:
    bool isValid(string s) {

        std::stack<char> stack;

        if (s.length()%2!=0) return false;
        
        for (auto c:s){
            
            if (isClosing(c)){
                
                if (stack.empty()) return false;

                if (isClosingAndMatches(c, stack)){
                    stack.pop();
                }else{
                    return false;
                }
               
            }else{
                stack.push(c);
            }
        }
    

        return stack.empty();
    }
};
