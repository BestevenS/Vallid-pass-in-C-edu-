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

        if(strength = is_valid_password(pwd)){
            break;
        }

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

    // Αν η συμβολοσειρά είναι μικρότερη απο 8 χαρακτήρες

    if(strlen(pwd) < 8){

        printf("Your password must contain be at least 8 characters");
        return strength;

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

    // for που ανατρέχει σε ολόκληρο τον πίνακα - 3 χαρακτήρων(συμβολοσειρά)

    for(int i = 0; i < strlen(pwd) - 3; i++){

        // Αν υπάρχουν περισσότερα από 3 ίδια στοιχεία στην σειρά

        if(pwd[i] == pwd[i + 1] && pwd[i] == pwd[i + 2] && pwd[i] == pwd[i + 3]){

            printf("Your password is not allowed to contain more than 3 similar characters in a row");
            return strength;
        
        }

    }

    for(int i = 0; i < strlen(pwd); i++){

        //c

        for(int j = 0; j < 26; j++){
            

            // Αν υπάρχουν κεφαλαία γράμματα
            // Για να ξέρω αν υπάρχει κάποιος κεφαλαίος χαρακτήρας & να μετράω πόσοι υπάρχουν

            if(pwd[i] == j + 65){
            
                upperC = 1;
                upperCaseCounter++;
            
            }


            // Αν υπάρχουν πεζά γράμματα
            // Για να ξέρω αν υπάρχει κάποιος πεζός χαρακτήρας & να μετράω πόσοι υπάρχουν

            if(pwd[i] == j + 97){
            
                lowerC = 1;
                lowerCaseCounter++;
            
            }

        }

        // Αν ο χαρακτήρας ειναι αριθμός
        // Για να ξέρω αν υπάρχει κάποιος αριθμός & να μετράω πόσοι υπάρχουν

        for(int j = 0; j < 10; j++){
            
            if(pwd[i] == j + 48){
            
                digitC = 1;
                digitCounter++;

            }

        }


        // Αν ο χαρακτήρας είναι οποιοδήποτε από τους παρακάτω 
        // Για να ξέρω αν υπάρχει κάποιος ειδικός χαρακτήρας & να μετράω πόσοι υπάρχουν

        if(pwd[i] == '!' || pwd[i] == '@' || pwd[i] == '#' || pwd[i] == '$' || pwd[i] == '&' ||  pwd[i] == '_'){
        
            specialC = 1;
            specialCharCounter++;
        
        }

    }


    // Αν υπάρχει χαρακτήρας που δεν ανήκει σε καμία κατηγορία

    if((upperCaseCounter + lowerCaseCounter + digitCounter + specialCharCounter) < strlen(pwd)){

        printf("Your password contains invalid characters");
        return strength;

    }


    // Αν υπάρχουν τουλάχιστον 1 από τουλάχιστον 3/4 κατηγορίες χαρακτήρων

    if((upperC + lowerC + digitC + specialC) < 3){
        
        printf("Your password must contain characters from at least 3 categories");
        return strength;
    
    }

    //2.
    

    // Αν είναι μεγέθους 8 χαρακτήρων

    if(strlen(pwd) >= 8){
        
        strength += 10;
    
    }

    //3.


    // for ανατρλέχει σε ολόκληρη τη συμβολοσειρά

    for(int i = 0; i < strlen(pwd); i++){

        // Για κάθε επιπλέον τέσσερις χαρακτήρες, η ισχύς του συνθηματικού αυξάνεται κατά 2

        if(i >= 8 && (i + 1) % 4 == 0){

            strength += 2;
            
        }
    }

    //4.

    // Ανατρέχει σε ολόκληρη τη συμβολοσειρά

    for(int i = 0; i < strlen(pwd); i++){

        // for ανατρέχει σε ολόκληρο τον πίνακα

        for(int j = 0; j < strlen(pwd); j++){
            

            // Αν i == j να μην ελέγξει γιατί θα ειναι το ίδιο στοιχείο
            // Αν οι χαρακτήρες είναι ίδιοι σταμάτα την επανάληψη
            
            if(i != j && pwd[i] == pwd[j]){

                break;

            }


            // Αν είμαστε την τελευταία επανάληψη και δεν έχει τρέξει η εντολή break σημαίνει
            // Είμαστε βέβαιοι πως ο χαρακτήρας δεν έχει ξαναγραφεί σε άλλο σημείο του πίνακα
            // Μπορούμε να του δώσουμε + 5 στην ισχύς του συνθηματικού

            if(j == strlen(pwd) - 1 && i == strlen(pwd) - 1){

                strength += 5;

            }

        }

    }

    //5.


    // Ανατρέχει σε ολόκληρη τη συμβολοσειρά
    
    for(int i = 0; i < strlen(pwd); i++){

        // Αν ο χαρακτήρας θέσης i είναι είναι ίσος με τους δύο επόμενους ή
        // μόνο με τον επόμενο χαρακτήρα

        // ((pwd[i] == pwd[i+1]) && (pwd[i] == pwd[i+2])) || (pwd[i] == pwd[i+1])
        // => Απλοποίηση σε (pwd[i] == pwd[i+1])
        
        if(pwd[i] == pwd[i+1]){

            strength -= 2;
            
            i += 2;         
            // Μετακίνηση του i κατά 2 θέσεις, επειδή ξερω πως ο 
            // επόμενος χαρακτήρας είναι ίδιος δεν το συγκρινω με 
            // τον επόμενο του, γιατί θα το αποτέλεσμα θα είναι ίδιο

        }

    }

    //6.


    // Αν έχει τουλάχιστον 1 χαρακτήρα και από τις 4 κατηγοριες

    if(upperC + lowerC + digitC + specialC == 4){

        strength *= 2;

    }
        
    return strength;

}