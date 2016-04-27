//
//  main.cpp
//  Chavez Final Project
//
//  Created by Juan Chavez on 4/26/16.
//  Copyright © 2016 Juan Chavez. All rights reserved.
//

#include <iostream>
#include "Project.hpp"
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int option;
    int input;
    int sect11;
    int sector;
    string course;
    string username;
    string section;
    string major;
    string drop;
    string sect;
    string search;
    
    Project inst;
    inst.readandAddCourse();
    
    inst.printEntry();
    cin>>input;
    cout<<"Please enter you full name."<<endl;
    cin.ignore();
    getline(cin,username);
    inst.insertID(input, username);
    
    inst.printLogin();
    inst.printMenu();
    
    while(cin>>option){
        if(option == 1){
            cout<<"Enter course number: "<<endl;
            cin.ignore();
            getline(cin,course);
            cout<<"Enter section: "<<endl;
            getline(cin,section);
            cout<<"Enter your Major: "<<endl;
            getline(cin,major);
            int section22 = atoi(section.c_str());
            inst.enroll(course,section22,major);
            inst.printMenu();
        }
        if(option == 2){
            string majornow;
            cout << "Enter the Course number and the section number of the class you want to drop:" << endl;
            cin.ignore();
            getline(cin, drop);
            cout<<"Enter the section number: "<<endl;
            cin>>sector;
            cout<<"Enter your major:"<<endl;
            cin.ignore();
            getline(cin,majornow);
            
            inst.drop(drop,sector,majornow);
            inst.printMenu();
        }
        if(option == 3){
            inst.printTableContents();
            inst.printMenu();
        }
        if(option == 4){
            cout<<"Please enter the course number of the course you would like to search for: "<<endl;
            cin.ignore();
            getline(cin,search);
            cout<<"Please enter the section number: "<<endl;
            cin>>sect11;
            inst.findCourses(search,sect11);
            inst.printMenu();
        }
        if(option == 5){
            int password;
            int real= 4201997;
            cout<<"Please enter you employee ID"<<endl;
            cin>>password;
            if(password == real){
                inst.adminLogin();
                inst.adminMenu();
                int adminOp;
                while(cin>>adminOp){
                    string name;
                    int sectionNo;
                    string courseNo;
                    string teachername;
                    string timeat;
                    string roomNo;
                    int credithrs;
                    int seatsaval;
                    
                    if(adminOp == 1){
                        string classto;
                        int sectionto;
                        
                        cout<<"Enter the course number: "<<endl;
                        cin.ignore();
                        getline(cin,classto);
                        cout<<"Now enter the section number: "<<endl;
                        cin>>sectionto;
                        
                        inst.adminEnroll(classto, sectionto);
                        inst.adminMenu();
                    }
                    if(adminOp == 2){
                        cout<<"Enter Course number: "<<endl;
                        cin.ignore();
                        getline(cin,courseNo);
                        cout<<"Enter Section Number: "<<endl;
                        cin>>sectionNo;
                        cout<<"Enter the class name: "<<endl;
                        cin.ignore();
                        getline(cin,name);
                        cout<<"Enter the instructor's name: "<<endl;
                        getline(cin,teachername);
                        cout<<"Enter the dates and times the class is at: (Days(TimeIn-TimeOut))"<<endl;
                        getline(cin,timeat);
                        cout<<"Enter the room where the class will be at: "<<endl;
                        getline(cin, roomNo);
                        cout<<"Enter the number of seats that will be available: "<<endl;
                        cin>>seatsaval;
                        cout<<"Enter the amount of credit hours the course will be worth: "<<endl;
                        cin>>credithrs;
                        inst.createClass(name, sectionNo, courseNo, teachername, timeat, roomNo, seatsaval, credithrs);
                        inst.adminMenu();
                        
                    }
                    if(adminOp == 3){
                        inst.dropID();
                        inst.adminMenu();
                    }
                    if(adminOp == 4){
                        cout<<"Logged out."<<endl;
                        break;
                    }
                }
            }
            else{
                cout<<"Incorrect employee i.d, attempt to breach the system results in immediate end to the session. Goodbye. "<<endl;
                break;
            }
            inst.printMenu();
        }
        if(option == 6){
            cout << "Goodbye!" << endl;
            break;
        }
    }
    
    return 0;
}
