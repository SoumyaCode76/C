#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
    fstream myfile;
    string name, cls, age, read_from_file, input_choice;
    int student_class, student_age;
    while(true)
    {
        try
        {
            cout << "==========================================\n";
            cout <<  "1. Perform file operations with student details\n";
            cout << "2. Exit\n";
            cout << "==========================================\n";
            while(!(cin >> input_choice));
            if(input_choice.find_first_not_of("12") == string::npos)
            {
                    int choice = stoi(input_choice);
                    switch(choice)
                    {
                        case 1:
                        {
                                myfile.open("student_info.txt", ios::in | ios::out | ios::app);
                                if(!myfile.good())
                                {
                                        throw 2;                
                                }            
                                cout << "Enter student's name: ";
                                while(true)
                                {
                                    getline(cin, name);
                                    if(name.empty() == false)
                                    {
                                        break;
                                    }
                                }
                                cout << "Enter student's class: ";
                                while(!(cin >> cls));
                                if(cls.find_first_not_of("0123456789") == string::npos && cls != "0")
                                {
                                    student_class = stoi(cls);
                                }
                                else
                                {
                                    throw 1;
                                }
                                cout << "Enter student's age: ";
                                while(!(cin >> age));
                                if(age.find_first_not_of("0123456789") == string::npos && age != "0")
                                {
                                    student_age = stoi(age);
                                }
                                else
                                {
                                    throw 1;
                                }
                                myfile << name << ", " << student_class << ", " << student_age << endl;
                                myfile.seekg(0);    // move cursor to the beginning of the file
                                if(myfile.good() == true)
                                {
                                    cout << "Data read from the file: " << endl;
                                    while(myfile.eof() == false)
                                    {
                                        getline(myfile, read_from_file);
                                        cout << read_from_file << endl;
                                    }
                                    myfile.close();
                                }        
                        }
                        break;
                        case 2:
                        {
                            cout << "Goodbye!" << endl;
                            exit(EXIT_SUCCESS);
                        }
                    }
            }
            else
            {
                throw 3;
            }
        }
        catch(int e)
        {
            switch(e)
            {
                case 1:
                    cout << "Please enter an integer for class and age" << endl;
                    break;
                case 2:
                    cout << "File could not be opened" << endl;
                    break;
                case 3:
                    cout << "Invalid app choice made. Please try again" << endl;
                    break;
                default:
                    cout << "Some other exception occurred! Please try again" << endl;
            }
            try
            {
                myfile.close();
                if(myfile.fail())
                {
                    throw 4;
                }
                continue;                
            }
            catch(int e1)
            {
                if(e1 == 4)
                {
                    cout << "File could not be closed!" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}