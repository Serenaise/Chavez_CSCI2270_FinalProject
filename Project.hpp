//
//  Project.hpp
//  Chavez Final Project
//
//  Created by Juan Chavez on 4/26/16.
//  Copyright © 2016 Juan Chavez. All rights reserved.
//

#ifndef Project_hpp
#define Project_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Course1{
    bool enrolled = false;
    int coursenum;
    int section;
    int units;
    int seats;
    int waitlist = 0;
    string instructor;
    string title;
    string time;
    string location;
    Course1 *next;
    Course1 *previous;
    Course1(){};
    Course1(string in_title, int section1, int course2,string name1, string time1, string location1,int seats1,int units1){
        section = section1;
        time = time1;
        units=units1;
        location = location1;
        instructor = name1;
        title = in_title;
        coursenum = course2;
        seats=seats1;
        next = NULL;
        previous=NULL;
    }
    
};

struct student{
    string name;
    int sid;
    student(){};
    student(string name34,int id){
        sid=id;
        name = name34;
    }
};



class Project
{
public:
    Project();
    void dropID();
    void printEntry();
    void printMenu();
    void printLogin();
    void adminLogin();
    void adminMenu();
    void insertID(int sid, string name);
    void printTableContents();
    void adminEnroll(string course, int section);
    void enroll(string course, int section, string major);
    void drop(string name, int sector, string major);
    void findCourses(string title, int sect);
    void readandAddCourse();
    void createClass(string in_title, int section1, string course2,string name1, string time1, string location1,int seats1,int units1);
    Course1* findClass(string name,int id);
    int hashSum(string x, int s);
    
private:
    int tableSize = 10;
    Course1* hashTable[10];
    student* array[1];
    
};


#endif /* Project_hpp */
