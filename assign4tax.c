//Aliyah Khan
//COP 3223
//Assignment 4
//4-9-2021

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define TOTAL_EMPLOYEES 20
#define MAX_LEN 30
#define MAX_FILENAME_LEN 50

char clockFile[MAX_FILENAME_LEN];
char w2File[MAX_FILENAME_LEN];

struct employee
{
    char first[MAX_LEN];
    char last[MAX_LEN];
    double payperhr;
    double gross;
    double taxes;
    double hours_in_week;
    double netpay;
    int weeklyMinutes;
};
struct employee arrEmployees[TOTAL_EMPLOYEES];


//getting the file names from the user for getting and saving data
void promptUserForFile()
{
    char fileName[MAX_FILENAME_LEN];

    printf("What file would you like to open? ");
    scanf("%s", fileName);
    strcpy(clockFile, fileName);

}

void promptUserForW2File()
{
    char fileName[MAX_FILENAME_LEN];

    printf("What file name would you like to save data? ");
    scanf("%s", fileName);
    strcpy(w2File, fileName);

}


struct employee getEmployee(char line[255])
{
    struct employee emp;
    char *first;
    char *last;
    char *hourly;
    int x = 0;
    char *lineDetail = strtok(line, " ");
    while(lineDetail != NULL)
    {
        if (x == 0)
        {
            first = lineDetail;
        }
        else if (x == 1)
        {
            last = lineDetail;
        }
        else if (x == 2)
        {
            hourly = lineDetail;
        }

        lineDetail = strtok(NULL, " ");
        x++;
    }

    double hourlyConv = (double)atof(hourly);
    strcpy(emp.first, first);
    strcpy(emp.last, last);
    emp.payperhr = hourlyConv;
    emp.gross =0;
    emp.taxes =0;
    emp.hours_in_week =0;
    emp.netpay=0;
    emp.weeklyMinutes=0;
    return emp;

}

void getDailyWork(char line[255])
{
    char *first;
    char *last;
    int *clockInHour;
    int *clockInMin;
    int *clockOutHour;
    int *clockOutMin;
    int x = 0;
    char *lineDetail = strtok(line, " ");
    while(lineDetail != NULL)
    {
        if (x == 0)
        {
            last = lineDetail;
        }
        else if (x == 1)
        {
            first = lineDetail;
        }
        else if (x == 2)
        {
            clockInHour = atoi(lineDetail);
        }
        else if (x == 3)
        {
            clockInMin = atoi(lineDetail);
        }
        else if (x == 4)
        {
            clockOutHour = atoi(lineDetail);
        }
        else if (x == 5)
        {
            clockOutMin = atoi(lineDetail);
        }

        lineDetail = strtok(NULL, " ");
        x++;
    }
    getHoursTotal(first, last, clockInHour, clockInMin, clockOutHour, clockOutMin);

}

void getHoursTotal(char *first, char *last, int *clockInHour, int *clockInMin, int *clockOutHour, int *clockOutMin)
{
    double totalValue=0;
    int clockHourDiff =0;
    int clockMinDiff =0;
    clockHourDiff = (int)(clockOutHour) - (int)(clockInHour);
    clockMinDiff = abs((int)(clockOutMin) - (int)(clockInMin));
    int totalWeeklyMinutes = ((clockHourDiff * 60) + clockMinDiff);

    employeeTime(first, last, totalWeeklyMinutes);

}
void employeeTime(char *first, char *last, int minutes)
{
    char firstName;

    for(int i=0; i<TOTAL_EMPLOYEES; i++)
    {
        if ((strcmp(arrEmployees[i].first, first)==0)&& (strcmp(arrEmployees[i].last, last)==0))
        {
            arrEmployees[i].weeklyMinutes = ((int)arrEmployees[i].weeklyMinutes) + minutes;
            break;
        }
    }

}
int isNumeric(const char *str)
{
    while(*str != '\0' && *str != '\n' && *str != '\r')
    {
        if(*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}
int DoWeeklyCheck(char line[255])
{
    int isNewWeek =0;
    isNewWeek = isNumeric(line);
    return isNewWeek;
}
double getOverTimePayRate(double regularPay)
{
    double ot = regularPay * 1.5;
    return ot;
}
double getTotalWeeklyHours(int totalMinutes)
{
    double hours = (totalMinutes / 60);
    return hours;
}

double getTotalWeeklyOvertimeHours(double hours)
{
    double OThours = 0;

    if (hours > 40)
    {
        OThours = (hours - 40);
    }
    return OThours;
}

double getTotalWeeklyRegularTaxes(double regularGross)
{
    double regularTaxes = (regularGross * 0.10);
    return regularTaxes;
}

double getTotalWeeklyOvertimeTaxes(double OTgross)
{
    double OTtax = (OTgross * 0.20);
    return OTtax;
}


void calculateWeeklyPay()
{
    int hours, minutes, salary, overtimeNormalHrs, hoursWorked;
    double overTimeHourlyPayRate;
    double totalWeeklyHours;
    double totalWeeklyOvertimeHours;
    double totalWeeklyRegularTaxes;
    double totalWeeklyOvertimeTaxes;
    double totalWeeklyRegularGross;
    double totalWeeklyOTGross;


    for(int i=0; i<TOTAL_EMPLOYEES; i++)
    {
        overTimeHourlyPayRate =0;
        totalWeeklyHours =0;
        totalWeeklyOvertimeHours =0;
        totalWeeklyRegularTaxes =0;
        totalWeeklyOvertimeTaxes =0;
        totalWeeklyRegularGross =0;
        totalWeeklyOTGross =0;

        overTimeHourlyPayRate = getOverTimePayRate(arrEmployees[i].payperhr);
        totalWeeklyHours = getTotalWeeklyHours(arrEmployees[i].weeklyMinutes);
        totalWeeklyOvertimeHours = getTotalWeeklyOvertimeHours(totalWeeklyHours);


        if (totalWeeklyOvertimeHours <= 0)
        {
            totalWeeklyRegularGross = (totalWeeklyHours * arrEmployees[i].payperhr);
            totalWeeklyRegularTaxes = getTotalWeeklyRegularTaxes(totalWeeklyRegularGross );
        }
        else
        {
            totalWeeklyRegularGross = (40 * arrEmployees[i].payperhr);
            totalWeeklyOTGross = (totalWeeklyOvertimeHours * overTimeHourlyPayRate);
            totalWeeklyRegularTaxes = getTotalWeeklyRegularTaxes(totalWeeklyRegularGross );
            totalWeeklyOvertimeTaxes = getTotalWeeklyOvertimeTaxes(totalWeeklyOTGross);
        }
        arrEmployees[i].gross =  (arrEmployees[i].gross + (totalWeeklyRegularGross + totalWeeklyOTGross));
        arrEmployees[i].taxes =  (arrEmployees[i].taxes + (totalWeeklyRegularTaxes + totalWeeklyOvertimeTaxes));
        arrEmployees[i].hours_in_week =  (arrEmployees[i].hours_in_week + (totalWeeklyHours));
        arrEmployees[i].weeklyMinutes =0;
    }
}

void writeW2(int totalEmployees)
{
    FILE *ofp;
    ofp = fopen(w2File, "w");

    fprintf(ofp,"Number of Employees: %d", totalEmployees);
    fprintf(ofp,"\n\n");

    for(int i=0; i<totalEmployees; i++)
    {
        fprintf(ofp,"W2 Form\n");
        fprintf(ofp,"-------\n");
        fprintf(ofp,"Name: %s\ %s \n", arrEmployees[i].first, arrEmployees[i].last);
        fprintf(ofp,"Gross Pay: %.2lf \n", arrEmployees[i].gross);
        fprintf(ofp,"Taxed Withheld: %.2lf \n", arrEmployees[i].taxes);
        fprintf(ofp,"Net Pay: %.2lf \n", (arrEmployees[i].gross -arrEmployees[i].taxes));
        fprintf(ofp,"\n \n");
    }
    fclose(ofp);
}

int main ()
{
    struct employee emp;
    int linesInFile;
    int lineLength = 255;
    char line[lineLength];
    int totalEmployees = 0;
    int lineCounter = 0;
    int totalWeeks =0;
    int employeeCounter =0;
    int weeklyClockIns =0;

    FILE *ifp;

    promptUserForFile();
    promptUserForW2File();

    ifp = fopen(clockFile, "r");

    while(fgets(line, lineLength, ifp) )
    {
        if (lineCounter == 0)
        {
            // Retrieve total employees from line.
            totalEmployees = atoi(line);
        }
        else if(lineCounter <=totalEmployees)
        {
            // Retrieve each employees from file then parse.
            emp = getEmployee(line);

            // Add each employee to employee array.
            arrEmployees[employeeCounter] =emp;
            employeeCounter++;
        }
        else if ((totalEmployees + 1)==lineCounter)
        {
            // Retrieve total weeks from line.
            totalWeeks = atoi(line);

        }
        else if ((totalEmployees + 2)==lineCounter)
        {
            // Retrieve total weekly employee clockins.
            weeklyClockIns = atoi(line);

        }
        else if ((totalEmployees + 3)==lineCounter)
        {
            // Process first weekly data.
            getDailyWork(line);

        }
        else
        {
            int isNewWeek = DoWeeklyCheck(line);
            if (isNewWeek ==1)
            {
                //Make calculations for salary.
                calculateWeeklyPay();
            }
            else
            {
                // Process all other weeks.
                getDailyWork(line);
            }


        }
        lineCounter++;
    }
    // Closing file.
    fclose(ifp);
    calculateWeeklyPay();
    // Write W2 for everyone..
    writeW2(totalEmployees);
    return 0;
}
