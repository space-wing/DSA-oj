#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
//运算符优先级
int op(char c){
    if(c=='+'||c=='-')return 0;
    else return 1;
}

//中缀表达式转后缀表达式
string change_behind(string middle){
    int l=middle.length();
    int i=0;
    string behind;
    stack<char> sign;
    while(i<l){
        char c=middle[i];
        if(middle[i]=='+'||middle[i]=='-'||middle[i]=='*'||middle[i]=='/'){
            if(sign.empty())sign.push(c);
            else{
                if(sign.top()=='(')sign.push(c);
                else{
                    while(!sign.empty() and op(sign.top())>=op(c) and sign.top()!='('){
                        behind=behind+sign.top()+' ';
                        sign.pop();
                    }
                    sign.push(c);
                }
            }
            i++;
        }
        else if(middle[i]=='('){
            sign.push('(');
            i++;
        }
        else if(middle[i]==')'){
            while(sign.top()!='('){
                behind+=sign.top();
                behind+=' ';
                sign.pop();
            }
            sign.pop();
            i++;
        }
        else{
            while(middle[i]>='0' and middle[i]<='9'){
                behind+=middle[i];
                i++;
            }
            behind+=' ';
        }
    }
    while(!sign.empty()){
        behind=behind+sign.top()+' ';
        sign.pop();
    }
    return behind;
}
//后缀表达式求值
int solve_behind(string behind){
    int l=behind.length();
    int i=0;
    stack<int> num;
    while(i<l){
        if(behind[i]=='+'||behind[i]=='-'||behind[i]=='*'||behind[i]=='/'){
            int num1,num2;
            num1=num.top();
            num.pop();
            num2=num.top();
            num.pop();
            switch (behind[i])
            {
            case '+':
                num.push(num1+num2);
                break;
            
            case '-':
                num.push(num2-num1);
                break;
            case '*':
                num.push(num2*num1);
                break;
            case '/':
                num.push(num2/num1);
                break;
            }
            i++;
        }
        else if(behind[i]==' ')i++;
        else{
            int num0=0;
            while(behind[i]>='0' and behind[i]<='9'){
                num0=num0*10+(behind[i]-'0');
                i++;
            }
            num.push(num0);
        }
    }
    return num.top();
}

int main(){
    string s;
    while(getline(cin,s)){
        cout<<solve_behind(change_behind(s))<<endl;
    }
}