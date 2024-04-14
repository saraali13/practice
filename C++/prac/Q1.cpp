#include <iostream>
#include <string>

using namespace std;

// Function to check login credentials
bool authenticate(const string& username, const string& password) {
    // Dummy username and password
    const string validUsername = "SaraZaidi";
    const string validPassword = "frg34";

    // Check if the provided username and password match the valid credentials
    return (username == validUsername && password == validPassword);
}

int main() {
    string username, password;

    // Display login prompt
    cout << "Welcome to the Login Page!" << endl;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if credentials are valid
    if (authenticate(username, password)) {
        cout << "Login successful. Welcome, " << username << "!" << endl;
    } else {
        cout << "Login failed. Invalid username or password." << endl;
    }

    return 0;
}
