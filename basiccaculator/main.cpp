/*all right preserved by duanchong
�Ӻ�������Գ������stack������
bug: 123 �Ӻ����ȡ�� Ӧ�� ����fold ������sum=sum*10+varible;
fold=fold*10 Ӧ�ý�������ǰ�� ��Ȼfold=1 ���û���Ч
�Ӽ���ֿ����ǻ��൱�򵥺ܶ࣬����һ���� ���Ӹ�����

*/


#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:

    int cal(int num1,int num2,char oper){
        if(oper=='+')
        return num1+num2;
        else if(oper=='-')
            return num1-num2;
        else return 0;
    }
    int calculate(string s) {
        stack<int> stknum;
        stack<char> stkoper;
        int len=s.size();
        int number=0,fold=1;

        for(int i=len-1;i>=0;i--)
        {
            if(s[i]==' ')continue;
            if(s[i]-'0'>=0&&s[i]-'0'<=9){
                number=number+(s[i]-'0')*fold;
                  fold=fold*10;
                if(i==0||s[i-1]-'0'<0||s[i-1]-'0'>9){
                   stknum.push(number);
                   number=0;
                   fold=1;

                }

            }
            else if(s[i]=='+'||s[i]=='-'){
               stkoper.push(s[i]);
            }

            else if(s[i]==')'){
                stkoper.push(s[i]);
            }
            else{
                while(true){
                     char oper=stkoper.top();stkoper.pop();
                     if(oper==')'){
                         break;
                     }
                     int num1=stknum.top();stknum.pop();
                     int num2=stknum.top();stknum.pop();
                     stknum.push(cal(num1,num2,oper));
                }


            }

        }
        while(!stkoper.empty()){
            char oper=stkoper.top();stkoper.pop();
            int num1=stknum.top();stknum.pop();
            int num2=stknum.top();stknum.pop();
            stknum.push(cal(num1,num2,oper));
        }
        return stknum.top();

    }

};



int main()
{
    Solution s;
    cout<<s.calculate("(1+(4+5+2)-3)+(6+8)");
    return 0;
}
