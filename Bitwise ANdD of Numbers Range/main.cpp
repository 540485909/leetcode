#include <iostream>

using namespace std;
/*����Ĺؼ����ڰ��ұߵ�һһ��ȥ��һ��*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    while(m<n){
          n=n&(n-1);
      }
      return n;

    }
};
int main()
{
    Solution s;
    cout<<s.rangeBitwiseAnd(5,7);
    cout << "Hello world!" << endl;
    return 0;
}
