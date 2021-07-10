using namespace std;

/*
  THIS IS PSEUDOCODE ONLY
*/

// F[i] is smth like: 0,...,0,1,...,1
// WANT: smallest x s.t. P[x] is T
int bin_search_mono_incr(int l, int r) {
  int lo = l, hi = r;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (F[mid]) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

// F[i] is smth like: 1,...,1,0,...,0
// WANT: largest x s.t. P[x] is T
// Let G[i] = !F[i]
// hence G[i] is smth like 0,...,0,1...,1
// WANT: largest x s.t. P[x] is F
// use incr_mono bin-search to find largest x s.t. P[x] is T, then ans is x-1
int bin_search_mono_decr(int l, int r) {
  int x = bin_search_mono_incr(l, r);
  return x - 1;
}
