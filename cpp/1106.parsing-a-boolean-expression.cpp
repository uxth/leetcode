/*
 * @lc app=leetcode id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 *
 * https://leetcode.com/problems/parsing-a-boolean-expression/description/
 *
 * algorithms
 * Hard (58.48%)
 * Likes:    283
 * Dislikes: 18
 * Total Accepted:    11.3K
 * Total Submissions: 19.1K
 * Testcase Example:  '"!(f)"'
 *
 * Return the result of evaluating a given boolean expression, represented as a
 * string.
 * 
 * An expression can either be:
 * 
 * 
 * "t", evaluating to True;
 * "f", evaluating to False;
 * "!(expr)", evaluating to the logical NOT of the inner expression expr;
 * "&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner
 * expressions expr1, expr2, ...;
 * "|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner
 * expressions expr1, expr2, ...
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: expression = "!(f)"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: expression = "|(f,t)"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: expression = "&(t,f)"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: expression = "|(&(t,f,t),!(t))"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= expression.length <= 20000
 * expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f',
 * ','}.
 * expression is a valid expression representing a boolean, as given in the
 * description.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool f_not(const string& s,int& i){
        i+=2;
        auto ret = f(s,i);
        i++;
        return !ret;
    }
    
    bool f_and(const string& s,int& i){
        i+=2;
        bool ret = true;
        ret &= f(s,i);
        while(s[i]!=')'){
            i++;
            ret &= f(s,i);
        }
        i++;
        return ret;
    }
    
    bool f_or(const string& s,int& i){
        i+=2;
        bool ret = false;
        ret |= f(s,i);
        while(s[i]!=')'){
            i++;
            ret |= f(s,i);
        }
        i++;
        return ret;
    }
    
    bool f(const string& s, int& i){
        if(s[i] == 't'){
            i++;
            return true;
        } else if(s[i] == 'f'){
            i++;
            return false;
        } else if(s[i] == '!'){
            return f_not(s,i);
        } else if(s[i] == '&'){
            return f_and(s,i);
        } return f_or(s,i);
    }
    bool parseBoolExpr(string expression) {
        int i = 0;
        return f(expression,i);
    }
};
// @lc code=end

