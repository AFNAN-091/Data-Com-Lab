#include<iostream>

using namespace std;

int main()
{
    string s;
    cout<<"Enter the Dataword :";
    cin>>s;
    long long cnt = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='1')
        {
            cnt++;
        }
    }

    if(cnt&1)
    {
        s+='1';
        cout<<"Codeword : "<<s<<endl;
        cout<<"Parity bit : "<<1<<endl;
    }
    else{
        s+='0';
        cout<<"Codeword : "<<s<<endl;
        cout<<"Parity bit : "<<0<<endl;
    }

    exit(0);
}