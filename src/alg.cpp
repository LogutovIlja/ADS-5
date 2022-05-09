// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int pri(char p) {
    switch (p) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    case ' ':
        return 4;
    default:
        return 5;
    }
}
int call(char k, int x, int y) {
    switch (k) {
    case '+':
        return (x + y);
    case '-':
        return (y - x);
    case '*':
        return (x * y);
    case '/':
        return (y / x);
    default:
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
    std::string st;
    char pu = ' ';
    TStack<char, 100> stack1;
    for (int i = 0; i < inf.size(); i++) {
        if (pri(inf[i]) == 5) {
            st.push_back(inf[i]);
            st.push_back(pu);
        } else {
            if (pri(inf[i]) == 0) {
                stack1.push(inf[i]);
            } else if (stack1.isEmpty()) {
                stack1.push(inf[i]);
            } else if ((pri(inf[i]) > pri(stack1.get()))) {
                stack1.push(inf[i]);
            } else if (pri(inf[i]) == 1) {
                while (pri((stack1.get()) != 0)) {
                    st.push_back(stack1.get());
                    st.push_back(pu);
                    stack1.pop();
                }
                stack1.pop();
            } else {
                char a = pri(inf[i]);
                char b = pri(stack1.get());
                while ((a <= b) && (!stack1.isEmpty())) {
                    st.push_back(stack1.get());
                    st.push_back(pu);
                    stack1.pop();
                }
                stack1.push(inf[i]);
            }
        }
        while (!stack1.isEmpty()) {
            st.push_back(stack1.get());
            st.push_back(pu);
            stack1.pop();
        }
        for (int i = 0; i < st.size(); i++) {
            if (st[st.size() - 1] == ' ')
                st.erase(st.size() - 1);
        }
        return st;
}

int eval(std::string st); {
    TStack<int, 100> stack2;
    std::string z;
    int x = 0;
    int y = 0;
    for (int i = 0; i < st.size(); i++) {
        if (pri(st[i]) == 5) {
            stack2.push(st[i] - '0');
        } else if (pri(st[i]) < 5) {
            x = stack2.get();
            stack2.pop();
            y = stack2.get();
            stack2.pop();
            stack2.push(call(st[i], x, y));
        }
    }
    z = stack2.get();
    return z;
    return 0;
}
