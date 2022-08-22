#include "cppadd.h"
#include "iostream"

int main(){

    ws::cppadd s(3.f,4.f);
    float a = 1.f;
    float b = 2.f;
    std::cout << s.sum(a,b) << std::endl;

}