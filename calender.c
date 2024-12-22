#include <stdio.h>

int get_first_day_of_month(int year, int month) {
    int d = 1;
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int first_day = (d + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    
    // Adjust to start week on Sunday (Zeller's formula returns 0 = Saturday)
    return (first_day + 6) % 7;
}

int days_in_month(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0;
    }
}

void print_calendar(int year, int month) {
    const char *months[] = { "", "January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December" };
    const char *days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    printf("\n   %s %d\n", months[month], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int first_day = get_first_day_of_month(year, month);
    int num_days = days_in_month(month, year);

    // Print leading spaces for the first week
    for (int i = 0; i < first_day; i++) {
        printf("     ");
    }

    // Print the days of the month
    for (int day = 1; day <= num_days; day++) {
        printf("%5d", day);
        if ((first_day + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int year, month;
    char cont;

    do {
        // Get user input for year and month
        printf("Enter year (e.g., 2024): ");
        scanf("%d", &year);
        printf("Enter month (1-12): ");
        scanf("%d", &month);

        // Print the calendar
        print_calendar(year, month);

        // Ask if user wants to view another month
        printf("Do you want to view another month? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
