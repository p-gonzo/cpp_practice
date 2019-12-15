#include <iostream>
#include <bitset>

using namespace std;

int main()

{
    cout << "Enter a number between 0 and 255: ";
    unsigned short inputNum = 0;
    cin >> inputNum;

    bitset<8> inputBits(inputNum); // Todo - how is this cpp assignment?
    cout << inputNum << " in binary is " << inputBits << endl;

    bitset<8> bitwiseNOT = (~inputBits);
    cout << "Logical Not ~" << endl;
    cout << "~" << inputBits << " = " << bitwiseNOT << endl;
    cout << "And the resulting number is: " << bitwiseNOT.to_ulong() << endl;

    cout << "Logical AND, & with 00001111" << endl;
    bitset<8> bitwiseAND = (0x0F & inputNum);
    cout << "00001111 & " << inputBits << " = " << bitwiseAND << endl;
    cout << "And the resulting number is: " << bitwiseAND.to_ulong() << endl;

    cout << "Logical OR, | with 00001111" << endl;
    bitset<8> bitwiseOR = (0x0F | inputNum);
    cout << "00001111 | " << inputBits << " = " << bitwiseOR << endl;
    cout << "And the resulting number is: " << bitwiseOR.to_ulong() << endl;

    cout << "Logical XOR, ^ with 00001111" << endl;
    bitset<8> bitwiseXOR = (0x0F ^ inputNum);
    cout << "00001111 ^ " << inputBits << " = " << bitwiseXOR << endl;
    cout << "And the resulting number is: " << bitwiseXOR.to_ulong() << endl;

    return 0;
}