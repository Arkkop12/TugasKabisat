#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1; 
    else
        return 0; 
}

int daysInMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        default:
            return -1; 
    }
}

struct Date tomorrow(struct Date date) {
    struct Date nextDay;
    nextDay.day = date.day;
    nextDay.month = date.month;
    nextDay.year = date.year;
    
    if (nextDay.day == 28 && nextDay.month == 2 && isLeapYear(nextDay.year)) {
        nextDay.day = 29;
    } else if (nextDay.day == 29 && nextDay.month == 2 && !isLeapYear(nextDay.year)) {
        nextDay.day = 1;
        nextDay.month = 3;
    } else if (nextDay.day == 31 && nextDay.month == 12) {
        nextDay.day = 1;
        nextDay.month = 1;
        nextDay.year++;
    } else if (nextDay.day == daysInMonth(nextDay.month, nextDay.year)) {
        nextDay.day = 1;
        nextDay.month++;
    } else {
        nextDay.day++;
    }
    
    return nextDay;
}

int main() {
    struct Date inputDate, nextDate;
    
    printf("Masukkan tanggal yang ingin di cek: \ndd/mm/yyyy\n");
    scanf("%d/%d/%d", &inputDate.day, &inputDate.month, &inputDate.year);

    if (inputDate.day < 1 || inputDate.day > 31 || inputDate.month < 1 || inputDate.month > 12 || inputDate.year < 1) {
        printf("Input tidak valid!\n");
        return 1;
    }
    
    if (inputDate.day > daysInMonth(inputDate.month, inputDate.year)) {
        printf("Input tanggal tidak valid!\n");
        return 1;
    }
    
    nextDate = tomorrow(inputDate);
    
    printf("\nTanggal besoknya adalah: %d/%d/%d\n", nextDate.day, nextDate.month, nextDate.year);
    
    return 0;
}
