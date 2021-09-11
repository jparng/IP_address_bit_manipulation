
#include <iostream>
#include <string>
using namespace std;

struct splitNum {
    unsigned int num1 : 8;
    unsigned int num2 : 8;
    unsigned int num3 : 8;
    unsigned int num4 : 8;
};


struct bits {
    unsigned int a1 : 1;
    unsigned int a2 : 1;
    unsigned int a3 : 1;
    unsigned int a4 : 1;
    unsigned int a5 : 1;
    unsigned int a6 : 1;
    unsigned int a7 : 1;
    unsigned int a8 : 1;
    unsigned int a9: 1;
    unsigned int a10: 1;
    unsigned int a11 : 1;
    unsigned int a12 : 1;
    unsigned int a13 : 1;
    unsigned int a14 : 1;
    unsigned int a15 : 1;
    unsigned int a16 : 1;
    unsigned int a17 : 1;
    unsigned int a18 : 1;
    unsigned int a19 : 1;
    unsigned int a20 : 1;
    unsigned int a21 : 1;
    unsigned int a22 : 1;
    unsigned int a23 : 1;
    unsigned int a24 : 1;
    unsigned int a25 : 1;
    unsigned int a26 : 1;
    unsigned int a27 : 1;
    unsigned int a28 : 1;
    unsigned int a29 : 1;
    unsigned int a30 : 1;
    unsigned int a31 : 1;
    unsigned int a32 : 1;
};



union fullIp{
    bits bitNumber;
    splitNum someVal;
    unsigned int wholeVal;

};

int main()
{    

    unsigned int num1, num2, num3, num4;
    int answer, bits, bitNum, specialBit, hostNum, subNum;

    cout << "Enter an IP address ";
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cin >> num4;

    splitNum number = {number.num1 = num1, number.num2 = num2, number.num3 = num3, number.num4 = num4};
    fullIp totalVal;
    totalVal.someVal.num1 = number.num4; //The numbers are input in reversed to read right to left.
    totalVal.someVal.num2 = number.num3;
    totalVal.someVal.num3 = number.num2;
    totalVal.someVal.num4 = number.num1;

    cout << "How would you like to see your IP address((1) single value, (2) four values, (3) two values, (4) a single bit value? ";

    cin >> answer;

    switch (answer) {
    case 1:
        //return 4 8-bit integers into 1 32-bit integer.
        cout << totalVal.wholeVal << endl;

        break;
    case 2:
        //add four values
        cout << "Output should be: " << number.num1 << "." << number.num2 << "." << number.num3 << "." << number.num4;
        break;
    case 3:
        // asks how many bits in network address and add two values
        cout << "How many bits in the network address : ";
        cin >> bits;

        
        hostNum = totalVal.wholeVal >> bits; // shift based on user input

        subNum = totalVal.wholeVal & 0xffff ; //using a mask for the 2nd half
                

        cout << "Output should be : " << hostNum << ", " << subNum;
        break;
    case 4:
        //ask which bit to see and then output the single bit
        cout << "Which bit would you like to see: ";
        cin >> bitNum;

        if (bitNum > 32 || bitNum < 0) {
            cout << endl;
            cout << "Invalid bit number";
        }
        else {
            specialBit = ((totalVal.wholeVal & (1 << (bitNum)) ? 1 : 0)); // using bitwise AND to compare, if true return 1, otherwise return 0.

            cout << "Output should be: " << specialBit;
        }

        break;
    default:
        cout << "Invalid input" << endl;
    }
    return 0;
}
