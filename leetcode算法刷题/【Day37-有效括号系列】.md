## [20.有效的括号](https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode/)
### 解题思路
遍历string的每一个字符，使用栈这种数据结构模拟进行括号匹配。
假设当前的字符是 `(` `[` `{` ，就将他们对应的字符 `)` `]` `}` 入栈。
如果现在`栈`不为空且 当前字符与栈顶元素相等，那就将栈顶元素弹出。反之直接返回 fasle。
如果这个字符串是有效括号，那么遍历结束后栈为空。所以最后返回 栈 是否为空。
### C++代码实现
```
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        int n = s.size();
        if(n % 2 > 0)
            return false;
        stack<char> stack;
        for(auto i : s){
            if(i == ')' || i == ']' || i == '}'){
                if(!stack.empty() && i == stack.top())
                    stack.pop();
                else
                    return false;
            }
            else{
                switch(i){
                    case '(':
                        stack.push(')');
                        break;
                    case '[':
                        stack.push(']');
                        break;
                    case '{':
                        stack.push('}');
                        break;
                }
            }
        }
        return stack.empty();
    }
};
```
执行效果：
![image](https://user-images.githubusercontent.com/21257485/86752718-2226e300-c072-11ea-854f-30201604b997.png)

### 复杂度分析

- 1. 时间复杂度：全程只遍历一遍字符串，时间为 O(n)
- 2. 空间复杂度：栈使用线性的空间大小，复杂度为O(n)
- _O(1)空间复杂度的写法现在还不会_
## [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)
### 解题思路
解题思路晚上再来补
### C++代码实现
```
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n < 2)
            return 0;
        stack<int> stack;
        stack.push(-1);
        int maxLenght = 0;
        for(int i = 0 ;i < n; i++){
            if(s[i] == '(')
                stack.push(i);
            else{
                stack.pop();
                if(!stack.empty())
                    maxLenght = max(maxLenght,i - stack.top());
                else
                    stack.push(i);
            }
        }
        return maxLenght;
    }
};
```
### 复杂度分析

- 时间复杂度：遍历一遍字符串，时间为O(n)
- 空间复杂度：创建一个栈，消耗空间O(n)
