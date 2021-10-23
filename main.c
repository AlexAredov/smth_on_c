#include <Windows.h>
#include <wincon.h>
#include <stdio.h>
#include <string.h>

void add(char p[1000]) {
    FILE* Pre;
    char str[100] = "";
    printf("Enter prefix: ");
    scanf_s("%s", &str, 100);
    char str1[10000];
    fopen_s(&Pre, p, "r");
    fgets(&str1, 10000, Pre);
    //printf("%s", str1);
    fclose(Pre);

    char *istr;

    char result[100];

    strcpy(result, str);
    strcat(result, " ");

    istr = strstr (str1, result);

    if ( istr == NULL) {
        fopen_s(&Pre, p, "a");
        fprintf(Pre, "%s", str);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
        printf("***Success!***\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        fclose(Pre);
    } else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        printf("***This item already exists!***\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    }
}

void squeeze (char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void rem(char p[1000]) {
    FILE* Pre;
    char str[100] = "";
    printf("Enter prefix: ");
    scanf_s("%s", &str, 100);

    char str1[110];
    fopen_s(&Pre, p, "r");
    fgets(&str1, 255, Pre);
    fclose(Pre);

    char *istr;

    istr = strstr (str1, str);

    if ( istr == NULL) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        printf("***There is no such item in the list!***\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    } else{
        fopen_s(&Pre, p, "w");
        int ind;
        ind = (int)(istr - str1);
        //printf("index = %d\n", ind);
        for (int i = ind; i <= ind + strlen(str); i++){
            //printf("%c, %d\n", str1[i], i);
            str1[i] = '?';
        }
        squeeze(str1, '?');
        //printf("%s", str1);
        fprintf(Pre, "%s ", str1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
        printf("***Success!***\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        fclose(Pre);
    }
}

void menu_p() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("***List of prefixes***\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    FILE* Pre;
    char str1[110];
    fopen_s(&Pre, "C:\\Users\\aared\\CLionProjects\\untitled\\Pre.txt", "r");
    fgets(&str1, 255, Pre);
    printf("%s\n", str1);
    fclose(Pre);
    printf(" 0 - Menu\n");
    printf(" 1 - Remove prefix\n");
    printf(" 2 - Add prefix\n");
    int t;
    scanf_s("%d", &t);
    switch (t) {
    case 0:
        return;
    case 1:
        rem("C:\\Users\\aared\\CLionProjects\\untitled\\Pre.txt");
        break;
    case 2:
        add("C:\\Users\\aared\\CLionProjects\\untitled\\Pre.txt");
        break;
    default:
        printf("ERROR: There is no such menu item. Try again");
        menu_p();
    }
}

void menu_r() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("***List of roots***\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    FILE* Pre;
    char str1[110];
    fopen_s(&Pre, "C:\\Users\\aared\\CLionProjects\\untitled\\Root.txt", "r");
    fgets(&str1, 255, Pre);
    printf("%s\n", str1);
    fclose(Pre);
    printf(" 0 - Menu\n");
    printf(" 1 - Remove root\n");
    printf(" 2 - Add root\n");
    int t;
    scanf_s("%d", &t);
    switch (t) {
        case 0:
            return;
        case 1:
            rem("C:\\Users\\aared\\CLionProjects\\untitled\\Root.txt");
            break;
        case 2:
            add("C:\\Users\\aared\\CLionProjects\\untitled\\Root.txt");
            break;
        default:
            printf("ERROR: There is no such menu item. Try again");
            menu_r();
    }
}

void menu_s() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("***List of suffixes***\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    FILE* Pre;
    char str1[1100];
    fopen_s(&Pre, "C:\\Users\\aared\\CLionProjects\\untitled\\Suff.txt", "r");
    fgets(&str1, 255, Pre);
    printf("%s\n", str1);
    fclose(Pre);
    printf(" 0 - Menu\n");
    printf(" 1 - Remove suffix\n");
    printf(" 2 - Add suffix\n");
    int t;
    scanf_s("%d", &t);
    switch (t) {
        case 0:
            return;
        case 1:
            rem("C:\\Users\\aared\\CLionProjects\\untitled\\Suff.txt");
            break;
        case 2:
            add("C:\\Users\\aared\\CLionProjects\\untitled\\Suff.txt");
            break;
        default:
            printf("ERROR: There is no such menu item. Try again");
            menu_p();
    }
}

void menu_e() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("***List of endings***\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    FILE* Pre;
    char str1[110];
    fopen_s(&Pre, "C:\\Users\\aared\\CLionProjects\\untitled\\End.txt", "r");
    fgets(&str1, 255, Pre);
    printf("%s\n", str1);
    fclose(Pre);
    printf(" 0 - Menu\n");
    printf(" 1 - Remove ending\n");
    printf(" 2 - Add ending\n");
    int t;
    scanf_s("%d", &t);
    switch (t) {
        case 0:
            return;
        case 1:
            rem("C:\\Users\\aared\\CLionProjects\\untitled\\End.txt");
            break;
        case 2:
            add("C:\\Users\\aared\\CLionProjects\\untitled\\End.txt");
            break;
        default:
            printf("ERROR: There is no such menu item. Try again");
            menu_p();
    }
}

void strrem(char* _pSourceStr, const char* _pDelStr )
{
    char* pTmpStr;
    pTmpStr = strstr( _pSourceStr, _pDelStr );
    //printf("%s\n", pTmpStr);
    strcpy( pTmpStr, pTmpStr + strlen(_pDelStr) );
    //printf("%s, %d", pTmpStr, strlen(_pDelStr));
}

void del(char sss[], char strr[], int k, char* str){
    char **res  = NULL;
    char *p    = strtok(sss, " ");
    int n_spaces = 0;

    while (p) {
        res = realloc(res, sizeof (char*) * ++n_spaces);
        if (res == NULL)
            exit (-1);

        res[n_spaces-1] = p;
        p = strtok (NULL, " ");
    }

    res = realloc (res, sizeof (char*) * (n_spaces+1));
    res[n_spaces] = 0;
    char *istr;
    int d = 0;

    for (int i = 0; i < n_spaces; i++) {
        istr = strstr (strr,res[i]);
        if ( istr == NULL) {
            //printf("NO\n");
        }
        else {
            //printf("res[%d] = %s\n", i, res[i]);
            //printf("YES %d %d\n", istr - strr + 1, strlen(strr) - 3);
            if (istr - strr == 0 && k == 1){
                printf("Prefix: %s\n", res[i]);

                strrem(strr, res[i]);
                str = strr;

                break;
            }
            if (istr - strr > strlen(strr) - 4 && k == 4){
                //printf("%d", istr - strr + 1 + strlen(res[i]));

                if (strcmp(res[i], "s") != 0){
                    printf("Ending: %s\n", res[i]);

                    strrem(strr, res[i]);
                    str = strr;

                    break;
                }
                else{
                    if (istr - strr == strlen(strr)){
                        printf("Ending: %s\n", res[i]);

                        strrem(strr, res[i]);
                        str = strr;

                        break;
                    }
                }



            }
            if (k == 3){

                if (strcmp(res[i], "age") != 0 && strcmp(res[i], "ant") != 0){
                    printf("Suffix: %s\n", res[i]);
                    strrem(strr, res[i]);
                    str = strr;
                }
                else{
                    if (strcmp(str, "age") != 0 && strcmp (str, "ant") != 0){
                        printf("Suffix: %s\n", res[i]);
                        strrem(strr, res[i]);
                        str = strr;
                    }
                    else{
                        str = strr;
                        break;
                    }

                }
            }
            if (k == 2){
                if (strcmp(strr, res[i])==0){
                    d++;
                }
            }
        }
    }
    if (k == 2){
        if (d == 0){
            FILE* rot;
            fopen_s(&rot, "C:\\Users\\aared\\CLionProjects\\untitled\\Root.txt", "a");
            //printf("%s\n", strcat(strr, " "));
            fprintf(rot, "%s", strcat(strr, " "));
            printf("Root: %s\n", strr);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
            printf("*the root was not found in the database and was entered into it*\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            fclose(rot);
        }
        else {
            printf("Root: %s\n", strr);
        }
    }
}

void razbor(){
    FILE* Pre;
    char pre[110];
    fopen_s(&Pre, "C:\\Users\\aared\\CLionProjects\\untitled\\Pre.txt", "r");
    fgets(&pre, 255, Pre);

    FILE* SSS;
    char sufff[1100];
    fopen_s(&SSS, "C:\\Users\\aared\\CLionProjects\\untitled\\Suff.txt", "r");
    fgets(&sufff, 255, SSS);

    FILE* Root;
    char rt[100000];
    fopen_s(&Root, "C:\\Users\\aared\\CLionProjects\\untitled\\Root.txt", "r");
    fgets(&rt, 100000, Root);

    FILE* End;
    char end[110];
    fopen_s(&End, "C:\\Users\\aared\\CLionProjects\\untitled\\End.txt", "r");
    fgets(&end, 255, End);

    char str[100] = "";
    printf("Enter word: ");
    scanf_s("%s", &str, 100);
    printf("\n");

    del(pre, str, 1, str);
    del(end, str, 4, str);
    del(sufff, str, 3, str);


    //printf("%s\n", str);

    fclose(Root);

    del(rt, str, 2, str);
    printf("\n");

    fclose(Pre);
    fclose(SSS);
    fclose(End);
}

void menuu() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("***Menu***\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" 1 - List of prefixes\n");
    printf(" 2 - Root list\n");
    printf(" 3 - List of suffixes\n");
    printf(" 4 - Endings list\n");
    printf(" 5 - Parsing a word by composition\n");
    int t = 0;
    scanf_s("%d", &t);
    if (t <= 5 && t >= 1) {
        if (t == 1) {
            menu_p();
        }
        else if (t == 2) {
            menu_r();
        }
        else if (t == 3) {
            menu_s();
        }
        else if (t == 4) {
            menu_e();
        }
        else if (t == 5) {
            razbor();
        }
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        printf("ERROR: There is no such menu item. Try again\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        menuu();
    }
}

int main()
{
    while (1) {
        menuu();
    }
}