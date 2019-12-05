#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string shift(string text);
string argv2;

int main(int argc, string argv[])
{
    if (argc != 2) //Checks that there are exactly 2 arguments
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    argv2 = argv[1];  //converting argv[1] to a variable makes it easier to use if being used often
    for (int j = 0; j < strlen(argv2); j++)
    {
        if (isalpha(argv2[j]) == 0)  //Check that user inputted corrected usage requirements (alphabet)
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }        
    }
    string plaintext = get_string("plaintext: "); //Gets plaintext to be ciphered
    string ciphertext = shift(plaintext); //Calls function shift
    printf("ciphertext: %s\n", ciphertext);
        
}


string shift(string text)
{
    int j = 0;
    string cipher = "";
    cipher = malloc(strlen(argv2) + 1); //Assigns appropriate amount of memeroy allocation
    while (j < strlen(text))
    {
        if (isalpha(text[j]) == 0)
        {
            printf("%c\n", text[j]);
            strncat(cipher, &text[j], 1);
            j++;
            continue;
        }
        else
        {
            for (int i = 0; i < strlen(argv2); i++)
            {
                char c = argv2[i];
                c = tolower(c);
                int key = c - 'a'; //Turns the alphabetical key to a numerical one (starts at a = 0)
                char cipher_test = text[j];
                for (int test = 0; test < key; test++)
                {
                    if (cipher_test == 'z')
                    {
                        cipher_test = 'a';
                    }
                    else if (cipher_test == 'Z')
                    {
                        cipher_test = 'A';
                    }
                    else
                    {
                        cipher_test = cipher_test + 1; 
                    }
                }
                strncat(cipher, &cipher_test, 1); //Appends the ciphered character to the overall message
                j++;
            }
            
        }
            
    }
    return cipher;
}





