#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void high_add(const char *x, const char *y, char *result) {
    char x_int[410] = {0}, x_dec[410] = {0};
    char y_int[410] = {0}, y_dec[410] = {0};
    sscanf(x, "%[^.].%s", x_int, x_dec); 
    sscanf(y, "%[^.].%s", y_int, y_dec); 
    int x_dec_len = strlen(x_dec), y_dec_len = strlen(y_dec);
    int max_dec_len = x_dec_len > y_dec_len ? x_dec_len : y_dec_len;
    while (strlen(x_dec) < max_dec_len) strcat(x_dec, "0");
    while (strlen(y_dec) < max_dec_len) strcat(y_dec, "0");
    char dec_sum[410] = {0};
    int carry = 0, i;
    for (i = max_dec_len - 1; i >= 0; i--) {
        int sum = (x_dec[i] - '0') + (y_dec[i] - '0') + carry;
        dec_sum[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(x_int);
    reverse(y_int);
    int x_int_len = strlen(x_int), y_int_len = strlen(y_int);
    int max_int_len = x_int_len > y_int_len ? x_int_len : y_int_len;
    char int_sum[410] = {0};
    for (i = 0; i < max_int_len; i++) {
        int a = i < x_int_len ? (x_int[i] - '0') : 0;
        int b = i < y_int_len ? (y_int[i] - '0') : 0;
        int sum = a + b + carry;
        int_sum[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) int_sum[i++] = carry + '0';

    int_sum[i] = '\0';
    reverse(int_sum);
    int dec_len = strlen(dec_sum);
    while (dec_len > 0 && dec_sum[dec_len - 1] == '0') dec_sum[--dec_len] = '\0';
    if (dec_len > 0) {
        sprintf(result, "%s.%s", int_sum, dec_sum);
    } else {
        sprintf(result, "%s", int_sum);
    }
}

int main() {
    char x[410], y[410];
    char result[820];
    while (scanf("%s %s", x, y) != EOF) {
        if (!strchr(x, '.')) strcat(x, ".0");
        if (!strchr(y, '.')) strcat(y, ".0");

        high_add(x, y, result);
        printf("%s\n", result);
    }
    return 0;
}