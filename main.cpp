#include <iostream>
#include <stack>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
std::vector<char>in_date;
std::stack<char>inver;
std::string search_brackets(std::string str);
void transformation(std::string str);

int main()
{
    std::string i_date;
    std::cin>>i_date;
    transformation(i_date);
    for (char n : in_date){
        std::cout<<n;
    }
    return 0;
}
void transformation(std::string str){
    for (int i=0; str[i]!='\0';i++){
        int j=i;
        if (str[i]>='0'&& str[i]<='9'){
                in_date.push_back(str[i]);
        }
        if(str[i]=='+'||str[i]=='-'){
            if((str[i]=='-' && str[i-1]=='(')||i==0){
                in_date.push_back('0');
            }
            if (inver.empty()||inver.top()=='('){
                inver.push(str[i]);
            }
            else{
                while((inver.empty()==false)&& (inver.top()!='(')){
                    in_date.push_back(inver.top());
                    inver.pop();
                }
                inver.push(str[i]);
            }

        }
        if(str[i]=='('){
            inver.push(str[i]);
        }
        if(str[i]==')'){
            while(inver.top()!='('){
                in_date.push_back(inver.top());
                inver.pop();
            }
            inver.pop();
        }
        if(str[i]=='*'||str[i]=='/'){
            if(inver.empty()||inver.top()=='-'||inver.top()=='+'||inver.top()=='('){
                inver.push(str[i]);
            }
            else{
                while((inver.empty()==false)&& ((inver.top()=='*')||(inver.top()=='/'))){
                    in_date.push_back(inver.top());
                    inver.pop();
                }
                inver.push(str[i]);
            }
        }
    }
    while (!inver.empty()){
        in_date.push_back(inver.top());
        inver.pop();
    }
}
