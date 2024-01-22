    /*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
    define
    include
    class
    strlen
    strcat
    string
    strcmp
    strcpy
    memmove
    strstr
    ###End banned keyword*/

    #include <iostream>
    #include <string.h>
    using namespace std;
    #define MAX 300

    int myStrcmp(char s1[], char s2[]);
    int myStrlen(char s[], int k);
    void myStrcpy(char s[], int vt, char s1[], int k);
    void mySubstr(char s[], int b, int count, char ss[]);
    bool myStrcat(char s1[], char s2[]);
    void StringReverse(char st[]);
    bool checkChuoiRong(char s1[]);

    int main()
    {
        char s[MAX];
        fgets(s,300,stdin);
        if (checkChuoiRong(s))
            cout << "Chuoi rong." << endl;
        else
        {
            StringReverse(s);
            cout << s << endl;
        }
        return 0;
    }   

    bool checkChuoiRong(char s1[]){
        for (int i = 0; i < myStrlen(s1,0); i++)
            if(s1[i] != '\0' && s1[i] != ' ')
                return false;
        return true;
    }
    void myStrcpy(char s[], int vt, char s1[], int k)
    {
        int i=vt;
        int j=0;
        while(s1[i]!='\0')
                s[j++]=s1[i++];
    }
    int myStrlen(char s[], int k)
    {
        int i=k;
        while(s[i] != '\0' && s[i] != '\n')
            i++;
        return i;
    }

    bool myStrcat(char s1[], char s2[])
    {
        int s1Length = myStrlen(s1,0),
            s2Length = myStrlen(s2,0);
        for (int i = 0; i < s2Length; i++)
        {
            s1[s1Length + i] = s2[i];
        }
        s1[s1Length + s2Length] = '\0';
        return true;
    }

    void StringReverse(char st[])
    {
        int sLength = myStrlen(st,0);
        char s[MAX];
        for(int i=sLength-1; i>=0; i--)
        {
            if(st[i]==' ')
            {
                char ss[MAX] = {0};
                myStrcpy(ss,i+1,st,0);
                myStrcat(s,ss);
                s[myStrlen(s,0)] = ' ';
                st[i]='\0';
            }
            if(i==0)
            {
                char ss[MAX] = {0};
                myStrcpy(ss,i,st,0);
                myStrcat(s,ss);
            }
        }
        myStrcpy(st,0,s,0);
    }