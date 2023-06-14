#include <bits/stdc++.h>
using namespace std;
struct ii //Thông tin di kèm v?i m?i d?u mút i
{
    int val; //Toa do
    int kind; //Ðóng/mo {1/0}
    int conf; //So hieu cuoc hop
};
ii ID[1000001];
int n,u,v;
int m; //Luu so luong phòng can dùng, cung chính là so hieu phòng max
int meet[1000001];
vector <int> room[1000001]; //Vì 1 phòng có the to chuc nhieu cuoc hop, nên dùng Vector
stack <int> s;

bool cmp(const ii&x, const ii &y)
{
    if (x.val==y.val) return x.kind>y.kind;
    else return x.val<y.val;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("ROOMS.inp","r",stdin);
    freopen("ROOMS.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>u>>v;
        ID[i*2-1].val=u;
        ID[i*2].kind=0;
        ID[i*2-1].conf=i;

        ID[i*2].val=v;
        ID[i*2].kind=1;
        ID[i*2].conf=i;

    }
   for (int i=n;i>=1;i--) s.push(i);//Ðay n phòng vào Stack

    sort (ID+1,ID+2*n+1,cmp);

    for (int i=1;i<=2*n;i++)
    {
        if (ID[i].kind==0) //Neu gap toa do là diem bat dau 1 cuoc hop
        {
            int meetNum=s.top(); s.pop(); //Lay 1 phòng trong Stack
            meet[ID[i].conf]=meetNum; // Gán cho cuoc hop conf

            room[meetNum].push_back(ID[i].conf); //Bo sung cuoc hop vào phòng meetNum, chú ý 1 phòng có the dùng cho nhieu cuoc hop
            m=max(m,meetNum);//Xác dinh so hieu phòng max
        }
        else s.push(meet[ID[i].conf]); //Neu gap toa do là diem ket thúc 1 cuoc hop, thì tra phòng lai cho Stack
    }
    cout<<m<<'\n';
    for (int i=1;i<=m;i++)
    {
        for (int j=0;j<room[i].size();j++) cout<<room[i][j]<<" ";
        cout<<'\n';
    }
}