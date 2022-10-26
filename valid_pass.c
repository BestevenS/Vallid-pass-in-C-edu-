#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_password(char pwd[]);

int main() {
    char pwd[100];
    int strength;
    while(1){

        printf("\n\nEnter password: ");
        scanf("%s", pwd);

        if(strength = is_valid_password(pwd))
            break;

        if(pwd[0] == 0x0A){
            printf("fdasf");
            return 1;
        }

    }

    printf("Your password is valid and has a strength of %d", strength);

    return 0;

}

int is_valid_password(char pwd[]){

    int strength = 0;

    //a

    if(strlen(pwd) < 8){

        printf("Your password must contain be at least 8 characters");
        return 0;

    }

    //b

    // Είναι ίσα με 0 αν δεν υπάρχει καθόλου η εκάστωτε κατηγορία χαρακτήρα
    // Είναι ίσα με 1 αν υπάρχει έστω και ένας από τους χαρακτήρες της εκάστωτε κατηγορίας

    int upperC = 0;
    int lowerC = 0;
    int digitC = 0;
    int specialC = 0;

    // Μετράει πόσοι από κάθε κατηγορία χαρακτήρων υπάρχουν

    int upperCaseCounter = 0;
    int lowerCaseCounter = 0;
    int digitCounter = 0;
    int specialCharCounter = 0;

    // for που ανατρέχει σε ολόκληρο τον πίνακα χαρακτήρων(συμβολοσειρά)

    for(int i = 0; i < strlen(pwd) - 3; i++){

        printf("%i\n", pwd[i] == pwd[i + 1]);

        // printf("pwd[i] == %c, pwd[i+1] == %c, pwd[i+2] == %c, pwd[i+3] == %c \n", pwd[i], pwd[i+1], pwd[i+2], pwd[i+3]);
        // printf("\n%c == %c = %d \n", pwd[i], pwd[i+1], pwd[i] == pwd[i+1]);

        // Αν υπάρχουν περισσότερα από 3 ίδια στοιχεία στην σειρά

        if(pwd[i] == pwd[i + 1] && pwd[i] == pwd[i + 2] && pwd[i] == pwd[i + 3]){

            // printf("\n%d\n", i);

            // printf("\n%c%c%c%c%c\n", pwd[i], pwd[i+1], pwd[i+2], pwd[i+3], pwd[i+4]);

            printf("Your password is not allowed to contain more than 3 similar characters in a row");
            return strength;
        
        }

    }

    for(int i = 0; i < strlen(pwd); i++){

        //c

        for(int j = 0; j < 26; j++){
            
            if(pwd[i] == j + 65){
            
                upperC == 1;
                upperCaseCounter++;
            
            }

            if(pwd[i] == j + 97){
            
                lowerC == 1;
                lowerCaseCounter++;
            
            }

        }

        for(int j = 0; j < 10; j++){
            
            if(pwd[i] == j + 48){
            
                digitC == 1;
                digitCounter++;

            }

        }

        if(pwd[i] == '!' || pwd[i] == '@' || pwd[i] == '#' || pwd[i] == '$' || pwd[i] == '&' ||  pwd[i] == '_'){
        
            specialC == 1;
            specialCharCounter++;
        
        }

    }

    if((upperCaseCounter + lowerCaseCounter + digitCounter + specialCharCounter) < strlen(pwd)){

        printf("Your password contains invalid characters");
        return strength;

    }

    if((upperC + lowerC + digitC + specialC) < 3){
        
        printf("Your password must contain characters from at least 3 categories");
        return strength;
    
    }

    //2.

    if(strlen(pwd) == 8){
        
        strength = 10;
        return strength;
    
    }

    //3.

    for(int i = 0; i < strlen(pwd); i++){

        if(i >= 8 && (i + 1) % 4 == 0){
         
            strength += 2;

        }

        //4.

        for(int j = 0; j < strlen(pwd); j++){
            
            if(i != j && pwd[i] == pwd[j]){

                break;

            }

            else
            
                strength += 5;

        }

    }

    //5.
    
    for(int i = 0; i < strlen(pwd); i++){

        
        if((pwd[i] == pwd[i+1] == pwd[i+2]) || (pwd[i] == pwd[i+1])){

            strength -= 2;
            i += 2;

        }

    }

    //6.

    if(upperC + lowerC + digitC + specialC == 4){

        strength *= 2;

    }
        
    return strength;

}