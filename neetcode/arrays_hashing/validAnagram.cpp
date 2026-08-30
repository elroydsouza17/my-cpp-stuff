#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t);

int main()
{
    std::string str1 = "cat";
    std::string str2 = "art";
    
    std::cout << isAnagram(str1, str2) << std::endl;

    return 0;
}


bool isAnagram(std::string s, std::string t) {

    // First check if size of strings match if not directly return since they can't be anagrams
        if(s.size() != t.size()) return false;        

        // Hashmaps for storing chars and their counts in each string so space complexity is O(n) + O(n) worst case
        std::unordered_map<char,int> hashMapS;
        std::unordered_map<char,int> hashMapT;


        // for every element insert the value in hashmap , if already present increment count, if not set count to 1; O(n)
        for (int i = 0; i < s.size(); i++)
        {
            auto result = hashMapS.insert({s[i], 1});
            if(result.second == false)
            {
                hashMapS[s[i]]++;
            }
        }

        // same thing for other string O(n)
        for (int i = 0; i < t.size(); i++)
        {
            auto result = hashMapT.insert({t[i], 1});
            if(result.second == false)
            {
                hashMapT[t[i]]++;
            }
        }

        // compare hashvalues of both , if they're are equal string is an anagram O(n)
        for (auto [key, val]: hashMapS)
        {
            if(hashMapS[key] != hashMapT[key])
            {
                return false;
            }
        }

        // Time complexity is O(n) + O(n) + O(n) = O(3n)

        return true;

    }