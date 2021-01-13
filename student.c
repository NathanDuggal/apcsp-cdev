#include <stdio.h>
#include <string.h>


// student structure
//struct Student...

struct Student {
  char firstName[20];
  char lastName[20];
  int age;
  int id;
};

void printStudent(struct Student* student)
{
  char name[41];
  printf("  Student: %s %s\n    Age: %d\n    ID: %d\n\n", student->firstName, student->lastName, student->age, student->id);
}


void printAllStudents(struct Student students[], int num)
{
  for(int i = 0; i < num; i++){
    printf("\n----- student %d -----\n", i);
    printStudent(&(students[i]));
  }
}


int main()
{
  // an array of students
  //xxx students;
  struct Student students[1000];
  char input[256];
  int numStudents = 0;

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit: ");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student

      printf("\nFirst name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].firstName);

      printf("Last name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].lastName);

      while(1){
        printf("Age: ");
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &(students[numStudents].age)) == 1) break;
        printf("Invalid age\n");
      }

      while(1){
        printf("ID: ");
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &(students[numStudents].id)) == 1) break;
        printf("Invalid ID\n");
      }

      numStudents++;
    }
  }
  printf("\nGoodbye!\n");
}
