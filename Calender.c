#include <stdio.h>

int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *month_name[] = {
    " ",
    "\n\n\nJanuary",
    "\n\nFebruary",
    "\n\nMarch",
    "\n\nApril",
    "\n\nMay",
    "\n\nJune",
    "\n\nJuly",
    "\n\nAugust",
    "\n\nSeptember",
    "\n\nOctober",
    "\n\nNovember",
    "\n\nDecember"
};


int get_first_daycode(int year) {
    int daycode;
    int x, y, z;
    
    x = (year - 1) / 4;
    y = (year - 1) / 100;
    z = (year - 1) / 400;
    daycode = (year + x - y + z) % 7;
    return daycode;
}


int determineleapyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
        month_days[2] = 29; 
        return 1; 
    } else {
        printf("%d is not a leap year.\n", year);
        month_days[2] = 28; 
        return 0; 
    }
}


void print_calendar(int year, int daycode) {
    int month, day;
    for (month = 1; month <= 12; month++) {
        printf("%s, %d", month_name[month], year);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        
        
        for (day = 1; day <= 1 + daycode * 5; day++) {
            printf(" ");
        }
        
        
        for (day = 1; day <= month_days[month]; day++) {
            printf("%2d", day);
            if ((day + daycode) % 7 > 0) // Not Saturday
                printf("   ");
            else // Saturday
                printf("\n ");
        }
        daycode = (daycode + month_days[month]) % 7; 
    }
}

int main(void) {
    int year, daycode, leapyear;
    
    printf("Please Enter a Year: ");
    scanf("%d", &year);
    daycode = get_first_daycode(year);
    determineleapyear(year);
    print_calendar(year, daycode);
    printf("\n");
    return 0;
}