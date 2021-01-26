#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
const string subjects[5] = { "Math", "Biology", "Computer Science", "Physics", "Geology" };
class Student_Account
{
    string name;
    int points[5];
public:
    Student_Account() {}
    //////////////////////////////////////////////////////////////////////////////////////
    void add_Student(string n, int point[])
    {
        name = n;
        for (int i = 0; i < 5; i++)
        {
            points[i] = point[i];
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////
    double avarage(Student_Account student)
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += student.points[i];
        }

        return sum / 5;
    }
    char Grade(double number)
    {
        if (number >= 90)
            return 'A';
        else if (number < 90 && number >= 80)
            return 'B';
        else if (number < 80 && number >= 70)
            return 'C';
        else if (number < 70 && number >= 60)
            return 'D';
        else if (number < 60)
            return 'F';

    }
    void display(vector <Student_Account> student, const int& length)
    {
        cout << "\t\t\t\tAll Students Results" << endl;
        cout << "================================================================================" << endl;
        cout << "R.No  Name  Math  Biology  Computer Science   Physics  Geology   %avg   Grade" << endl;
        cout << "================================================================================" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << i + 1 << "    " << student[i].name << "     ";
            for (int j = 0; j < 5; j++)
            {
                cout << student[i].points[j] << "       ";
            }
            cout << avarage(student[i]) << "       " << Grade(avarage(student[i]));
            cout << endl;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////
    void Main_Menu()
    {
        cout << "   <<< Main Menu >>>" << endl << endl;
        cout << "1. Result Menu." << endl;
        cout << "2. Entry/Edit Menu." << endl;
        cout << "3. Exit." << endl;
        cout << "Please Enter Your Option (1-3):" << endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////
    void  Entry_Edit_Menu()
    {
        cout << "   <<<< Entry/Edit Menu >>>>" << endl << endl;
        cout << "1. Create Student Record." << endl;
        cout << "2. Display All Students Records." << endl;
        cout << "3. Search Student Record." << endl;
        cout << "4. Modify Student Record." << endl;
        cout << "5. Delete Student Record." << endl;
        cout << "6. Back to Main Menu." << endl;
        cout << "Please Enter Your Option (1-6):" << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////////
    void Display_All_Students(vector <Student_Account>All_Recoeds, const int& length)
    {
        for (int i = 0; i < length; i++)
        {
            cout << "Roll Number: " << i + 1 << endl;
            cout << "Name: " << All_Recoeds[i].name << endl;
            for (int j = 0; j < 5; j++)
            {
                cout << "The marks of " << subjects[j] << ": " << All_Recoeds[i].points[j] << endl;
            }
            cout << "Average: " << avarage(All_Recoeds[i]) << endl;
            cout << "Grade: " << Grade(avarage(All_Recoeds[i])) << endl;
            cout << endl;
            cout << "============================================" << endl;
            cout << endl;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////
    void intro()
    {
        cout << "\t Student" << endl;
        cout << "    Report Card Project" << endl;
        cout << "        Made By: F4" << endl << endl;
        system("pause");
    }
    //////////////////////////////////////////////////////////////////////////////////////
    void Modify(vector<Student_Account>& Edit_Records)
    {
        int ch1, ch2;

        try {
            cout << "Enter the roll number: " << endl;

            while (!(cin >> ch1))
            {
                cout << "Enter an integer number : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            system("pause");
            system("cls");

            if (ch1 <= 0 || ch1 > Edit_Records.size())
            {
                throw "error";
            }
            cout << "What do you want to edit? " << endl;
            cout << "1. Name" << endl;
            cout << "2. Marks" << endl;

            while (!(cin >> ch2))
            {
                cout << "Enter an integer number : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            system("cls");

            switch (ch2)
            {
            case 1:
                cout << "Enter the now name: " << endl;
                cin.ignore();
                getline(cin, Edit_Records[ch1 - 1].name);

                cout << "Modified Correctly..." << endl;
                system("pause");
                system("cls");
                break;

            case 2:
                int ch3;
                while (true)
                {
                    try {
                        cout << "1. Math." << endl;
                        cout << "2. Biology." << endl;
                        cout << "3. Computer Science." << endl;
                        cout << "4. Physics." << endl;
                        cout << "5. Geology." << endl;
                        cout << "6. Exit." << endl;

                        while (!(cin >> ch3))
                        {
                            cout << "Enter an integer number : ";
                            cin.clear();
                            cin.ignore(123, '\n');
                        }

                        if (ch3 <= 0)
                        {
                            throw "error";
                        }
                        if (ch3 > 6)
                        {
                            cout << "Wrong Input..." << endl;
                            system("pause");
                            system("cls");
                        }
                        else if (ch3 == 6)
                        {
                            system("cls");
                            break;
                        }
                        else
                        {
                            cout << "Enter the now mark of " << subjects[ch3 - 1] << endl;
                            cin >> Edit_Records[ch1 - 1].points[ch3 - 1];
                            cout << "Modified Correctly..." << endl;
                            system("pause");
                            system("cls");
                        }
                    }
                    catch (...)
                    {
                        cout << "Wrong Input..." << endl;
                        cout << "Try again..." << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                }
                break;

            default:
                cout << "Wrong Input..." << endl;
                system("pause");
                system("cls");
                break;
            }
        }
        catch (...)
        {
            cout << "Wrong Input..." << endl;
            cout << "Try again..." << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////
    void Search(vector <Student_Account> Student)
    {
        int numberOfRoll;
        try {
            cout << "Enter the Student's roll number: " << endl;
            while (!(cin >> numberOfRoll))
            {
                cout << "Enter an integer number : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            if (numberOfRoll <= 0 || numberOfRoll > Student.size())
            {
                throw "error";
            }
            cout << "The student's name is:   " << Student[numberOfRoll - 1].name;
            cout << endl;

            for (int i = 0; i < 5; i++)
            {
                cout << "- The Marks of " << subjects[i]
                    << "    " << Student[numberOfRoll - 1].points[i] << endl;
            }

            cout << "Average: " << avarage(Student[numberOfRoll - 1]) << endl;
            cout << "Grade: " << Grade(avarage(Student[numberOfRoll - 1])) << endl;
        }
        catch (...)
        {
            cout << "Wrong input..." << endl;
            cout << "Try again..." << endl;
            return;
        }

    }
    //////////////////////////////////////////////////////////////////////////////////////
    void Result_Menu()
    {
        cout << "    <<<< Result Menu >>>>" << endl << endl;
        cout << "1. Class Results." << endl;
        cout << "2. Student Report Card." << endl;
        cout << "3. Back to Main Menu." << endl;
        cout << "Please Enter you option (1-3)" << endl;
    }

    //////////////////////////////////////////////////////////////////////////////////////

    void Result_Card(vector <Student_Account> Student)
    {
        int ch;
        try {
            cout << "Enter the roll number: " << endl;
            while (!(cin >> ch))
            {
                cout << "Enter an integer number : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            if (ch <= 0 || ch > Student.size())
            {
                throw "error";
            }
            system("cls");
            cout << "The student's name is: " << Student[ch - 1].name << endl;

            for (int i = 0; i < 5; i++)
            {
                cout << "The Mark of " << subjects[i]
                    << ":  " << Student[ch - 1].points[i] << endl;
            }
            cout << "Average: " << avarage(Student[ch - 1]) << endl;
            cout << "Grade: " << Grade(avarage(Student[ch - 1])) << endl;
        }
        catch (...)
        {
            cout << "Wrong input..." << endl;
            cout << "Try again..." << endl;
            return;
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////
    void Delete(vector<Student_Account>& Studs, int& length)
    {
        int ch1;
        cout << "Enter the roll number of the student who you want to delete:" << endl;
        while (!(cin >> ch1))
        {
            cout << "Enter an integer number : ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        if (ch1 > Studs.size() || ch1 <= 0)
        {
            cout << "Out of range..." << endl;
            system("pause");
            system("cls");
        }
        else if (ch1 == Studs.size() - 1)
        {
            length--;
            cout << "Deleted..." << endl;
            system("pause");
        }
        else
        {
            for (int j = ch1 - 1; j < Studs.size() - 1; j++)
            {
                Studs[j].name = Studs[j + 1].name;
                for (int i = 0; i < Studs.size(); i++)
                {
                    Studs[j].points[i] = Studs[j + 1].points[i];
                }
            }
            length--;
            cout << "Deleted..." << endl;
        }
    }


    void add(vector<Student_Account>& Studs, int& sum, int& length)
    {
        int ch;
        string n = "";
        int point[5] = { 0 };

        cout << "How many students do you want to enter? " << endl;
        while (!(cin >> ch))
        {
            cout << "Enter an integer number : ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        system("cls");

        if (ch <= 0)
        {
            cout << "Wrong input..." << endl;
            system("pause");
            system("cls");
        }
        else
        {
            sum += ch;
            Studs.resize(sum);
            for (int x = sum - ch; x < Studs.size(); x++)
            {
                cout << "Please Enter the name of student number(" << x + 1 << "): " << endl;
                cin.ignore();
                getline(cin, n);
                cout << endl;

                for (int i = 0; i < 5;)
                {
                    cout << "Enter the marks of " << subjects[i] << ": " << endl;
                    while (!(cin >> point[i]))
                    {
                        cout << "Enter an integer number : ";
                        cin.clear();
                        cin.ignore(123, '\n');
                    }
                    if (point[i] < 0 || point[i]>100)
                    {
                        cout << "Wrong input..." << endl;
                        system("pause");
                        system("cls");
                    }
                    else { i++; }
                }
                length++;
                Studs[x].add_Student(n, point);
                cout << "Created..." << endl;
                system("pause");
                system("cls");
            }

        }
    }
    //////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////   About Input/Output File   /////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    void FileOptions()
    {
        cout << "Choose your Input/Output." << endl;
        cout << "1. From file to Dos." << endl;
        cout << "2. From Dos to Dos." << endl;
    }
    ////////////////////////////////////////
    void File()
    {
        cout << "Choose your Output Screen." << endl;
        cout << "1. File." << endl;
        cout << "2. Dos." << endl;
    }
    ////////////////////////////////////////
    void ToFile_ClassResults(vector <Student_Account> student, const int& length)
    {
        ofstream out;
        out.open("D:\\Student System(Class Results).txt");
        out << "\t\t\t\tAll Students Results" << endl;
        out << "===================================================================================" << endl;
        out << "R.No - Name - Math - Biology - Computer Science - Physics - Geology - %avg - Grade" << endl;
        out << "===================================================================================" << endl;
        for (int i = 0; i < length; i++)
        {
            out << i + 1 << "     " << student[i].name << "       ";
            for (int j = 0; j < 5; j++)
            {
                out << student[i].points[j] << "        ";
            }
            out << avarage(student[i]) << "        " << Grade(avarage(student[i]));
            out << endl;
        }
        out.close();
    }
    //////////////////////////////////////////////////////////////////////////////////
    void ToFile_ResultCard(vector <Student_Account> Student)
    {
        ofstream out;
        out.open("D:\\Student System(Result Card).txt");
        int ch;

        try {
            cout << "Enter the roll number: " << endl;
            while (!(cin >> ch))
            {
                cout << "Enter an integer number : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            if (ch <= 0 || ch > Student.size())
            {
                throw "error";
            }
            system("cls");
            out << "The student's name is: " << Student[ch - 1].name << endl;

            for (int i = 0; i < 5; i++)
            {
                out << "The Mark of " << subjects[i]
                    << ":  " << Student[ch - 1].points[i] << endl;
            }
            out << "Average: " << avarage(Student[ch - 1]) << endl;
            out << "Grade: " << Grade(avarage(Student[ch - 1])) << endl;
        }
        catch (...)
        {
            cout << "Wrong input..." << endl;
            cout << "Try again..." << endl;
            return;
        }
        out.close();
    }
    /////////////////////////////////////////////////////////////////////
    void ToFile_AllStudents(vector <Student_Account>All_Recoeds, const int& length)
    {
        ofstream out;
        out.open("D:\\Student System(All Students).txt");

        for (int i = 0; i < length; i++)
        {
            out << "Roll Number: " << i + 1 << endl;
            out << "Name: " << All_Recoeds[i].name << endl;

            for (int j = 0; j < 5; j++)
            {
                out << "The marks of " << subjects[j]
                    << ": " << All_Recoeds[i].points[j] << endl;
            }

            out << "Average: " << avarage(All_Recoeds[i]) << endl;
            out << "Grade: " << Grade(avarage(All_Recoeds[i])) << endl;
            out << endl;
            out << "============================================" << endl;
            out << endl;
        }
        out.close();
    }
    //////////////////////////////////////////////////////////////////////////////////////
};
int main()
{
    int sum = 0;
    int choice1, choice2, length = 0;
    Student_Account Student;
    vector <Student_Account> Studs;

    Student.intro();
    system("cls");

    do {
        Student.Main_Menu();
        while (!(cin >> choice1))
        {
            cout << "Enter an integer number : ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        system("cls");
        switch (choice1)
        {

        case 1:
            //////////////////////////     Result Menu    ////////////////////////////////
            system("cls");
            int choice3;

            Student.Result_Menu();

            while (!(cin >> choice3))
            {
                cout << "Enter an integer number : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            system("cls");
            switch (choice3)
            {
            case 1:
                ///////////////   Class Results   ///////////////
                Student.File();
                int ch1;
                while (!(cin >> ch1))
                {
                    cout << "Enter an integer number : ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                system("cls");
                switch (ch1)
                {
                case 1:
                    Student.ToFile_ClassResults(Studs, length);
                    cout << "Done..." << endl;
                    system("pause");
                    system("cls");
                    break;

                case 2:
                    Student.display(Studs, length);
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Wrong Input..." << endl;
                    system("pause");
                    system("cls");
                    break;
                }

                break;

            case 2:
                ///////////////   Student Report Card   ///////////////
                Student.File();
                int ch2;
                while (!(cin >> ch2))
                {
                    cout << "Enter an integer number : ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                system("cls");
                switch (ch2)
                {
                case 1:
                    Student.ToFile_ResultCard(Studs);
                    cout << "Done..." << endl;
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    Student.Result_Card(Studs);
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Wrong Input..." << endl;
                    system("cls");
                    break;
                }
                break;

            case 3:
                ///////////////   Exit   ///////////////
                system("cls");
                break;

            default:
                cout << "Wrong Input..." << endl;
                system("cls");
                break;
            }
            break;

        case 2:
            ////////////////////////////////  Entry/Edit_Menu   ////////////////////////////////////
            Student.Entry_Edit_Menu();
            while (!(cin >> choice2))
            {
                cout << "Enter an integer number : ";
                cin.clear();
                cin.ignore(123, '\n');
            }
            system("cls");

            switch (choice2)
            {
                ///////////////////   Add New     /////////////////////////
            case 1:
                Student.add(Studs, sum, length);
                break;

                //////////////   Display All  /////////////////////
            case 2:
                Student.File();
                int ch2;
                while (!(cin >> ch2))
                {
                    cout << "Enter an integer number : ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                system("cls");
                switch (ch2)
                {
                case 1:
                    Student.ToFile_AllStudents(Studs, length);
                    cout << "Done..." << endl;
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    Student.Display_All_Students(Studs, length);
                    system("pause");
                    system("cls");
                    break;
                default:
                    cout << "Wrong Input..." << endl;
                    system("cls");
                    break;

                }
                break;
                ///////////////     Search      //////////////////////
            case 3:
                Student.Search(Studs);
                system("pause");
                system("cls");
                break;

                ///////////////     Modify     ///////////////////////
            case 4:
                Student.Modify(Studs);
                break;

                ///////////////     Delete     /////////////////////
            case 5:
                Student.Delete(Studs, length);
                system("pause");
                system("cls");
                break;

                ///////////////       Exit      ////////////////
            case 6:
                system("cls");
                break;

            default:
                cout << "Wrong Input..." << endl;
                system("pause");
                system("cls");
                break;
            }
            break;

        case 3:
            return 0;
            break;

        default:
            cout << "Wrong Input..." << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (true);
}
