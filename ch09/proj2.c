// Proj 2
// Modify Ch 5, Project 5 so it uses a function to compute the
// income tax due. The function takes an "income" parameter and
// returns tax due

#include <stdio.h>

float tax_on_income(float income) {
  float percent_tax, fixed_tax;
  if (income < 750.0f) {
    fixed_tax = 0.0f;
    percent_tax = 0.01f;
  } else if (income < 2250.0f) {
    fixed_tax = 7.50f;
    percent_tax = 0.02f;
  } else if (income < 3750.0f) {
    fixed_tax = 37.5f;
    percent_tax = 0.03f;
  } else if (income < 5250.0f) {
    fixed_tax = 82.5f;
    percent_tax = 0.04f;
  } else if (income < 7000.0f) {
    fixed_tax = 142.5f;
    percent_tax = 0.05f;
  } else {
    fixed_tax = 230.0f;
    percent_tax = 0.06f;
  }

  return fixed_tax + (income * percent_tax);
}

int main(void) {
  float income;
  printf("Enter your income: ");
  scanf("%f", &income);

  printf("You owe $%0.2f in taxes.\n", tax_on_income(income));

  return 0;
}
