#ifndef FUNKTIONEN_H_INCLUDED
#define FUNKTIONEN_H_INCLUDED

int day_of_the_year(struct dateStruct date) // Funktion zur berechnung der Tage
{
  for(int i = date.month - 2; i >= 0; i--)
   {
       sum_of_days += days_per_month[i];
   }
   // Tage des aktuell angegebenen Monats.
   sum_of_days += date.day;

   // Ausgabe.
   printf("Das Jahr hat bereits %i Tage", sum_of_days);
   return 0;

}

int is_leapyear(struct dateStruct date) // Funktion zur überprüfung des Schaltjahres
{
    if(date.year >= 1582 || date.year > 2400) //Prüft, ob das eingegebene Jahr gleich oder über 1582 oder unter 2400 liegt.
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

int exists_date(struct dateStruct date) // Funktion zur überprüfung des Eingegebenes Datums
{
    if(is_leapyear(date.year) == -1) // Überprüfung des gültigen Jahres
    {
        printf("Ungültiges Jahr");
        return 0;
    }
    else
    {
        return 1;
    }

    if(date.month <= 0 || date.month > 12) // Überprüfung des gültigen Monats
    {
        printf("Ungültiger Monat");
        return 0;
    }
    else
    {
        return 1;
    }

    if(date.day <= 0 || date.day > get_days_for_month(date.month, date.year)) // Überprüfung des gültigen Tags
    {
        printf("Ungültiger Tag");
        return 0;
    }
     else
    {
        return 1;
    }
}

int get_days_for_month(struct dateStruct date) // Funktion für die bestimmung des Monats eines gegebenen Jahres
{
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; // Tage pro Monate mit ein Array definiert
    if(is_leapyear(date.year) == 1)  // Überprüft ob es ein Schaltjahr ist
    {
        days_per_month[1] = 29; // Wenn es ein Schaltjahr ist werden die Tage vom Februar auf 29 gesetzt
    }

    if(date.month > 12 || date.month < 1 || is_leapyear == -1) //Wird überprüft ob ein ungültiger monat eingegeben wurde
    {
        return -1;
    }
    else
    {
        return days_per_month[month + 1]; // Gibt den Indexwert des Arrays zurück
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

        if(exists_date(InputDate) != 1)  // Überprüft das eingegebene Datum
        {
            printf("Input is not a valid date.\n\n\n");
        }
    }
    while(exists_date(InputDate) != 1); // Bei einem ungültigen Datum soll es erneut eingelesen werden

    return InputDate;
}

#endif // FUNKTIONEN_H_INCLUDED
