using namespace std;

// iterate over all subset of bit rep of n, except 0
void iterate_over_subsets(int n) {
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = mask; i; i = (i - 1) & mask) {
      // i is subset of mask
    }
  }
}
