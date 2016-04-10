#include <iostream>

using namespace std;

int main() {
    int t, check[10];
    cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
    long n[t], r, sum = 0;
    for (int i = 0; i < t; ++i) {
        cin >> n[i];
    }

    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 10; j++) {
            check[j] = false; // reset the stupid thing
        }

        if (n[i] == 0) {
            cout << "Case #" << i + 1 << ": INSOMNIA" << endl;
        } else {
           // cout << "n[" << i << "]" << n[i] << endl;
            long factor = 1;
            while ((n[i] * factor) <= 1000000) {
                int temp = n[i] * factor;
                int temp2 = temp;
                //cout << "temp = " << temp << endl;
                //cout << "temp2 = " << temp2 << endl;
                while (temp != 0) {
                    r = temp % 10;
                    temp = temp / 10;
                    check[r] = true;
                    //cout << "r = " << r << endl;
                    //cout << "temp = " << temp << endl;
                }
                sum = 0;
                for (int j = 0; j < 10; j++) {
                    if (check[j] == true) {
                        sum += 1;
                    }
                }
                //cout << "sum = " << sum << endl;
                if (sum >= 10) {
                    cout << "Case #" << i + 1 << ": " << temp2 << endl;
                    sum = 0;
                    break;
                }
                sum = 0; // reset
                factor++;
            }
        }
    }

    return 0;
}