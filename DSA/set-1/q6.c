#include <stdio.h>
#include <string.h>

void addLargeNumbers(char num1[], char num2[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    char result[maxLen + 2];
    for(int i=0;i<maxLen+1;i++){
        result[i]='0';
    }
    result[maxLen + 1] = '\0';

    int carry = 0, sum = 0;
    int i = len1 - 1, j = len2 - 1, k = maxLen;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[k] = (sum % 10) + '0';
        i--;
        j--;
        k--;
    }

    if (result[0] == '0') {
        printf("Sum: %s\n", result + 1);
    } else {
        printf("Sum: %s\n", result);
    }
}

int main() {
    char num1[1000], num2[1000];

    printf("Enter the first large number: ");
    scanf("%s", num1);

    printf("Enter the second large number: ");
    scanf("%s", num2);

    addLargeNumbers(num1, num2);

    return 0;
}
