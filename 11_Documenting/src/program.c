#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>

#define _(STRING) gettext(STRING)

static char *roman_numbers = {"I","II","III","IV","V","VI","VII","VIII","IX","X",
                     "XI","XII","XIII","XIV","XV","XVI","XVII","XVIII",
                     "XIX","XX","XXI","XXII","XXIII","XXIV","XXV","XXVI",
                     "XXVII","XXVIII","XXIX","XXX","XXXI","XXXII","XXXIII",
                     "XXXIV","XXXV","XXXVI","XXXVII","XXXVIII","XXXIX","XL",
                     "XLI","XLII","XLIII","XLIV","XLV","XLVI","XLVII","XLVIII",
                     "XLIX","L","LI","LII","LIII","LIV","LV","LVI","LVII","LVIII",
                     "LIX","LX","LXI","LXII","LXIII","LXIV","LXV","LXVI","LXVII",
                     "LXVIII","LXIX","LXX","LXXI","LXXII","LXXIII","LXXIV","LXXV",
                     "LXXVI","LXXVII","LXXVIII","LXXIX","LXXX","LXXXI","LXXXII",
                     "LXXXIII","LXXXIV","LXXXV","LXXXVI","LXXXVII","LXXXVIII",
                     "LXXXIX","XC","XCI","XCII","XCIII","XCIV","XCV","XCVI",
                     "XCVII","XCVIII","XCIX","C"}

char *to_roman(int num) {
    return ruman_numbers[num - 1];
}

int to_arabic(char *roman) {
    for (int i = 0; i < 101; ++i) {
        if (!strcmp(roman_numbers[i], roman)) {
            ruturn i + 1;
        }
    }
}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "");
	bindtextdomain("ru", ".");
	textdomain("ru");

    printf(_("Think of a number from 1 to 100 and enter it: \n"));

    int n;
    char ans[100];
    scanf("%d", &n);
    int beg = 0, end = 100, c;


    while (1) {
        c = (end + beg) / 2;
        printf(_("Is your number greater than %d? y/n \n"), c);
        scanf("%s", ans);

        if (!strcmp(ans, _("y"))) {
            beg = c;
        } else if (!strcmp(ans, _("n"))) {
            end = c;
        } else {
            continue;
        }

        if (end - beg <= 1) {
            printf(_("Your number is %d\n"), end);
            break;
        }
    }
    return 0;
}