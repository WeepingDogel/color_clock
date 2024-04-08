#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    while (1)
    {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[9];
        int r, g, b;
        // Clear output screen
        system("clear");
        // Obtain the current time
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        // Format the time as HHMMSS
        strftime(buffer, sizeof(buffer), "%H%M%S", timeinfo);
        // Parse the time as an RGB hex color
        sscanf(buffer, "%02x%02x%02x", &r, &g, &b);
        // Print the time string with the text color set to the time-based RGB value
        printf("\n");
        printf("\x1b[38;2;%d;%d;%dm #%s\x1b[0m\n", r, g, b, buffer);
        printf("\n");
        // Wait for 1 second
        sleep(1);
    }
    return 0;
}
