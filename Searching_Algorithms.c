#include <stdio.h>
#include <stdlib.h>

unsigned int Data[10] = {0 , 11 , 22 , 33 , 44 , 55 , 66 , 77 , 88 , 99};
int ret = 0 ;

int Linear_Search_1(unsigned int Data[], unsigned int Lenght , unsigned int ReqVal){
    unsigned int index = 0 ;
    for (index = 0 ; index < Lenght ; index++){
        if(ReqVal == Data[index]){
            return index;
        }
    }
    return -1;
}

int Linear_Search_2(unsigned int Data[], unsigned int Lenght , unsigned int ReqVal){
    unsigned int index_L = 0 ;
    unsigned int index_R = Lenght - 1 ;
    while(index_L <= index_R ){
        if(ReqVal == Data[index_L]){
            return index_L ;
        }
        if((ReqVal == Data[index_R])){
            return index_R ;
        }
        index_L++;
        index_R--;
    }
    return -1;
}

int Binary_Search_1(unsigned int Data[], unsigned int StartIndex ,unsigned int EndIndex , unsigned int ReqVal){
    while(StartIndex <= EndIndex){
        unsigned int MiddleIndex = (StartIndex + EndIndex )/2 ;
        if(ReqVal == Data[MiddleIndex]){
            return MiddleIndex;
        }
        else if (ReqVal>Data[MiddleIndex]){
            StartIndex = MiddleIndex + 1 ;
        }
        else{
            EndIndex = MiddleIndex - 1 ;
        }
    }
    return -1;
}

int Binary_Search_2(unsigned int Data[], unsigned int StartIndex ,unsigned int EndIndex , unsigned int ReqVal){
    while(StartIndex <= EndIndex){
        unsigned int MiddleIndex = (StartIndex + EndIndex )/2 ;
        if(ReqVal == Data[MiddleIndex]){
            return MiddleIndex;
        }
        else if (ReqVal>Data[MiddleIndex]){
            return Binary_Search_2(Data,MiddleIndex + 1,EndIndex,ReqVal);
        }
        else{
            return Binary_Search_2(Data,StartIndex,MiddleIndex - 1,ReqVal);
        }
    }
    return -1;
}

int main()
{
    ret = Bin_t_1(Data,10,77);printf("ret = %i\n",ret);
    ret = Linear_Search_1(Data,10,33);printf("ret = %i\n",ret);
    ret = Linear_Search_1(Data,10,100);printf("ret = %i\n",ret);
    printf("==========================================================\n");
    ret = Linear_Search_2(Data,10,77);printf("ret = %i\n",ret);
    ret = Linear_Search_2(Data,10,33);printf("ret = %i\n",ret);
    ret = Linear_Search_2(Data,10,100);printf("ret = %i\n",ret);
    printf("==========================================================\n");
    ret = Binary_Search_1(Data,0,9,77);printf("ret = %i\n",ret);
    ret = Binary_Search_1(Data,0,9,33);printf("ret = %i\n",ret);
    ret = Binary_Search_1(Data,0,9,100);printf("ret = %i\n",ret);
    printf("==========================================================\n");
    ret = Binary_Search_2(Data,0,9,77);printf("ret = %i\n",ret);
    ret = Binary_Search_2(Data,0,9,33);printf("ret = %i\n",ret);
    ret = Binary_Search_2(Data,0,9,100);printf("ret = %i\n",ret);
    printf("==========================================================\n");
    ret = sizeof(Data)/sizeof(unsigned int);printf("ret = %i\n",ret);

    return 0;
}



