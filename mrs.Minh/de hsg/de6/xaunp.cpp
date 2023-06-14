#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
string s;
ll dem = 0;
void slove(){
    for(int i = 0; i < s.size(); i++){
        if((s[i] == '0' && s[i+1] == '1')){
            dem++;
            i++;
            continue;
        }
        if((s[i] == '1' && s[i+1] == '1')){
            dem++;
            i++;
            continue;
        }
    }
    cout<<s.size() - 2*dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("xaunp.inp","r",stdin);
    freopen("xaunp.out","w",stdout);
    cin>>s;
    slove();
}
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long 
// const long long R = 1e9+7;
// const long long N = 1e6+9;
// ll n;
// string s;
// stack<char>st;
// void slove(){
//     for(int i = 0; i < s.size(); i++){
//         //int t = s[i] - '0';
//         if(!st.empty())
//             if(((st.top() == '1') || (st.top() == '0')) && s[i] == '1')
//                 st.pop();
//             else
//                 st.push(s[i]);
//         else
//             st.push(s[i]);
//     }
//     cout<<st.size();
// }

// int main()
// {
//     cin.tie(NULL); cout.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     freopen("xaunp.inp","r",stdin);
//     freopen("xaunp.out","w",stdout);
//     cin>>s;
//     slove();
// }