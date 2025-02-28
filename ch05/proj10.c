#include <stdio.h>

int main(void) {
  char letter_grade = 'W';
  int numeric_grade;

  printf("Enter numerical grade: ");
  scanf("%d", &numeric_grade);

  if (numeric_grade > 100 || numeric_grade < 0) {
    printf("Please enter a valid grade from 0 to 100.\n");
    return 1;
  }

  int test_grade = numeric_grade / 10;

  switch (test_grade) {
  case 10:
  case 9:
    letter_grade = 'A';
    break;
  case 8:
    letter_grade = 'B';
    break;
  case 7:
    letter_grade = 'C';
    break;
  case 6:
    letter_grade = 'D';
    break;
  default:
    letter_grade = 'F';
  }

  printf("Letter grade: %c\n", letter_grade);

  return 0;
}
