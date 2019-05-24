#include <stdio.h>

/*Run this with pipe command in command line with | (pipe) operator.
This will feed the data from bermuda into geo2json via the output stream

run with:

(./bermuda | ./geo2json) < gpsdata.csv > output.json

You connect the programs with the pipe, this connects two processes together
as if they were one program?

so the data will be first filtered through the bermuda program and 
then put into the geo2json program. The gpsdata.csv file provides 
the data and then it flows to the output.json.

I believe this happens one line at a time so:

1) a line from gpsdata.csv is fed into bermuda.c
2) bermuda.c prints output which is received by geo2json.c
3) geo2json.c prints put which is received by output.json

Remember 


The programs run at the same time and when one produces input the other can 
take it in.
*/

int IsDataInTheBermudaTriange(float latitude, float longitude)
{
    if (latitude < 26 || latitude > 34 || longitude < -76 || longitude > -64)
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

    /*Remember you need the address operator, & to read data to the memory 
    address*/
    while (scanf("%f, %f, %79[^\n]", &latitude, &longitude, &info) == 3)
    {
        if (IsDataInTheBermudaTriange(latitude, longitude) == 0)
        {
            continue;
        }
        else
        {
            printf("%f, %f, '%s'},\n",
                   latitude, longitude, info);
        }
    }
    return 0;
}