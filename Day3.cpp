#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int trees( vector<vector<char>>vv, int right, int down){
    int cnt=0;
    for(int i=0, j=0;i<vv.size();i+=down){
        j%=vv[i].size();
        if(vv[i][j]=='#')cnt++;
        j+=right;
    }
    return cnt;
}
vector<vector<char>> load(string input){
    char c[100];
    vector<vector<char>>vv;
    vector<char>vc;
    ifstream f(input);
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return vv;
    }
    while(1){
        f.getline(c,100);
        if(c[0]=='\0')break;
        for(int i=0;c[i]!='\0';i++)
            vc.push_back(c[i]);
        vv.push_back(vc);
        vc.clear();
    }
    //ispis ucitanih podataka
    /*for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++){
            cout<<vv[i][j];
        }
        cout<<"!\n";
    }*/
    return vv;
}


int task1(string input){
    vector<vector<char>>vv=load(input);
    return trees(vv,3,1);
}

int task2(string input){
    vector<vector<char>>vv=load(input);
    int cnt=trees(vv,1,1);
    cnt*=trees(vv,3,1);
    cnt*=trees(vv,5,1);
    cnt*=trees(vv,7,1);
    cnt*=trees(vv,1,2);
    return cnt;
}

int main(){
    int a=task1("Day3Input.txt");
    cout<<"Task1= "<<a<<endl;
    int b=task2("Day3Input.txt");
    cout<<"\nTask2= "<<b<<endl;
return 0;
}
