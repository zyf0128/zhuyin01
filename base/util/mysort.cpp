#include<iostream>
#include<vector>

using namespace std;


// 由于 nums 是一个 无重复元素 的升序数组. 所以考虑使用 二分查找来解决
int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        int mid = (l + r) / 2;
        while(l <= r ){
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                r = mid -1;
            }else{
                l = mid + 1;
            }
            mid= (l + r) / 2;
        }
        cout << "mid ="  <<  mid << endl;
        cout << "l ="  <<  l << endl;
        cout << "r ="  <<  r << endl;
        // 如果没有找到target, 就返回 -1 表示 集合中 没有我们要找的元素
        return l;             
}

/*找插入的位置*/
int* find_pos(int* begin,int* end, int target){
    for(int *p = begin; p < end; p++){
        if(*p >= target){
            return p;
        }
    }
    return NULL;
}

/*
用来进行数据的拷贝
*/
void my_copy(int* dst, int* src, int* src_end ){
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

/*
可以把数组分开成两个区域，左边是排好序的，右边是待排序的。
    从右边拿一个数，插入左边适当的位置
    寻找恰当的位置
    把那个位置的数据向后平移
    放入插入的数据
重复2，直到没有剩余数据
*/
/*插入排序*/
void insert_sort(int* a, const int N){
    // 从左往右遍历数组
    for(int* p = a; p < a+N; p++){
        // t 就是即将要插入的那个元素
        int t = *p;
        // 在左边的有序 序列中 找到 t 应该插入的位置,返回指针,如果没有找到应该要插入的位置就返回 NULL
        int *q = find_pos(a,p,t);
        // 如果 q != NULL 就代表, 找到了 t 应该插入的位置.
        if(q != NULL){
            /*首先把将数组 [q,end] 向后平移*/

            my_copy(q+1, q, p);
            *q = t;
        }
    }
}

/***
 * 用来测试 插入排序 
*/
int main(){

    int num[4] = {1,5,3,6};
    
    insert_sort(num,4);
    
    for(int i = 0; i < 4; i++){
        cout << num[i] << " " << endl;
    }

    // vector<int> v(num, num + 4);
    // int target = 2;
    // cout << "结果为: " << searchInsert(v,target) << endl;

    return 0;

}