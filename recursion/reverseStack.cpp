#include <bits/stdc++.h>
#include <stack>
using namespace std;

void insertBottom(stack<int> &st, int x){
    if(st.empty()) {
        st.push(x);
        return;
    }
    int u = st.top();
    st.pop();
    insertBottom(st, x);
    st.push(u);
}

void reverse(stack<int> &st){
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    reverse(st);
    insertBottom(st, x);
}
