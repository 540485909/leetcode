/*
���η���divide and conquer��

ע�⵽A[1...n]������Ӵ�A[i..j]����������������������е�һ�֣�

1 �� i �� j �� n/2��Ҳ������Ӵ�������ԭ������벿��
n/2 �� i �� j �� n��Ҳ������Ӵ�������ԭ�����Ұ벿��
1 �� i �� n/2 �� j �� n��Ҳ������Ӵ���������ԭ������벿�֣���������ԭ�����Ұ벿��
������ǿ��Էֱ��������������µĽ⣬Ȼ��������������õ�һ��ѡ����Ϊ��������Ľ⡣

���ǰ�����������ʵ���൱�ڰ�����Ĺ�ģ��С�ˣ�divide�������󳤶�Ϊn�����������Ӵ���Ϊ�󳤶���n/2�����������Ӵ��������ģ��С�˵�����Ľ�ͬ����������������������е�ǰ���������������Ȼ��ȡϸ�ֵķ��������ǣ�������ϸ�ֻ���ͷ�𣿵�Ȼ��ģ�����������ǻ�õ�һ��������Ϊ1�����飬�����ּ�������£����ǾͲ��ؿ��������������Ϊ��ʱ������Ӵ���Ȼ�����������Ϊ1���Ӵ��Լ���conquer����

����Ե�������������ǲ�ȡ��һ�ֲ��ԣ������ǽ����⻯Ϊ��ͬ�ĸ�С��ģ�����⣬����ֱ����⡣�����������A[i...n/2]ʹ��ΪA[1...n/2]������Ӵ����������һ�α������ɣ�ʱ�临�Ӷ�ΪO(n)��ͬ������Ҳ�������A[n/2...j]ʹ��ΪA[n/2...n]������Ӵ�������2������Ӵ�����һ�𣬾͵õ������л��Խ�����в����Ӵ��е�����Ӵ���

�ܽ�����������ʹ��T(n)����ʹ�ô˷�������СΪn�����������Ӵ����������ĵ�ʱ�䣬���У�

T(n) = 2T(n/2) + O(n)��n>1
T(1) = O(1)��n=1
���ѷ��֣���ʱ������������ʱ�临�Ӷ�ΪO(nlogn)��

http://blog.csdn.net/mitkook/article/details/7431951

*/

#include <iostream>

using namespace std;
class Solution {
public:
    int solve(int A[],int low,int high)
    {
        if(low==high)return A[low];
        int mid=(low+high)/2;
        int leftSum=solve(A,0,mid);
        int rightSum=solve(A,mid+1,high);
        int left=A[mid];
        int  sum=A[mid];
        for(int i=mid-1;i>=low;i--)
        {
            sum=sum+A[i];
            left=max(sum,left);
        }
        sum=A[mid];
        int right=A[mid];
        for(int i=mid+1;i<high;i++)
        {
            sum=sum+A[i];
            right=max(right,sum);
        }
        return max(max(leftSum,rightSum),left+right);

    }
    int maxSubArray(int A[], int n) {
        return solve(A,0,n-1);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
