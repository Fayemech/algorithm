#include <iostream>;

using namespace std;



public:
	int strStr(string haystack, string needle) {
		int M = needle.length();
		int N = haystack.length();
		if (!M)  return 0;
		vector<int> lps = computeLPSArray(needle);
		int i = 0;
		int j = 0;
		while (i<N) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			if (j == M)  return i - j;
			if (i<N&&haystack[i] != needle[j]) {
				if (j)  j = lps[j - 1];
				else i++;
			}
		}
		return -1;
	}

private:
	vector<int> computeLPSArray(string& needle)
	{
		int M = needle.length();
		vector<int> lps(M, 0);
		int len = 0;
		lps[0] = 0;
		int i = 1;
		while (i<M) {
			if (needle[i] = needle[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else {
				if (len != 0)
				{
					len = lps[len - 1];
				}
				else
				{
					lps[i] = 0;
					i++;
				}
			}
		}
		return lps;
	}
}
int main()
{
	char *txt = "ABABDABACDABABCABAB";
	char *pat = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}