#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "Faculty.h"
using namespace std;

int main(int argc, char* argv[]){
  int input = 0;
  ifstream inputStream;
  ofstream outputStream;
  BST<Student> *studentBST = new BST<Student>();
  BST<Faculty> *facultyBST = new BST<Faculty>();
  inputStream.open("studentTable.txt");
  if(!inputStream.is_open()){
    cout << "Student table file does not exist. Will create new one." << endl;
  }
  else{
    //get info from txt file
  }
  inputStream.open("facultyTable.txt");
  if(!inputStream.is_open()){
    cout << "Faculty table file does not exist. Will create new one." << endl;
  }
  else{
    //get info from txt file
  }
  inputStream.close();
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
      }
    }
    if(input == 14){
      return 0;
    }
  }
  while(input != 14);
}
