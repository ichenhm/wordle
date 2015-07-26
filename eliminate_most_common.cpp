#include<cstdio>
#include<cstring>
char a[500][20];
char s[20];
int n;
int main()
{   n=0;
   freopen("oneHundredWords.txt","r",stdin);
   while (scanf("%s",a[n++])!=EOF);
   freopen("allWordsAndFrequency.txt","r",stdin);
   freopen("finalWordsAndFrequency.txt","w",stdout);
   int x;

   while (scanf("[\"%s ,%d],",s,&x)!=EOF)
   {   int f=0;
       s[strlen(s)-1]=0;
       for (int i=0;i<n;i++)if (strcmp(a[i],s)==0) {f=1;break;}
       if (f)continue;
       printf("[\"%s\",%d],",s,x);
   }



}
