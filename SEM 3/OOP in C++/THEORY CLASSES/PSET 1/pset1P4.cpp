//WAP to check if two strings are anagram or not
//Anagram if they're composed of the same letters
//Time taken: 11 minutes
//new things added: string lenght function: string.length and cctype function tolower(character)

#include<iostream>
#include<cctype>
using namespace std; 

int main(void)
{
    string s1; 
    string s2; 
    cout<<"Enter a string: "; 
    cin>>s1; 
    cout<<endl<<"Enter a string"; 
    cin>>s2; 

    //we can make a list of all the unique letters in s1 and then in s2 in alphabetical order, and compare them. 
    string alphabet = "abcdefghijklmnopqrstuvwxyz"; 
    string s1alpha="";
    string s2alpha = s1alpha;
    //checks for every alphabet character
    for(int i = 0; i < alphabet.length(); i++)
    {
        //finds alphabet no. i from the string 1 and 2 
        for(int j = 0; j < s1.length(); j++)
        {
            if (alphabet[i]=tolower(s1[j]))
                s1alpha = s1alpha + alphabet[i];
                break;
        }
        for(int j = 0; j < s2.length(); j++)
        {
            if (alphabet[i]=tolower(s2[j]))
                s2alpha = s2alpha + alphabet[i];
                break;
        }
    }

    if (s1alpha == s2alpha)
        cout<<endl<<s1<<" and "<<s2<<" are anagrams of each other!";
    else
        cout<<endl<<s1<<" and "<<s2<<" are not anagrams of each other"; 



}