//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"

char EZ[] = "asdfsafsa";
const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  Student* student = (Student*)malloc(sizeof(Student));
  char* firstName = (char*)malloc(strlen(fname)*sizeof(char)+1);
  char* lastName = (char*)malloc(strlen(fname)*sizeof(char)+1);
  strcpy(firstName, fname);
  strcpy(lastName, lname);
  student->firstName = firstName;
  student->lastName = lastName;
  student->age = age;
  student->id = id;
  students[numStudents] = student;
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  for(int i = 0; i < numStudents; i++){
    deleteStudent(students[i]);
  }
  numStudents = 0;
}

void saveStudents(char* key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  FILE* fp = fopen(STUFILE, "w");
  if(fp){
    for(int i = 0; i < numStudents; i++){
      char buff[256];

      sprintf(buff, "%s %s %d %ld", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
      if(strlen(key) > 0){
        vEncrypt(buff, key);
      }
      fprintf(fp, "%s\n", buff);
      }
    fclose(fp);
  }
  printf("\n----- Saved %d students -----\n", numStudents);
}


void loadStudents(char* key)
{
  // load the students from the data file overwriting all exisiting students in memory
  deleteStudents();
  FILE* fp = fopen(STUFILE, "r");
  if(fp){
    while(1){
      char buff[256];
      if(fscanf(fp, "%s\n", buff) == 1){
        if(strlen(key) > 0){
          vDecrypt(buff, key);
        }
        char fname[256];
        char lname[256];
        int age;
        long int id;
        sscanf(buff, "%s %s %d %ld", fname, lname, &age, &id);
        createStudent(fname, lname, age, id);
      }else{
        break;
      }
    }
    fclose(fp);
  }
  printf("\n----- Loaded %d students -----\n", numStudents);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




