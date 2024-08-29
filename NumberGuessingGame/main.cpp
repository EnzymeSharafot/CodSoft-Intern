#include<bits/stdc++.h>
using namespace std;

//Number Guessing Game

class NumberGuess{
    private:
      string user_name;
      int userturn = 0;
      bool flag = true;
      void run(){
        srand(static_cast<unsigned int>(time(0)));
        int randomNumber = rand() % 1000 + 1;
        cout << "I have generated a random number between 1 and 1000." << endl;
        int userGuess;
        cout << "Can you guess what it is?" << endl;
        while (flag) {
           cout << "Enter your guess: ";
           cin >> userGuess;
           if (!cin) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout << "Invalid input. Please enter an integer." << endl;
              continue;
            }
           if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
           } else if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
           } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
            cout<<"It Took "<<userturn<<" Turns To Guess You The Correct Number"<<endl;
            userGuess = 0;
            cout<<"Do You Want To Play Again? (y/n) : ";
            char answer; cin>>answer;
            while(answer!='y' && answer!='n'){
                cout<<"Invalid Option"<<endl;
                cout<<"Please Again Input : ";
                cin>>answer;
            }
            if(answer=='n'){flag = false;}
           }
           userturn++;
      }
      }
    public:
      NumberGuess(const string &name){user_name = name;}
      void game(){
        cout<<"Hi, "<<user_name<<endl;
        cout<<"Welcome To NumberGuess"<<endl;
        cout<<"Press 1 To Play...."<<endl;
        cout<<"Press 2 To Quit...."<<endl;
        cout<<"Enter Your Option : ";
        int option; cin>>option;
        while(option!=1 && option!=2){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>option;
        }
        if(option==1){run();}
      }
};

int main(void){
    cout<<"-+ WELCOME +-"<<endl;
    cout<<"Press 1 To Continue...."<<endl;
    cout<<"Press 2 To Quit......"<<endl;
    int option;cin>>option;
    while(option!=1 && option!=2){
        cout<<"Invalid Input"<<endl;
        cout<<"Please Try Again : ";
        cin>>option;
    }
    if(option==1){
       cout<<"Enter Your Name : ";
       string user_name;
       cin.ignore();
       getline(cin, user_name);
       cout<<"\n";
       NumberGuess n1(user_name);
       n1.game();
    }
    cout<<"Closing The Application......"<<endl;
}
