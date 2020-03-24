#pragma once
#include "solutions.h"
#include <stack>
/*
	71. Simplify Path
*/

class SimplifyPath {
public:
    //自己的写法，效率还可以，但是有点啰嗦，要用test case测很多遍才accept
    string simplifyPath(string path) 
    {
        string result = "";
        if(path.length() == 0 || path[0] != '/')
            return result;
        string subStr = "";
        stack<string> st;
        for (int i = 1; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                if (subStr != "")
                {
                    if (subStr == "..")
                    {
                        if(!st.empty())
                            st.pop();
                    }
                    else if (subStr == ".")
                    {
                        subStr = "";
                        continue;
                    }
                    else
                        st.push(subStr);
                    subStr = "";
                }
            }
            else
                subStr += path[i];
        }
        //if last charactor not '/'
        if (subStr != "")
        {
            if (subStr == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
            {
                if (subStr != ".")
                    st.push(subStr);
            }
        }

        if (!st.empty())
        {
            result = st.top();
            st.pop();
        }
        while (!st.empty())
        {
            result = st.top() + '/' + result;
            st.pop();
        }

        return '/'+result;
    }
};
