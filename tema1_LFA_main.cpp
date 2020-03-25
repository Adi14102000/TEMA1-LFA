#include<iostream>
#include<cstring>
using namespace std;
struct translatie
{
    char l[1], si, sf;
};
int n, m, q0, k, l, sf[2], i,j, a, b, sc, sol1[100], sol2[100], c=0, aux1, aux2;
char alfabet[]="abcxyz", cuv[100], autom[100][100][100]= {'\0'};
translatie t[100];
bool ok, verif;

int main()
{
    cin>>n>>m>>q0>>k>>l;
    for(i=0; i<k; i++)
        cin>>sf[i];
    cin.get();
    cin.get(alfabet, 100);
    cin.get();
    for(i=0; i<l; i++)
    {
        cin>>t[i].si>>t[i].l>>t[i].sf;
    }
    cin.get(cuv, 100);
    cin.get();
    cout<<cuv<<endl;
    for(i=0; i<l; i++)
    {
        a=t[i].si-'0';
        b=t[i].sf-'0';
        if(autom[a][b]=='\0')
            strcpy(autom[a][b], t[i].l);
        else
            strcat(autom[a][b],t[i].l);
    }
    for(i=0; i<l; i++)
    {
        for(j=0; j<l; j++)
            cout<<autom[i][j]<<" ";
        cout<<endl;
    }
    ok=false;
    sc=q0;
    sol1[0]=q0;
    c++;
    for(a=0; a<strlen(cuv); a++)
    {
        for(i=0; i<l; i++)
        {
            aux1=i;
            aux2=a;
retry:      i=aux1;
            a=aux2;
            for(j=0; j<strlen(autom[sc][i]); j++)
            {
                if(autom[sc][i][j]==cuv[b])
                {
                    sc=i;
                    sol1[c]=i;
                    sol2[c]=a;
                    c++;
                    break;
                }
                else
                {
                    if(autom[sc][i][j]=='$')
                    {
                        sc=i;
                        a--;
                        sol1[c]=i;
                        sol2[c]=a;
                        c++;
                        break;
                    }
                }

            }
        }

    }
    for(i=0; i<k; i++)
    {
        if(sf[i]==sc)
            ok=true;
        else
        {
            aux1=sol1[c-1]+1;
            aux2=sol2[c-1];
            c=c-2;
            goto retry;
        }
    }
    if(ok)
      cout<<"TRUE";
    else
      cout<<"FALSE";
    return 0;
}
