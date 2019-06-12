#include <iostream>
#include "comparision.h"
#include "conversion.h"
#include "concurrency.h"
#include "containers.h"
#include "date_time.h"
#include "dumper.h"
#include "evector.h"
#include "intvector.h"
#include "safe_printf.h"
#include "string_master.h"
#include "units.h"

using namespace std;

int main() {
    string s1 = "0x12AB";
    cout << hexToInt(s1) << endl;
    string s2 = "12AB";
    cout << hexToInt(s2) << endl;
    string s3 = "QAFG";
    cout << hexToInt(s3) << endl;

    int a = 1977;
    cout << intToHex(a) << endl;

    string s4 = "razzle dazzle giddyup";

    string tmp;

    StringTokenizer st(s4);
    cout << "there are " << st.countTokens() << " tokens.\n";
    while (st.hasMoreTokens()){
        st.nextToken(tmp);
        cout << "token = " << tmp << '\n';
    }

    string s5 = "One fish, two fish, blue fish.";
    string s6 = "fish";
    removeSubstring(s5, s6);
    cout << s5 << '\r\n';
    return 0;
}