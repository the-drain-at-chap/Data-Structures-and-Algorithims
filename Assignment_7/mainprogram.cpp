#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "Faculty.h"
using namespace std;

int main(int argc, char* argv[]){
  int input = 0;
  int lineCount = 0;
  string usedForLineCount;
  ifstream inputStream;
  ofstream outputStream;
  BST<Student> *studentBST = new BST<Student>();
  BST<Faculty> *facultyBST = new BST<Faculty>();
  inputStream.open("studentTable.txt");
  if(!inputStream.is_open()){
    cout << "Student table file does not exist. Will create new one." << endl;
  }
  else{
    while(getline(inputStream, usedForLineCount)){
      ++lineCount;
    }
    inputStream.close();
    inputStream.open("studentTable.txt");
    for(int i = 0;i < lineCount; i++){
      string information[6];
      for(int j = 0; j < 6; j++){
        if(j == 5){
          getline(inputStream, usedForLineCount, '\n');
          information[j] = usedForLineCount;
        }
        else{
          getline(inputStream, usedForLineCount, '|');
          information[j] = usedForLineCount;
        }
      }
      Student aStudent;
      aStudent.setID(stoi(information[0]));
      aStudent.setName(information[1]);
      aStudent.setLevel(information[2]);
      aStudent.setMajor(information[3]);
      aStudent.setGPA(stod(information[4]));
      aStudent.setAdvisor(stoi(information[5]));
      TreeNode<Student> *studentNode = new TreeNode<Student>(aStudent.getID(), aStudent);
      studentBST->insert(studentNode);
    }
    inputStream.close();
  }
  inputStream.open("facultyTable.txt");
  if(!inputStream.is_open()){
    cout << "Faculty table file does not exist. Will create new one." << endl;
  }
  else{
    lineCount = 0;
    usedForLineCount = "";
    while(getline(inputStream, usedForLineCount)){
      ++lineCount;
    }
    inputStream.close();
    inputStream.open("facultyTable.txt");
    int commaCounter = 0;
    for(int i = 0; i < lineCount; i++){
      string information2[4];
      DLList<int> *theAdvisees = new DLList<int>();
      for(int j = 0; j < 5; j++){
        if(j == 4){
          commaCounter = 0;
          getline(inputStream, usedForLineCount, '|');
          for(int k = 0; k < usedForLineCount.length(); k++){
            if(usedForLineCount[k] == ','){
              commaCounter++;
            }
          }
          string delimiter = ",";
          string seperatedAdvisee;
          for(int l = 0; l < commaCounter + 1; l++){
              seperatedAdvisee = usedForLineCount.substr(0, usedForLineCount.find(delimiter));
              theAdvisees->insertBack(stoi(seperatedAdvisee));
              usedForLineCount.erase(0, usedForLineCount.find(delimiter) + delimiter.length());
          }
        }
        else{
          getline(inputStream, usedForLineCount, '|');
          information2[j] = usedForLineCount;
        }
      }
      Faculty aFaculty;
      aFaculty.setID(stoi(information2[0]));
      aFaculty.setName(information2[1]);
      aFaculty.setLevel(information2[2]);
      aFaculty.setDepartment(information2[3]);
      aFaculty.setAdvisees(theAdvisees);
      TreeNode<Faculty> *facultyNode = new TreeNode<Faculty>(aFaculty.getID(), aFaculty);
      facultyBST->insert(facultyNode);
    }
    inputStream.close();
  }
  do{
    cout << "1. Print all students and their information." << endl;
    cout << "2. Print all faculty and their information." << endl;
    cout << "3. Find and display student information given the student id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student's id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print all the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student's advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids." << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    while(!(cin >> input)){
      cout << "Enter an input between 1 - 14." << endl;
      cin.clear();
    }
    if(input <= 0 || input >= 15){
      cout << "Input must be between 1 - 14." << endl;
      continue;
    }
    if(input == 1){
      if(studentBST->isEmpty()){
        cout << "There are no students." << endl;
        continue;
      }
      else{
        studentBST->printTree();
      }
    }
    else if(input == 2){
      if(facultyBST->isEmpty()){
        cout << "There are no faculty members." << endl;
        continue;
      }
      else{
        facultyBST->printTree();
      }
    }
    else if(input == 3){
      int id = 0;
      cout << "Enter the ID of the student: " << endl;
      while(!(cin >> id)){
        cout << "Not a valid ID. Please input again." << endl;
        cin.clear();
      }
      if(studentBST->contains(id)){
        studentBST->find(id).printInfo();
        continue;
      }
      else{
        cout << "Student does not exist." << endl;
        continue;
      }
    }
    else if(input == 4){
      int id = 0;
      cout << "Enter the ID of the faculty member: " << endl;
      while(!(cin >> id)){
        cout << "Not a valid ID. Please input again." << endl;
        cin.clear();
      }
      if(facultyBST->contains(id)){
        facultyBST->find(id).printInfo();
        continue;
      }
      else{
        cout << "Faculty member does not exist." << endl;
        continue;
      }
    }
    else if(input == 5){
      int id = 0;
      cout << "Enter the ID of the student: " << endl;
      while(!(cin >> id)){
        cout << "Not a valid ID. Please input again." << endl;
        cin.clear();
      }
      if(studentBST->contains(id)){
        id = studentBST->find(id).getAdvisor();
        facultyBST->find(id).printInfo();
      }
      else{
        cout << "Student does not exist." << endl;
        continue;
      }
    }
    else if(input == 6){
      int id = 0;
      cout << "Enter the ID of the faculty member: " << endl;
      while(!(cin >> id)){
        cout << "Not a valid ID. Please input again." << endl;
        cin.clear();
      }
      if(facultyBST->contains(id)){
        DLList<int> *tempAdvisees = new DLList<int>();
        tempAdvisees = facultyBST->find(id).getAdvisees();
        for(int i = 0; i < tempAdvisees->length(); i++){
          id = tempAdvisees->findItem(i);
          studentBST->find(id).printInfo();
        }
        continue;
      }
      else{
        cout << "Faculty member does not exist." << endl;
        continue;
      }
    }
    if(input == 7){
      int id;
      string name;
      string level;
      string major;
      double GPA;
      int advisor;
      cout << "Input the student's ID: " << endl;
      cin >> id;
      cout << "Input the student's name: " << endl;
      getline(cin, name);
      cout << "Input the student's level: " << endl;
      getline(cin, level);
      cout << "Input the student's major: " << endl;
      getline(cin, major);
      cout << "Input the student's GPA: " << endl;
      cin >> GPA;
      cout << "Input the student's advisor ID: " << endl;
      cin >> advisor;
      while(!facultyBST->contains(advisor)){
        cout << "That faculty member does not exist. Enter another advisor's ID: " << endl;
        cin >> advisor;
      }
      Student newStudent(id, name, level, major, GPA, advisor);
      TreeNode<Student> *studentNode = new TreeNode<Student>(newStudent.getID(), newStudent);
      studentBST->insert(studentNode);
      facultyBST->find(advisor).addAdvisee(newStudent.getID());
      cout << "Student successfully added." << endl;
      continue;
    }
    if(input == 8){
      int id;
      cout << "Input the ID of the student you want to delete: " << endl;
      cin >> id;
      while(!studentBST->contains(id)){
        cout << "Student does not exist, input another ID: " << endl;
      }




    }
    if(input == 9){
      int id;
      string name;
      string level;
      string department;
      DLList<int> *theAdvisees = new DLList<int>();
      cout << "Input the faculty member's ID: " << endl;
      cin >> id;
      cout << "Input the faculty member's name: " << endl;
      getline(cin,name);
      cout << "Input the faculty member's level: " << endl;
      getline(cin, level);
      cout << "Input the faculty member's department: " << endl;
      getline(cin, department);
      Faculty newFaculty(id, name, level, department);
      newFaculty.setAdvisees(theAdvisees);
      TreeNode<Faculty> *facultyNode = new TreeNode<Faculty>(aFaculty.getID(), aFaculty);
      facultyBST->insert(facultyNode);
      continue;
    }
    if(input == 10){
      int id = 0;
      cout << "Enter the ID of the faculty member: " << endl;
      while(!(cin >> id)){
        cout << "Not a valid ID. Please input again." << endl;
        cin.clear();
      }
      if(facultyBST->contains(id)){
        DLList<int> *tempAdvisees = new DLList<int>();
        tempAdvisees = facultyBST->find(id).getAdvisees();
        for(int i = 0; i < tempAdvisees->length(); i++){
          id = tempAdvisees->findItem(i);
          studentBST->find(id).printInfo();
        }
      }
    }
    if(input == 14){
      return 0;
    }
  }
  while(input != 14);
}
