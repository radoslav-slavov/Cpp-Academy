#include <iostream>
using namespace std;

bool F(bool a, bool b, bool c) {
    return (!a && (b || c)) || (a && b && c);
}

bool F_synthesized_0(bool a, bool b, bool c) {
    return (a && !b && c) || (!a && b && c) || (!a && !b && c) || (!a && !b && !c);
}

bool F_synthesized_1(bool a, bool b, bool c) {
    return (!a && b && c) || (a && b && c) || (!a && b && !c) || (a && b && !c);
}

int main() {
    bool a, b, c;
    cin >> a >> b >> c;

    cout << "F(a, b, c): " << F(a, b, c) << endl;
    cout << "F_synthesized_0(a, b, c): " << F_synthesized_0(a, b, c) << endl;
    cout << "F_synthesized_1(a, b, c): " << F_synthesized_1(a, b, c) << endl;

    return 0;
}
