#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[50];
  int phoneNumber;
} phonebook;

int main(void)
{
  phonebook person[5];

  strcpy(person[0].name, "Henry");
  person[0].phoneNumber = 123456789;

  strcpy(person[1].name, "Alice");
  person[1].phoneNumber = 987654321;

  strcpy(person[2].name, "Bob");
  person[2].phoneNumber = 555555555;

  for (int i = 0; i < 3; i++)
  {
    printf("Name: %s, Phone Number: %d\n", person[i].name, person[i].phoneNumber);
  }

  return 0;
}