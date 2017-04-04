#include <iostream>
#include "wineasyhttpclient.hpp"
using namespace std;
using namespace GitHub::Nircek;
int main()
{
    cout<<wineasyhttpclient("https://github.com/Nircek/")<<'\n'<<'\n';
    return 0;
}
