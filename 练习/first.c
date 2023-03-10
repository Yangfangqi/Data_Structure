#include <stdio.h>


typedef struct{
    int * head; //定义一个名为head的长度不确定的数组，也叫“动态数组”
    int length; //记录当前顺序表的长度
    int size; //记录顺序表的存储容量
}Table;

#define Size 5 //对Size进行宏定义，表示顺序表的最大容量
void initTable(Table * t) {
    //构造一个空的顺序表，动态申请存储空间
    t->head = (int*)malloc(Size * sizeof(int));
    //如果申请失败，作出提示并直接退出程序
    if (!t->head)
    {
        printf("初始化失败");
        exit(0);
    }
    //空表的长度初始化为0
    t->length = 0;
    //空表的初始存储空间为Size
    t->size = Size;
}

//输出顺序表中元素的函数
void displayTable(Table t) {
    int i;
    for (i = 0; i < t.length; i++) {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}
int main() {
    int i;
    Table t = { NULL,0,0 };
    initTable(&t);
    //向顺序表中添加{1,2,3,4,5}
    for (i = 1; i <= Size; i++) {
        t.head[i - 1] = i;
        t.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    free(t.head);//释放申请的堆内存
    return 0;
}