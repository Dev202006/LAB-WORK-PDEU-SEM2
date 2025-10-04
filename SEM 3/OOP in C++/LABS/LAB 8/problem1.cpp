//writea  C++ program that reads the content from a specified text file and calculates: 
//total number of characters
//total number of words
//total numver of sentences. display these counts to the console.

#include<iostream>
#include<fstream>

using namespace std; 

int main()
{
    string filename; 
    cout<<"Enter file you want to read along with .txt: ";
    cin>>filename; 

    ifstream f_word(filename);
    ifstream f_sentence(filename);
    ifstream f_char(filename);
    int count_char = 0; 
    int count_sentence =0; 
    int count_word = 0; 


    string s; 

    while(!f_word.eof())
    {
        f_word>>s; 
        count_word++; 
    }
    string sentence; 
    while(!f_sentence.eof())
    {
        getline(f_sentence , sentence);
        count_sentence++;
    }
    char c; 
    while(!f_char.eof())
    {
        f_char.get(c);
        count_char++;
    }

    f_word.close();
    f_sentence.close();
    f_char.close();

    cout<<"The character count is: "<<count_char<<endl; 
    cout<<"The word count is: "<<count_word<<endl;
    cout<<"The sentence count is: "<<count_sentence; 


}