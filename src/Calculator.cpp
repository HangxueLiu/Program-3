/*��һ����
��׺���ʽת��׺���ʽ

�������Ҷ�����׺���ʽ

����ʱ�������׺���ʽ��

�������
-��Ϊ ��(������ջ
-��Ϊ ��)���������ΰ�ջ�еĵ�����������׺���ʽ�У�ֱ�����֡�(������ջ��ɾ����(��
-��Ϊ�������������������� �������ȼ����ڳ���('�����ջ�������ʱ��ֱ����ջ�������ջ����ʼ�����ε����ȵ�ǰ�������������ȼ��ߺ����ȼ���ȵ��������ֱ��һ���������ȼ��͵Ļ���������һ��������Ϊֹ��Ȼ��������ѹ��ջ�У��ȳ����룩��

��ɨ�����׺���ʽ����ʱ��ջ�еĵ������������ջ��*/

/*�ڶ���
�����׺���ʽ
����һ��ջS �������Ҷ����ʽ����������������ͽ���ѹ��ջS�У��������nԪ�����(����Ҫ��������Ϊn�������)��ȡ����ջ�����µ�n����������㣬�ٽ�����Ľ������ԭջ����n�ѹ��ջS�� �������׺���ʽδ���꣬���ظ�������̣�������ջ������ֵ��Ϊ������
����֮��

�����Ҷ����ʽ
����������ѹ��ջ��
����������ȡ������ջ��n��Ԫ�أ���nȡ���ڲ�������nԪ����������������ѹ��ջ��
��׺���ʽ���꣬��ǰջ��Ԫ�ؼ�Ϊ���
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
//ջ�е����ȼ�
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

//ת��Ϊ��׺���ʽ
string Infix2suffix(string Infix)
{
    stack<char>operate;
    string Suffix="                                                                                                  #";//��ʼ����׺���ʽ;
    char currentOp;//��ǰ������
    int negative; //�Ƿ�Ϊ����
    int i=0;//��׺��ǰָ��
    int j=0;//��׺��ǰָ��
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
                //�Ȱ���ȡ������Ȼ��ת����sin��double��Ȼ����ת����string
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
                    while(Infix[i]>=48&&Infix[i]<=57)//С������
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
        if(Infix[i]>=48 && Infix[i]<=57)//�ж��Ƿ�Ϊ����
        {
            Suffix[j++]='|';//j�Ǻ�׺���ʽ������
            Suffix[j++]=Infix[i]; //�洢��ǰ���ֲ�ָ����һ��
            while(Infix[++i]>=48&&Infix[i]<=57)//��������
            {
                Suffix[j++]=Infix[i];
            }
            if(Infix[i]=='.')//С������
            {
                Suffix[j++]='.';
                i++;//����һλ
                while(Infix[i]>=48&&Infix[i]<=57)//С������
                {
                    Suffix[j++]=Infix[i];
                    i+=1;
                }
            }
        }
            else if(Infix[i]=='(')//�������(����Ϊ���������ȼ���ߣ���˷���ջ�У�����ע�⣬�������ŷ���ջ�к������ȼ���͡�
            {
                operate.push(Infix[i++]);
            }
            else if(Infix[i]==')')//�������),��ջ�������ȡ����������ַ�����ֱ��ȡ����
            {
                if(operate.empty())//û��������
                    cout<<"���ʽ����"<<endl;
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
                            cout<<"���ʽ����"<<endl;
                            break;
                        }
                        currentOp=operate.top();
                    }
                    operate.pop();//ɾ��(
                    i++;
                }
            }
            else if(Infix[i]=='+'||Infix[i]=='-'||Infix[i]=='/'||Infix[i]=='*'||Infix[i]=='%')
            {
                //�жϸ���
                if(Infix[i]=='-')
                {
                    if(i==0)
                    {
                        negative=1;
                    }
                    else if(Infix[i-1]=='+'||Infix[i-1]=='-'||Infix[i-1]=='/'||Infix[i-1]=='*'||Infix[i-1]=='%')//���ǰ���в�������Ϊ����
                    {
                        negative=1;
                    }

                    if(negative==1)
                    {
                        Suffix[j++]='|';//����
                        Suffix[j++]='-';
                        i++;
                        if(Infix[i]>=48&&Infix[i]<=57)//�ж�����
                        {
                            Suffix[j++]=Infix[i];
                            while(Infix[++i]>=48&&Infix[i]<=57)//��������
                            {
                                Suffix[j++]=Infix[i];
                            }
                            if(Infix[i]=='.')//С������
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

                //�������һ���������+-*/��������ջ�����Ƿ����ջ֮ǰ����Ҫ���ջ��
                if(operate.empty())
                {
                    operate.push(Infix[i++]);
                }
                else
                {
                     char top = operate.top();//ջ��
                     if(Priority(top)<Priority(Infix[i])) //����ķ������ȼ�����ջ��
                     {
                         operate.push(Infix[i++]);//����ջ����ָ����һ��
                     }
                     else{//�����������ȼ��ϵͣ�����Ҫ��ջ�����������������ַ�����
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
                        operate.push(Infix[i++]);//����ջ����ָ����һ��
                     }
                }
            }

            else
            {
                //cout<<"���Ŵ���1111"<<endl;
                i++;
            }
        //˳�������ʽ�����ջ�л��в��������򵯳�������������ַ�����
    }
        while(!operate.empty())
        {
            char to = operate.top();
            Suffix[j++]='|';
            Suffix[j++]=to;
            operate.pop();
        }
        Suffix[j]='#';//������
        return Suffix;
}

//�����׺���ֵ
double CalSuffix(string suffix)
{
    double result;
    stack<double> number;
    int i=0;
    int j=0;
    int isNum=0;//�ж��Ƿ�Ϊ����
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
            //��ȡ|A|֮��Ԫ��
            for(int k=i+1;k<j;k++)
            {
                current+=suffix[k];
            }
            //�ж��Ƿ�Ϊ��ֵ
            for(int k=0; k<current.size(); k++)
            {
                if(current[k]>=48 && current[k]<=57)//����
                {
                    //strinfתdouble
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
            current="";//��յ�ǰ�ַ���;
        }
        i++;
    }
     if(number.size()!=1)
        cout<<"��������"<<endl;
    else
        return number.top();
}

//�����Ǻ��������������㻯Ϊ&�ַ�������ʶ��ͼ���
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
    //�ж��Ƿ����쳣�ַ�
    while(1)
    {
        cin>>a;
        if(a=="")
            break;
    if(a.find('&')!=-1)
    {
        cout<<"��������ַ�"<<endl;
        return 0;
    }
    a=convertString(a);
    //cout<<a<<endl;
    istringstream iss(a);
    double num;
    iss >> num;
    cout<<num;
    cout<<"��׺Ϊ��"<<Infix2suffix(a)<<endl;
    cout<<CalSuffix(Infix2suffix(a))<<endl;
    }
    return 0;
}
