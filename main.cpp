#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <map>

using namespace std;

int main() {
    //p1
//    map<int, int> m = {{1, 1},
//                       {2, 4},
//                       {3, 9},
//                       {4, 16},
//                       {5, 25}};
//
//    for (auto item: m) {
//        cout << "Square of " << item.first << " is " << item.second << endl;
//    }
    //p2
    map<int, std::string> m1 = {{74, "Mike"},
                                {76, "Elena"},
                                {93, "David"},
                                {70, "George"},
                                {89, "Indira"}};
    int counter = 1;
    for (auto it: m1) {
        cout << counter++ << " place is " << it.second << endl;
    }


    return 0;
}

