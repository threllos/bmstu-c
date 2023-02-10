#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

int main(void)
{
	setbuf(stdout, NULL);
	
	// Тест функции strpbrk
	if (strpbrk("", "") == my_strpbrk("", ""))
		printf("Test 1 strpbrk OK\n");
	else
		printf("Test 1 strpbrk not OK...\n");
	
	if (strpbrk("abcabc", "abcabc") == my_strpbrk("abcabc", "abcabc"))
		printf("Test 2 strpbrk OK\n");
	else
		printf("Test 2 strpbrk not OK...\n");
	
	if (strpbrk("abcabc", "def") == my_strpbrk("abcabc", "def"))
		printf("Test 3 strpbrk OK\n");
	else
		printf("Test 3 strpbrk not OK...\n");
		
	if (strpbrk("abcabc", "defc") == my_strpbrk("abcabc", "defc"))
		printf("Test 4 strpbrk OK\n");
	else
		printf("Test 4 strpbrk not OK...\n");
		
	if (strpbrk("abcabc", "deaf") == my_strpbrk("abcabc", "deaf"))
		printf("Test 5 strpbrk OK\n");
	else
		printf("Test 5 strpbrk not OK...\n");
		
	if (strpbrk("abcabc", "") == my_strpbrk("abcabc", ""))
		printf("Test 6 strpbrk OK\n");
	else
		printf("Test 6 strpbrk not OK...\n");
		
	if (strpbrk("", "abc") == my_strpbrk("", "abc"))
		printf("Test 7 strpbrk OK\n");
	else
		printf("Test 7 strpbrk not OK...\n");
		
	printf("\n");
	
	// Teст функции strspn
	if (strspn("", "") == my_strspn("", ""))
		printf("Test 1 strspn OK\n");
	else
		printf("Test 1 strspn not OK...\n");
	
	if (strspn("abcabc", "abcabc") == my_strspn("abcabc", "abcabc"))
		printf("Test 2 strspn OK\n");
	else
		printf("Test 2 strspn not OK...\n");
		
	if (strspn("abcabc", "def") == my_strspn("abcabc", "def"))
		printf("Test 3 strspn OK\n");
	else
		printf("Test 3 strspn not OK...\n");
		
	if (strspn("abccabc", "bc") == my_strspn("abccabc", "bc"))
		printf("Test 4 strspn OK\n");
	else
		printf("Test 4 strspn not OK...\n");
	
	if (strspn("abcabc", "") == my_strspn("abcabc", ""))
		printf("Test 5 strspn OK\n");
	else
		printf("Test 5 strspn not OK...\n");
		
	if (strspn("", "abc") == my_strspn("", "abc"))
		printf("Test 6 strspn OK\n");
	else
		printf("Test 6 strspn not OK...\n");
		
	if (strspn("abcdef", "fe") == my_strspn("abcdef", "fe"))
		printf("Test 7 strspn OK\n");
	else
		printf("Test 7 strspn not OK...\n");
		
	printf("\n");
	
	// Teст функции strcspn
	if (strcspn("", "") == my_strcspn("", ""))
		printf("Test 1 strcspn OK\n");
	else
		printf("Test 1 strcspn not OK...\n");
	
	if (strcspn("abcabc", "abcabc") == my_strcspn("abcabc", "abcabc"))
		printf("Test 2 strcspn OK\n");
	else
		printf("Test 2 strcspn not OK...\n");
		
	if (strcspn("abcabc", "def") == my_strcspn("abcabc", "def"))
		printf("Test 3 strcspn OK\n");
	else
		printf("Test 3 strcspn not OK...\n");
		
	if (strcspn("abccabc", "bc") == my_strcspn("abccabc", "bc"))
		printf("Test 4 strcspn OK\n");
	else
		printf("Test 4 strcspn not OK...\n");
	
	if (strcspn("abcabc", "") == my_strcspn("abcabc", ""))
		printf("Test 5 strcspn OK\n");
	else
		printf("Test 5 strcspn not OK...\n");
		
	if (strcspn("", "abc") == my_strcspn("", "abc"))
		printf("Test 6 strcspn OK\n");
	else
		printf("Test 6 strcspn not OK...\n");
		
	if (strcspn("abcdef", "fe") == my_strcspn("abcdef", "fe"))
		printf("Test 7 strcspn OK\n");
	else
		printf("Test 7 strcspn not OK...\n");
		
	printf("\n");
	
	// Teст функции strchr
	if (strchr("", '\0') == my_strchr("", '\0'))
		printf("Test 1 strchr OK\n");
	else
		printf("Test 1 strchr not OK...\n");
		
	if (strchr("abbc", 'a') == my_strchr("abbc", 'a'))
		printf("Test 2 strchr OK\n");
	else
		printf("Test 2 strchr not OK...\n");
		
	if (strchr("abbc", 'b') == my_strchr("abbc", 'b'))
		printf("Test 3 strchr OK\n");
	else
		printf("Test 3 strchr not OK...\n");
		
	if (strchr("abbc", 'c') == my_strchr("abbc", 'c'))
		printf("Test 4 strchr OK\n");
	else
		printf("Test 4 strchr not OK...\n");
		
	if (strchr("abbc", 'd') == my_strchr("abbc", 'd'))
		printf("Test 5 strchr OK\n");
	else
		printf("Test 5 strchr not OK...\n");
		
	if (strchr("abbc", '\0') == my_strchr("abbc", '\0'))
		printf("Test 6 strchr OK\n");
	else
		printf("Test 6 strchr not OK...\n");
		
	if (strchr("", 'a') == my_strchr("", 'a'))
		printf("Test 7 strchr OK\n");
	else
		printf("Test 7 strchr not OK...\n");
		
	printf("\n");
	
	// Teст функции strrchr
	if (strrchr("", '\0') == my_strrchr("", '\0'))
		printf("Test 1 strrchr OK\n");
	else
		printf("Test 1 strrchr not OK...\n");
		
	if (strrchr("abbc", 'a') == my_strrchr("abbc", 'a'))
		printf("Test 2 strrchr OK\n");
	else
		printf("Test 2 strrchr not OK...\n");
		
	if (strrchr("abbc", 'b') == my_strrchr("abbc", 'b'))
		printf("Test 3 strrchr OK\n");
	else
		printf("Test 3 strrchr not OK...\n");
		
	if (strrchr("abbc", 'c') == my_strrchr("abbc", 'c'))
		printf("Test 4 strrchr OK\n");
	else
		printf("Test 4 strrchr not OK...\n");
		
	if (strrchr("abbc", 'd') == my_strrchr("abbc", 'd'))
		printf("Test 5 strrchr OK\n");
	else
		printf("Test 5 strrchr not OK...\n");
		
	if (strrchr("abbc", '\0') == my_strrchr("abbc", '\0'))
		printf("Test 6 strrchr OK\n");
	else
		printf("Test 6 strrchr not OK...\n");
		
	if (strrchr("", 'a') == my_strrchr("", 'a'))
		printf("Test 7 strrchr OK\n");
	else
		printf("Test 7 strrchr not OK...\n");
		
	printf("\n");
		
	return EXIT_SUCCESS;
}