#include <stdio.h>

int subtractProductAndSum(int n) {
    int product = 1, sum = 0;
    
    while (n > 0) {
        int digit = n % 10;  // Get the last digit
        product *= digit;    // Multiply the product by the digit
        sum += digit;        // Add the digit to the sum
        n /= 10;             // Remove the last digit from n
    }
    
    return product - sum;  // Return the difference
}

// Example usage
int main() {
    int n1 = 234;
    int n2 = 4421;

    printf("Result for n = %d: %d\n", n1, subtractProductAndSum(n1));  // Output: 15
    printf("Result for n = %d: %d\n", n2, subtractProductAndSum(n2));  // Output: 21

    return 0;
}
