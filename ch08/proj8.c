// Modify proj7 so that it prompts for 5 quiz grades for 5 students
// and computes the total score, average score for each student.
// compute the average, high, and low score for each QUIZ

#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS(a) (int)(sizeof(a) / sizeof(a[0]))

int main(int argc, char *argv[]) {

  int student_total[5] = {0};
  int student_avg[5] = {0};

  int high[5] = {0};
  int low[5] = {99999};
  int quiz_tot[5] = {0};
  int quiz_avg[5];

  int this_value;

  int s, q;

  for (s = 0; s < 5; s++) {
    printf("Enter quiz scores for student %d: ", s + 1);
    for (q = 0; q < 5; q++) {
      // We could do this without saving the 2-d array.
      // Save each int to a temp variable, then add it to the
      // running total the same way. I saved the values because
      // it seemed to be in the spirit of the chapter
      scanf("%d", &this_value);

      student_total[s] += this_value;
      quiz_tot[q] += this_value;

      if (this_value > high[q])
        high[q] = this_value;
      if (this_value < high[q])
        low[q] = this_value;
    }
  }

  for (s = 0; s < 5; s++) {
    student_avg[s] = student_total[s] / 5;
  }

  for (q = 0; q < 5; q++) {
    quiz_avg[q] = quiz_tot[q] / 5;
  }

  printf("\nStudent Statistics:\n---------------------------------\n");

  int i = 0;
  while (i < ELEMENTS(student_avg)) {
    printf("Student %d    Total Score: %3d     Average Score: %3d\n", i + 1,
           student_total[i], student_avg[i]);
    i++;
  }

  printf("\nQuiz Statistics:\n---------------------------------\n");
  i = 0;
  while (i < ELEMENTS(quiz_avg)) {
    printf("Quiz %d       High Score: %3d      Low Score: %3d     Average "
           "Score: %3d\n",
           i + 1, high[i], low[i], quiz_avg[i]);
    i++;
  }

  printf("\n\n");

  return EXIT_SUCCESS;
}
