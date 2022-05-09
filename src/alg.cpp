// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include <iostream>
#include "tstack.h"


int prir(char pr) {
    switch (pr) {
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
    default:
        return -1;
    }
}
int call(char k, int x, int y) {
    switch (k) {
    case '+':
        return x + y;
            break;
    case '-':
        return x - y;
            break;
    case '*':
        return x * y;
            break;
    case '/':
        return x / y;
            break;
    default:
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
  TStack <char, 100> stack1;
  std::string st;
  for (size_t i = 0; i < inf.size(); i++) {
    if ((prir(inf[i]) == -1) && (prir(inf[i]) != 1)) {
      if (!st.empty() && prir(inf[i - 1]) != -1) {
        st.push_back(' ');
      }
      st.push_back(inf[i]);
    } else if ((prir(inf[i]) > prir(stack1.get()))
               || (stack1.isEmpty()) || (prir(inf[i]) == 0)) {
      stack1.push(inf[i]);
    } else {
      if (prir(inf[i]) == 1) {
        while (prir(stack1.get()) != 0) {
          st.push_back(' ');
          st.push_back(stack1.get());
          stack1.pop();
        }
        stack1.pop();
      } else {
        while (prir(stack1.get()) >= prir(inf[i])) {
          st.push_back(' ');
          st.push_back(stack1.get());
          stack1.pop();
        }
        stack1.push(inf[i]);
      }
    }
  }
  while (!stack1.isEmpty()) {
    st.push_back(' ');
    if (prir(stack1.get()) != 0) {
      st.push_back(stack1.get());
    }
    stack1.pop();
  }
  return st;
}

int eval(std::string pst) {
    TStack<int, 100> stack2;
    int z = 0;
    int x = 0;
    int y = 0;
for (int i = 0; i < pst.length(); i++) {
        if ((prir(pst[i]) == -1) && pst[i] != ' ') {
            stack2.push(pst[i] - '0');
        } else if (prir(pst[i]) > 1) {
            y = stack2.get();
            stack2.pop();
            x = stack2.get();
            stack2.pop();
            stack2.push(call(pst[i], x, y));
        }
    }
    z = stack2.get();
  return z;
}
