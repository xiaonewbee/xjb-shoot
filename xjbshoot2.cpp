#include<iostream>
#include<thread>
using namespace std;

class Solution {
public:
    void numIslands() {
        static  int max_x = 0;
        // static const int max_y ;
        static int island = 0;
        for (int i = 0;i<10;i++){
            max_x++;
        }
        cout << max_x;
    }
};

int main() {

    Solution s;
    s.numIslands();
    s.numIslands();
    s.numIslands();
    s.numIslands();
    Solution e;
    thread t1(&Solution::numIslands, &e);
    // thread t2(&Solution::numIslands, &s);
    // t2.join();
    t1.join();
}

// output：1020304050
// 如果去掉注释 102030405060

// 2.3 静态局部变量有以下特点：
// （1）该变量在全局数据区分配内存；
// （2）静态局部变量在程序执行到该对象的声明处时被首次初始化，即以后的函数调用不再进行初始化；
// （3）静态局部变量一般在声明处初始化，如果没有显式初始化，会被程序自动初始化为 0；
// （4）它始终驻留在全局数据区，直到程序运行结束。但其作用域为局部作用域，当定义它的函数或语句块结束时，其作用域随之结束。
