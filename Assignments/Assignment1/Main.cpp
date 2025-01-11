#include <iostream> //C++
#include <stdio.h> //C
#include <vector> //Vector

using namespace std;

/*
Input
the input to the function/method consists of an
argument - inputList, a list of characters
representing the sequence of shots.

Output
Return a list of integers representing the length of each scene, in the order in which it
appears in the given sequence of shots.

Examples:
example 1:
input :
inputList = [a,b,a,b,c,b,a,c,a,d,e,f,e,g,d,e,h,i,j,h,k,l,i,j]
output:
[9,7,8]

Explanation:
the first scene consists of the shots a,b and c.
the second scene consists of d,e,f and g.
finally, the last scene consists of h,i,j,k and l.
the answer is 9,7,8 because a,b, and c only appear in the
first 9 characters, then d,e,f, and g appear in the next 7.
the final 8 characters consist entirely of h,i,j,k, and l.

example 2:
input:
inputList=[a,b,c]
output:
[1,1,1]

explanation:
because there are no recurring shots, all shots can be in
the minimal length 1 scene.

example 3
input:
inputList =[a,b,c,a]
output:
[4]
explanation:
because 'a' appears more than once, everything between the first and last appearance of 'a' must be in the same list.

Testcase 1:
[a,b,c,d,a,e,f,g,h,i,j,e]

expected return values:
5 7

Testcase 2:
input:
[z,w,c,b,z,c,h,f,i,h,i]

expected return values:
6 5

*/



int main()
{

    string i;    //user input variable

    cout << "Enter the input sequence :\n\n";
    cin >> i;
    cout << "\nThe sequence is : [ ";
    vector<char> input(i.begin(), i.end());    //turning the string into a vector of char

    for (const char& c : input)
    {        //print the vector
        cout << c << " ";
    }
    //cout << "]\n";

    //int sequenceStart = 0; //first letter of the sequence
    //int sequenceEnd = 0; //last letter of the sequence
    //int next = 0;    //next scans the next letter of the vector
    //int sequenceLength; //the number of char in one sequence
    //int inputLength = input.size(); //the number of char in the vector
    //cout << "\n[";
    //do
    //{
    //    do
    //    {
    //        for (int i = next; i < inputLength; i++)
    //        {
    //            if (input[i] == input[sequenceStart]) //if the letter at position 'i' is the same as the letter at position of the beginning of the sequence
    //            {   
    //                //if current letter is the same as the 
    //                sequenceEnd = i + 1;                    //one at the start of the sequence it becomes the end of the sequence
    //                                                        //**should be comparing it to "next" instead**
    //                
    //            }
    //        }
    //        if (next != sequenceEnd)
    //        {        //if the scanned letter is not the last letter of the sequence    
    //            next++;                        //scans next letter in the current sequence
    //        }
    //    } while (next != sequenceEnd);
    //    sequenceLength = sequenceEnd - sequenceStart; //the number of char in one sequence

    //    cout << " " << sequenceLength;
    //    sequenceStart = sequenceEnd;    //start of the sequence changes after the previous end of sequence
    //    next = sequenceEnd;                //starts scanning the letter after the previous end of sequence
    //} while (next != inputLength);        //loops until it scans the last letter of the vector
    //cout << " ]" << endl;

    int count{ 0 }; //number of char in a sequence
    int current{ 0 }; //current index 
    int sequenceStart{ 0 }; //the index where the sequence starts
    int sequenceEnd{ 0 }; //the index where the sequence ends
    int next{ 0 }; //the number next to the char considered as the end of a sequence

    vector<char>sequencetemp; //vector to store current sequence

    // [z, w, c, b, z, c, h, f, i, h, i] 6 5 
    for (int i = current; i < input.size(); i++) 
    {
        if (input[i] == input[sequenceStart]) //if we find the same char as the char beginning the sequence
        {
            for (int j = 0; j < i; j++)
            {
                sequencetemp.push_back(input[j]);
                count++;
            }
            
            sequenceEnd = i; //the index where the sequence ends is equal to the current index
            if (sequencetemp.empty()) //if the vector is empty
            {
                count = i + 1; //count equals to the number of the current index + 1
            }

            for (const char& ch : sequencetemp) //going through the vector
            {
                //starting from the next index after where the sequence ends
                //j is smaller than the size of the vector input - (current index +1)
                for (int j = sequenceEnd + 1; j < (input.size() - j); j++) 
                {
                    if (input[j] == ch) //if we find other char matching the ones in the vector 
                    {
                        count++; //we increment the count
                        sequenceEnd++; //since the count as increased, the end of the sequence will also change
                    }
                }
            }
        }
    }

    

    cout << sequenceStart << endl;
    cout << sequenceEnd << endl;
    cout << count << endl;
    cout << current << endl;
    for (const char& ch: sequencetemp)
    {        //print the vector
        cout << ch << " ";
    }
    cout << endl;

    


    return 0;
};