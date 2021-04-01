#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

#define LSOne(S) ((S) & -(S))

const long long P = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

/*
  YOU CAN DO THIS!! ;)
  1. Note the limits!
  2. Give logical, short variable names
  3. If you are stuck for a long time, skip to next problem
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  /*
    0        !   9        "   6        #  24        $  29        %  22
&  24        '   3        (  12        )  12        *  17        +  13
,   7        -   7        .   4        /  10        0  22        1  19
2  22        3  23        4  21        5  27        6  26        7  16
8  23        9  26        :   8        ;  11        <  10        =  14
>  10        ?  15        @  32        A  24        B  29        C  20
D  26        E  26        F  20        G  25        H  25        I  18
J  18        K  21        L  16        M  28        N  25        O  26
P  23        Q  31        R  28        S  25        T  16        U  23
V  19        W  26        X  18        Y  14        Z  22        [  18
\  10        ]  18        ^   7        _   8        `   3        a  23
b  25        c  17        d  25        e  23        f  18        g  30
h  21        i  15        j  20        k  21        l  16        m  22
n  18        o  20        p  25        q  25        r  13        s  21
t  17        u  17        v  13        w  19        x  13        y  24
z  19        {  18        |  12        }  18        ~   9        
  */
  vector<int> v(256, 0);
  v[32] = 0, v[33] = 9, v[34] = 6, v[35] = 24, v[36] = 29, v[37] = 22;
  v[38] = 24, v[39] = 3, v[40] = 12, v[41] = 12, v[42] = 17, v[43] = 13;
  v[44] = 7, v[45] = 7, v[46] = 4, v[47] = 10, v[48] = 22, v[49] = 19;
  v[50] = 22, v[51] = 23, v[52] = 21, v[53] = 27, v[54] = 26, v[55] = 16;
  v[56] = 23, v[57] = 26, v[58] = 8, v[59] = 11, v[60] = 10, v[61] = 14;
  v[62] = 10, v[63] = 15, v[64] = 32, v[65] = 24, v[66] = 29, v[67] = 20;
  v[68] = 26, v[69] = 26, v[70] = 20, v[71] = 25, v[72] = 25, v[73] = 18;
  v[74] = 18, v[75] = 21, v[76] = 16, v[77] = 28, v[78] = 25, v[79] = 26;
  v[80] = 23, v[81] = 31, v[82] = 28, v[83] = 25, v[84] = 16, v[85] = 23;
  v[86] = 19, v[87] = 26, v[88] = 18, v[89] = 14, v[90] = 22, v[91] = 18;
  v[92] = 10, v[93] = 18, v[94] = 7, v[95] = 8, v[96] = 3, v[97] = 23;
  v[98] = 25, v[99] = 17, v[100] = 25, v[101] = 23, v[102] = 18, v[103] = 30;
  v[104] = 21, v[105] = 15, v[106] = 20, v[107] = 21, v[108] = 16, v[109] = 22;
  v[110] = 18, v[111] = 20, v[112] = 25, v[113] = 25, v[114] = 13, v[115] = 21;
  v[116] = 17, v[117] = 17, v[118] = 13, v[119] = 19, v[120] = 13, v[121] = 24;
  v[122] = 19, v[123] = 18, v[124] = 12, v[125] = 18, v[126] = 9;

  string s;
  while (getline(cin, s)) {
    long long res = 0;
    for (char c : s) {
      int as = toascii(c);
      res += v[as];
    }
    cout << res << '\n';
  }
}
