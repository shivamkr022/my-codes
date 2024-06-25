#include <iostream>
#include <string>

class Student {
private:
   std::string name;
   int rollNo;
   std::string class_; 

public:
   
   Student(const std::string& name, int rollNo, const std::string& class_) :
       name(name), rollNo(rollNo), class_(class_) {}


   void setRollNo(int newRollNo) { rollNo = newRollNo; }
   void setName(const std::string& newName) { name = newName; }

   
   void printDetails() const {
       std::cout << "Name: " << name << std::endl;
       std::cout << "Roll No: " << rollNo << std::endl;
       std::cout << "Class: " << class_ << std::endl;
   }
};

int main() {
  
   Student student("Rohit", 12352, "b.tech");

   std::cout << "Initial details:" << std::endl;
   student.printDetails();

  
   int yourRollNo = 22108026; 
   std::string yourName = "Devanshu Sharma";  
   student.setRollNo(yourRollNo);
   student.setName(yourName);

   std::cout << "\nUpdated details:" << std::endl;
   student.printDetails();

   return 0;
}