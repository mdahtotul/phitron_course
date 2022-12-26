#include <stdio.h>

int main() {

    int T;
    scanf("%d",&T);
    for(int j=0; j<T; j++)
    {
        int N;
        scanf("%d",&N);
        char str[N];
        int pairs=0;
        scanf("%s",str);
        int i = 0;
        while(str[i] != '\0')
        {
            if((str[i]=='0' && str[i+1]=='1') || (str[i]=='1' && str[i+1]=='0'))
            {
                pairs++;
            }
            i++;
        }
        printf("%d\n",pairs);
    }
    return 0;
}
