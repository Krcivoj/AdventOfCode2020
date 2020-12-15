#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

vector<vector<char>> load(string input){
    vector<vector<char>> vv;
    vector<char> v;
    char c;
    fstream f(input);
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return vv;
    }
    f.get(c);
    while(!f.eof()){
        if(c=='\n'){
            vv.push_back(v);
            v.clear();
        }
        else v.push_back(c);
        f.get(c);
    }
    vv.push_back(v);
    return vv;
}

int occupied (vector<vector<char>> vv, int i, int j){
    int cnt=0;
    if(i>0){
        if(j>0){
            if(vv[i-1][j-1]=='#')cnt++;
        }
        if(vv[i-1][j]=='#')cnt++;
        if(j<vv[i-1].size()-1){
            if(vv[i-1][j+1]=='#')cnt++;
        }
    }
    if(j>0){
        if(vv[i][j-1]=='#')cnt++;
    }
    if(j<vv[i].size()-1){
        if(vv[i][j+1]=='#')cnt++;
    }
    if(i<vv.size()-1){
        if(j>0){
            if(vv[i+1][j-1]=='#')cnt++;
        }
        if(vv[i+1][j]=='#')cnt++;
        if(j<vv[i+1].size()-1){
            if(vv[i+1][j+1]=='#')cnt++;
        }
    }
    return cnt;
}

bool modify1(vector<vector<char>>& vv){
    vector<vector<char>>vv2;
    vector<char> v2;
    bool changed=false;
    for(int i=0;i<vv.size();i++){
        for(int j=0; j<vv[i].size();j++){
            if(vv[i][j]=='L' && occupied(vv,i,j)==0){
               v2.push_back('#');
               changed=true; 
            }
            else if(vv[i][j]=='#' && occupied(vv,i,j)>3){
               v2.push_back('L');
               changed=true; 
            }
            else v2.push_back(vv[i][j]);
        }
        vv2.push_back(v2);
        v2.clear();
    }
    vv=vv2;
    return changed;
}

int task1(vector<vector<char>> vv){
    int cnt=0;
    while(modify1(vv)){}
    for(int i=0;i<vv.size();i++){
        for(int j=0; j<vv[i].size();j++){
            if(vv[i][j]=='#')cnt++;
        }
    }
    return cnt;
}

bool in(vector<vector<char>> vv, int i, int j){return i>=0 && i<vv.size() && j>=0 && j<vv[i].size();}

int occupiedVisible(vector<vector<char>> vv, int i, int j){
    int cnt=0;
    int m,n;
    m=i-1;
    n=j-1;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        m--;
        n--;
    }
    m=i-1;
    n=j;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        m--;
    }
    m=i-1;
    n=j+1;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        m--;
        n++;
    }
    m=i;
    n=j-1;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        n--;
    }
    m=i;
    n=j+1;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        n++;
    }
    m=i+1;
    n=j-1;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        m++;
        n--;
    }
    m=i+1;
    n=j;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        m++;
    }
    m=i+1;
    n=j+1;
    while(in(vv,m,n)){
        if(vv[m][n]=='#'){
            cnt++;
            break;
        }
        if(vv[m][n]=='L')break;
        m++;
        n++;
    }
    return cnt;
}

bool modify2(vector<vector<char>>& vv){
    vector<vector<char>>vv2;
    vector<char> v2;
    bool changed=false;
    for(int i=0;i<vv.size();i++){
        for(int j=0; j<vv[i].size();j++){
            if(vv[i][j]=='L' && occupiedVisible(vv,i,j)==0){
               v2.push_back('#');
               changed=true; 
            }
            else if(vv[i][j]=='#' && occupiedVisible(vv,i,j)>4){
               v2.push_back('L');
               changed=true; 
            }
            else v2.push_back(vv[i][j]);
        }
        vv2.push_back(v2);
        v2.clear();
    }
    vv=vv2;
    return changed;
}

int task2(vector<vector<char>> vv){
    int cnt=0;
    while(modify2(vv)){}
    for(int i=0;i<vv.size();i++){
        for(int j=0; j<vv[i].size();j++){
            if(vv[i][j]=='#')cnt++;
        }
    }
    return cnt;
}

int main(){
    //string input="../../Day11Test.txt";
    string input="../../Day11Input.txt";
    vector<vector<char>> vv=load(input);
    int a= task1(vv);
    cout<<"Task1= "<<a<<endl;
    int b= task2(vv);
    cout<<"\nTask2= "<<b<<endl;
    return 0;
}