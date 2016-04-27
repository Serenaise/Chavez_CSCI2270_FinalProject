//
//  Project.cpp
//  Chavez Final Project
//
//  Created by Juan Chavez on 4/26/16.
//  Copyright © 2016 Juan Chavez. All rights reserved.
//

#include "Project.hpp"
//
//  HashTable.cpp
//  Assignment 12
//
//  Created by Juan Chavez on 4/19/16.
//  Copyright © 2016 Juan Chavez. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

Project::Project(){
    //ctor
    for(int x= 0; x < tableSize; x++){
        hashTable[x] = NULL;
    }
}
void Project::printEntry(){
    cout<<"====MYCUINFO COMPUTER SCIENCE SUMMER 2016 LOWER DIVISION COURSE REGISTRATION===="<<endl;
    cout<<"                       <Login>(Enter your student ID number)"<<endl;
}
void Project::insertID(int sid, string name){
    array[1] = new student(name,sid);
    cout<<"Welcome "<<array[1] -> name<<endl;
}
void Project::adminLogin(){
    cout<<"ADMINISTRATOR LOGIN"<<endl;
    cout<<"...SUCCESS"<<endl;
    cout<<" "<<endl;
}
void Project::adminMenu(){
    cout<<"===ADMINISTRATIVE MENU==="<<endl;
    cout<<"1. Override Enrollment"<<endl;
    cout<<"2. Create New Class"<<endl;
    cout<<"3. Withdrawal"<<endl;
    cout<<"4. Secure Log out"<<endl;
}
void Project::printMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Enroll" << endl;
    cout << "2. Drop" << endl;
    cout << "3. Print List of Courses" << endl;
    cout << "4. Find Specific Course" << endl;
    cout << "5. Administrator Menu" << endl;
    cout << "6. Log out" << endl;
}
void Project::printLogin(){
    cout<<"Login Success"<<endl;
}
void Project::dropID(){
    cout<<array[1] ->name<<", Student ID: "<<array[1] -> sid<<" has been administratively withdrawn."<<endl;
}

void Project::printTableContents(){
    for(int z = 0; z < 10; z++){
        if(hashTable[z] != NULL){
            Course1 *temp;
            cout << "CSCI "<<hashTable[z]-> coursenum << ": " << hashTable[z] -> title << " Section: " <<hashTable[z] -> section<<": "<< hashTable[z] -> time <<", Room: "<<hashTable[z] -> location<<": Instructor Name - "<<hashTable[z] -> instructor<<", Credit Hours: "<<hashTable[z] -> units<<": Available Seats: "<<hashTable[z] -> seats<<": Waitlist total: "<<hashTable[z] -> waitlist<<endl;
            cout<<endl;
            temp = hashTable[z] -> next;
            while(temp != NULL){
                cout << "CSCI "<<temp-> coursenum << ": " << temp -> title << " Section: " <<temp -> section<<": "<< temp -> time <<", Room: "<<temp -> location<<": Instructor Name - "<<temp -> instructor<<", Credit Hours: "<<temp -> units<<": Available Seats: "<<temp -> seats<<": Waitlist total: "<<temp -> waitlist<<endl;
                cout<<endl;
                temp = temp -> next;
            }
        }
    }
}


void Project::enroll(string course, int section, string major){
    Course1* tmp = findClass(course, section);
    
    int iSecret = rand() % 100000 + 1;
    if(tmp!= NULL){
        if(tmp -> seats != 0 && major == "CSCI"){
            tmp -> seats = tmp -> seats - 1;
            cout<<"Congratulations! You are now enrolled in... CSCI-"<<tmp-> coursenum << ": " << tmp -> title << ": " << tmp -> time <<", Room: "<<tmp -> location<<": Instructor Name - "<<tmp -> instructor<<", Credit Hours: "<<tmp -> units<<": Available Seats: "<<tmp -> seats <<": Waitlist total: "<<tmp -> waitlist<<endl;
            cout<<"Confirmation Number: "<<iSecret<<". Please save this for your records."<<endl;
            tmp -> enrolled = true;
        }
        else if(tmp -> seats == 0 && major == "CSCI"){
            cout<<"No available seats. You have been placed on the waitlist."<<endl;
            tmp -> waitlist = tmp -> waitlist + 1;
            cout<<"You are number: "<<tmp -> waitlist<<" on the waitlist."<<endl;
            cout<<"If you have been number 1 on the waitlist for over 2 weeks, please contact a system administrator for a forced over enrollment of the class and override the restriction."<<endl;
        }
        else if (major != "CSCI"){
            cout<<"These courses are restricted to CSCI majors only. Please contact an administrator to override."<<endl;
        }}
    else if (tmp == NULL){
        cout<<"Class Does not exist"<<endl;
    }
   
}


void Project::adminEnroll(string course, int section){
    Course1* tmp = findClass(course, section);
    int iSecret = rand() % 100000 + 1;
    if(tmp!= NULL){
        if(tmp -> seats != 0){
            tmp -> seats = tmp -> seats - 1;
            cout<<"Congratulations! You are now enrolled in... CSCI-"<<tmp-> coursenum << ": " << tmp -> title << ": " << tmp -> time <<", Room: "<<tmp -> location<<": Instructor Name - "<<tmp -> instructor<<", Credit Hours: "<<tmp -> units<<": Available Seats: "<<tmp -> seats<<": Waitlist total: "<<tmp -> waitlist<<endl;
            cout<<"Confirmation Number: "<<iSecret<<". Please save this for your records."<<endl;
            tmp -> enrolled = true;
        }
        else if(tmp -> seats == 0){
            cout<<"No available seats. You have been placed on the waitlist."<<endl;
            tmp -> waitlist = tmp -> waitlist + 1;
            cout<<"You are number: "<<tmp -> waitlist<<" on the waitlist."<<endl;
            cout<<"If you have been number 1 on the waitlist for over 2 weeks, please contact a system administrator for a forced over enrollment of the class and override the restriction."<<endl;
            tmp -> enrolled = true;
        }
    }
    else if (tmp == NULL){
        cout<<"Class Does not exist"<<endl;
    }
}


void Project::drop(string course, int sector, string major){
    int index = hashSum(course, tableSize);
    Course1 *tmp = hashTable[index];
        if(tmp -> waitlist != 0 && tmp -> enrolled == true){
            tmp -> waitlist = tmp -> waitlist - 1;
                    cout<<"You have succesfully dropped the class."<<" Available seats: "<<tmp -> seats<<" Waitlist total: "<<tmp->waitlist<<endl;
            tmp ->enrolled = false;
        }
        else if(tmp -> waitlist == 0 && tmp ->seats < 30 && tmp -> enrolled == true){
            tmp -> seats = tmp -> seats + 1;
                    cout<<"You have succesfully dropped the class."<<" Available seats: "<<tmp -> seats<<" Waitlist total: "<<tmp->waitlist<<endl;
            tmp ->enrolled = false;
        }
        else if(tmp -> enrolled == false){
            cout<<"you have not enrolled in this course."<<endl;
        }
}


int Project::hashSum(string x, int s){    int sum = 0;
    for(int i = 0; i < x.size(); i++){
        sum = sum + x[i];
    }
    sum = sum % s;
    return sum;
}

Course1* Project::findClass(string name,int id){
        int index = hashSum(name,tableSize);
        Course1 *tmp;
        
        if(hashTable[index] != NULL){
            tmp = hashTable[index];
            while(tmp != NULL){
                if (tmp -> section == id){
                    return tmp;
                    break;
                }
                else{
                    tmp = tmp -> next;
                }
            }
        }
        else if(hashTable[index] == NULL){
            cout << "Class not found." << endl;
        }
        return NULL;
}


void Project::findCourses(string title,int sect){
    int index = hashSum(title,tableSize);
    Course1 *tmp;
    
    if(hashTable[index] != NULL){
        tmp = hashTable[index];
        while(tmp != NULL){
            if (tmp -> section == sect){
                cout << hashTable[index]-> coursenum << ": " << hashTable[index] -> title << ": " << hashTable[index] -> time <<", Room: "<<hashTable[index] -> location<<": Instructor Name - "<<hashTable[index] -> instructor<<", Credit Hours: "<<hashTable[index] -> units<<": Available Seats: "<<hashTable[index] -> seats<<": Waitlist total: "<<hashTable[index] -> waitlist<<endl;
                break;
            }
            else{
                tmp = tmp -> next;
            }
        }
    }
    else if(hashTable[index] == NULL){
        cout << "Class not found." << endl;
    }
}

void Project::createClass(string title, int section1, string course2,string name1, string time1, string location1,int seats1,int units1){
    int index = hashSum(course2, tableSize);
    
    if (hashTable[index] == NULL){
        hashTable[index] = new Course1(title,section1,atoi(course2.c_str()),name1,time1,location1,seats1,units1);
    }
    else{
        hashTable[index] -> next = new Course1(title,section1,atoi(course2.c_str()),name1,time1,location1,seats1,units1);
    }
    cout<<"Class added succesfully."<<endl;
}

void Project::readandAddCourse(){
    string notneeded;
    string section;
    string course;
    string title;
    string times;
    string room;
    string teacher;
    string availableSeats;
    string credits;
    
    ifstream inFile;
    inFile.open("CourseList.txt");
    while(!inFile.eof()){
        getline(inFile,notneeded,',');
        getline(inFile,course,',');
        getline(inFile,title,',');
        getline(inFile,section,',');
        getline(inFile,times,',');
        getline(inFile,room,',');
        getline(inFile,teacher,',');
        getline(inFile,availableSeats,',');
        getline(inFile,credits);
        
        
        int index = hashSum(course, tableSize);
        
        if (hashTable[index] == NULL){
            hashTable[index] = new Course1(title,atoi(section.c_str()),atoi(course.c_str()),teacher,times,room,atoi(availableSeats.c_str()),atoi(credits.c_str()));
            
        }
        else{
            hashTable[index]->next = new Course1(title,atoi(section.c_str()),atoi(course.c_str()),teacher,times,room,atoi(availableSeats.c_str()),atoi(credits.c_str()));
            hashTable[index] -> next -> previous = hashTable[index];
                    }

        
    }
}