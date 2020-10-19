#include <stdio.h>

int main()
{
    FILE *fp, *newfp;
    char buf[1024];
    newfp = fopen("contents.md", "w+");
    fp = fopen("README.md", "r");

    while (!feof(fp))
    {
        fgets(buf, sizeof buf, fp);
        int i = 0;
        while (1)
        {
            if (buf[i] == '#')
            {
                fputs(buf, newfp);
                break;
            }
            if (buf[i] == '(')
                break;
            i++;
        }
    }
    fclose(fp);
    return 0;
}