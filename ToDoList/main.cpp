#include <bits/stdc++.h>
using namespace std;
// ToDoList
class ToDoList
{
private:
    string user_name;
    vector<tuple<int, pair<string, string>, bool>> task_list;
    int input_validation(int a, int b)
    {
        int option;
        cout << "Enter Your Option: ";
        while (true)
        {
            if (cin >> option)
            { // Check if the input is an integer
                if (option >= a && option <= b)
                {
                    break; // Valid input, break the loop
                }
                else
                {
                    cout << "Invalid Option!!! Please Enter Again: ";
                }
            }
            else
            {
                cout << "Invalid Input!!! Please Enter an Integer: ";
                cin.clear();                                         // Clear the error flag set by cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            }
        }
        return option;
    }
    void getInput(string &prompt)
    {
        while (true)
        {
            cin.ignore();
            getline(cin, prompt);
            if (prompt.empty())
            {
                cout << "Input cannot be empty! Please enter again: ";
            }
            else
            {
                break;
            }
        }
    }

    char input_validation_char()
    {
        char answer;
        while (!(cin >> answer) || (answer != 'y' && answer != 'n'))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter 'y' or 'n': ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the rest of the input buffer
        return answer;
    }

    string to_lowercase(string str)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    bool task_duplication_check2(string new_task, string existing_task)
    {
        if (new_task.size() != existing_task.size())
        {
            return false;
        }
        else
        {
            string lower_new_task = to_lowercase(new_task);
            string lower_existing_task = to_lowercase(existing_task);
            for (int i = 0; i < lower_new_task.size(); i++)
            {
                if (lower_new_task[i] != lower_existing_task[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool task_duplication_check1(string new_task)
    {
        for (auto &task : task_list)
        {
            bool flag = task_duplication_check2(new_task, get<1>(task).first);
            if (flag)
            {
                return true;
            }
        }
        return false;
    }
    void New_Task()
    {
        cout << "Follow The Following Steps To Add A New Task :-->" << endl;
        cout << endl;
        cout << "Enter The Task Name : ";
        string task_name;
        getInput(task_name);
        while (task_duplication_check1(task_name))
        {
            cout << "Task Already Exists" << endl;
            cout << "Enter New Task : ";
            getline(cin, task_name);
        }
        int priority_no;
        cout << "Enter Priority Number : ";
        cin >> priority_no;
        cin.ignore();
        task_list.push_back({priority_no, {task_name, "Pending"}, true});
        cout << endl;
        cout << "Your Task Has Successfully Added To The List!!!!" << endl;
    }
    void View_Task()
    {
        cout << "You Have Added The Following Tasks To Your Task List :-> " << endl;
        cout << endl;
        int count = 1;
        for (auto &task : task_list)
        {
            if (get<2>(task))
            {
                cout << "Task No. : " << count << "  || Task Name : " << get<1>(task).first << " || Status : " << get<1>(task).second << " || Priority : " << get<0>(task) << endl;
                count++;
            }
        }
        cout << endl;
        cout << "Clock Is Running!!!! Complete Your Tasks Fast!!!" << endl;
    }

    void Mark_Complete_Task()
    {
        cout << "Which Task You Have Completed ?\n";
        string task_name;
        cout << "Enter Task Name : ";
        getInput(task_name);
        bool flag = false;
        for (auto &task : task_list)
        {
            if ((task_duplication_check2(task_name, get<1>(task).first)) && get<2>(task))
            {
                get<1>(task).second = "Completed";
                flag = true;
            }
        }
        if (flag)
        {
            cout << "Task Has Sucessfully Completed!!!";
        }
        else
        {
            cout << "Sorry The Task Dosen't Exists On The Task-List!!!!!";
        }
        cout << "\n\n";
    }

    void Remove_Task()
    {
        cout << "Which Task You Want To Remove ?";
        string task_name;
        cout << "Enter Task Name : ";
        getInput(task_name);
        bool flag = false;
        for (auto &task : task_list)
        {
            if ((task_duplication_check2(task_name, get<1>(task).first)) && get<2>(task))
            {
                get<2>(task) = false;
                flag = true;
            }
        }
        if (flag)
        {
            cout << "Task Has Sucessfully Removed!!!";
        }
        else
        {
            cout << "Sorry The Task Dosen't Exists On The Task-List!!!!!";
        }
        cout << "\n\n";
    }

    void Edit_Task()
    {
        cout << "Which Task You Want To Edit ?\n";
        string task_name;
        cout << "Enter Task Name : ";
        getInput(task_name);
        bool flag = false;
        for (auto &task : task_list)
        {
            if ((task_duplication_check2(task_name, get<1>(task).first)) && get<2>(task))
            {
                string new_task;
                cout << "Enter New Task Name : ";
                getInput(new_task);
                get<1>(task).first = new_task;
                string new_status;
                cout << "Enter New Status : ";
                getInput(new_status);
                get<1>(task).second = new_status;
                int new_priority;
                cout << "Enter New Priority : ";
                cin >> new_priority;
                get<0>(task) = new_priority;
                flag = true;
            }
        }
        if (flag)
        {
            cout << "Task Has Sucessfully Editted!!!";
        }
        else
        {
            cout << "Sorry The Task Dosen't Exists On The Task-List!!!!!";
        }
        cout << "\n\n";
    }

    void Prioritize_Task()
    {
        cout << "Do You Want To Order You Task According To Priority ?(y/n) : ";
        char answer = input_validation_char();
        if (answer == 'y')
        {
            sort(task_list.begin(), task_list.end(), [](const auto &a, const auto &b)
                 { return get<0>(a) < get<0>(b); });

            cout << "Task List by Priority:\n";
            for (const auto &task : task_list)
            {
                if (get<2>(task))
                {
                    cout << "Priority: " << get<0>(task)
                         << " | Task: " << get<1>(task).first
                         << " - " << get<1>(task).second
                         << '\n';
                }
            }
        }
        else
        {
            cout << "Okay No Worry!!" << endl;
            cout << "\n";
        }
    }

public:
    ToDoList(const string name)
    {
        user_name = name;
    }
    void Homepage()
    {
        cout << "Welcome " << user_name << "!!!" << endl;
        cout << endl;
        while (true)
        {
            cout << "Chose From The Following Options : ";
            cout << endl;
            cout << "1. Add A New Task" << endl;
            cout << "2. View Existing Task" << endl;
            cout << "3. Mark A Task As Completed " << endl;
            cout << "4. Remove A Task" << endl;
            cout << "5. Edit A Task" << endl;
            cout << "6. Priotize Task" << endl;
            cout << "7. Exit" << endl;
            cout << endl;
            int choices = input_validation(1, 7);
            bool flag = false;
            switch (choices)
            {
            case 1:
                New_Task();
                break;
            case 2:
                View_Task();
                break;
            case 3:
                Mark_Complete_Task();
                break;
            case 4:
                Remove_Task();
                break;
            case 5:
                Edit_Task();
                break;
            case 6:
                Prioritize_Task();
                break;
            case 7:
                flag = true;
                break;
            }
            if (flag)
            {
                break;
            }
        }
    }
};

bool landing_page()
{
    cout << "!!! Welcome To To-Do-List !!!" << endl;
    cout << "\n";
    cout << "Make Your Choice :--> \n";
    cout << "--> 1 For Making Your Daily Task List...\n";
    cout << "--> 2 For Exiting From The Application...\n";
    cout << "Enter Your Choice : ";
    int a;
    cin >> a;
    while (a != 1 && a != 2)
    {
        cout << "Invalid Decission !!!!\n";
        cout << "Please Enter A Correct Option : ";
        cin >> a;
    }
    if (a == 1)
    {
        return true;
    }
    return false;
}
int main()
{
    bool flag = landing_page();
    if (flag)
    {
        string user_name;
        cout << "Please Enter Your Name : ";
        cin.ignore();
        getline(cin, user_name);
        cout << endl;
        ToDoList todo(user_name);
        todo.Homepage();
    }
    cout << "Closing The Aplication......!!!" << endl;
    return 0;
}
