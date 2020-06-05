//Solution of the problem 'Substitution' from the Problem Set 2 of the CS50 Harvard OpenCourseWare
//For more information on the problem, go to: https://cs50.harvard.edu/x/2020/psets/2/substitution/

//This a program that implements a substitution cipher.
//In other words, encrypt a message by replacing every letter with another letter using a key.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h> //This library belongs to the course


//Function declared after main
string encrypt(string plainText, string key);


//Begin of the main function
int main(int argc, string argv[]) //In this case we will receive an argument or input from the terminal
{
    //First, make sure that the user type a valid key: 
    string key = "";


    //check if the user typed just one key (string of characters without space)
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26) //is the string equal to 26? (considering 26 alphabet letters)
        {
            int check = 0; // will be used as a flag to check if the input is valid
            string input = argv[1]; //take the string typed by the user
            int rep = 0; //will be useful to validate is each letter is unique
            for (int i = 0; i < 26; i++)
            {
                //check if each character is a letter
                if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
                {
                    //check if each character is a new letter (not been introduced before)
                    if (input[i] > 0)
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if (input[i] == input[j])
                            {
                                rep = 1; //indicates that the letter has been introduced before
                                break;
                            }
                        }
                    }
                    if (rep == 1) //send a message to the user to change the input
                    {
                        printf("Key must contain 26 different alphabetic characters.\n");
                        check = 1;
                        break;
                    }
                }
                //If at least one character is not a letter, send a message to the user
                else
                {
                    printf("Key must contain 26 alphabetic characters.\n");
                    check = 1;
                    break;
                }
            }
            //If is a valid input, take it as the key
            if (check == 0)
            {
                key = argv[1];
            }
            //If something went wrong during validation (the above for), main will return a 1
            else
            {
                return 1;
            }
        }
        //If the string lenght is less than 26, send a message to the user
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    //If there is no input or if it has spaces between characters, send a message to the user
    else
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    //Ask the user to input the plaintext message that wish to encrypt
    string plainText = get_string("plaintext: ");

    //Encyrpt the message
    string newText = encrypt(plainText, key);
    printf("ciphertext: %s\n", newText);
    return 0;

}
//End of main function


//Begin of functions declaration



//Function to convert the plain text

char *encrypt(string plainText, string key)
{
    char alphabet[27] = {'A', 'B', 'C', 'D',
                         'E', 'F', 'G', 'H',
                         'I', 'J', 'K', 'L',
                         'M', 'N', 'O', 'P',
                         'Q', 'R', 'S', 'T',
                         'U', 'V', 'W', 'X',
                         'Y', 'Z', '\0'
                        };

    int length = strlen(plainText);
    int pos = 0; //this variable will be useful to identify the place of each letter of the plain text on the alphabet
    char *newText = malloc(length + 1); //creates a char array that can be returned at the end of the function

    for (int i = 0; i < length; i++)
    {
        //Check if the character is a letter or a sign (, ! ...), if is a letter procced to convert
        if ((plainText[i] >= 'a' && plainText[i] <= 'z') || (plainText[i] >= 'A' && plainText[i] <= 'Z'))
        {
            for (int j = 0; j < 26; j++)
            {
                //transform to upper case to make comparison easier (toupper() and tolower() are functions of the <cytpe.h>
                if (toupper(plainText[i]) == alphabet[j])
                {
                    pos = j;
                    break;
                }
            }
            //check if the input plain text is in lower case, if so, conserve the same format
            if (plainText[i] >= 'a' && plainText[i] <= 'z')
            {
                newText[i] = tolower(key[pos]);
            }
            else
            {
                newText[i] = toupper(key[pos]);
            }
            pos = 0;
        }
        //If the character is a punctuation sign, just pass it to the new text
        else
        {
            newText[i] = plainText[i];
        }
    }
    newText[length + 1] = '\0'; //terminates the char array
    return newText;
}


//End of the code
