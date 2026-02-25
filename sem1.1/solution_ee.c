#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Функция расширенного алгоритма Евклида
long long extended_gcd(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b % a, a, &x1, &y1);

    // Обновление x и y на основе результатов рекурсивного вызова
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Итеративная версия расширенного алгоритма Евклида
long long extended_gcd_iter(long long a, long long b, long long *x, long long *y) {
    long long x0 = 1, y0 = 0;
    long long x1 = 0, y1 = 1;

    while (b != 0) {
        long long q = a / b;
        long long r = a % b;

        long long x2 = x0 - q * x1;
        long long y2 = y0 - q * y1;

        a = b;
        b = r;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    *x = x0;
    *y = y0;
    return a;
}

int main() {
    long long a, b, x, y;
    printf("Введите числа a и b: ");
    scanf("%lld %lld", &a, &b);

    long long g = extended_gcd_iter(a, b, &x, &y);
    printf("НОД(%lld, %lld) = %lld\n", a, b, g);
    printf("Коэффициенты Безу: x = %lld, y = %lld\n", x, y);
    printf("Проверка: %lld*(%lld) + %lld*(%lld) = %lld\n", a, x, b, y, a * x + b * y);

    return 0;
}
