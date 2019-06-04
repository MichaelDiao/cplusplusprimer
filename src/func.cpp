#include<iostream>
#include<vector>

#define NBUGY 

using namespace std;

void reset(const int *beg, const int *end){
    while(beg != end)
        std::cout << *beg++ << std::endl;
}
void showVector(int &idex, const vector<int>& arr){
    if(idex < arr.size()){
        /* std::cout << "vector<" << idex << ">: " << arr[idex] << std::endl; */
        std::cout << arr[idex] << std::endl;
        showVector(++idex, arr); 
    }
    /* std::cout << "vector<" << idex << ">: " << arr[idex] << std::endl; */
}

int odd[] = {1,3,5,7,9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i){
    return (i % 2) ? &odd : &even;
}

int calc(int, int);
int calc(int*, int*);
int *reset(int* a){
    (*a)++;
    return a;
}
double* reset(double* b){
    (*b)++;
    return b;
}

void print(const int ia[], size_t size){
#ifdef NBUGY
    cerr << "Error: " << __FILE__
        << " : in function " << __func__
        << " at line " << __LINE__ << endl
        << "\tCompiled on " << __DATE__
        << " at " << __TIME__ << endl
        << "\tWord read was \"" << size << endl;
#endif
    std::cout << "print" << std::endl;
}

int add(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int multiply(int a, int b){
    return a*b;
}
int divid(int a, int b){
    return b != 0 ? a/b : 0;
}
/* typedef int func1(int a, int b); */
typedef int (*pfunc1)(int a, int  b);
typedef decltype(add) *pfunc2;
typedef decltype(add) func2;
using func3 = int(int a, int b);
using pfunc3 = int (*)(int a, int b);
using pfunc4 = decltype(add) *;
using func4 = decltype(add);

int main()
{
    /* vector<func1> f1; */
    vector<pfunc1> pf1;
    vector<func2*> f2;
    vector<pfunc2> pf2;
    vector<func3*> f3;
    vector<pfunc3> pf3;
    vector<func4*> f4;
    vector<pfunc4> pf4;

    /* vector<decltype(add)*> vec{add, sub, multiply, divid}; */
    /* vector<pfunc1> vec{add, sub, multiply, divid}; */
    /* vector<pfunc2> vec{add, sub, multiply, divid}; */
    /* vector<pfunc3> vec{add, sub, multiply, divid}; */
    /* vector<pfunc4> vec{add, sub, multiply, divid}; */
    /* vector<func2*> vec{add, sub, multiply, divid}; */
    /* vector<func3*> vec{add, sub, multiply, divid}; */
    vector<func4*> vec{add, sub, multiply, divid};
    for(auto f:vec){
        std::cout <<(int*)f << std::endl;
        std::cout << f(36, 9) << std::endl;
    }

    return 0;
}

int main1(int argc, char *argv[])
{
    std::cout << "hello" << std::endl;
    int a[5] = {2,3,4,5,6};
    vector<int> arr(a, a+5);
    int i = 7;
    int j = 3;
    double k = 5.5;
    /* showVector(i,arr); */
    int * p1 = &i;
    int *p2 = &j;
    double *p3 = &k;
    std::cout << calc(6,4) << std::endl;
    std::cout << calc(p1,p2) << std::endl;
    std::cout << *reset(p1) << std::endl;
    std::cout << *reset(p3) << std::endl;

    /* std::cout << showVector(i, arr) << std::endl; */

    return 0;
}
int calc(int a, int b){
    return a+b;
}
int calc(int* a, int* b){
    return *a-*b;
}
