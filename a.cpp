#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;
#define N 100000
int wordnum,mapid;
int left=0,nlen=0;
bool lastIsQuotation=0;
map<string,int>ma;
char s[100];
struct lexnode{
    char lex[30];
}a[N];

struct word{
    char lex[30];
    int t;
    bool operator<(const word&oth)const{
        return t>oth.t;
    }
}b[N];


void addword()
{
    if (left!=2)
        {   if (s[0]=='\'') wordnum--;
            lastIsQuotation=(s[0]=='\'');left=0;nlen=0;
            return;
        }
    if (!lastIsQuotation)
        {
            s[nlen++]='\0';
            strcpy(a[wordnum].lex,s);
            wordnum++;
        }
    lastIsQuotation=(s[0]=='\'');left=0;nlen=0;
}
int main()
{
    freopen("origin.txt","r",stdin);
    freopen("a1.txt","w",stdout);
    char cc;
    while (scanf("%c",&cc)!=EOF)
        {
            if (cc==' '||cc=='\t'||cc=='\n')
                {
                    if (left)addword();
                }
            else if (cc>='a'&&cc<='z'||cc>='A'&&cc<='Z')
                {
                    if (left==1)addword();
                    if (cc<='Z')cc+=32;
                    if (left==0)left=2;
                    s[nlen++]=cc;
                }
            else{
                    if (left)addword();
                    if (left==0)left=1;
                    s[nlen++]=cc;
                }
        }
    if (left)addword();

    //printf("~~~~~%d\n",wordnum);
    ma.clear();
    mapid=0;


    for (int i=0;i<wordnum;i++)
    if (!ma.count(a[i].lex))
    {
        ma[a[i].lex]=mapid;
        b[mapid].t=1;
        strcpy(b[mapid].lex,a[i].lex);
        mapid++;
    }
    else b[ma[a[i].lex]].t++;
    sort(b,b+mapid);
    for (int i=0;i<mapid;i++)
        printf("[\"%s\" ,%d],",b[i].lex,b[i].t);

}
