//
// Created by jinzh on 2019/5/21.
//
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

//Done
int Triangle(const int *num){
    int x = *num;
    int n = 0;
    n = int(sqrt(2*x));
    if(2*x == n*(n+1)){
        return 1;
    }
    else
        return 0;
}

//Done
int Palindrome(const int *num){
    int x = *num;
    int m,n = 0;
    m = x;
    while(m>0){
        n = n * 10 + m % 10;
        m = m / 10;
    }
    if(x == n){
        return 1;
    }
    else
        return 0;
}

//Done
int Odious(const int *num){
    int n = *num;
    int count = 0;
    while (n != 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    if (count % 2 == 1){
        return 1;
    }
    else
        return 0;
}

int NumOfDig(const int * num){
    int x = *num;
    int count = 0;
    while(x > 0){
        x = x / 10;
        count = count + 1;
    }
    return count;
}

int Extravagant(const int *num){
    int x = *num;
    int Digits = NumOfDig(num);
    int exp = 0;
    int save_factor = 0;
    int NumDigits = 0;
    int FactorDigits = 0;
    if (*num < 2){
        return 0;
    }
    else{
        for (int i = 2; i <= sqrt(*num); i++){
            if (x % i == 0){
                    x = x / i;
                    exp++;
                    if (save_factor != i){
                        NumDigits++;
                        save_factor = i;
                    }
                    i--;
            }
            else{
                FactorDigits = FactorDigits + NumOfDig(&exp);
                exp = 0;
            }
        }
    }
//    cout << "Digits are: " << Digits << endl;
//    cout << "Factorization Digits are: "<< NumDigits + FactorDigits << endl;
    if (Digits < (NumDigits + FactorDigits)){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    int a, b;
    int flag = 0;
    do {
        cout << "Please enter the integer and the test number: ";
        cin >> a >> b;
        if (a <= 10000000 && a >= 0) {
            switch(b) {
                case 1:
                    cout << Triangle(&a) << endl; break;
                case 2:
                    cout << Palindrome(&a) << endl; break;
                case 3:
                    cout << Odious(&a) << endl; break;
                case 4:
                    cout << Extravagant(&a) << endl; break;
                default:
                    break;
            }
            break;
        }
    } while (flag == 0);
    return 0;
}