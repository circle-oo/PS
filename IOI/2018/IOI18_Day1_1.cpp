#include<iostream>
#include<string>
#include<vector>
#include"combo.h"
 
using namespace std;
 
vector<string> str;
 
string guess_sequence(int N) {
  string p = "";
  str.push_back("A");
  str.push_back("B");
  str.push_back("X");
  str.push_back("Y");
  int a = press("AB"), b = press("AX");
  if((a > 0) && (b > 0)) {
    p += "A";
    str.erase(str.begin());
  } else if(a > 0) {
    p += "B";
    str.erase(str.begin()+1);
  } else if(b > 0){
    p += "X";
    str.erase(str.begin()+2);
  } else {
    p += "Y";
    str.erase(str.begin()+3);
  }
  if(N == 1) return p;
  for(int i = 1; i < N-1; i++) {
    string tmp = p + str[0] + str[0] + p + str[0] + str[1] + p + str[0] + str[2] + p + str[1];
    int k = press(tmp);
    if(k == i+2) p += str[0];
    else if(k == i+1) p += str[1];
    else p += str[2];
  }
  a = press(p+str[0]);
  b = press(p+str[1]);
  if(a == N) p += str[0];
  else if(b == N) p += str[1];
  else p += str[2];
  return p;
}
