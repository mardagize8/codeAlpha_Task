#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(const string &username) {
    ifstream file(username + ".txt");
    return file.good();
}

void registerUser() {
    string username, password;
    cout << "Register
Username: ";
    cin >> username;
    if (userExists(username)) {
        cout << "Error: Username already exists.\n";
        return;
    }
    cout << "Password: ";
    cin >> password;
    ofstream file(username + ".txt");
    file << username << endl << password << endl;
    file.close();
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, storedUser, storedPass;
    cout << "Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    ifstream file(username + ".txt");
    if (!file) {
        cout << "Error: User not found.\n";
        return;
    }
    getline(file, storedUser);
    getline(file, storedPass);
    file.close();
    if (username == storedUser && password == storedPass)
        cout << "Login successful!\n";
    else
        cout << "Login failed. Incorrect password.\n";
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoice: ";
    cin >> choice;
    if (choice == 1) registerUser();
    else if (choice == 2) loginUser();
    else cout << "Invalid choice.\n";
    return 0;
}
