#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<set>
#include<sstream>

using namespace std;

class bag{
    public:
        string color;
        vector<pair<int,string>> contain;

        bag(string input){
            stringstream ss(input);
            string s;
            ss>>s;
            color=s;
            ss>>s;
            color+=" "+s;
            ss>>s;//bags
            ss>>s;//contain
            pair<int,string>p;
            while(ss>>s){
                if(s=="no")break;
                p.first=s[0]-'0';
                ss>>s;
                p.second=s;
                ss>>s;
                p.second+=" "+s;
                ss>>s;//bags, ili bag.
                contain.push_back(p);
            }
        }

        bool operator==(bag b) {return color==b.color;}
        bool operator==(string s) {return color==s;}

        void ispis(ostream& out){
            out<<color;
            out<<'{';
            for(auto x: contain){
                cout<<x.first<<x.second<<", ";
            }
            cout<<'}'<<endl;
        }
};

vector<bag> load(string input){
    ifstream f(input);
    vector<bag> v;
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return v;
    }
    string s;
    while(!f.eof()){
        getline(f,s);
         v.push_back(bag(s));
    }
    return v;
}

bool contain(bag b, vector<bag> v, set<string>& yes, set<string>& no){
    if(b.color=="shiny gold"){
        return true;
    }
    else{
        if(yes.find(b.color)!=yes.end())return true;
        else if(no.find(b.color)!=no.end())return false;
        else{
            vector<bag>::iterator it;
            for(auto x: b.contain){
                it=find(v.begin(),v.end(), x.second);
                if(it!=v.end()){
                    if(contain(*it,v,yes,no)){
                        yes.insert(b.color);
                        return true;
                    }
                }
                else cout<<"GRESKA";
            }
        }
    }
    no.insert(b.color);
    return false;
}

int numBags(bag b, vector<bag> v){
    int cnt=1;
    vector<bag>::iterator it;
    for(auto x: b.contain){
        it=find(v.begin(),v.end(), x.second);
        if(it!=v.end()){
            cnt+=x.first*numBags(*it,v);
        }
        else cout<<"GRESKA";
    }
    return cnt;
}

int task1(vector<bag> v){
    set<string> yes, no;
    for(auto x: v){
        contain(x,v,yes,no);
    }
    /*if(yes.size()+no.size()!=v.size())cout<<"SIZE";
    for(auto x: yes){
        cout<<x<<endl;
    }*/
    return yes.size();
}

int task2(vector<bag> v){
    vector<bag>::iterator it=find(v.begin(),v.end(),"shiny gold");
    return numBags(*it,v)-1;
}

int main(){
    string input="../../Day7Input.txt";
    //string input="../../Day7Test.txt";
    vector<bag> v=load(input);
    //for(auto x: v)x.ispis(cout);
    int a= task1(v);
    cout<<"Task1= "<<a<<endl;
    int b= task2(v);
    cout<<"\nTask2= "<<b<<endl;
    return 0;
}