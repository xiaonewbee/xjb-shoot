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
