#include <string>
using namespace std;

string encrypt(string s){
    for (int i = 0; i<s.length(); i++){
        s[i] = s[i] + 45;
    }
    return s;
}

string decrypt(string s){
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i] - 45;
    }
    return s;
}

string encryptDouble(double d){
    string s = to_string(d);
    for (int i = 0; i<s.length(); i++){
        s[i] = s[i] + 45;
    }
    return s;
}

double decryptDouble(string s){
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i] - 45;
    }
    double d = stod(s);
    return d;
}