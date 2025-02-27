#include <stdio.h>

int main(void) {
  float income, fixed_tax, percent_tax;
  printf("Enter your income: ");
  scanf("%f", &income);

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

  float tax_due = fixed_tax + (income * percent_tax);

  printf("You owe $%0.2f in taxes.\n", tax_due);

  return 0;
}
