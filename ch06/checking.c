#include <stdio.h>

// Simple program works.
// Entering non-integers as a command produces very strange looping behavior.

void print_commands() {
  printf("Commands: 0=clear, 1=credit, 2=debit, ");
  printf("3=balance, 4=exit\n\n");
}

int main(void) {
  int cmd;
  float balance = 0.0f, credit, debit;

  printf("*** FLASHTECH checkbook-balancing program ***\n");
  print_commands();

  for (;;) {
    printf("Enter command: ");
    scanf("%d", &cmd);

    switch (cmd) {
    case 0:
      balance = 0.0f;
      break;
    case 1:
      printf("Enter amount of credit: ");
      scanf("%f", &credit);
      balance += credit;
      break;
    case 2:
      printf("Enter amount of debit: ");
      scanf("%f", &debit);
      balance -= debit;
      break;
    case 3:
      printf("Current balance: $%0.2f\n", balance);
      break;
    case 4:
      return 0;
    default:
      print_commands();
      break;
    }
  }

  return 0;
}
