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

void AFnaN()
{
  
}


string xor1(string a, string b)
{
 
    // Initialize result
    string result = "";
 
    int n = b.length();
 
    // Traverse all bits, if bits are
    // same, then XOR is 0, else 1
    for (int i = 1; i < n; i++) {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

string mod2div(string dividend, string divisor)
{
 
    // Number of bits to be XORed at a time.
    int pick = divisor.length();
 
    // Slicing the dividend to appropriate
    // length for particular step
    string tmp = dividend.substr(0, pick);
 
    int n = dividend.length();
 
    while (pick < n) {
        if (tmp[0] == '1')
 
            // Replace the dividend by the result
            // of XOR and pull 1 bit down
            tmp = xor1(divisor, tmp) + dividend[pick];
        else
 
            // If leftmost bit is '0'.
            // If the leftmost bit of the dividend (or the
            // part used in each step) is 0, the step cannot
            // use the regular divisor; we need to use an
            // all-0s divisor.
            tmp = xor1(string(pick, '0'), tmp)
                  + dividend[pick];
 
        // Increment pick to move further
        pick += 1;
    }
 
    // For the last n bits, we have to carry it out
    // normally as increased value of pick will cause
    // Index Out of Bounds.
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(std::string(pick, '0'), tmp);
 
    return tmp;
}


string  encodeData(string data, string key)
{
    int l_key = key.length();
 
    // Appends n-1 zeroes at end of data
    string appended_data
        = (data + string(l_key - 1, '0'));
 
    string remainder = mod2div(appended_data, key);
 
    // Append remainder in the original data
    string codeword = data + remainder;
    cout << "Remainder : " << remainder << "\n";
    cout << "Encoded Data (Data + Remainder) :" << codeword
         << "\n";
         return codeword;
}

void receiver(string data, string key)
{
    string currxor
        = mod2div(data.substr(0, key.size()), key);
    int curr = key.size();
    while (curr != data.size()) {
        if (currxor.size() != key.size()) {
            currxor.push_back(data[curr++]);
        }
        else {
            currxor = mod2div(currxor, key);
        }
    }
    if (currxor.size() == key.size()) {
        currxor = mod2div(currxor, key);
    }
    if (count(currxor.begin(), currxor.end(),'1')) {
        cout << "there is some error in data" << endl;
    }
    else {
        cout << "correct message received" << endl;
    }
}

int main()
{   
    FAsT  
    cout<<"Enter the Dataword: ";
    string dataword;
    cin>>dataword;
    cout<<endl;
    cout<<"Enter the Divisor :";
    string divisor;
    cin>>divisor;

    string codeword = encodeData(dataword, divisor);
   
    receiver(codeword,divisor);
    exit(0);
}
//Solution submitted by: AFnaN, SUST CSE19