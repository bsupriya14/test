/*
I Baba Avinash Puppala declare that I have completed this assignment
completely and entirely on my own, without any consultation with
others. I have read the UAB Academic Honor Code and understand
that any breach of the Honor Code may result in severe
penalties.

Student signature/initials: bpuppala
Date: 16 June 2024
*/


// Question 1
#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to find the nearest prime number below a given number and check if it's a power of 2
int nearestPrimeBelowAndPowerOfTwo(int n, int *isPowerOfTwo) {
    *isPowerOfTwo = (n && !(n & (n - 1)));
    for (int i = n - 1; i > 1; --i) {
        if (isPrime(i)) return i;
    }
    return 2; // the smallest prime number
}

// Function to calculate the sum of digits of a number
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void numberTransformer(int n) {
    if (n % 3 == 0 && n % 5 == 0) {
        printf("UAB CS 332&532\n");
    } else if (isPrime(n) && n != 3 && n != 5) {
        printf("Go Blazers\n");
    } else {
        int isPower;
        int nearestPrime = nearestPrimeBelowAndPowerOfTwo(n, &isPower);
        if (isPower) {
            printf("%d\n", n + nearestPrime);
        } else if (sumOfDigits(n) % 3 == 0) {
            printf("CS\n");
        } else {
            int sum = sumOfDigits(n);
            printf("%d\n", sum * sum);
        }
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    numberTransformer(n);

    return 0;
}




// Question 2
#include <stdio.h>
#include <stdbool.h>

bool UABNumber() {
    int n2, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &n2);

    // Find positive divisors and sum them up, excluding the number itself
    for (int i = 1; i < n2; i++) {
        if (n2 % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of divisors equals the number
    if (sum == n2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Call the UABNumber function and print the result
    bool result = UABNumber();
    if (result) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}






// Question 3

#include <stdio.h>

int reverseNum(int n3) {
    int reversed = 0;

    while (n3 != 0) {
        reversed = reversed * 10 + n3 % 10;
        n3 = n3 / 10;
    }

    return reversed;
}

int main() {
    int n3;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n3);
    
    int result = reverseNum(n3);
    printf("Reversed number: %d\n", result);
    
    return 0;
}






// Question 4
#include <stdio.h>

// Function to count the number of integers smaller than their index
int smallerThanIndex(int* numbers) {
    int count = 0;
    int index = 0;
    
    // Traverse the array using a pointer until the end marker is found
    while (numbers[index] != -1) {
        if (numbers[index] < index) {
            count++;
        }
        index++;
    }
    
    return count;
}

int main() {
    int numbers1[] = {10, 20, 1, 2, 30, -1};
    printf("Result: %d\n", smallerThanIndex(numbers1)); // Expected Output: 2
    
    int numbers2[] = {1, 2, 0, 44, 29, 309, -1};
    printf("Result: %d\n", smallerThanIndex(numbers2)); // Expected Output: 1
    
    int numbers3[] = {-4, -3, 2, 1, 0, -1};            // Expected Output: 4
    printf("Result: %d\n", smallerThanIndex(numbers3)); 

    int numbers4[] = {5, 3, 8, 6, 1, -1};
    printf("Result: %d\n", smallerThanIndex(numbers4)); // Expected Output: 1

    int numbers5[] = {0, 2, 4, 1, 3, -1};                   // Expected Output: 2
    printf("Result: %d\n", smallerThanIndex(numbers5)); 

    int numbers6[] = {3, 2, 1, 0, -1};                  // Expected Output: 2
    printf("Result: %d\n", smallerThanIndex(numbers6)); 

    int numbers7[] = {7, 6, 5, 4, 3, 2, 1, 0, -1};
    printf("Result: %d\n", smallerThanIndex(numbers7)); // Expected Output: 4

    return 0;
}






// Question 5
#include <stdio.h>
#include <limits.h>

void arrayDetails(int arr[], int size) {
    int count = size;
    int min = INT_MAX;
    int minIndex = 0;
    int max = INT_MIN;
    int maxIndex = 0;
    float sum = 0;
    
    for (int i = 0; i < size; i++) {
        // Find minimum value and its index
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        // Find maximum value and its index
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
        // Calculate sum
        sum += arr[i];
    }
    
    // Calculate mean
    float mean = sum / count;
    
    // Print results
    printf("[");
    printf("%d, ", count);
    printf("%d, ", min);
    printf("%d, ", minIndex);
    printf("%.2f, ", mean);
    printf("%d, ", max);
    printf("%d", maxIndex);
    printf("]\n");
}

int main() {
    int arr1[] = {-8, -23, 18, 103, 0, 1, -4, 631, 3, -41, 5}; // Expected Output: [11, -41, 9, 62.27, 631, 7]
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    arrayDetails(arr1, size1);
    
    int arr2[] = {100, -50, 200, -150, 300};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);     // Expected Output: [5, -150, 3, 80.00, 300, 4]
    arrayDetails(arr2, size2);
    
    int arr3[] = {10};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);    // Expected Output: 1, 10, 0, 10.00, 10, 0]
    arrayDetails(arr3, size3);
    
    int arr4[] = {5, -5, 5, -5, 5};          // Expected Output: [5, -5, 1, 1.00, 5, 0]
    int size4 = sizeof(arr4) / sizeof(arr4[0]);                 
    arrayDetails(arr4, size4);
    
    int arr5[] = {2, 2, 2, 2, 2};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);     // Expected Output:[5, 2, 0, 2.00, 2, 0]
    arrayDetails(arr5, size5);
    
    return 0;
}
