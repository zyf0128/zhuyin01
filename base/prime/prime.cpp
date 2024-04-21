#include<iostream>

using namespace std;

/*
判断一个数是否是 素数
*/
bool is_prime(int x){
    for(int i = 2; i < x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

/*
把 数组中 *p  的整数倍全都标记为 合数.
*/
void  put_tag(int* p, int* end){
    /*
    由于 *p 是素数(*p 就不用标记了), 所以  *p 的整数倍就是应该每次向前移动 *p 个位置.
    */
    for(int* q = p + *p; q < end; q += *p){
        *q = -1; // 标记为 -1, 表示他是 合数
    }
}

/*
从当前位置找到下一个最靠近的 (没有被标记的数字)
*/
int* next_pos(int* p, int *end){
    
    // 这句话的意思就是 从 p + 1 位置开始往后遍历指导找到 非 -1 的数字.
    while(++p < end && *p < 0);

    return p < end ? p : NULL;
}
/*
求第 x 个素数
*/
int get_nth(int x){
    // 先求出来 需要筛选的数字范围
    const int N = x * 20;

    int* a = new int[N]; // 使用 new 在堆上动态分配空间
    for(int i = 0; i < N; i++){
        a[i] = i+2; // 把数组初始化: 把要筛选的数字放到 数组中, 由于 2 以下不用筛选所以就直接使用 i + 2 
    }

    int* p = a; // 标尺: 即将要进行标记他的所有倍数.

    while(p != NULL){
        put_tag(p, a + N);
        p = next_pos(p,a + N);
    }
    int t = -1;
    for(int i = 0; i < N; i++){
        if(a[i] > 0){
            x--;
        }
        if(x == 0){
            t = a[i];
            break;
            
        }
    }
    // 释放内存
    delete []a;
    // 返回结果
    return t;


}

int main(){
    
    int x;
    cout << "请输入一个数字: " << endl;
    
    cin >> x;

    cout << "第" << x <<"个素数是: " << get_nth(x) << endl;

    return 0;
}