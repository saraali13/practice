#include <iostream>
#include <stack>
using namespace std;

string reverseString(const string& str) {
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }

    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

int main() {
    string str = "hello";
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reverseString(str) << endl;
    return 0;
}
