#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cctype>
#include<sstream>

using namespace std;

bool Fill(string &s, ifstream &f){
    bool ret=!f.eof();
    s.clear();
    char c;
    f.get(c);
    while(!f.eof()){
        if(c=='\n')break;
        if(c==' ')break;
        s.push_back(c);
        f.get(c);
    }
    return ret;
}

class passport{
public:
    string byr;
    string iyr;
    string eyr;
    string hgt;
    string hcl;
    string ecl;
    string pid;
    string cid;

    passport(ifstream &f){
        string s;
        while(Fill(s,f)){
            if(s.empty())break;
            else if(s.substr(0,3)=="byr")byr=s.substr(4);
            else if(s.substr(0,3)=="iyr")iyr=s.substr(4);
            else if(s.substr(0,3)=="eyr")eyr=s.substr(4);
            else if(s.substr(0,3)=="hgt")hgt=s.substr(4);
            else if(s.substr(0,3)=="hcl")hcl=s.substr(4);
            else if(s.substr(0,3)=="ecl")ecl=s.substr(4);
            else if(s.substr(0,3)=="pid")pid=s.substr(4);
            else if(s.substr(0,3)=="cid")cid=s.substr(4);
            s.clear();
        }
    }
    bool is_valid(){
        if(byr.empty())return false;
        if(iyr.empty())return false;
        if(eyr.empty())return false;
        if(hgt.empty())return false;
        if(hcl.empty())return false;
        if(ecl.empty())return false;
        if(pid.empty())return false;
        return true;
    }

    bool byr_valid(){
        int x;
        stringstream ss(byr);
        ss>>x;
        return 1920<=x && x<=2002;

    }

    bool iyr_valid(){
        int x;
        stringstream ss(iyr);
        ss>>x;
        return 2010<=x && x<=2020;
    }

    bool eyr_valid(){
        int x;
        stringstream ss(eyr);
        ss>>x;
        return 2020<=x && x<=2030;
    }

    bool hgt_valid(){
        int x;
        stringstream ss;
        if(hgt.size()<3)return false;
        string s=hgt.substr(0,hgt.size()-2);
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i]))return false;
        }
        ss.str(s);
        ss>>x;
        if(hgt.substr(hgt.size()-2,2)=="cm"){
            return 150<=x && x<=193;
        }
        else if(hgt.substr(hgt.size()-2,2)=="in"){
            return 59<=x && x<=76;
        }
        else return false;
    }

    bool hcl_valid(){
        if(hcl.size()!=7)return false;
        if(hcl[0]!='#')return false;
        for(int i=1;i<7;i++){
            char x=hcl[i];
            if(x<'0')return false;
            if(x>'9' && x<'a')return false;
            if(x>'f')return false;
        }
        return true;
    }

    bool ecl_valid(){
        if(ecl.size()!=3)return false;
        if(ecl=="amb")return true;
        if(ecl=="blu")return true;
        if(ecl=="brn")return true;
        if(ecl=="gry")return true;
        if(ecl=="grn")return true;
        if(ecl=="hzl")return true;
        if(ecl=="oth")return true;
        return false;
    }

    bool pid_valid(){
        if(pid.size()!=9)return false;
        for(int i=1; i<9;i++)
            if(!isdigit(pid[i]))return false;
        return true;
    }
};

vector<passport> load(string input){
    ifstream f(input);
    vector<passport> v;
    while(!f.eof()){
        passport p(f);
        v.push_back(p);
    }
    return v;
}

int task1(vector<passport> v){
    int cnt=0;
    for(int i=0; i<v.size();i++){
        if(v[i].is_valid())cnt++;
    }
return cnt;
}


int task2(vector<passport> v){
    int cnt=0;
    for(int i=0; i<v.size();i++){
        if(v[i].is_valid()){
            if(v[i].byr_valid() && v[i].iyr_valid() && v[i].eyr_valid() &&
               v[i].hgt_valid() && v[i].hcl_valid() &&
               v[i].ecl_valid() && v[i].pid_valid())
                cnt++;
        }
    }
return cnt;
}

int main(){
    string input="Day4Input.txt";
    vector<passport> v=load(input);
    int a= task1(v);
    cout<<"Task1= "<<a<<endl;
    int b= task2(v);
    cout<<"\nTask2= "<<b<<endl;
}
