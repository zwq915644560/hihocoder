#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a,b;
    vector<int> vi;
    while(cin>>a>>b)
    {
        vi.push_back(a+b);
    }
    for(auto c: vi)
    {
        cout<<c<<endl;
    }
    return 0;
}
