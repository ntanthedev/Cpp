#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
string s;
stack<int>st;
ll Li, Lj, gmax = 0;
void slove(){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            st.push(i);
        else{
            st.pop();
            if(st.empty())
                st.push(i);
            else{
                if(i - st.top() > gmax){
                    gmax = i - st.top();
                    Li = st.top()+1;
                    Lj = i;
                }
            }
        }
    }
    cout<<gmax<<'\n';
    cout<<Li+1<<" "<<Lj+1;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("LBRACKET.inp","r",stdin);
    freopen("LBRACKET.out","w",stdout);
    cin>>s;
    st.push(-1);
    slove();
}
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long 
// const long long R = 1e9+7;
// const long long N = 1e6+9;
// string s;
// stack<int>st;
// ll Li, Lj, gmax = LLONG_MIN;
// void slove(){
//     st.push(-1);
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == '(')
//             st.push(i);
//         else{
//             st.pop();
//             if(st.empty())
//                 st.push(i);
//             else{
//                 if(i - st.top() > gmax)
//                     gmax = i - st.top();
//                     Li = st.top()+1;
//                     Lj = i;         
//             }
//         }    
//     }
//     cout<<gmax<<'\n';
//     cout<<Li<<" "<<Lj;
// }

// int main()
// {
//     cin.tie(NULL); cout.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     freopen("LBRACKET.inp","r",stdin);
//     freopen("LBRACKET.out","w",stdout);
//     cin>>s;
//     slove();
// }
