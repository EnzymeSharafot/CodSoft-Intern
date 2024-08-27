#include<bits/stdc++.h>
using namespace std;

class Calculator {
private:
    double input_1, input_2;
    bool flag = true;

    int inputvalidation(int x, int y) {
        int choice;
        cout << "Enter Operation: ";
        cin >> choice;
        while (choice > y || choice < x) {
            cout << "Invalid Input!!\n";
            cout << "Enter Again: ";
            cin >> choice;
        }
        return choice;
    }

    int getChoice() {
        cout << "Following Operations:\n";
        cout << "1. Addition -- (+)\n";
        cout << "2. Subtraction -- (-)\n";
        cout << "3. Multiplication -- (x)\n";
        cout << "4. Division -- (/)\n";
        cout << "5. Exit\n";
        return inputvalidation(1, 5);
    }

    void Exit(bool &flag) {
        cout << "Do You Want To Close The Calculator? (y/n): ";
        char answer; 
        cin >> answer;
        while (answer != 'y' && answer != 'n') {
            cout << "Invalid Input!!\n";
            cout << "Please Try Again: ";
            cin >> answer;
        }
        if (answer == 'y') { flag = false; }
    }

    void showResult(double result) {
        cout << "Result: " << result << endl;
        cout << "\n";
    }

    void display(const string &task, const char &op) {
        cout << "Performing " << task << endl;
        cout << "Enter Input 1: "; 
        cin >> input_1;
        cout << "Enter Input 2: "; 
        cin >> input_2;
        switch(op) {
            case '+': showResult(input_1 + input_2); break;
            case '-': showResult(input_1- input_2); break;
            case '/':
                if (input_2 != 0) {
                    showResult(input_1 / input_2);
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            case '*': showResult(input_1 * input_2); break;
        }
    }

public:
    void run() {
        while (flag) {
            cout << " ||| CALCULATOR |||" << endl;
            int choice = getChoice();
            switch(choice) {
                case 1: display("Addition", '+'); break;
                case 2: display("Subtraction", '-'); break;
                case 3: display("Multiplication", '*'); break;
                case 4: display("Division", '/'); break;
                case 5: Exit(flag); break;
            }
        }
    }
};

bool landingPage() {
    int a;
    cout << "-+ WELCOME +-" << endl;
    cout << "Press 1 To Continue...." << endl;
    cout << "Press 2 To Quit....." << endl;
    cout << "Enter Option: ";
    cin >> a;
    while (a != 1 && a != 2) {
        cout << "!!!! Invalid Input !!!!" << endl;
        cout << "Please Enter Again: ";
        cin >> a;
    }
    return a == 1;
}

int main() {
    bool flag = landingPage();
    if (flag) {
        Calculator calculator;
        calculator.run();
    }
    cout << "Closing The Application" << endl;
    return 0;
}
