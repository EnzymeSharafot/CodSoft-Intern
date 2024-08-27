#include<bits/stdc++.h>
using namespace std;

class TickTackToe{
    private:
       char sign_1,sign_2;
       int player_1, player_2;
       vector<vector<char>>grid = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
       void drawboard(vector<vector<char>>&grid){
        for(int i=0;i<3;i++){
            cout<<"----"<<"----"<<"-----"<<endl;
            cout<<"| "<<grid[i][0]<<" | "<<grid[i][1]<<" | "<<grid[i][2]<<" | "<<endl;
            cout<<"----"<<"----"<<"-----"<<endl;
        }
       }

       bool checkresult(vector<vector<char>>&grid){
          //First We Check The Rows
          for(int i=0;i<3;i++){
            if((grid[i][1]==grid[i][0])&&(grid[i][1]==grid[i][2])&&(grid[i][0]==grid[i][2])&&(grid[i][1]!=' '&&grid[i][0]!=' '&&grid[i][2]!=' ')){
                return true;
            }
          }
          //Second We Check The Columns
          for(int i=0;i<3;i++){
            if((grid[1][i]==grid[0][i])&&(grid[1][i]==grid[2][i])&&(grid[0][i]==grid[2][i])&&(grid[1][i]!=' '&&grid[0][i]!=' '&&grid[2][i]!=' ')){
                return true;
            }
          }
          //Checking The Diagonals
          if(((grid[2][0]==grid[1][1])&&(grid[2][0]==grid[0][2])&&(grid[0][2]==grid[1][1])&&(grid[1][1]!=' '&&grid[2][0]!=' '&&grid[0][2]!=' '))||((grid[0][0]==grid[1][1])&&(grid[1][1]==grid[2][2])&&(grid[0][0]==grid[2][2])&&(grid[0][0]!=' '&&grid[2][2]!=' '&&grid[1][1]!=' '))){
            return true;
          }
          return false;
       }
    
    public:
       TickTackToe(int x, char a, int y, char b){
        player_1 = x;
        sign_1 = a;
        player_2 = y;
        sign_2 = b;
       }
       void run(){
        int count = 0;
            while(count<9){
                drawboard(grid);
               if(player_1==1){
                   cout<<"Enter Row and Column To Put "<<sign_1<<" For Player_1 "<<endl;
                   int a,b;
                   cout<<"Between 0 to 2 !!!";
                   cout<<"Enter Row : ";cin>>a;
                   cout<<"Enter Column : ";cin>>b;
                   while((a<0||a>2)||(b<0||b>2)||grid[a][b]!=' '){
                    cout<<"!!!! Invalid Input !!!!"<<endl;;
                    cout<<"Try Again...";
                    cout<<"Enter Row : ";cin>>a;
                    cout<<"Enter Column : ";cin>>b;
                   }
                   grid[a][b] = sign_1;
                   if(checkresult(grid)){
                    cout<<"!!!!!Hurray!!!!!\n";
                    cout<<"Player 1 Has Won The Game!!!\n\n\n";
                    break;
                   }
                   player_2 = 1;
                   player_1 = 2;
               }
               else{
                   cout<<"Enter Row and Column To Put "<<sign_2<<" For Player_2 "<<endl;
                   int a,b;
                   cout<<"Between 0 to 2 !!!";
                   cout<<"Enter Row : ";cin>>a;
                   cout<<"Enter Column : ";cin>>b;
                   while((a<0||a>2)||(b<0||b>2)||grid[a][b]!=' '){
                    cout<<"!!!! Invalid Input !!!!"<<endl;;
                    cout<<"Try Again...";
                    cout<<"Enter Row : ";cin>>a;
                    cout<<"Enter Column : ";cin>>b;
                   }
                   grid[a][b] = sign_2;
                   if(checkresult(grid)){
                    cout<<"!!!!!Hurray!!!!!\n";
                    cout<<"Player 2 Has Won The Game!!!\n\n\n";
                    break;
                   }
                   player_1 = 1;
                   player_2 = 2;
               }
               count++;
            }
            if(count==9){
                cout<<"The Game Is a DRAW!!!!!!!!!!\n\n\n";
            }
       }

};


bool homepage(){
    char flag;
    cout<<setw(10)<<"TICK || TACK || TOE\n";
    cout<<"\n";
    cout<<setw(11)<<"Press '1' For Next.."<<endl;
    cout<<setw(11)<<"Press '2' For Quit.."<<endl;
    cout<<"\nEnter Your Opinon : ";
    cin>>flag;
    while(flag!='1'&&flag!='2'){
        cout<<"Invalid Input!!! Please Try Again\n";
        cout<<"\n";
        cout<<"Enter Option : ";
        cin>>flag;
    }
    if(flag=='1'){return true;}
    return false;
}

void newpage(int &player_1, int &player_2){
    cout<<setw(10)<<"! NEW GAME !"<<endl;
    cout<<endl;
    cout<<"Who Wil Move First ?"<<endl;
    cout<<"Enter '1' For Player_1"<<endl;
    cout<<"Enter '2' For Player_2"<<endl;
    cout<<"Enter '3' For Random Selection"<<endl;
    cout<<"\n";
    cout<<"Enter Your Choice : ";
    int choice; cin>>choice;
    cout<<endl;
    while(choice!=1&&choice!=2&&choice!=3){
        cout<<"Invalid Input!!! Please Try Again\n";
        cout<<"\n";
        cout<<"Enter Option : ";
        cin>>choice;
    }
    if(choice==1){
        player_1 = 1;
        player_2 = 2;
    }
    else if(choice==2){
        player_2 = 1;
        player_1 = 2;
    }
    else{
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(1,2);
        player_1 = dis(gen);
        player_2 = (player_1==2)? 2 : 1;
    }
}

void signselection(char &sign_1, char &sign_2){
    cout<<setw(10)<<"! Sign Selection !"<<endl;
    cout<<endl;
    cout<<"Who Wil Select Sign First ?"<<endl;
    cout<<"Enter '1' For Player_1"<<endl;
    cout<<"Enter '2' For Player_1"<<endl;
    cout<<"Enter '3' For Random Selection"<<endl;
    cout<<"\n";
    cout<<"Enter Your Choice : ";
    int choice; cin>>choice;
    while(choice!=1&&choice!=2&&choice!=3){
        cout<<"Invalid Input!!! Please Try Again\n";
        cout<<"\n";
        cout<<"Enter Option : ";
        cin>>choice;
    }
    if(choice==1 || choice ==2){
        cout<<"Chose Between 'X' and 'O'!!!!!!!"<<endl;
        if(choice==1){
            cout<<"Player 1 Enter Your Mark : ";cin>>sign_1;
            sign_2 = (sign_1=='X')? 'O' : 'X';
        }
        else{
            cout<<"Player 2 Enter Your Mark : ";cin>>sign_2;
            sign_1 = (sign_2=='X')? 'O' : 'X';
        }
    }
    else{
        char choices[] = {'X', 'O'};
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0,1);
        sign_1 = choices[dis(gen)];
        sign_2 = (sign_1 == 'X')? 'O' : 'X';
        cout<<"Player 1 Will Be PLaying As : "<<sign_1<<endl;
        cout<<"Player 2 Will Be PLaying As : "<<sign_2<<endl;
    }
}

int main(){
    bool flag = homepage();
    if(flag){
        while(true){
        cout<<"\n";cout<<"\n";cout<<"\n";
        int player_1, player_2;
        newpage(player_1, player_2);
        if(player_1==1){
            cout<<"Player 1 Will Gonna Move First!!!!";
        }
        else{
            cout<<"Player 2 Will Gonna Move First!!!!";
        }
        cout<<"\n";cout<<"\n";cout<<"\n";
        char sign_1, sign_2;
        signselection(sign_1, sign_2);
        cout<<"\n";cout<<"\n";cout<<"\n";
        TickTackToe ttt(player_1, sign_1, player_2, sign_2);
        ttt.run();
        cout<<"\n";cout<<"\n";cout<<"\n";
        cout<<"Do You Want To Replay The Game?(y/n) : ";
        char x;cin>>x;
        while(x!='y'&&x!='n'){
            cout<<"!!! Invalid Input !!!\n";
            cout<<"Please Enter Again : ";cin>>x;
        }
        if(x=='n'){
            cout<<"Thanks For Playing.........."<<endl;
            cout<<"\n";
            cout<<"Ending The Game....."<<endl;
        }
      } 
    }
    else{
        cout<<"Ending The Game....."<<endl;
    }
    return 0;
}
