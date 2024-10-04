#include <stdio.h>

int gcd(int number1, int number2) {
    if (number2 != 0)
        return gcd(number2, number1 % number2);
    else
        return number1;
}
int main() {
    int number1, number2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &number1, &number2);
    printf("GCD: %d",gcd(number1, number2));
    return 0;
}

