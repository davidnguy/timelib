/**
 *  David Nguyen
 *  Tag des Jahres
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

struct dateStruct { //Anlegen der Struct variable
int year;
int month;
int day;
};

int main()
{
    struct dateStruct date;
    int day;
    int month;
    int year;
    int sum_of_days = 0;
    int *pointerYear = &year;
    int *pointerMonth = &month;
    int *pointerDay = &day;

    printf("Day of the Year\n");
    inpute_date(&date.day, &date.month, &date.year);
    printf("Day of the Year: %1\n", day_of_the_year(date.day, date.month, date.year));
}

