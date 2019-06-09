/*第一步：
中缀表达式转后缀表达式

自左向右读入中缀表达式

数字时，加入后缀表达式；

运算符：
-若为 ‘(’，入栈
-若为 ‘)’，则依次把栈中的的运算符加入后缀表达式中，直到出现’(’，从栈中删除’(’
-若为除括号外的其他运算符， 当其优先级高于除’('以外的栈顶运算符时，直接入栈。否则从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符，直到一个比它优先级低的或者遇到了一个左括号为止，然后将其自身压入栈中（先出后入）。

当扫描的中缀表达式结束时，栈中的的所有运算符出栈；*/

/*第二步
计算后缀表达式
建立一个栈S 。从左到右读表达式，如果读到操作数就将它压入栈S中，如果读到n元运算符(即需要参数个数为n的运算符)则取出由栈顶向下的n项按操作数运算，再将运算的结果代替原栈顶的n项，压入栈S中 。如果后缀表达式未读完，则重复上面过程，最后输出栈顶的数值则为结束。
简言之：

从左到右读表达式
遇到操作数压入栈中
遇到操作符取并弹出栈顶n个元素，（n取决于操作符是n元操作符），计算结果压入栈中
后缀表达式读完，当前栈顶元素及为结果
*/

#include<iostream>
#include<stack>
#include<sstream>
#include<stdlib.h>
#include<cstdio>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;
double CalSuffix(string suffix);

string double2string(double do_b)
{
    string str1;
    stringstream ss;
    ss<<do_b;
    ss>>str1;
    return str1;
}
//栈中的优先级
int Priority(char operate)
{
    switch(operate)
    {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

//转换为后缀表达式
string Infix2suffix(string Infix)
{
    stack<char>operate;
    string Suffix="                                                                                                  #";//初始化后缀表达式;
    char currentOp;//当前操作符
    int negative; //是否为负数
    int i=0;//中缀当前指向
    int j=0;//后缀当前指向
    while(Infix[i]!='\0')
    {
        if(i+1!='\0')
        {
            negative=0;
        }
        if(Infix[i]=='&')
        {
            i++;
            string number="                                                                                                        ";
            int location=0;
            if(Infix[i]=='1')
            {
                number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=sin(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;
            }else if(Infix[i]=='2')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=cos(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;
            }else if(Infix[i]=='3')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=tan(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;
            }else if(Infix[i]=='4')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=log(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;

            }else if(Infix[i]=='5')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=log10(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;

            }else if(Infix[i]=='6')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=sqrt(temp);

                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;

            }else if(Infix[i]=='7')
            {
                  number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                double sum=1;
                while(temp>=1)
                {
                    sum=sum*temp;
                    temp--;
                }
                string t=double2string(sum);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;
            }else if(Infix[i]=='8')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=asin(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;
            }else if(Infix[i]=='9')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=acos(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;
            }else if(Infix[i]=='0')
            {
                 number[location++]='|';
                //先把数取出来，然后转换成sin的double，然后再转换成string
                while(Infix[++i]>=48&&Infix[i]<=57)
                {
                    number[location++]=Infix[i];
                    //cout<<i<<endl;
                    //cout<<"location "<<number[location-1]<<endl;
                    //temp=
                }
                if(Infix[i]=='.')
                {
                    number[location++]='.';
                    i++;
                    while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                    {
                        number[location++]=Infix[i];
                        i++;
                    }
                }
                number[location++]='#';
                //cout<<"number "<<number<<endl;
                double temp;
                temp=CalSuffix(number);
                //cout<<"temp="<<temp<<endl;
                temp=atan(temp);
                string t=double2string(temp);
                Suffix[j]='|';
                j++;
                for(int p=0;p<t.length();p++)
                {
                    Suffix[j++]=t[p];
                }
                //cout<<"  "<<Suffix<<endl;
            }
        }
        //cout<<Infix.length()<<"         "<<i<<"Infix[i] "<<Infix[i]<<endl;
        if(Infix.length()==i)
        {
             //cout<<"break"<<endl;
             break;
        }
       // cout<<"aaaaaaaaaaaaaaaaaaa"<<endl;
        if(Infix[i]>=48 && Infix[i]<=57)//判断是否为数字
        {
            Suffix[j++]='|';//j是后缀表达式的索引
            Suffix[j++]=Infix[i]; //存储当前数字并指向下一个
            while(Infix[++i]>=48&&Infix[i]<=57)//整数部分
            {
                Suffix[j++]=Infix[i];
            }
            if(Infix[i]=='.')//小数部分
            {
                Suffix[j++]='.';
                i++;//后移一位
                while(Infix[i]>=48&&Infix[i]<=57)//小数部分
                {
                    Suffix[j++]=Infix[i];
                    i+=1;
                }
            }
        }
            else if(Infix[i]=='(')//如果读入(，因为左括号优先级最高，因此放入栈中，但是注意，当左括号放入栈中后，则优先级最低。
            {
                operate.push(Infix[i++]);
            }
            else if(Infix[i]==')')//如果读入),则将栈中运算符取出放入输出字符串，直到取出（
            {
                if(operate.empty())//没有左括号
                    cout<<"表达式错误"<<endl;
                else
                {
                    currentOp=operate.top();
                    while(currentOp!='(')
                    {
                        Suffix[j++]='|';
                        Suffix[j++]=currentOp;
                        operate.pop();
                        if(operate.empty())
                        {
                            cout<<"表达式错误"<<endl;
                            break;
                        }
                        currentOp=operate.top();
                    }
                    operate.pop();//删除(
                    i++;
                }
            }
            else if(Infix[i]=='+'||Infix[i]=='-'||Infix[i]=='/'||Infix[i]=='*'||Infix[i]=='%')
            {
                //判断负数
                if(Infix[i]=='-')
                {
                    if(i==0)
                    {
                        negative=1;
                    }
                    else if(Infix[i-1]=='+'||Infix[i-1]=='-'||Infix[i-1]=='/'||Infix[i-1]=='*'||Infix[i-1]=='%')//如果前面有操作符则为负号
                    {
                        negative=1;
                    }

                    if(negative==1)
                    {
                        Suffix[j++]='|';//负号
                        Suffix[j++]='-';
                        i++;
                        if(Infix[i]>=48&&Infix[i]<=57)//判断数字
                        {
                            Suffix[j++]=Infix[i];
                            while(Infix[++i]>=48&&Infix[i]<=57)//整数部分
                            {
                                Suffix[j++]=Infix[i];
                            }
                            if(Infix[i]=='.')//小数部分
                            {
                                Suffix[j++]='.';
                                i++;
                                while(Infix[i]>=48&&Infix[i]<=57)
                                {
                                    Suffix[j++]=Infix[i];
                                    i++;
                                }
                            }
                        }
                        continue;
                    }
                }

                //如果读入一般运算符如+-*/，则放入堆栈，但是放入堆栈之前必须要检查栈顶
                if(operate.empty())
                {
                    operate.push(Infix[i++]);
                }
                else
                {
                     char top = operate.top();//栈顶
                     if(Priority(top)<Priority(Infix[i])) //放入的符号优先级低于栈顶
                     {
                         operate.push(Infix[i++]);//放入栈顶并指向下一个
                     }
                     else{//如果放入的优先级较低，则需要将栈顶的运算符放入输出字符串。
                        while(Priority(top)>=Priority(Infix[i]))
                        {
                            Suffix[j++]='|';
                            Suffix[j++]=top;
                            operate.pop();
                            if(!operate.empty())
                            {
                                top=operate.top();
                            }
                            else
                                break;
                        }
                        operate.push(Infix[i++]);//放入栈顶并指向下一个
                     }
                }
            }

            else
            {
                //cout<<"符号错误1111"<<endl;
                i++;
            }
        //顺序读完表达式，如果栈中还有操作符，则弹出，并放入输出字符串。
    }
        while(!operate.empty())
        {
            char to = operate.top();
            Suffix[j++]='|';
            Suffix[j++]=to;
            operate.pop();
        }
        Suffix[j]='#';//结束符
        return Suffix;
}

//计算后缀码的值
double CalSuffix(string suffix)
{
    double result;
    stack<double> number;
    int i=0;
    int j=0;
    int isNum=0;//判断是否为数字
    string current;
    while(suffix[i]!='#')
    {
        isNum=0;
        if(suffix[i]=='|')
        {
            for(j=i+1;;j++)
            {
                if(suffix[j]=='|')
                    break;
                if(suffix[j]=='#')
                    break;
            }
            //获取|A|之间元素
            for(int k=i+1;k<j;k++)
            {
                current+=suffix[k];
            }
            //判断是否为数值
            for(int k=0; k<current.size(); k++)
            {
                if(current[k]>=48 && current[k]<=57)//数字
                {
                    //strinf转double
                    istringstream iss(current);
                    double num;
                    iss >> num;
                    number.push(num);
                    isNum = 1;
                    break;
                }
            }
            if(isNum!=1){
                double n2 = number.top();
                number.pop();
                double n1 = number.top();
                number.pop();
                if(current=="+"){
                    number.push(n1+n2);
                }
                else if(current=="-"){
                    number.push(n1-n2);
                }
                else if(current=="*"){
                    number.push(n1*n2);
                }
                else if(current=="/"){
                    number.push(n1/n2);
                }
                else if(current=="%"){
                    number.push((int)n1%(int)n2);
                }
            }
            current="";//清空当前字符串;
        }
        i++;
    }
     if(number.size()!=1)
        cout<<"输入有误"<<endl;
    else
        return number.top();
}

//将三角函数名等特殊运算化为&字符，便于识别和计算
string convertString(string s)
{
    int location=0;
    while((location=s.find("asin"))!=-1)
    {
        s.replace(location,4,"&8");
    }
    while((location=s.find("acos"))!=-1)
    {
        s.replace(location,4,"&9");
    }
    while((location=s.find("atan"))!=-1)
    {
        s.replace(location,4,"&0");
    }
    while((location=s.find("sin"))!=-1)
    {
        s.replace(location,3,"&1");
    }
    while((location=s.find("cos"))!=-1)
    {
        s.replace(location,3,"&2");
    }
    while((location=s.find("tan"))!=-1)
    {
        s.replace(location,3,"&3");
    }
    while((location=s.find("ln"))!=-1)
    {
        s.replace(location,2,"&4");
    }
    while((location=s.find("lg"))!=-1)
    {
        s.replace(location,2,"&5");
    }
    while((location=s.find("sqrt"))!=-1)
    {
        s.replace(location,4,"&6");
    }
    while((location=s.find("!"))!=-1)
    {
        s.replace(location,1,"&7");
    }
    while((location=s.find("10^2"))!=-1)
    {
        s.replace(location,4,"100");
    }
    while((location=s.find("10^3"))!=-1)
    {
        s.replace(location,4,"1000");
    }
    while((location=s.find("10^4"))!=-1)
    {
        s.replace(location,4,"10000");
    }
    while((location=s.find("10^5"))!=-1)
    {
        s.replace(location,4,"100000");
    }
    return s;
}
int main()
{
    string a;
    //判断是否有异常字符
    while(1)
    {
        cin>>a;
        if(a=="")
            break;
    if(a.find('&')!=-1)
    {
        cout<<"输入错误字符"<<endl;
        return 0;
    }
    a=convertString(a);
    //cout<<a<<endl;
    istringstream iss(a);
    double num;
    iss >> num;
    cout<<num;
    cout<<"后缀为："<<Infix2suffix(a)<<endl;
    cout<<CalSuffix(Infix2suffix(a))<<endl;
    }
    return 0;
}
