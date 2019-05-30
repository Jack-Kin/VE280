#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

/**The prerequisite string operation
 *
 */
//Default reverse function is inside the library <algorithm>
string reverse(string str){
    auto n=str.size();
    auto j=n-1;
    for (int i=0 ; i < j; i++, j--){
        char c=str[i];
        str[i]=str[j];
        str[j]=c;
    }
    return str;
}

//Transform the input number to the corresponding string of arbitrary numeric scale
string NumtoStr(unsigned int i, int divisor){
    string str;
    do {
        str += i % divisor + '0'; //ASCII Transformation
        i /= divisor;
    }while(i > 0);
    reverse(str);
    return str;
}

/**The core functions
 *
 */

int isTriangle_1(unsigned int i)
{
    //Based on the formula of sum of the arithmetic sequence from 1 to n
    int n;
    int sum = 0;
    for (n = 1; sum < i; n++ ) {
        sum += n;
        if (sum == i) return 1;
    }
    return 0;
}

int isTriangle_2(unsigned int i)
{
    //Based on the root of a quadratic function
    const double eps=1e-6;
    //Actually the quadratic equation is n * n + n - 2 * i = 0
    int a = 1, b = 1, c = -2*i;
    auto delta = b * b - 4 * a * c;
    auto sol1 = (-b + sqrt(delta))/(2*a);
    auto sol2 = (-b - sqrt(delta))/(2*a);

    //Test if both sol1 and sol2 are integers
    if ((sol1 - floor(sol1) < eps) && (sol2 - floor(sol2) < eps)) return 1;
    return 0;
}

int isPalindrome_1(unsigned int i)
{
    //Based on string

    string sri; //container containing the original / reverse integer i
    //Converting the numerical number into the string expression
//    do {
//        sri += i % 10 + '0'; //ASCII Transformation
//        i /= 10;
//    }while(i > 0);
    sri = NumtoStr(i, 10);
    auto si = sri;
    reverse (sri);
    if (sri == si) return 1;
    return 0;
}

int isPalindrome_2(unsigned int i)
{
    //Based on numerical operation
    unsigned int reverse = 0;
    auto comparator = i;
    if (i < 10) return 1;
    else {
        do {
            reverse = reverse * 10 + i % 10;
            i /= 10;
        } while (i > 0);
    }
    if (reverse == comparator) return 1;
    return 0;
}

int isOdious_1(unsigned int i){
    string sbi; //The string of the binary expression of the integer i
    int count = 0;
//    Transforming the integer i into the binary expression
//    do {
//        sbi += i % 2 + '0'; //ASCII Transformation
//        i /= 2;
//    }while(i > 0);
//    reverse(sbi.begin(),sbi.end());
    sbi=NumtoStr(i,2);

//    Calculate the number of '1'
    for (i = 0; i < sbi.size(); i++){
       if (sbi[i] == '1') count += 1;
        else continue;
    }

//    Determine whether it is an odd number
    if (count % 2) return 1;
//    cout << sbi << endl;  //Test for the transformation expression
    else return 0;
}

int isOdious_2(unsigned int i){
    //Based on the bitwise operation and shifting operator

    int count = 0;
    while (i){
        if (i & 1) count += 1; //bitwise operator & compare the last digit of the binary expression of i with 1
        i >>= 1; //shifting the binary expression right by 1 digit
    }
    if (count % 2) return 1;
    else return 0;
}


int isExtravagant_1(unsigned int i){
    //The function is based on the understanding that count of the prime occurrence as the prime digits
    // Prime Factorization
    int pcount=0; //count the number of factoring prime
    auto nstr = NumtoStr(i, 10);
    for (int factor = 2; factor <= i; factor++){
        while (i != factor){
            if (i % factor == 0) {
                pcount += 1;
                i /= factor;
                continue;
            }
            else break;
        }
        if (i == factor) pcount +=1;
        else continue;
    }
    if (nstr.size() < pcount) return 1;
    else return 0;
}

int isExtravagant_2(unsigned int i){
    //The function is based on the understanding of the pure digits understanding of the prime expression
    unsigned int fcount; //count the number of factoring prime
    string sfactor; //string to restore the digits of factor
    auto nstr = NumtoStr(i, 10); //The digit of the decimal expression
    for (unsigned int factor = 2; factor <= i; factor++){
        fcount =0; //initialize pcount for every factor
        while (i != factor){
            if (i % factor == 0) {
                fcount += 1;
                i /= factor;
                continue;
            }
            else break;
        }
        if (i == factor) fcount +=1;//iterator which determines the occurrence time of the certain factor.
        if (fcount > 1) sfactor += NumtoStr(factor,10) + NumtoStr(fcount,10);
        else if(fcount == 1 ) sfactor += NumtoStr(factor,10);
        continue;
    }
    if (nstr.size() < sfactor.size()) return 1;
    else return 0;
}


int main() {
    int integer, testnum;
    int flag = 0;
    do {
        cout << "Please enter the integer and the test number: " << endl;
        cin >> integer >> testnum;
//        cout << integer << endl;
    }while(testnum < 1 || testnum > 4 || integer < 1 || integer > 10000000 + 1);
//The input range is between 1-10000000

    switch (testnum)
    {
        case 1:
            flag = isTriangle_1((unsigned int) integer);
            break;
        case 2:
            flag = isPalindrome_2((unsigned int) integer);
            break;
        case 3:
            flag = isOdious_2((unsigned int) integer);
            break;
        case 4:
            flag = isExtravagant_2((unsigned int) integer);
            break;
        default:
            break;

    }
    cout << flag << endl;
    return 0;
}