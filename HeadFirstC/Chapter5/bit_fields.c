/*C doesn't support binary literals but it supports hexadeciaml 
literals. Every time it sees an int beginning with 0x it means base 16
number.

each hexidecimal unit mathces a binary digit of length 4

bitfields let you specify how many bits an individual field will
store.


*/

//bitfields in struct
/*
    if you have a sequence of bitfields the computer can squash them
    together to save space. 8 single bitfields can be stored in a single
    byte.


    if the compiler finds a single bitfield though it may still have
    to pad out the size of a word. This is why bitfields are usually
    grouped together. It can save space if grouped on a struct.
*/
struct synth
{
    unsigned int low_pass_vcf : 1;
    unsigned int filter_coupler : 1;
    unsigned int reverb : 1;
    unsigned int sequential : 1;
};

//bitfields should always be unsigned ints
//number after the colon the number of bits field will store
struct Questionaire
{
    //can store 0 or 1
    unsigned int firstVisit : 1;
    unsigned int willReturn : 1;
    //can store 0-11
    unsigned int fingersLost : 4;
    unsigned int childLost : 1;
    //can store 0-7
    unsigned int daysAWeek : 3;
};

int main()
{
}