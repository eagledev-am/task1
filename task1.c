#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct User{
    char userName[50],Password[50];
};


struct User users[10];
int i = 0;

struct User Register(){
    struct User u;
    printf("Enter User Name: ");
    scanf("%s",&u.userName);


    printf("Enter Password: ");
    scanf("%s",&u.Password);
	
    return u;
}


int Login(char _userName[],char _password[]){
    int j;
    for(j = 0;j <= i;j++){
        if(strcmp(users[j].userName,_userName) == 0  && strcmp(users[j].Password,_password) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    while(true){
        printf("Welcome\n1- Register\n2- Login\n3- Exit\n--------------------\n");
        int t;
        scanf("%d",&t);

        if(t == 1){
            struct User u;
            u = Register();
            users[i++] = u;
            printf("Register success\n");
        }else if(t == 2){
            char _userName[50],_password[50];
            printf("Enter User Name: ");
            scanf("%s",&_userName);

            printf("Enter Password: ");
            scanf("%s",&_password);
            int ch = Login(_userName,_password);
            if(ch == (int)1)
                printf("Login Success\n");
            else
                printf("Login Failed\n");

        }else if(t == 3){
            return 0;
        }else{
            printf("Wrong Value\n");
        }
        printf("--------------------\n");
    }
}
