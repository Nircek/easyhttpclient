#include <iostream>
#include "easyhttpclient.hpp"

int main() {
    std::cout<<easyhttpclient("https://www.google.com")<<std::endl;
    return 0;
}
