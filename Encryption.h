#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include "Encryption.h"
#include <string>
using namespace std;

inline string encrypt(string s){
    for (int i = 0; i<s.length(); i++){
        s[i] = s[i] + 45;
    }
    return s;
}

inline string decrypt(string s){
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i] - 45;
    }
    return s;
}

inline string encryptDouble(double d){
    string s = to_string(d);
    for (int i = 0; i<s.length(); i++){
        s[i] = s[i] + 45;
    }
    return s;
}

inline double decryptDouble(string s){
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i] - 45;
    }
    double d = stod(s);
    return d;
}

inline string encryptInt(int i){
    string s = to_string(i);
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i] + 45;
    }
    return s;
}

inline int decryptInt(string s){
    for (int i = 0; i < s.length(); i++){
        s[i] = s[i] - 45;
    }
    int i = stoi(s);
    return i;
}
#endif