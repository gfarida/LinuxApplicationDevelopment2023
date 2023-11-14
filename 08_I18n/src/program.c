#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>

#define _(STRING) gettext(STRING)

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