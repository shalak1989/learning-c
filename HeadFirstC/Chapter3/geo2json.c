#include <stdio.h>

/*

see https://askubuntu.com/questions/172982/what-is-the-difference-between-redirection-and-pipe
for a good explanation

Use the < (input) operator in command line to redirect the input of
geo2json to to a file called output.json. This will read in 
info from gpsdata.csv into the geo2json program.

Then you can use the > (output) operator in command line to redirect
the std output of geo2json to the file output.json

So basically the flow will go: read gpsdata.csv into geo2json, then
print the outout to output.json.

I believe this will occur one line at a time. This is because 
in this program "print" is the output. Traditionally print would just
display to the screen. Using the > operator though we can redirect 
"print" to a file.

So the final command to run in command line is:

./geo2json < gpsdata.csv > output.json
*/

/* can also run by combining with bermuda.c:

()./geo2json | ./bermuda)< gpsdata.csv > output.json

****Effectively you can reuse geo2json.c as a small tool that other small
tools can consume. Read Chapter 3 more for further understanding.

read comments in bermuda.c for more details

NOTE:
Piped programs run at the same time and when one produces output the other can 
take it in.

Pipe is used to pass output to another program or utility.

Redirect is used to pass output to either a file or stream.

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