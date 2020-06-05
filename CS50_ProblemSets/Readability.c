//Solution to the problem "Readability" from the Problem Set 2 of the CS50 Harvard OpenCourseWare 
//For more information of the problem go to: https://cs50.harvard.edu/x/2020/psets/2/readability/

//Readability test by Coleman-Liau index
//formula is: index = 0.0588 * L - 0.296 * S - 15.8
//L is the average number of letters per 100 words in the text
//S is the avergae number of sentences per 100 words in the text

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h> //This is a course library
#include <math.h>


//Functions that are described after main
int countCharacters(string text);
int countWords(string text);
int countSentences(string text);
int getGrade(int letters, int words, int sentences);


//Begin of the main function
int main(void)
{
    //First ask the user for an input
    string text = get_string("Text: ");

    //Count number of characters
    int letters = countCharacters(text);

    //Count number of words
    int words = countWords(text);

    //Count number of sentences
    int sentences = countSentences(text);

    //Obtain the grade based on the Coleman-Liau index
    int grade = getGrade(letters, words, sentences);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}
//End of the main function


//Begin of functions

//Function to count characters
int countCharacters(string text)
{
    //Obtain the string lenght with the function strlen() form the <string.h> library
    int length = strlen(text);

    //Declare a variable to count the a-z and A-Z characters
    int count = 0;

    for (int i = 0, n = length; i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count ++;
        }
    }
    return count;
}

//Function to count words
int countWords(string text)
{
    int countW = 1;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (text[i] != '\0' && text[i] == ' ')
        {
            countW++;
        }
    }
    return countW;
}


//Function to count sentences
int countSentences(string text)
{
    int countS = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            countS++;
        }
    }
    return countS;
}

//Function to obtain the grade
int getGrade(int letters, int words, int sentences)
{
    int grade;
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    grade = (int) round(index);


    return grade;
}

//End of code
