#include <stdio.h>

/*Run this with redirection in command line with < (output) operator, 
so ./geo2json < gpsdata.csv

Use the > (input) operator in command line to redirect the input
to a file called output.json. This will read in info from gpsdata.csv
into the file output.json

./geo2json < gpsdata.csv > output.json
*/

/* can also run by combining with bermuda.c:

****Effectively you can reuse geo2json.c as a small tool that other small
tools can consume. Read Chapter 3 more for further understanding.

read comments in bermuda.c for more details

NOTE:
Piped programs run at the same time and when one produces output the other can 
take it in.
*/

int ValidateLatitudeLongitude(float latitude, float longitude)
{
    //latitude -90.000000 to 90.000000, longitude -180.000000, 180.000000
    //precision needs to be kept to 6 dig,
    if (latitude < -90.000000 || latitude > 90.000000 || longitude < -180.000000 || longitude > 180.000000)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    float latitude = 0.00;
    float longitude = 0.00;
    char info[80];

    puts("data=[");
    //Remember you need the address operator, & to read data to the memory address
    while (scanf("%f, %f, %79[^\n]", &latitude, &longitude, &info) == 3)
    {
        if (ValidateLatitudeLongitude(latitude, longitude) == 0)
        {
            //using fprintf and feeding in stderr lets errors go to console instead
            //of the file, I prefer errors in the file so I will use stdout
            fprintf(stdout, "{Invalid latitude: %f, Invalid longitude: %f, info: '%s'},\n",
                   latitude, longitude, info);
        }
        else
        {
            printf("{latitude: %f, longitude: %f, info: '%s'},\n",
                   latitude, longitude, info);
        }
    }
    puts("\n]");
    return 0;
}