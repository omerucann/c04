#include <stdio.h>

int ft_atoi(char *str) {
    int n = 0;
    int sign = 1;
    int valid_input = 0; // Geçerli rakam bulunduğunu belirten flag

    // Boşlukları atla
    while (*str == ' ')
        str++;

    // İşaret kontrolü
    while (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -sign; // İşaret değişkenini negatif yap
        str++;
    }

    // Rakamları işle
    while (*str >= '0' && *str <= '9') {
        n = n * 10 + (*str - '0');
        str++;
        valid_input = 1; // En az bir rakam işlendi
    }

    // Geçersiz karakterler için kontrol
    if (!valid_input)
        return 0; // Geçersiz bir giriş durumunda 0 döndür

    // İşareti uygula
    return sign * n;
}

int main() {
    char str[] = "---+--+1234ab567";
    int result = ft_atoi(str);
    printf("String '%s' nin tamsayı değeri: %d\n", str, result);
    return 0;
}
