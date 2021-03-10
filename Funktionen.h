#ifndef FUNKTIONEN_H_INCLUDED
#define FUNKTIONEN_H_INCLUDED
/**
*
*   David Nguyen
*   Tag des Jahres
*
**/

int day_of_the_year(struct dateStruct date) // Funktion zur Berechnung der Tage
{
    if (exists_date(date.year,date.month,date.day) == 1)    //Pr�ft ob dieses Datum existiert
    {
        for(int i=1; i < date.month; i++)
        {
            sum_of_days += get_days_for_month(date.year, i); // Addiert den Tag f�r jeden Monat
        }
        sum_of_days += date.day; // Addiert die Tage vom aktuellen Monat
        return sum_of_days;

    }
}

int is_leapyear(struct dateStruct date) // Funktion zur �berpr�fung des Schaltjahres
{
    if(date.year >= 1582 || date.year > 2400) //Pr�ft, ob das eingegebene Jahr gleich oder �ber 1582 oder unter 2400 liegt.
    {
        if (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

int exists_date(struct dateStruct date) // Funktion zur �berpr�fung des Eingegebenes Datums
{
    if(is_leapyear(date.year) == -1) // �berpr�fung des g�ltigen Jahres
    {
        printf("Ung�ltiges Jahr");
        return 0;
    }
    else
    {
        return 1;
    }

    if(date.month <= 0 || date.month > 12) // �berpr�fung des g�ltigen Monats
    {
        printf("Ung�ltiger Monat");
        return 0;
    }
    else
    {
        return 1;
    }

    if(date.day <= 0 || date.day > get_days_for_month(date.month, date.year)) // �berpr�fung des g�ltigen Tags
    {
        printf("Ung�ltiger Tag");
        return 0;
    }
     else
    {
        return 1;
    }
}

int get_days_for_month(struct dateStruct date) // Funktion f�r die bestimmung des Monats eines gegebenen Jahres
{
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; // Tage pro Monate mit ein Array definiert
    if(is_leapyear(date.year) == 1)  // �berpr�ft ob es ein Schaltjahr ist
    {
        days_per_month[1] = 29; // Wenn es ein Schaltjahr ist werden die Tage vom Februar auf 29 gesetzt
    }

    if(date.month > 12 || date.month < 1 || is_leapyear == -1) //Wird �berpr�ft ob ein ung�ltiger monat eingegeben wurde
    {
        return -1;
    }
    else
    {
        return days_per_month[month + 1]; // Gibt den Indexwert des Arrays zur�ck
    }
}

void inpute_date(dateStruct) // Funktion der Eingabe von Jahr,Monat und Tag
{
    struct dateStruct InputDate;

    do
    {
        printf("Enter Year: "); // Eingabe des Jahr
        scanf("%i", InputDate.year);
        printf("Enter Month: ");
        scanf("%i", InputDate.month); // Eingabe des Monat
        printf("Enter Day: ");
        scanf("%i", InputDate.day); // Eingabe des Tag
        printf("\n");

        if(exists_date(InputDate) != 1)  // �berpr�ft das eingegebene Datum
        {
            printf("Input is not a valid date.\n\n\n");
        }
    }
    while(exists_date(InputDate) != 1); // Bei einem ung�ltigen Datum soll es erneut eingelesen werden

    return InputDate;
}

#endif // FUNKTIONEN_H_INCLUDED
