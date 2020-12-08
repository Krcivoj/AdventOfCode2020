#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class instruction{
    public:
        string op;
        int num;
        bool done;

        instruction(string s, int x):op(s),num(x),done(false){}

        bool operator()(int& acc, int& i){
            if(done)return false;
            done=true;
            if(op=="acc"){
                acc+=num;
                i++;
                return true;
            }
            if(op=="jmp"){
                i+=num;
                return true;
            }
            if(op=="nop"){
                i++;
                return true;
            }
            cout<<"\nNOT VALID OPERATION "<<op<<endl;
            return false;
        }

        bool swap(){
            if(op=="acc")return false;
            if(op=="jmp"){
                op="nop";
                return true;
            }
            op="jmp";
            return true;
        }

};

vector<instruction> load(string input){
    ifstream f(input);
    vector<instruction> v;
    if(!f.is_open()){
        cout<<"CAN NOT READ "<<input;
        return v;
    }
    string s;
    int x;
    while(f>>s){
        f>>x;
        //cout<<s<<x<<endl;
        v.push_back(instruction(s,x));
    }
    return v;
}

int task1(vector<instruction> v){
    int acc=0, i=0;
    if(v.empty())return 0;
    while(v[i](acc,i)){}
    return acc;
}

int task2(vector<instruction> v){
    int acc=0;
    for(int i=0; i<v.size();i++){
        vector<instruction> tempV=v;
        if(tempV[i].swap()){
            int j=0;
            acc=0;
            while(tempV[j](acc,j)){
                if(j>=tempV.size())return acc;
            }  
        }
    }
    return acc;
}


int main(){
    //string input="../../Day8Test.txt";
    string input="../../Day8Input.txt";
    vector<instruction> v=load(input);
    int a= task1(v);
    cout<<"Task1= "<<a<<endl;
    int b= task2(v);
    cout<<"\nTask2= "<<b<<endl;
    return 0;
}