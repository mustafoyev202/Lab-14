#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <string>
#include <set>
#include <unordered_set>
#include <random>
#include <queue>
#include <stack>

using namespace std;

void outputMap(const map<int, double> &myMap) {
    for (const auto &pair: myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void displayPairs(const unordered_map<string, int> &myMap) {
    cout << "Pairs in the map:\n";
    for (const auto &pair: myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void show(const set<int> &s) {
    cout << "Elements in sorted order:";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}

void show(const unordered_set<int> &s) {
    cout << "Elements:";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}

void show(const multiset<int> &s) {
    cout << "Elements:";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}

bool isSymmetric(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return false;
    // Sort the numbers
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    // Check if the sequence is symmetric
    for (int i = 0; i < n; ++i) {
        if (sorted_nums[i] % 10 != sorted_nums[n - 1 - i] % 10) {
            return false;
        }
    }
    return true;
}

void displayQueue(queue<int> q) {
    cout << "Elements in the queue:";
    while (!q.empty()) {
        cout << " " << q.front();
        q.pop();
    }
    cout << endl;
}

void clearQueue(queue<int> &q) {
    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    std::cout << "Problem_1" << std::endl;
    std::map<int, int> m;
    // Insert key-value pairs
    m.insert({1, 1});
    m.insert({2, 4});
    m.insert({3, 9});
    m.insert({4, 16});
    m.insert({5, 25});
    // Print the contents of the map
    std::cout << "Contents of the map:" << std::endl;
    for (const auto &pair: m) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    std::cout << "Problem_2" << std::endl;
    map<int, string> competitionResults;
    vector<pair < int, string>>
    students = {{74, "Mike"},
                {76, "Elena"},
                {93, "David"},
                {70, "George"},
                {89, "Indira"}};
    // Sort students based on their grades
    sort(students.begin(), students.end(), greater<pair < int, string>>
    ());
    // Store students' places and names in the map
    for (size_t i = 0; i < students.size(); ++i) {
        competitionResults[i + 1] = students[i].second;
    }
    // Output the results
    for (const auto &result: competitionResults) {
        cout << result.first << " place is " << result.second << ".\n";
    }

    std::cout << "Problem_3" << std::endl;
    // Create a map to store uppercase letters and their positions
    map<char, int> alphabetPositions;
    // Populate the map
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        alphabetPositions[letter] = letter - 'A' + 1;
    }
    // Prompt the user to input a letter
    cout << "Enter an uppercase letter: ";
    char inputLetter;
    cin >> inputLetter;
    // Convert the input letter to uppercase if it's lowercase
    inputLetter = toupper(inputLetter);
    // Check if the input letter exists in the map
    if (alphabetPositions.find(inputLetter) != alphabetPositions.end()) {
        // Print the position of the input letter
        cout << "Position of " << inputLetter << " is " << alphabetPositions[inputLetter] << endl;
    } else {
        cout << "Invalid input. Please enter an uppercase letter." << endl;
    }

    std::cout << "Problem_4" << std::endl;
    // 1. Create a map with the given pairs
    map<int, double> myMap = {{4,  7.5},
                              {25, 6.01},
                              {-9, 3.2},
                              {12, 5.16}};
    // 2. Output each pair of the map
    cout << "Original map:\n";
    outputMap(myMap);
    // 3. Insert a new pair (3, 3.75) and display resulting map
    myMap.insert(make_pair(3, 3.75));
    cout << "\nMap after inserting (3, 3.75):\n";
    outputMap(myMap);
    // 4. Insert a new pair (-10, 4.3) and display resulting map
    myMap.insert(make_pair(-10, 4.3));
    cout << "\nMap after inserting (-10, 4.3):\n";
    outputMap(myMap);
    // 5. Using method .find(), find key 12, store result inside iterator it and print the value
    auto it = myMap.find(12);
    if (it != myMap.end()) {
        cout << "\nThe value corresponding to key 12 is: " << it->second << endl;
    } else {
        cout << "\nKey 12 not found in the map.\n";
    }
    // 6. Using the same iterator, delete pair with key 12 and print resulting map
    if (it != myMap.end()) {
        myMap.erase(it);
        cout << "\nMap after deleting pair with key 12:\n";
        outputMap(myMap);
    }
    // 7. Modify a value whose key is -9 to 4.44 and print resulting map
    it = myMap.find(-9);
    if (it != myMap.end()) {
        it->second = 4.44;
        cout << "\nMap after modifying value with key -9 to 4.44:\n";
        outputMap(myMap);
    }

    std::cout << "Problem_5" << std::endl;
    // 1. Create an unordered map with the given pairs
    unordered_map<string, int> myMap1 = {{"Earth",   3},
                                         {"Mercury", 1},
                                         {"Venus",   2}};
    // 2. Display all pairs of the map
    displayPairs(myMap1);
    // 3. Insert a pair ("Mars", 4) into the beginning and display the result
    myMap1.insert(myMap1.begin(), make_pair("Mars", 4));
    cout << "\nMap after inserting ('Mars', 4) into the beginning:\n";
    displayPairs(myMap1);
    // 4. Insert a pair ("Saturn", 6) into position 3 and then insert ("Neptune", 8) into the same position. Display the result.
    auto it1 = myMap1.begin();
    advance(it1, 2); // Move iterator to position 3
    myMap1.emplace_hint(it1, "Saturn", 6);
    myMap1.emplace_hint(it1, "Neptune", 8);
    cout << "\nMap after inserting ('Saturn', 6) and ('Neptune', 8) into position 3:\n";
    displayPairs(myMap1);
    // 5. Display the size of the map
    cout << "\nSize of the map: " << myMap1.size() << endl;
    // 6. Delete an element with key "Venus" and display resulting map
    myMap1.erase("Venus");
    cout << "\nMap after deleting element with key 'Venus':\n";
    displayPairs(myMap1);

    std::cout << "Problem_6" << std::endl;
    // 1. Create a multimap with the given pairs
    multimap<int, int> myMultiMap = {{100, 3},
                                     {150, 4},
                                     {100, 90}};
    // 2. Using method .count(), print how many keys are equal to 100
    cout << "Number of keys equal to 100: " << myMultiMap.count(100) << endl;
    // 3. Insert the following pairs
    myMultiMap.insert({200, 32});
    myMultiMap.insert({100, -12});
    myMultiMap.insert({90, 45});
    // 4. Find the upper bound of key 100 and store result inside iterator variable
    auto it2 = myMultiMap.upper_bound(100);
    // 5. Using iterator variable it, insert a new pair {60, 45} and print resulting multimap
    myMultiMap.insert(it2, {60, 45});
    cout << "\nMultimap after inserting {60, 45}:\n";
    for (const auto &pair: myMultiMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    std::cout << "Problem_7" << std::endl;
    // a) Creating a set s1 and an unordered set s2, both contain integers
    set<int> s1 = {1, 2, 3, 4, 5};
    unordered_set<int> s2 = {5, 4, 3, 2, 1};

    // b) Display the elements of s1 and s2
    cout << "Set s1 elements in sorted order:" << endl;
    show(s1);
    cout << "Unordered set s2 elements:" << endl;
    show(s2);

    // c) Insert 0 into both sets and display them again
    s1.insert(0);
    s2.insert(0);
    cout << "Set s1 elements after inserting 0:" << endl;
    show(s1);
    cout << "Unordered set s2 elements after inserting 0:" << endl;
    show(s2);

    // d) Check if s2 contains element 2
    if (s2.find(2) != s2.end()) {
        cout << "s2 contains element 2." << endl;
    } else {
        cout << "s2 does not contain element 2." << endl;
    }

    // e) Remove element 4 from s1 and display the result
    s1.erase(4);
    cout << "Set s1 elements after removing 4:" << endl;
    show(s1);

    std::cout << "Problem_8" << std::endl;
    // a) Create a multiset s containing {2, 4, 2, 5, 3, 4, 2}
    multiset<int> s = {2, 4, 2, 5, 3, 4, 2};

    // b) Display the elements of the multiset
    cout << "Multiset s elements:" << endl;
    show(s);

    // c) Find how many times element 2 occurs in the multiset
    cout << "Element 2 occurs " << s.count(2) << " times in the multiset." << endl;

    // d) Insert 3 and 4 into the multiset and display the result
    s.insert(3);
    s.insert(4);
    cout << "Multiset s elements after inserting 3 and 4:" << endl;
    show(s);

    // e) Check if multiset contains element 5
    if (s.find(5) != s.end()) {
        cout << "Multiset contains element 5." << endl;
    } else {
        cout << "Multiset does not contain element 5." << endl;
    }

    std::cout << "Problem_9" << std::endl;
    // 1. Create a vector of random integers
    vector<int> nums(10);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (auto &num: nums) {
        num = dis(gen);
    }
    // 2. Print the vector
    cout << "Original vector:" << endl;
    for (const auto &num: nums) {
        cout << num << " ";
    }
    cout << endl;
    // 3. Sort the vector in ascending order
    sort(nums.begin(), nums.end());
    // 4. Print the sorted vector
    cout << "Sorted vector:" << endl;
    for (const auto &num: nums) {
        cout << num << " ";
    }
    cout << endl;
    // 5. Check if the sequence is symmetric
    if (isSymmetric(nums)) {
        cout << "The sequence is symmetric." << endl;
    } else {
        cout << "The sequence is not symmetric." << endl;
    }

    std::cout << "Problem_10" << std::endl;
    // 1. Create a queue of integers
    queue<int> q;
    // 2. Insert 5 random numbers into the queue
    for (int i = 0; i < 5; ++i) {
        q.push(dis(gen));
    }
    // 3. Display the contents of the queue
    displayQueue(q);
    // 4. Clear the queue
    clearQueue(q);
    // 5. Display the queue again to confirm it's empty
    cout << "Queue after clearing:";
    displayQueue(q);

    std::cout << "Problem_11" << std::endl;
    // a) Create a stack of integers and push the numbers 10, 20, 30, 40, and 50 onto the stack
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // b) Display the elements of the stack
    cout << "Elements of the stack:" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    // c) Push the numbers 60, 70, and 80 onto the stack and display the result
    st.push(60);
    st.push(70);
    st.push(80);
    cout << "Elements of the stack after pushing 60, 70, and 80:" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
