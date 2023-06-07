#include <iostream>
#include <string>
#include <vector>
using namespace std;
int hammingDistance(string codeword1, string codeword2) {
    int distance = 0;
    if (codeword1.length() != codeword2.length()) {
        return -1;
    }
    for (int i = 0; i < codeword1.length(); i++) {
        if (codeword1[i] != codeword2[i]) {
            distance++;
        }
    }
    return distance;
}

int minimumHammingDistance( vector<string>& codewords) {
    if (codewords.empty()) {
        
        return -1; 
    }
    int minDistance = codewords[0].length(); 
    for (int  i = 0; i < codewords.size(); i++) {
        for (int j = i + 1; j < codewords.size(); j++) {
            int distance = hammingDistance(codewords[i], codewords[j]);
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
    }
    return minDistance;
}

int main() {
   
    long long n;
    cin>>n;

    vector<string> codewords(n);
    for(int i=0; i<n; i++)
    {
        cin>>codewords[i];
    }
    int minDistance = minimumHammingDistance(codewords);
    cout << "Minimum Hamming distance: " << minDistance << endl;

    return 0;
}
