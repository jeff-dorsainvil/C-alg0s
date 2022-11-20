/**
 * @author Jeff Dorsainvil
 * @brief Spliting a string using pointer.
 * @details This program asks the user for their username and password then it splits them
 * using pointer manipulation.
 * 
 * It takes the username and password as a single string in the format 'username/password'
 * 
 * EXAMPLE:
 * if the user enters 'johndoe1/w10%fOot!'
 * the program will split this string into two parts as: 
 * username: johndoe1
 * password: w10%fOot!
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Prototype for the find function, this function will find you a character in a given string. */
char *find(char *str, char query);

int main(){
    char *separator;
    char user_input[70];
    char *password;
    char *username;
    
    printf("Please login (format: username/password): ");
    fgets(user_input, sizeof(user_input), stdin);

    // Looking for '/' in the string
    separator = find(user_input, '/');

    if (separator != NULL){ // If we did find the '/'
        *separator = '\0';
        username = user_input;
        password = ++separator;

        if((isspace(*username) != 0) || (isspace(*password) != 0 )) {
            printf("Nice try! please enter actual values");

            return 8;
        }
        printf("Your username is: %s\n", username); 
        printf("Your password is: %s\n", password);
    }
    else // we couldn't find '/' in the string
        printf("Please try again!");
    
    return 0;
}

/**
 * @brief This function will find a character in a given string. 
 * it will return a pointer to the location of the character if the character was found 
 * or it will return NULL in case the character wasn't found.
 * 
 * @param str A pointer to the string you want to find the character from 
 * @param query The character you want to find
 * @return char* 
 */
char *find (char *str, char query){
    while (*str != query){
        // If we reach the end of the string
        if(*str == '\0') return NULL;   

        ++str;
    }

    // if the character was found
    return str;
}