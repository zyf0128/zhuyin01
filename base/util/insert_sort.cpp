#include<iostream>

using namespace std;

/*
用来打印数组的元素
*/
void show_array(int* arr,const int N){
    if(N < 0){
        cout << "参数 N 应该大于 0" << endl;
        return;
    }
    if(N == 0){
        cout << "数组为 空, 元素个数为 0" << endl;
        return;
    }
    
    for(int i = 0; i < N; i++){
        cout << arr[i] << " "; 
    }
    cout << "打印完毕" << endl; 
}


int find_index_by_harf_find(int* arr, int begin, int end, int target){
    
    int low = begin, high = end -1;
    int mid = (low + high) / 2;
    while(low <= high){
        if(arr[mid] == ){
            return mid;
        }else if(arr[mid] < target){
            low = mid + 1;    
        }else{
            high = mid -1;
        }
    }
    return low;    
}

void my_copy_array(int* dst, int* src, int* src_end){
    if(dst == src){
        return;
    }
    int n = src_end - src;

    if(dst > src){
        for(int i = n -1; i >= 0; i--){
            dst[i] = src[i];
        }
    }else{
        for(int i = 0; i < n; i++){
            dst[i] = src[i];
        }
    }
}

void my_insert_sort(int* arr,const int N){
    
    for(int i = 0; i < N; i++){
        
        int t = arr[i];
        int index = find_index_by_harf_find(arr,0,i,t);

        my_copy_array(arr + index, arr , arr + N - 1);

    }

}



int main(){
    
    int array[10] = {1,7,3,9,2,3,5,4,8,10};
    
    my_insert_sort(array,10);

    show_array(array,10);

    return 0;

}