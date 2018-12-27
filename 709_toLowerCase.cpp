/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.



Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
*/

#include <string>
#include <algorithm>

using namespace std;

string toLowerCase(string str)
{
    //1. 
    //for (char &c : str)
    //{
    //    if (c >= 'A' && c <= 'Z') {
    //        c = c + 'a' - 'A';
    //    }
    //}
    //return str;

    //2.
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}