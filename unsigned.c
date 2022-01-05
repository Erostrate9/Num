
#include <stdlib.h>
#include "unsigned.h"

// -----------------------------------------------------------------------------

static const Int ignore = 42;

// 在此处可定义若干辅助函数，以供定义其它函数时使用
Unsigned* Normalize(const Unsigned* x)
{
    // 拷贝x，保证size>0，将开头多余的0去除并返回。
    if (x==NULL || x->size==0){
        return unsigned_from_ll(0);
    }
    Unsigned* res=unsigned_copy(x);
    while(res->head && res->head->n==0 && res ->head->next){
        remove_front(res);
    }
    return res;
}
// -----------------------------------------------------------------------------
// long long整型x转换成Unsigned数，并返回
Unsigned* unsigned_from_ll(long long x)
{
    Unsigned* ret = get_list();

    insert_front(ret, x % 10, ignore);
    while (x /= 10)
        insert_front(ret, x % 10, ignore);
    return ret;
}

// 拷贝Unsigned数x，并返回
Unsigned* unsigned_copy(const Unsigned* x)
{
    if (x==NULL)
        return 0;

    Unsigned* y = get_list();
    for (Link* link = x->head; link; link = link->next)
        insert_back(y, link->n, link->x);
    return y;
}

void unsigned_free(Unsigned* x)
{
    list_free(x);
}

long long unsigned_to_ll(const Unsigned* x)
{
    long long ret = 0;
    for (Link* link = x->head; link; link = link->next) {
        ret *= 10;
        ret += link->n;
    }
    return ret;
}

//当x<y时，返回值=-1；
//当x=y时，返回值=0；
//当x>y时，返回值=1。
int unsigned_cmp(const Unsigned* x, const Unsigned* y)
{
    // 在此处补充完整

    int res=0;
    Unsigned* x1=Normalize(x);
    Unsigned* y1=Normalize(y);
    if(x1->size < y1->size){
        res=-1;
    }
    else if (x1->size > y1->size){
        res=1;
    }
    else if (x1->size==y1->size){
        Link* pX=x1->head;
        Link* pY=y1->head;
        while(pX && pY){
            if (pX->n<pY->n)
            {
                res=-1;
                break;
            }else{
                if(pX->n>pY->n){
                    res=1;
                    break;
                }
            }
            pX=pX->next;
            pY=pY->next;
        }
    }
    unsigned_free(x1);
    unsigned_free(y1);
    return res;
}

Unsigned* unsigned_add(const Unsigned* x, const Unsigned* y)
{
    // 在此处补充完整
    Unsigned* result=get_list();
    int isCarry = 0;  //进位，初始0
    Link *pX, *pY;
    pX = x->tail;  //从低位开始处理
    pY = y->tail;
    while(pX!=NULL && pY!=NULL)  //两数相同位处理
    {
        int digit = pX->n + pY->n + isCarry;
        isCarry = digit / 10;  //新进位
        digit %= 10;  //当前结果位
        insert_front(result,digit,ignore);  //添加至结果最高位
        pX = pX->prior;  //准备处理前一位
        pY = pY->prior;
    }
    while(pX!=NULL)  //第一位大数剩余位处理
    {
        int digit = pX->n + isCarry;
        isCarry = digit / 10;
        digit %= 10;
        insert_front(result,digit,ignore);
        pX = pX->prior;
    }
    while(pY!=NULL)  //第二位大数剩余位处理
    {
        int digit = pY->n + isCarry;
        isCarry = digit / 10;
        digit %= 10;
        insert_front(result,digit,ignore);
        pY = pY->prior;
    }
    if(isCarry != 0)  //最后进位处理
        insert_front(result,isCarry,ignore);
    Unsigned* p =result;
    result=Normalize(result);
    unsigned_free(p);
    return result;
}

Unsigned* unsigned_sub(const Unsigned* x, const Unsigned* y)
{
    // 在此处补充完整
    Unsigned* result=get_list();
    int iCarry = 0;  //退位，初始0
    Link *pX, *pY;
    pX = x->tail;  //从低位开始处理
    pY = y->tail;
    while(pX != NULL && pY != NULL)  //两数相同位处理
    {
        int digit = pX->n - pY->n - iCarry;
        iCarry = 0; //初始化
        if(digit < 0)
        {
            digit += 10;
            iCarry = 1;  //前一位退1
        }
        insert_front(result,digit,ignore);
        pX = pX->prior;
        pY = pY->prior;
    }
    while(pX != NULL)  //最后退位处理
    {
        int digit = pX->n - iCarry;
        iCarry = 0;
        if(digit < 0)
        {
            digit += 10;
            iCarry = 1;  //前一位退1
        }
        insert_front(result,digit,ignore);
        pX = pX->prior;
    }
    Unsigned* p =result;
    result=Normalize(result);
    unsigned_free(p);
    return result;
}

Unsigned* unsigned_mul(const Unsigned* x, const Unsigned* y)
{
    // 在此处补充完整
    if ((x->size==1&&x->head->n==0)||(y->size==1&&y->head->n==0))
        return unsigned_from_ll(0);
    if(x->size==1&&x->head->n==1)
        return unsigned_copy(y);
    if(y->size==1&&y->head->n==1)
        return unsigned_copy(x);
    Unsigned* x1=x->size>=y->size?Normalize(x):Normalize(y);
    Unsigned* y1=y->size<=x->size?Normalize(y):Normalize(x);
    Unsigned* res=unsigned_from_ll(0);
    Unsigned* temp=get_list();
    Link* pY=y1->tail;
    int k=0;
    while(pY!=NULL){
        Unsigned *p=temp;
        temp=get_list();
        unsigned_free(p);
        if(pY->n!=0){
            int carry=0;
            Link* pX=x1->tail;
            while(pX!=NULL){
                Int digit=pX->n * pY->n + carry;
                carry=digit/10;
                digit%=10;
                insert_front(temp,digit,ignore);
                pX=pX->prior;
            }
            if(carry!=0){
                insert_front(temp,carry,ignore);
            }
            for (int i = 0; i < k; ++i) {
                insert_back(temp,0,ignore);
            }
            Unsigned *q=res;
            res=unsigned_add(res,temp);
            unsigned_free(q);
        }
        k++;
        pY=pY->prior;
    }

    return res;
}

Unsigned* unsigned_div(const Unsigned* x, const Unsigned* y, Unsigned** rem)
{
    // 在此处补充完整
    // 其中第一个参数表示被除数，第二个参数表示除数，第三个参数用于返回余数。
    int k=unsigned_cmp(x,y);
    if(k==-1){
        if(rem!=NULL)
            *rem=unsigned_copy(x);
        return unsigned_from_ll(0);
    }else if(k==0){
        if(rem!=NULL)
            *rem=unsigned_from_ll(0);
        return unsigned_from_ll(1);
    }else if(k==1){
        Unsigned* res=unsigned_from_ll(0);
        Unsigned* x1=unsigned_copy(x);
        if(rem!=NULL){
            Unsigned* p1=*rem;
            *rem=unsigned_from_ll(0);
            unsigned_free(p1);
        }
        Unsigned* one=unsigned_from_ll(1);
        do
        {
            Unsigned* p2=x1;
            x1=unsigned_sub(x1,y);
            unsigned_free(p2);

            Unsigned* p3=res;
            res=unsigned_add(res,one);
            unsigned_free(p3);
        } while (unsigned_cmp(x1,y)>=0);
        if(rem!=NULL){
            Unsigned* p4=*rem;
            *rem=x1;
            unsigned_free(p4);
        }
        unsigned_free(one);
        return res;
    }
}

// -----------------------------------------------------------------------------
