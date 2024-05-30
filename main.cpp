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
//    map<int, string> m1 = {{74, "Mike"},
//                           {76, "Elena"},
//                           {93, "David"},
//                           {70, "George"},
//                           {89, "Indira"}};
//    int counter = 1;
//    for (auto it = m1.rbegin(); it != m1.rend(); ++it) {
//        cout << counter++ << " place is " << it->second << endl;
//    }
//p3
//    map<char, int> alpha;
//    for (char letter = 'A'; letter <= 'Z'; ++letter) {
//        alpha[letter] = letter - 'A' + 1;
//    }
//    char ch;
//    cin >> ch;
//    ch = toupper(ch);
//    if (alpha.find(ch) != alpha.end()) {
//        cout << "Position of " << ch << " is " << alpha[ch] << endl;
//    } else {
//        cout << "Invalid input. Please enter a valid uppercase letter." << endl;
//    }
//p4
    map<int, double> m2 = {
            {4, 7.5}, {25, 6.01}, {-9, 3.2}, {12, 5.16}
    };

    // 2. Output each pair of the map
    cout << "Map contents:" << endl;
    for (auto item : m2) {
        cout << item.first << " , " << item.second << endl;
    }

    // 3. Insert a new pair (3, 3.75) and display resulting map
    m2.insert(make_pair(3, 3.75));
    cout << "\nMap after inserting (3, 3.75):" << endl;
    for (auto item : m2) {
        cout << item.first << " , " << item.second << endl;
    }

    // 4. Insert a new pair (-10, 4.3) and display resulting map
    m2.insert(make_pair(-10, 4.3));
    cout << "\nMap after inserting (-10, 4.3):" << endl;
    for (auto item : m2) {
        cout << item.first << " , " << item.second << endl;
    }

    // 5. Using method .find(), find key 12, store result inside iterator it and print the value
    auto it = m2.find(12);
    if (it != m2.end()) {
        cout << "\nValue corresponding to key 12: " << it->second << endl;
    } else {
        cout << "\nKey 12 not found in the map." << endl;
    }

    // 6. Using the same iterator, delete pair with key 12 and print resulting map
    if (it != m2.end()) {
        m2.erase(it);
        cout << "\nMap after deleting pair with key 12:" << endl;
        for (auto item : m2) {
            cout << item.first << " , " << item.second << endl;
        }
    }

    // 7. Modify a value whose key is -9 to 4.44 and print resulting map
    m2[-9] = 4.44;
    cout << "\nMap after modifying value with key -9:" << endl;
    for (auto item : m2) {
        cout << item.first << " , " << item.second << endl;
    }



    return 0;
}

