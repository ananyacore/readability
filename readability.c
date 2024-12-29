#include <ctype.h>
#include <stdio.h>
#include <string.h>

float lpw(char a[1000]);
float spw(char b[1000], int a);
void indexs(float ll, float ss);
int n = 0;
int let = 0;
int s = 0;
int main(void)
{
    char exc [10000];
    printf("Text: ");
    scanf("%[^\n]%*c", exc);
    lpw(exc);
    spw(exc, n);
    float lpw = ((float) let / (float) n) * 100.0;
    float spw = ((float) s / (float) n) * 100.0;
    indexs(lpw, spw);
}

float lpw(char a [1000])
{
    int l = strlen(a);
    for (int i = 0; i < l; i++)
    {
        let = let + 1;
        if (isblank(a[i]))
        {
            n++;
            let--;
        }
        if (ispunct(a[i]))
        {
            let--;
        }
    }
    n++;
    return n;
    return let;
}

float spw(char b[1000], int a)
{
    int l = strlen(b);
    for (int i = 0; i < l; i++)
    {
        if ((b[i] == '.') || (b[i] == '?') || (b[i] == '!'))
        {
            s++;
        }
    }
    return s;
}

void indexs(float ll, float ss)
{
    float sub = (0.0588 * ll) - (0.296 * ss);
    float ind = sub - 15.8;
    int rem = ind * 10;
    if (rem % 10 >= 5)
        ind = ind + 1;
    if (ind < 1)
        printf("Before Grade 1\n");
    else if ((int) ind > 10)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", (int) ind);
}
