#include <stdio.h>
#include <stdlib.h>

unsigned int Data[10] = {3 , 4 , 6 , 2 , 0 , 5 , 7 , 9 , 8 , 3};
unsigned int Data1[10] = {0,1,2,3,4,5,6,7,8,9};

void swap_Numb(unsigned int *ptr1 , unsigned int *ptr2 ){
    unsigned int temp = *ptr1 ;
    *ptr1 = *ptr2 ;
    *ptr2 = temp ;
}

void Print_AR(unsigned int my_Data[],unsigned int length){
    unsigned int i = 0 ;
    for(i ; i < length ; i++){
        printf("%i\t",my_Data[i]);
    }
    printf("\n");
}

void Bubble_Sort(unsigned int my_Data[],unsigned int length){
    unsigned int i = 0 , j = 0 ;
    unsigned char flag = 0 ;
    for( i = 0 ; i  < length-1 ; i++){
        for ( j = 0 ; j < length-1-i ; j++){
            if(my_Data[j]>my_Data[j+1]){
                swap_Numb(&my_Data[j],&my_Data[j+1]);
                flag = 1 ;
            }
        }
        if (flag == 0){
            return ;
        }
    }
}

void Insertion_Sort(unsigned int my_Data[],unsigned int length){
    unsigned int counter = 0 , InsertedItem = 0 ;
    int ComparedItemIndex = 0 ;
    for (counter = 1 ; counter < length ; counter++){
        InsertedItem = my_Data[counter];
        ComparedItemIndex = counter - 1 ;
        while(InsertedItem < my_Data[ComparedItemIndex] && ComparedItemIndex >= 0 ){
            my_Data[ComparedItemIndex + 1] = my_Data[ComparedItemIndex];
            ComparedItemIndex-- ;
        }
        my_Data[ComparedItemIndex+1] = InsertedItem ;
    }
}

void Selection_Sort(unsigned int my_Data[],unsigned int length){
    unsigned int counter = 0 , Min_Index = 0 ,Compared_Index = 0 ;

    for(counter = 0 ; counter < length - 1 ; counter++){
            Min_Index = counter ;
        for(Compared_Index = counter + 1 ; Compared_Index < length ; Compared_Index++){
            if(my_Data[Compared_Index] < my_Data[Min_Index]){
                Min_Index = Compared_Index ;
            }
        }
        swap_Numb(&my_Data[counter],&my_Data[Min_Index]);
    }

}





int main()
{
    Bubble_Sort(Data,10);
    Print_AR(Data,10);
    
    return 0;
}
