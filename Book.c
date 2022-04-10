#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define EPS 0.001
#define CNT 3

typedef struct {
    char name[100];
    char author[100];
    int pages;
    double price;
} book;



int checkTitleAndAuthor(char* str){
  char name[100];
    strcpy(name,str);
    int j = 0;
     while (name[j] != '\0')
     {
       int s = name[j];
        if ((s < 97 || s > 122) && (s < 65 || s > 90))
        {

            return 1;
            break;
        }

         j++;
     }

     if(j < 10 || j > 20){
     return 1;
     }
     return 0;
}

int checkPages(int num){

    if(num < 5 || num > 2000){

    return 1;

    }
    return 0;
}

int price (double price){
 double min = 1;
 double max = 1000;
 if(price < min || price > max){
 return 1;
 }else{
 return 0;
 }
}

int compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int compare1(const void* a, const void* b){
    return *(double*)b - *(double*)a;
}





void swapg(void *a, void* b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}
void bubbleSort(void* arr, size_t n, size_t size, int (*comp)(const void*,const void*)){
   for (int i = 0; i < n-1; i++){
       for (int j = 0; j < (n-i-1) * size; j += size){
           if (comp(arr + j, arr + j + size) < 0){
              swapg(arr + j, arr + j + size, size);

           }
       }
   }
}

int *lsearch(const double key, double* arr, size_t n){
    for (int i = 0; i < n; i++){
        if (fabs(arr[i] - key) < EPS){
            return arr + i;
        }
    }
    return NULL;
}


int main(){
book b[CNT];

for (int i = 0; i < CNT; i++)
{
    printf("Ener title: \n");
    scanf("%s",b[i].name);
     if(checkTitleAndAuthor(b[i].name) != 0){
    printf("Invalid input!");
    return 1;
    break;
    }

       printf("Ener author: \n");
    scanf("%s",b[i].author);
    if(checkTitleAndAuthor(b[i].author) != 0){
    printf("Invalid input!");
    return 1;
    break;
    }

     printf("Enter pages: \n");
     scanf("%d",&b[i].pages);
      if(checkPages(b[i].pages) != 0){
         printf("Invalid input");
         break;
       }

       printf("Ener price: \n");
    scanf("%lf",&b[i].price);
    if(price(b[i].price) != 0){
    printf("Invalid input!");
    return 1;
    break;
    }

    }
    
    int pages[CNT];
    for(int i = 0;i < CNT;i++){
         pages[i] = b[i].pages;
    }

    double price[CNT];
    for (int i = 0; i < CNT; i++)
    {
       price[i]=b[i].price;
    }
    
    char title[CNT][100];
    for (int i = 0; i < CNT; i++)
    {
        strcpy(title[i],b[i].name);
    }
    
     char s[100];
   
   for(int i=0;i<CNT;i++){
      for(int j=i+1;j<CNT;j++){
         if(strcmp(title[i],title[j])>0){
            strcpy(s,title[i]);
            strcpy(title[i],title[j]);
            strcpy(title[j],s);
         }
      }
   }
   printf("Titles: \n");
    for (int i = 0; i < CNT; i++)
    {
         printf("%s\n",title[i]);
    }
    
    char author[CNT][100];
    for (int i = 0; i < CNT; i++)
    {
        strcpy(author[i],b[i].author);
    }
    
     char s1[100];
   
   for(int i=0;i<CNT;i++){
      for(int j=i+1;j<CNT;j++){
         if(strcmp(author[i],author[j])>0){
            strcpy(s1,author[i]);
            strcpy(author[i],author[j]);
            strcpy(author[j],s);
         }
      }
   }
   printf("Authors: \n");
    for (int i = CNT-1; i >= 0; i--)
    {
         printf("%s\n",author[i]);
    }

   bubbleSort(pages,CNT,sizeof(int),compare);
   printf("The pages are: ");
    for(int i=0 ;i < CNT;i++){
    printf(" %d\n",pages[i]);
    }

    bubbleSort(price,CNT,sizeof(double),compare1);
    printf("The prices are: ");
    for(int i=0 ;i < CNT;i++){
    printf("%.2lf\n",price[i]);
    }

    int isThereabookWithSuchPrice = lsearch(20.5,price,CNT);
    printf("%d",isThereabookWithSuchPrice);
    return 0;
}
    
       
       
       
       
   



