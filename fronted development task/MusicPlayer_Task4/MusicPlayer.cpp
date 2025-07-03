#include <iostream>
using namespace std;

int main() {
    cout << "Music Player Simulation\n";
    cout << "------------------------\n";
    cout << "Playing: sample.mp3\n";
    cout << "[P]lay | [S]top | [N]ext | [Q]uit\n";

    char command;
    while (true) {
        cout << "Command: ";
        cin >> command;

        if (command == 'Q' || command == 'q') break;
        else if (command == 'P' || command == 'p') cout << "Playing music...\n";
        else if (command == 'S' || command == 's') cout << "Stopped.\n";
        else if (command == 'N' || command == 'n') cout << "Next track...\n";
        else cout << "Unknown command.\n";
    }

    return 0;
}