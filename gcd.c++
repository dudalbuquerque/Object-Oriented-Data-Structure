#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b > 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    int g = gcd(a, b);
    cout << "The gcd of " << a << " and " << b << " is " << g << endl;
    
    
    return 0;
}