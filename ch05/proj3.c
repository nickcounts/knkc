#include <stdio.h>

// Modify the `broker.c` procram from 5.2 as follows:
//
// - Ask the user to enter the number of shares and the price per share,
//   instead of the value of the trade
// - Add statements that compute the commission charged by a rival broker
//   ($33 + 3 cents per share for fewer than 2000 shares, or 2 cents for
//   more than 2000 shares)
//   - Display the rival's commission and the original broker's commission

float rival_commission(int num_shares, float share_price) {
  float per_share = 0.03f;
  if (num_shares >= 2000)
    per_share = 0.02f;
  return 33.0f + (float)(num_shares * per_share);
}

float our_commission(float trade_value) {
  float commission = 0;

  if (trade_value < 2500.0f)
    commission = 30.0f + 0.017f * trade_value;
  else if (trade_value < 6250.0f)
    commission = 56.0f + 0.0066f * trade_value;
  else if (trade_value < 20000.0f)
    commission = 76.0f + 0.0034f * trade_value;
  else if (trade_value < 50000.0)
    commission = 100.0f + 0.0022f * trade_value;
  else if (trade_value < 500000.0)
    commission = 155.0f + 0.0011f * trade_value;
  else
    commission = 255.0f + 0.0009f * trade_value;

  if (commission < 39.0f)
    commission = 39.0f;

  return commission;
}

int main(void) {
  int traded_shares;
  float price_per_share;

  printf("Enter the number of shares traded: ");
  scanf("%d", &traded_shares);

  printf("Enter the price per share: ");
  scanf("%f", &price_per_share);

  float our_commish = our_commission(price_per_share * (float)traded_shares);
  float their_commish = rival_commission(traded_shares, price_per_share);

  printf("Our commission   : $%.2f\n", our_commish);
  printf("Their commission : $%.2f\n", their_commish);

  return 0;
}
