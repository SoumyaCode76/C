#define Q1                      (0)
#define Q2                      (0)
#define Q3                      (1)

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#if (Q1 == 1)
void print_duplicates(string);

int main(void)
{
    string test = "";
    while(true)
    {
        cout << "Enter string: (Enter q or Q to quit)" << endl;
        while(!(cin >> test));
        if( test.length() == 1 && ((test == "q" ) || (test == "Q")) )
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if(test.length() == 0)
        {
            cout << "Empty string detected! Please try again!" << endl;
            continue;
        }
        print_duplicates(test);
    }    
    return 0;
}

void print_duplicates(string s)
{
    unsigned int length = s.length();
    unsigned int count = 0;
    unsigned int freq[256] = {0};
    unsigned int freq_size = (int *)(&freq + 1) - (int *)&freq;
    for(unsigned int i = 0; i < length; i++)
    {
        freq[static_cast<int>(s[i])] += 1;
    }
    string frequency_output = "";
    for(unsigned int i = 0; i < freq_size; i++)
    {
        if(freq[i] > 1)
        {
            frequency_output += static_cast<char>(i);
        }
    }
    if(frequency_output.length() == 0)
    {
        cout << "No duplicates found in " << s;
    }
    else
    {
        cout << "Duplicates found in " << s << ": " << frequency_output;
    }
    cout << endl;
}

#elif (Q2 == 1)
int main(void)
{
    while(true)
    {
        string input = "";
        char ch_in = 0;
        cout << "Enter the string and the character to search for: (Enter q or Q to quit)" << endl;
        while(!(cin >> input));
        if(input.length() == 1 && (input == "q" || input == "Q"))
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if(input.length() == 0)
        {
            cout << "No string received. Please try again!" << endl;
            continue;
        }
        else
        {
            while(!(cin >> ch_in));            
            bool found = false;
            for(int i = 0; i < input.length(); i++)
            {
                if(input[i] == ch_in)
                {
                    cout << "Found " << ch_in << " in " << input << " at: " << (i + 1) << "th position" << endl;
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                cout << "Character " << ch_in << " not found in " << input << endl;
            }
        }
    }
}
#elif (Q3 == 1)
string ToLowerCase(string input)
{
    for(int i = 0; i < input.length(); i++)
    {
        int ch = static_cast<int>(input[i]);
        if(ch >= 65 && ch <= 90)
        {
            input[i] = static_cast<char>(ch + 32);
        }
    }
    return input;
}

void print_vowels_consonants(const string& input)
{
    int no_of_vowels = 0, no_of_consonants = 0;
    string input_lowercase = ToLowerCase(input);
    int no_of_alphabets_found[26] = {0};
    for(int i = 0; i < input_lowercase.length(); i++)
    {
        int ch = static_cast<int>(input_lowercase[i]);
        if(ch >= 97 && ch <= 122)
        {
            /* The following check can be used to limit the output to distinct characters */
            if(no_of_alphabets_found[static_cast<int>(input_lowercase[i])] >= 0)            
            {
                if(input_lowercase[i] == 'a' || input_lowercase[i] == 'e' || input_lowercase[i] == 'i' || input_lowercase[i] == 'o' || input_lowercase[i] == 'u')
                {
                    no_of_vowels += 1;
                }
                else
                {
                    no_of_consonants += 1;
                }
                no_of_alphabets_found[static_cast<int>(input_lowercase[i])] += 1;
            }
        }
    }
    cout << "Number of vowels in " << input << " is: " << no_of_vowels << endl; 
    cout << "Number of consonants in " << input << " is: " << no_of_consonants << endl;
}

int main(void)
{
    while(true)
    {
        string input = "";
        cout << "\nEnter the string: " << endl;
        while(!(cin >> input));
        if(input.length() == 1 && (input == "q" || input == "Q"))
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if(input.empty() == true)
        {
            cout << "No string received. Please try again!" << endl;
            continue;
        }
        else
        {
            print_vowels_consonants(input);
        }
    }
}
#endif