#include <stdio.h>


int main(void) {
  float total_loan, interest, payment = 0;

  printf("Enter amount of loan: ");
  scanf("%f", &total_loan);

  printf("Enter interest rate: ");
  scanf("%f", &interest);

  printf("Enter monthly payment: ");
  scanf("%f", &payment);

  interest = interest / 100;
  float monthly_interest_rate = interest / 12;

  for (int month = 0; month < 3; month++) {
    float interest_accrued = total_loan * monthly_interest_rate;
    total_loan = total_loan + interest_accrued;
    total_loan = total_loan - payment;
    printf("Balance remaining after payment: $%.2f\n", total_loan);
  }

}
