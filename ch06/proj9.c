#include <stdio.h>
// Modify Chapter2, Project 8 to ask the user for a number of payments and
// then display the remaining balance after each one

int main(void) {
  float total_loan, interest, payment = 0;
  int num_payments = 0;

  printf("Enter amount of loan: ");
  scanf("%f", &total_loan);

  printf("Enter interest rate: ");
  scanf("%f", &interest);

  printf("Enter monthly payment: ");
  scanf("%f", &payment);

  printf("Enter the number of payments to display");
  scanf("%d", &num_payments);

  interest = interest / 100;
  float monthly_interest_rate = interest / 12;

  for (int month = 0; month < num_payments; month++) {
    float interest_accrued = total_loan * monthly_interest_rate;
    total_loan = total_loan + interest_accrued;
    total_loan = total_loan - payment;
    printf("Balance remaining after payment %3d: $%.2f\n", month + 1,
           total_loan);
  }
}
