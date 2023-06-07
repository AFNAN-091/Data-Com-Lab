//           * * ببسم الله الرحمن الرحيم    * *
// ********************@Author**************************************
//     ____     _____   __  _     ____     __  _
//    / __ \   | ____| |  \| |   / __ \   |  \| |
//   / /__\ \  | |__   | |\  |  / /__\ \  | |\  |
//  /_/    \_\ |_|     |_| \_| /_/    \_\ |_| \_|
 
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lcm(a,b)    a*b/__gcd(a,b)
#define endl '\n'
#define yes cout<< "YES\n"
#define no cout<< "NO\n"
#define f(x) cout<< x <<endl
#define in(x) cin>> x 
#define er(x) cerr << x << endl
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)
#define FAsT ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz 50000
#define intmax INT_MAX
#define intmin INT_MIN
typedef long long ll;
typedef vector<long long> vi;
int rr[] = { -1, 1, 0, 0, -1, -1, 1, 1};
int cc[] = {0, 0, -1, 1, -1, 1, -1, 1};
/*--------------------------------------------------------------------*/

string add(string data, ll len)
{
    ll n = data.length();
    ll cnt =1;
    while(n!=len)
    {
        string pre = data.substr(0, n-len);
	    data = data.erase(0,n-len);
	    ll j = pre.length();
	    j --;
	    string res = "";
        ll c = 0;
        //cout<<data<<" "<<pre<<endl;
        for(int i = data.size()-1; i >=0; i--)
        {
            if(j<0)
            {
                if(c==1 and data[i]=='1')
                {
                    res+='0';
                    c = 1;
                }
                else if(c==1 or data[i]=='1'){
                    res+='1';
                    c = 0;
                }
                else{
                    res+='0';
                    c = 0;
                }
            }
            else{
                if(c==1 and data[i]=='1' and pre[j]=='1')
                {
                    res+='1';
                    c = 1;
                }
                else if(c==1 and data[i]=='1'){
                    res+='0';
                    c = 0;
                }
                else if(data[i]=='1' and pre[j]=='1')
                {
                    res+='0';
                    c = 1;
                }
                else if(pre[j]=='1' and c==1)
                {
                    res+='0';
                    c = 1;
                }
                else if(c==1){
                    res+='1';
                    c = 0;
                }
                else if(data[i]=='1')
                {
                    res+='1';
                    c = 0;
                }
                else if(pre[j]=='1')
                {
                    res+='1';
                    c = 0;
                }
                else{
                    res+='0';
                    c = 0;
                }
            }
            j--;
           // cout<<res<<endl;
        }
        if(c==1)
        {
            res+='1';
        }
        reverse(res.begin(),res.end());
        n = res.length();
        data = res;
        //cout<<res<<endl;
    }

    return data;
}

int main()
{   
    FAsT  
    cout<<"Enter the number of n: ";

    ll n;
    cin>>n;
    cout<<endl;
    vi v(n);
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    ll mx = *max_element(v.begin(), v.end());

    ll numbits = log2(mx)+1;
    const ll numbitsSum = log2(sum) +1;

    bitset<32> bitSum (sum);
    //cout<<numbits<<endl;
    cout<<bitSum<<endl;
    string data = bitSum.to_string();
    data.erase(0,32-numbitsSum);
  //  cout<<data<<endl;
    string res = add(data, numbits);
    cout<<res<<endl;
    for(int i=0; i<res.length(); i++)
    {
        if(res[i]=='1'){
            res[i] = '0';
        }
        else{
            res[i] = '1';
        }
    }
    bitset<32> checkSum (res);
    
    cout<<"CheckSum in Binary : "<<checkSum<<endl;
    ll val = checkSum.to_ulong();
    cout<<"CheckSum in decimal: "<< val<<endl;
    sum+=val;
    bitset<32> recbin (sum);
    cout<<sum<<endl;
    string recStrign = recbin.to_string();
    string receiver = add(recStrign, numbits);
    for(int i=0; i<receiver.length(); i++)
    {
        if(receiver[i]=='1'){
            receiver[i] = '0';
        }
        else{
            receiver[i] = '1';
        }
    }
    cout<<"Receiver Checksum: "<<receiver<<endl;
    if(count(receiver.begin(),receiver.end(),'1'))
    {
        cout<<"Error Detected!!!"<<endl;
    }
    else{
        cout<<"Correct message received!!!"<<endl;
    }
       
    exit(0);
}
//Solution submitted by: AFnaN, SUST CSE19