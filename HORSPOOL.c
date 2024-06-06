#include <stdio.h>
#include <string.h>

#define max 256

int horspool(char*, char*);
int t[max];
void shifttable(char[]);

void main()
{
    char src[max], pat[max];
    int found;
    printf("ENTER THE SOURCE STRING\n");
    gets(src);
    printf("ENTER THE PATTERN STRING\n");
    gets(pat);
    found = horspool(src, pat);

    if (found == -1)
    {
        printf("PATTERN NOT FOUND\n");
    }
    else {
        printf("PATTERN FOUND AT %d\n", found + 1);
    }
    getchar();
}

void shifttable(char p[])
{
    int m, index, i, j;
    m = strlen(p);
    for (i = 0; i < max; i++)
    {
        t[i] = m;
    }
    for (j = 0; j < m - 1; j++)
    {
        index = (p[j]-'0');
        t[index] = m - 1 - j;
    }
}

int horspool(char s[], char p[])
{
    int i, n, m, index, k;
    n = strlen(s);
    m = strlen(p);
    shifttable(p);
    i = m - 1;

    while (i < n)
    {
        k = 0;
        while ((k < m) && (p[m - 1 - k] == s[i - k]))
        {
            k++;
        }
        if (k == m)
        {
            return (i - m + 1);
        }
        else {
            index = (s[i]-'0');
            i += t[index];
        }
    }
    return -1;
}
