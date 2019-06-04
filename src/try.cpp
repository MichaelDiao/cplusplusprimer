#include<iostream>
#include <stdexcept>
#include "Sales_item.h"

using namespace std;


int main(int argc, char *argv[])
{
    Sales_item item1, item2;
    int a, b;
    std::cout << "end" << std::endl;

    while(cin >> a >> b){
        std::cout << "start" << std::endl;
        try{
            if(b == 0)
                throw runtime_error("b is 0 error");
            std::cout << "result: " << a / (double)b << std::endl;
        } catch (runtime_error err){
            cout << err.what()
                << "\nTry again? Enter y or n " << endl;
            char c;
            cin >> c;
            if(! cin || c == 'n')
                break;
        }
        std::cout << "here" << std::endl;
    }

    return 0;
}
