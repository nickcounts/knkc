#include <stdio.h>

char first_nums[][8] = {"zero", "one",    "two",   "three", "four",
                        "five", "six",    "seven", "eight", "nine",
                        "ten",  "eleven", "twelve"};

void print_tens_place(int num) {
  switch (num / 10) {
  case 2:
    printf("twenty");
    break;
  case 3:
    printf("thirty");
    break;
  case 4:
    printf("forty");
    break;
  case 5:
    printf("fifty");
    break;
  case 6:
    printf("sixty");
    break;
  case 7:
    printf("seventy");
    break;
  case 8:
    printf("eighty");
    break;
  case 9:
    printf("ninety");
    break;
  }
}

void print_ones_place(int num) {
  switch (num % 10) {
  case 1:
    printf("one");
    break;
  case 2:
    printf("two");
    break;
  case 3:
    printf("three");
    break;
  case 4:
    printf("four");
    break;
  case 5:
    printf("five");
    break;
  case 6:
    printf("six");
    break;
  case 7:
    printf("seven");
    break;
  case 8:
    printf("eight");
    break;
  case 9:
    printf("nine");
    break;
  }
}

int main(void) {
  int number;
  printf("Enter a two-digit number: ");
  scanf("%d", &number);

  if (number > 99) {
    printf("Invalid number entered.\n");
    return 1;
  }

  printf("You entered the number ");

  if (number < 13) {
    printf("%s", first_nums[number]);
  } else if (number == 13) {
    printf("thirteen");
  } else if (number < 20) {
    print_ones_place(number);
    printf("teen");
  } else {
    print_tens_place(number);
    if (number % 10) {
      printf("-");
      print_ones_place(number);
    }
  }

  printf("\n");
  return 0;
}
