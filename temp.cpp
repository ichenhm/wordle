#include<cstdio>
#include<cstring>

char s[20];
int n;
int main()
{

    freopen("word.txt","r",stdin);


   freopen("oo.txt","w",stdout);
   int x=0;
    for (int i=1;i<=249;i++)

   {    scanf("%s %d",s,&x);
       int f=0;
       s[strlen(s)-1]=0;


       printf("[\"%s\",%d],",s,x);
   }



}
