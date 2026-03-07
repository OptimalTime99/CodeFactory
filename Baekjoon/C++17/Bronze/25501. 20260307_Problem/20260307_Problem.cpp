#include <iostream>
#include <cstring>

int count = 0;

int recursion(const char *s, int left, int right)
{
	count++;
    
	if (left >= right) return 1;
    else if (s[left] != s[right]) return 0;
    else return recursion(s, left + 1, right - 1);
}

int isPalindrome(const char *s)
{
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

	int T;
    char s[1001];
    std::cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
    	std::cin >> s;
        
        count = 0;
        
        int result = isPalindrome(s);
        
    	std::cout << result << " " << count << "\n";
    }
    
    return 0;
}