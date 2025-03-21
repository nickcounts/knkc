#include <stdio.h>
// Add a loop to the broker.c program from 5.2 so that the user can enter more
// than one trade and the program will calculate the commission on each. The
// program should terminate when the user enters 0 as a trade value

int main(void) {
  float commission, value;

  printf("Enter value of trade: ");
  scanf("%f", &value);

  while (value) {
    if (value < 2500.0f)
      commission = 30.0f + 0.017f * value;
    else if (value < 6250.0f)
      commission = 56.0f + 0.0066f * value;
    else if (value < 20000.0f)
      commission = 76.0f + 0.0034f * value;
    else if (value < 50000.0)
      commission = 100.0f + 0.0022f * value;
    else if (value < 500000.0)
      commission = 155.0f + 0.0011f * value;
    else
      commission = 255.0f + 0.0009f * value;

    if (commission < 39.0f)
      commission = 39.0f;

    printf("Commission: $%.2f\n\n", commission);
    printf("Enter value of trade: ");
    scanf("%f", &value);
  }

  return 0;
}
