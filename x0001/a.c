/*
C - Stack of C Exp
License    : GNU GPL v3 or later
Author     : Aurélien DESBRIERES
Mail       : aurelien@hackers.camp
Project    : Programming C Exp
Created on : Monday October 9 2017

Write with Emacs-Nox ──────────────────────────┐
C - a ─────────────────────────────────────────┘

using gcc -std=c11 -Wall -g -o a a.c
c11 oblige the use of setenv / putenv declaration rather than gnu11
*/

#include <stdio.h>                                          // man stdio I/O library functions
#include <limits.h>                                         // determines various properties of various variables
#include <stdlib.h>                                         // environment variable - standard library definitions

#define height 100                                          // Constants definition
#define number 3.14
#define letter 'A'
#define letter_sequence "ABC"
#define backslash_char '\?'

int total = 0;
int sum (int, int);

void tester();
//void test();int m = 22, n = 44;                           // Variables
//int a = 50, b = 80;

// Main function
int main(int argc, char *argv[])
{
    printf("Fucking Hell!\n");                              // Because it must be said!

    // How to print different type of characters, strings, and values
    char ch = 'A';
    char str[42] = "One day no one will make me piss anymore!";  // Just the perfect primer char sentence
    float flt = 10.234;
    int no = 150;
    double dbl = 20.123456;


    // C <stdio> specification area of different type of string, characters and much more
    printf("Character is %c \n", ch);
    printf("\n\t\t\t%s \n\n", str);
    printf("Float value is %f \n", flt);
    printf("Integer value is %d \n", no);
    printf("Double value is %lf \n", dbl);
    printf("Octal value is %o\n", no);
    printf("Hexadecimal value is %x \n", no);

    total = sum (1, 1);                                     // Calculus made from defined function I
    printf("Total is: %d\n", total);

    char ICE_CUBE;                                          // Scanf to read characters from keyboard
    printf("Enter any character \n");
    scanf("%c", &ICE_CUBE);                                 // '&'<word> for consecutive characters ' '<word> for string
    printf("So: %c \nIs what you mean \n", ICE_CUBE);

    char HAIL_STONE[42];                                    // Scanf > 42
    printf("Enter any string ( upto 42 characters ) \n");
    scanf("%s", HAIL_STONE);                                // &str for string
    printf("So: %s \nIs what you mean \n", HAIL_STONE);


    // enum example
    enum MONTH { Jan = 0, Feb, Mar };
    enum MONTH month = Mar;
    if(month == 0)
	printf("Value of Jan \n");
    else if(month == 1)
	printf("Month is Feb \n");
    if(month == 2)
	printf("Month is Mar \n");


    // Tokens example
    int x, y, total;
    x = 10, y = 20;
    total = x + y;
    printf ("Total = %d \n", total);

    printf("Value of height : %d \n", height );             // constant
    printf("Value of number : %f \n", number );
    printf("Value of letter : %c \n", letter );
    printf("Value of letter_sequence : %s \n", letter_sequence );
    printf("Value of backslach_char : %c \n", backslash_char );


    // C <limit> specifications
    int z;
    char b;
    float c;
    double d;
    printf("Storage size of int data type: %ld \n", sizeof(z));   // %ld is for long int
    printf("Storage size of char data type: %ld \n", sizeof(b));
    printf("Storage size of float data type: %ld \n", sizeof(c));
    printf("Storage size of double data type: %ld \n", sizeof(d));


    // Variables
    int m = 22, n = 44;
    /* m, n are local variables of main function
       m and n variables are having scope
       within this main function only.
       These are not visible to test function.

       If you try to access a and b in this function,
       you will get 'a' undeclared and 'b' undeclared error
    */
    printf("\nvalues : m = %d and n = %d\n", m, n);
    tester();                                               // swith to test part of the code

    int setenv();                                           // must be declared from c11 version
    printf("Directory = %s\n", getenv("DIR"));              // stdlib.h standard library definitions
    setenv("FILE", "/usr/bin/a.c", 50);                     // introduce to setenv, getenv
    printf("File = %s\n", getenv("FILE"));


    // must be declared from c11 version
    int putenv();
    printf("Directory name after modifying = %s\n", getenv("DIR"));
    putenv("DIR=/usr/home/");
    printf("Directory name after modifying = %s\n", getenv("DIR"));

    setenv("FILE", "/usr/bin/a.c", 42);
    printf("File = %s\n", getenv("FILE"));


    // A bit of Arithmetic
    int o=40,p=20,add,sub,mul,div,mod;
    add = o + p;
    sub = o - p;
    mul = o * p;
    div = o / p;
    mod = o % p;
    printf("Addition of o, p, is : %d\n", add);
    printf("Substraction of o, p is: %d\n", sub);
    printf("Multiplication of o, p is : %d\n", mul);
    printf("Division of o, p is : %d\n", div);
    printf("Modulus of o, p is : %d\n", mod);


    // Compound Operator
    int Total = 0, i;
    for( i = 0; i < 10; i++){
	Total += i;
    }
    printf("Total = %d\n", Total);


    // Relational Operator
    int e = 40, f = 20;
    if (e == f){
	printf("e and f are equal");
    } else {
	printf("e and f are not equal");
    }


    // Logical Operator
    int q = 40, r = 20;
    int s = 20, t = 30;
    if (q > r && q != 0){
	printf("&& Operator : Both conditions are true\n");
    }
    if ( s > t || t != 20 ){
	printf("|| Operator : Only one condition is true\n");
    }
    if (! ( q > r && q != 0 )){
	printf("! Operator : Both conditions are true\n" \
	       "But, status is inverted as false\n");
    }


    // Bit wise Operator
    int l = 40, j = 80, AND_opr, OR_opr, XOR_opr, NOT_opr;
    AND_opr = ( l & j );
    OR_opr  = ( l | j );
    NOT_opr = ( ~ l );
    XOR_opr = ( l ^ j );
    printf("AND_opr value = %d\n", AND_opr);
    printf("OR_opr value = %d\n", OR_opr);
    printf("NOT_opr value = %d\n", NOT_opr);
    printf("XOR_opr value = %d\n", XOR_opr);
    printf("left_shift value = %d\n", l << 1);
    printf("right_shift value = %d\n", l >> 1);


    // Conditional / ternary operators
    int xy = 1, yx;
    yx = ( xy == 1 ? 2 : 0 );
    printf("xy value is %d\n", xy);
    printf("yx value is %d\n", yx);


    // Increment & Decrement operator
    int za = 1;
    while ( za < 10 ) {
	printf("%d\n", za);
	za ++ ;
    }


    // Decrement operator
    int az = 10;
    while ( -- az > 0 ) {
	printf("%d\n", az);
    }

    int *rtp, zq;
    zq = 50;
    // Address of zq is assigned to rtp
    rtp = &zq;
    // Display q's value using rtp variable
    printf("%d\n", *rtp);


    // Special operator
    int ab;
    char bc;
    float ac;
    double ad;
    printf("Storage sizte for int data type: %ld\n", sizeof (ab));
    printf("Storage size for char data type: %ld\n", sizeof (bc));
    printf("Storage size for float data type: %ld\n", sizeof (ac));
    printf("Storage size for double data type: %ld\n", sizeof (ad));


    // if else and nested if
    int mn = 40, nm= 40;
    if (mn == nm) {
	printf("mn and nm are equal\n");
    }

    int mo = 40, om = 20;
    if (mo == om) {
	printf("mo and om are equal\n");
    } else {
	printf("mo and om are not equal\n");
    }

    int op = 40, po = 20;
    if (op > po) {
	printf("op is greater than po\n");
    } else if (op < po) {
	printf("op is less than po\n");
    } else {
	printf("op is equal to po\n");
    }


    // Loop control statements
    int in;
    for (in = 0; in < 10; in++) {
	printf("%d ", in);
	}
    printf("\n");

    int ni = 3;
    while (ni < 10) {
	printf("%d ", ni);
	ni++;
    }
    printf("\n");

    int on = 1;
    do {
	printf("Value of on is %d\n", on);
	on++;
    } while (on <= 4 && on >= 2);


    // Statements
    int value = 3;
    switch(value)
    {
      case 1:
      printf("Value is 1 \n" );
      break;

      case 2:
      printf("Value is 2 \n" );
      break;

      case 3:
      printf("Value is 3 \n" );
      break;

      case 4:
      printf("Value is 4 \n" );
      break;

      default :
      printf("Value is other than 1,2,3,4 \n" );
    }

    int wo;
    for(wo=0;wo<10;wo++) {
	if(wo==5) {
	     printf("\nComing out for loop when wo = 5\n");
	     break;
	} printf("%d ", wo);
    }


    // Exit
    printf("Hit Enter to exit\n");
    // Stand from keyboard
    getchar();

    return 0;
}

void tester()
{
    int a = 50, b = 80;
    /* a, b are local variables of test functions
       a and b variables are having scope
       within this test function only.
       These are not visible to main function.
       If you try to access m and n in this function,
       you will get 'm' undeclared and 'n' undeclared
       error
    */
    printf("\nvalues : a = %d and b = %d\n", a, b);
}


// Defined function I
int sum (int a, int b)
{
    return a + b;
}
