// Write a program to detect tokens in C
#include <bits/stdc++.h>
#include"error_log.h"
using namespace std;

vector<std::string> splitString(string& str, char delimiter) {
  vector<string> result;
  stringstream ss(str);
  string token;
  while (getline(ss, token, delimiter)) {
      result.push_back(token);
  }
  return result;
}
int main(){
Error_log* l = new Error_log() ;
ifstream inputFile("input.txt");
if (!inputFile) {
      cout << "Unable to open file" << endl;
      return 0; 
}
string s ;
while (std::getline(inputFile, s)) {
    cout << s << endl;
    string v1 = s.substr(0,1) ; 
    string v2 = s.substr(2) ;
    vector<string> v ;
    if(v1=="1"){
        v = splitString(v2,';') ;
        uint64_t a = stoull(v[0]) ;
        string str = v[1]  ;
        l->add(stoull(v[0]),str,stod(v[2])) ;
        cout<<"No output"<<endl ;
    }
    else if(v1=="4"){
        v = splitString(v2,' ') ;
        vector<double> b ;
        string str = v[1]  ;
        if(v[0]=="BEFORE") b = l->before(stoull(v[2]),str) ;
        else b = l->after(stoull(v[2]),str) ;
        if(b.size()==0) cout<<"Min: 0.0 , Max: 0.0 , Mean: 0.0"<<endl ; 
        else
        cout<<"Min: "<<b[1]<<", Max: "<<b[2]<<", Mean: "<<b[0]<<endl ; 
    }
    else if(v1=="2"){
        v = splitString(v2,';') ;
        string str = v[0] ;
       vector<double> b = l->log_type(str) ;
       if(b.size()==0) cout<<"Min: 0.0 , Max: 0.0 , Mean: 0.0"<<endl ; 
       else
       cout<<"Min: "<<b[1]<<", Max: "<<b[2]<<", Mean:"<<b[0]<<endl ;
    } 
    else{
        v = splitString(v2,' ') ;
        vector<double> b ;
        if(v[0]=="BEFORE") b = l->before(stoull(v[1])) ;
        else b = l->after(stoull(v[1])) ;
        if(b.size()==0) cout<<"Min: 0.0 , Max: 0.0 Mean: 0.0"<<endl ; 
        else
        cout<<"Min: "<<b[1]<<", Max: "<<b[2]<<", Mean:"<<b[0]<<endl ;  
    }
  }

  inputFile.close();
return 0 ;
}