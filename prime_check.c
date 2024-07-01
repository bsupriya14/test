/*
    Compile: gcc -o prime_check prime_check.c -lm
    Run: ./prime_check
*/

#include <stdio.h>
#include <math.h>

// Function to determine if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; 
    if (num == 2) return 1; 
    if (num % 2 == 0) return 0; 

    // Calculate the square root of the number

    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // An integer given_number variable has been defined. 
    int given_number;

    printf("Enter an integer: "); 
    // This is the scanf to read the integer variable given_number
    scanf("%d", &given_number);
    // The conditional statement to find out given_number is prime or not prime
    if (is_prime(given_number))
        printf("The number is prime.\n");   // “The number is prime” 
    else
        printf("The number is not prime.\n");   // “The number is not prime”

    return 0;
}

// The final output will be printed once the code is executed



