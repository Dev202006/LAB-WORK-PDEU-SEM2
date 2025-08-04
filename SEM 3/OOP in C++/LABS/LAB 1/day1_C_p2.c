//Scan a sentence from the user and find: number of vowels, consonants and words

#include<stdio.h>
#include<string.h>

void main(void)
{
    char vowels[] = "aeiouAEIOU"; 
    char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWYZ"; 
    char sentence[100]; 
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int vcount=0; 
    int ccount = 0; 
    int wcount = 0; 

    for(int i = 0; sentence[i] != '\0'; i++)
    {
        //word count
        if(sentence[i]== ' ')
            wcount +=1; 
        else
        {
            //vowel count
            for(int j = 0; j<strlen(vowels); j++)
            {
                if (sentence[i]==vowels[j])
                {
                    vcount = vcount +1; 
                    break;
                }

            }
            // consonant count
            for(int j = 0; j<strlen(consonants); j++)
            {
                if (sentence[i]==consonants[j])
                {
                    ccount = ccount +1; 
                    break;
                }

            }

        }
    }

    // printing result
    printf("The total number of vowels is %d\nThe total number of consonants is %d\nThe total number of words is %d",vcount,ccount,wcount+1);

}
