#include <iostream>
#include <cstring>
using namespace std;
/*
EDIT[i,j]��ʾ�����ַ���a��1��i���Ӵ����ַ���b��1��j���ִ��ı༭���롣���ַ����±��1��ʼ)

EDIT[i - 1,j] + 1��ʾ��a ��i λ��ɾ��delete����

EDIT[i,j - 1] + 1 ��ʾinsert��Ӳ���

EDIT[i-1, j - 1] + f(x[i],y[j])�������x[i] == y[j] �� f(x[i],y[j]) == 0 ���� ==1

��ʾ���������modify������

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
    int len1=word1.size();
    int len2=word2.size();
    int dp[len1+1][len2+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len1;i++)
    dp[i][0]=i;
    for(int j=1;j<=len2;j++)
    dp[0][j]=j;
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(word1[i]==word2[j])
            dp[i+1][j+1]=min(dp[i+1][j]+1,min(dp[i][j+1]+1,dp[i][j]));
            else
            {
               dp[i+1][j+1]=min(dp[i+1][j]+1,min(dp[i][j+1]+1,dp[i][j]+1));

            }
        }
    }
    return dp[len1][len2];
    }
};
int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    cout<<s.minDistance("eeba","abca");
    return 0;
}
