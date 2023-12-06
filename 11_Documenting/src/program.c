/** @mainpage Number guesser program
 * 
 */
/** @page Number guesser program
 * Program uses binary search to guess number from 1 to 100.
 *
 * Options:
 *  -r          Use Roman numbers instead of Arabic
 *  --help      Help for Number guesser program
 *
 */

/** @file program.c
 * Implementation
 * 
 * This program prompts the user to input a number 
 * between 1 and 100. Subsequently, it employs the 
 * binary search algorithm to locate this number within the range.

 *The binary search method works by continuously dividing the search
 * interval in half. It starts by defining a range of values 
 *(in this case, between 1 and 100) and checks the middle element. 
 *If the middle element matches the input number, the search concludes. 
 *Otherwise, it narrows the search range based on whether the input 
 *number is greater or smaller than the middle element. 
 *This process continues until the number is found or until 
 *the search interval becomes empty.
*/


#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>
#include <stdbool.h>

#define _(STRING) gettext(STRING)

//! Help message
void help() {
    printf(_("Usage: ./program [OPTIONS]\n"));
    printf(_("Options:\n"));
    printf(_("  -r        Use Roman numbers instead of Arabic\n"));
    printf(_("  --help    Help for Number guesser program\n\n"));
}


//! Roman numbers from 1 to 100
char *roman_numbers[] = {"I","II","III","IV","V","VI","VII","VIII","IX","X",
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
                     "XCVII","XCVIII","XCIX","C"};


/** Convert Arabic number @p num to Roman.
 *
 * @param num Arabic number
 * @return corresponding Roman number
 */
char *to_roman(int num) {
    return roman_numbers[num - 1];
}


/** Convert Roman number @p roman to Arabic.
 *
 * @param roman Roman number
 * @return corresponding Arabic number
 */
int to_arabic(char *roman) {
    printf("%s\n", roman);
    for (int i = 0; i < 101; ++i) {
        if (!strcmp(roman_numbers[i], roman)) {
            printf("%s\n", roman);
            return i + 1;
        }
    }
}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "");
	bindtextdomain("ru", ".");
	textdomain("ru");

    bool flag = true;

    if (argc == 2) {
        if (!strcmp(argv[1], "-r")) {
            flag = false;
        } else if (!strcmp(argv[1], "--help")) {
            
            return 0;
        }
    }

    if (flag) {
        printf(_("Think of a number from 1 to 100 and enter it: \n"));
    } else{
        printf(_("Think of a number from %s to %s and enter it: \n"), to_roman(1), to_roman(100));
    }

    int n;
    char ans[100];
    scanf("%d", &n);
    int beg = 0, end = 100, c;


    while (1) {
        c = (end + beg) / 2;

        if (flag) {
            printf(_("Is your number greater than %d? y/n \n"), c);
        } else {
            printf("%s\n", to_roman(c));
            printf(_("Is your number greater than %s? y/n \n"), to_roman(c));

        }

        scanf("%s", ans);

        if (!strcmp(ans, _("y"))) {
            beg = c;
        } else if (!strcmp(ans, _("n"))) {
            end = c;
        } else {
            continue;
        }

        if (end - beg <= 1) {
            if (flag) {
                printf(_("Your number is %d\n"), end);
            } else {
                printf(_("Your number is %s\n"), to_roman(end));
            }
            break;
        }
    }
    return 0;
}