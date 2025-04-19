// Write a program that prompts the user for a number and then displays the
// number using ASCII characters to simulate the effect of a 7-segment LED
// display.
//
// Characters other than digits should be ignored. Write the program so the
// maximym number of digits is controlled by a macro named MAX_DIGITS, which
// has the value 10.
//
// Using my code from the chapter 8 7-segment project as a starting point
#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITS 10
#define LENGTH(a) ((int)(sizeof(a) / sizeof(a[0])))

// Exercise 6
// Build a 2-D array to drive a seven-segment LED display:
// segments[digit][segment]

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

const char segs[11][3][4] = {
    {" _ ", "| |", "|_|"}, {"   ", "  |", "  |"}, {" _ ", " _|", "|_ "},
    {" _ ", " _|", " _|"}, {"   ", "|_|", "  |"}, {" _ ", "|_ ", " _|"},
    {" _ ", "|_ ", "|_|"}, {" _ ", "  |", "  |"}, {" _ ", "|_|", "|_|"},
    {" _ ", "|_|", " _|"}, {"   ", " _ ", "   "},
};

//                     0    1    2    3    4    5    6    7    8
const char disp[9] = {'_', '|', '|', '_', '|', '|', '_', ' ', ' '};
const int map[9] = {7, 0, 8, 5, 6, 1, 4, 3, 2};

void print_one_digit(int d) {
  //  _  708   7,8 = ' '
  // |_| 561   0,603 = '_'
  // |_| 432   5,1,4,2 = '|'

  char this_seg;
  int ind = 0;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (ind == 0 || ind == 2) {
        this_seg = disp[map[ind]];
      } else if (segments[d][map[ind]] == 1) {
        this_seg = disp[map[ind]];
      } else {
        this_seg = ' ';
      }
      printf("%c", this_seg);
      ind++;
    }
    printf("\n");
  }
}

void print_array_of_digits(int d[MAX_DIGITS], int len) {
  for (int r = 0; r < 3; r++) {
    for (int n = 0; n < len; n++) {
      printf("%s ", segs[d[n]][r]);
    }
    printf("\n");
  }
}

void print_array_of_chars(char d[MAX_DIGITS], int len) {
  int this_seg_ind;
  for (int r = 0; r < 3; r++) {
    for (int n = 0; n < len; n++) {
      switch (d[n]) {
      case '-':
        this_seg_ind = 10;
        break;
      default:
        if (d[n] >= '0' && d[n] <= '9') {
          this_seg_ind = d[n] - '0';
        } else {
          printf("    ");
          continue;
        }
        break;
      }
      printf("%s ", segs[this_seg_ind][r]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {

  int digit;
  printf("Enter a digit to display as a 7-segment character: ");
  scanf("%d", &digit);

  if (digit < 0 || digit > 9) {
    printf("Please enter a single positive digit\n");
    return 1;
  }

  print_one_digit(digit);

  int ar[7] = {8, 6, 7, 5, 3, 0, 9};
  print_array_of_digits(ar, LENGTH(ar));

  char cr[] = "867-5309a";
  print_array_of_chars(cr, LENGTH(cr));

  return 0;
}
