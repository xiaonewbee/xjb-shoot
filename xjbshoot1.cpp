#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct node
{
    node(int m) :num(m) {}
    int num;
} ;

// struct 
// {
//     bool operator () (const node&a, const node& b) {
//         return a.num > b.num;
//     }
// }customLess; 

// template<typename T>
// class customLess 
// {
//     public:
//     bool operator () (T a, T b) {
//         return a.num > b.num;
//     }
// }; 

// 
void test() {
    node a(1);
    node b(4);
    node c(3);
    vector<node*> vec {&a,&b,&c};
    cout << sizeof vec << ' ';

    sort(vec.begin(), vec.end(), []( node* a, node*b){
        return a->num < b->num;
    }); //主要是这里面的元素是指针存放
    for(auto  c : vec) {
        cout << (*c).num << ' ';
    }
}



int main() {
    test();
// std::string name1("Alice");
// std::string name2("Bob");
// std::format("hello, {} and {}!", name1, name2);  // hello, Alice and Bob!

    int a = 1;
    std::string b = "sdasd";
    // std::format("{} woshinide {} hehahaha", a, b)
    // std::cout<< std::format("{} woshinide {} hehahaha", a, b) << '\n';
    std::cout << __cplusplus;

}
