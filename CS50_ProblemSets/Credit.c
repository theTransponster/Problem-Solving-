//This is a code to solve the problem "Credit", which is part of the Problem Set 1, 
//within the course CS50 (from Harvard Open Course ware).
//The main intention of this code is to detect if a credit card number is valid or fake, through the 
//study of long numbers. 
//For more information of the problem, go to: https://cs50.harvard.edu/x/2020/weeks/1/

#include <stdio.h>
#include <cs50.h> //This library belongs to the course 

//Functions template that are implemented after main function
long get_correct_long(void);

int getNumberOfDigits(long cardNumber);

int sumValues(int digitsArray[], int count);

string checkType(int digitsArray[], int sum, int count);


//Begin of main function
int main(void)
{
    //First ask the user for the input
    long cardNumber = get_correct_long();

    //Then, calculate the amount of digits on the card number
    int digitsCount = getNumberOfDigits(cardNumber);

    //Create an array with each digit
    int digitsArray[digitsCount];
    long number = cardNumber;

    for (int i = 0; i < digitsCount; i++)
    {
        digitsArray[i] = number % 10; //this takes the residual as digit
        number = number / 10; //this divide the long number, obtaining a new long without the last residual
    }

    //Sum digits according to Luhn's Algorithm
    int sum = sumValues(digitsArray, digitsCount);


    //Check if the number is valid and return what type of card is (VISA, AMEX...)
    string type = checkType(digitsArray, sum, digitsCount);

    //Prints the result
    printf("%s\n", type);

}
//End of the main function


//Begin of auxiliar functions 


//Function to check if the input is valid
long get_correct_long(void)
{
    long cardNumber;

    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0); //if the input has hyphens ask for another input

    return cardNumber;
}

//Function to determine the amount of digits of the long number
int getNumberOfDigits(long cardNumber)
{
    int count = 0;
    long digits = cardNumber;
    while (digits > 0)
    {
        digits = digits / 10;
        count ++;
    }
    return count;
}

//Function to sum each other value on the array (according with Luhn's Algorithm
int sumValues(int digitsArray[], int count)
{
    int sum1 = 0; //variable to store the sum of each other value (digits)
    int tmp = 0; //temporal value



    for (int i = 1; i < count; i = i + 2)
    {
        tmp = digitsArray[i] * 2;

        if (tmp < 10)
        {
            sum1 += tmp;
        }
        else
        {
            sum1 += tmp / 10;
            sum1 += tmp % 10;
        }

    }


    int sum2 = 0; // variable to store the sum of remaining values

    for (int i = 0; i < count; i = i + 2)
    {
        sum2 += digitsArray[i]; //By Luhn's rule, these values aren't multiplied by 2
    }


    int sumTot = sum1 + sum2;

    return sumTot;

}


//Function to check what type of card is and if it valid
string checkType(int digitsArray[], int sum, int count)
{
    string type = "";

    int temp = sum % 10;  //temporal variable to store the residue

    if (temp == 0 && count >= 13)
    {
        //Then is a valid card and we can proceed to further identification
        if (digitsArray[count - 1] == 4)
        {
            type = "VISA";
        }
        else if (digitsArray[count - 1] == 3 && (digitsArray[count - 2] == 7 || digitsArray[count - 2] == 4))
        {
            type = "AMEX";
        }
        else if (digitsArray[count - 1] == 5 && (digitsArray[count - 2] == 5 || digitsArray[count - 2] == 4 || digitsArray[count - 2] == 3
                 || digitsArray[count - 2] == 2 || digitsArray[count - 2] == 1))
        {
            type = "MASTERCARD";
        }
        else
        {
            type = "INVALID";
        }
    }
    else
    {
        type = "INVALID";
    }

    return type;

}
