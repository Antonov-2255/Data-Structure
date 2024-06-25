#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int st[5];
int top=-1;

void push() {

    int n;
    if(top==4){
        printf("\nStack Overflow..!!");
    }
    else{
        printf("Enter Value Of N: ");
        scanf("%d", &n);
        top=top+1;
        st[top]=n;
    }
}

void pop() {

    int x;
    if(top==-1){
        printf("\nStack Underflow..!!");
    }
    else{
        x=st[top];
        top=top-1;
        printf("\nDeleted values is=%d", x);
    }
}

void display() {

      int i;
      if(top==-1){
        printf("\nStack is Empty...!!!");
      }
      else{
        for(i=top; i>=0; i--){
            printf("\n%d", st[i]);
        }
      }
}

void peep() {

      int i,x;
      printf("Enter Value of i: ");
      scanf("%d", &i);
      if(top-i+1<0){
        printf("\nStack Underflow For Peep..!!!");
      }
      else{
        x=st[top-i+1];
        printf("\nRequried value in peep operation is%d", x);
      }

}
void update(){

      int i,x;
      printf("Enter Value of i: ");
      scanf("%d", &i);
      if(top-i+1<0){
        printf("Stack Underflow For peep");
      }
      else {
        printf("Enter New Value: ");
        scanf("%d", &x);
        st[top-i+1]=x;
      }

}

void main(){

      int ch;
      do{

        printf("\n\n1.Push\n2.Pop\n3.Display\n4.peep\n5.Update\n6.Exit");
        printf("\nEnter Your choice: ");
        scanf("%d", &ch);
        switch(ch){

               case 1: push();
                    break;
               case 2: pop();
                    break;
               case 3: display();
                    break;
               case 4: peep();
                    break;
               case 5: update();
                    break;
               case 6: exit(0);
                    break;






        }
      }while(1);

      return 0;

}
