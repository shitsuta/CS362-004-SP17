char inputChar()
{
    return ' ' + (rand() % 94);
}

char *inputString()
{
	char singleChar;
    static char strArr[6];
	
	int i;
	for (i = 0; i < 5; i++){
		strArr[i] = 'a' + (rand() % 26);
	}
	strArr[5] = '\0';
    return strArr;
}

To correctly implement inputChar(), I had to make sure that the characters generated were within
the ASCII range to include '[', '(', '{', ' ', 'a', 'x', '}', ')', and ']' so that 'state' would
be able to increase by 1 to arrive at 9. This range begins at the ' ' character and spans 94 
characters total, so I had the function return a random value within that range.

To correctly implement *inputString(), I had to make sure that the string generated included the
ASCII lowercase letters.  This range begins at the 'a' character and spans 26 characters total,
so I had the function return a random value within that range.

The 8 tests that I ran generated the 'reset' string after the following iterations:

18,440,015
 3,337,146
 1,397,001
   920,358
11,290,486
 1,708,183
23,757,381
13,528,541