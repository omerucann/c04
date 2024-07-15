#include <stdio.h>

// Verilen karakterin tabanda bulunup bulunmadığını kontrol eder
int ft_in_base(char c, char *base) {
    for (int i = 0; base[i] != '\0'; i++) {
        if (c == base[i]) {
            return i;
        }
    }
    return -1;
}

// Tabanın uzunluğunu ve geçerliliğini kontrol eder
int ft_baselen(char *base) {
    int size = 0;
    while (base[size] != '\0') {
        if (base[size] == '+' || base[size] == '-' || base[size] == ' ' ||
            ft_in_base(base[size], base + size + 1) >= 0 ||
            (base[size] >= 9 && base[size] <= 13)) {
            return 0; // Geçersiz karakter veya tekrarlanan karakter varsa
        }
        size++;
    }
    return (size >= 2) ? size : 0; // Tabanın uzunluğunu döndürür, geçersizse 0 döndürür
}

// Verilen stringi belirtilen tabanda tamsayıya dönüştürür
int ft_atoi_base(char *str, char *base) {
    int size;
    int n = 0;
    int negative = 0;

    // Taban uzunluğunu kontrol eder
    if ((size = ft_baselen(base)) < 2) {
        return 0; // Geçersiz taban
    }

    // Boşlukları ve işaretleri atlar
    while ((*str >= 9 && *str <= 13) || *str == ' ') {
        str++;
    }

    // İşaretleri kontrol eder
    while (*str == '-' || *str == '+') {
        if (*str++ == '-') {
            negative = 1 - negative;
        }
    }

    // Her karakteri tabandaki bir sayıya dönüştürür
    while (ft_in_base(*str, base) >= 0) {
        n = n * size + ft_in_base(*str++, base);
    }

    // Negatif işarete göre sonucu işaretler
    return (negative) ? -n : n;
}

int main() {
    char *str = "1010";
    char *base = "01";
    int result = ft_atoi_base(str, base);
    printf("Result: %d\n", result); // Sonucu ekrana yazdırır
    return 0;
}
