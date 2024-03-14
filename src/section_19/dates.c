#include <stdio.h>
#include <time.h>

/**
 * examples of
 * - clock
 * - time
 * - time_t
 * - ctime
 * - asctime
 * - localtime
 * - gmtime
*/
int main() {
    // Get the current calendar time
    time_t currentTime;
    time(&currentTime);

    // Convert calendar time to local time
    struct tm *localTime = localtime(&currentTime);

    // Access individual time components
    int year = localTime->tm_year + 1900; // years since 1900
    int month = localTime->tm_mon + 1;    // months since January (0-11)
    int day = localTime->tm_mday;         // day of the month (1-31)
    int hour = localTime->tm_hour;        // hours since midnight (0-23)
    int minute = localTime->tm_min;       // minutes after the hour (0-59)
    int second = localTime->tm_sec;       // seconds after the minute (0-61)

    // Print current date and time in various formats
    printf("Current date and time:\n");
    printf("Calendar time: %ld\n", currentTime);
    printf("Local time: %s", asctime(localTime));
    printf("Formatted time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
    printf("Weekday: %d\n", localTime->tm_wday);    // Sunday = 0, Monday = 1, ..., Saturday = 6
    printf("Day of year: %d\n", localTime->tm_yday); // Day of year (0-365)

    // Convert calendar time to UTC (GMT) time
    struct tm *gmtTime = gmtime(&currentTime);
    
    // Convert calendar time to a string representation
    char *localTimeString = ctime(&currentTime);

    // Convert local time struct to a string representation
    char *localTimeStringStruct = asctime(localTime);

    printf("Current time using ctime(): %s", localTimeString);
    printf("Current time using asctime() and localtime(): %s", localTimeStringStruct);
    printf("Current time using gmtime(): %s", asctime(gmtTime));


    return 0;
}