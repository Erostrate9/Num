
#include <stdlib.h>
#include "big_int.h"

// -----------------------------------------------------------------------------

static BigInt* get_big_int(void)
{
    BigInt* bi = malloc(sizeof(BigInt));
    bi->sign = plus;
    bi->val  = 0;
    return bi;
}

// 在此处可定义若干辅助函数，以供定义其它函数时使用
static int is_zero(const BigInt* x){
    if (x!=NULL && x->val!=NULL && x->val->size==1 && x->val->head==0)
    {
        return 1;
    }else{
        return 0;
    }
}


// -----------------------------------------------------------------------------

BigInt* big_int_from_ll(long long x)
{
    BigInt* bi = get_big_int();
    bi->sign = (x >= 0) ? plus : minus;
    bi->val  = unsigned_from_ll(bi->sign * x);
    return bi;
}

BigInt* big_int_copy(const BigInt* x)
{
    if (x==NULL)
        return 0;

    BigInt* y = get_big_int();
    y->sign = x->sign;
    y->val  = unsigned_copy(x->val);
    return y;
}

void big_int_free(BigInt* bi)
{
    if (!bi)
        return;

    unsigned_free(bi->val);
    free(bi);
}

char* big_int_to_str(const BigInt* bi)
{
    if (!(bi && bi->val->size > 0))
        return 0;

    Int n = (bi->sign == minus) ? bi->val->size + 2
                                : bi->val->size + 1;

    char* ret = calloc(n, sizeof(char));
    char* p   = ret;
    if (bi->sign == minus)
        *p++ = '-';

    for (Link* link = bi->val->head; link; ++p, link = link->next)
        *p = link->n + '0';
    *p = '\0';
    return ret;
}

long long big_int_to_ll(const BigInt* bi)
{
    return bi->sign * unsigned_to_ll(bi->val);
}

// 当x<y时，返回值=-1；
// 当x=y时，返回值=0；
// 当x>y时，返回值=1。
int big_int_cmp(const BigInt* x, const BigInt* y)
{
    // 在此处补充完整
    if(x->sign==minus && y->sign==minus){
        return unsigned_cmp(x->val,y->val)*(-1);
    }else if(x->sign==minus && y->sign==plus){
        if (is_zero(x)&&is_zero(y))
        {
            return 0;
        }else{
            return -1;
        }
    }else if(x->sign==plus && y->sign==minus){
        if (is_zero(x)&&is_zero(y))
        {
            return 0;
        }else{
            return 1;
        }

    }else if(x->sign==plus && y->sign==plus){
        return unsigned_cmp(x->val,y->val);
    }

    return 0;
}

BigInt* big_int_add(const BigInt* x, const BigInt* y)
{
    BigInt* res=get_big_int();
    if(x->sign==minus && y->sign==minus){
        res->sign=minus;
        res->val=unsigned_add(x->val,y->val);
    }else if(x->sign==minus && y->sign==plus){
        if(unsigned_cmp(x->val,y->val)==-1){
            res->sign=plus;
            res->val=unsigned_sub(y->val,x->val);
        }else{
            res->sign=minus;
            res->val=unsigned_sub(x->val,y->val);
        }
    }else if(x->sign==plus && y->sign==plus){
        res->sign=plus;
        res->val=unsigned_add(x->val,y->val);
    }else if(x->sign==plus && y->sign==minus){
        if(unsigned_cmp(x->val,y->val)==-1){
            res->sign=minus;
            res->val=unsigned_sub(y->val,x->val);
        }else{
            res->sign=plus;
            res->val=unsigned_sub(x->val,y->val);
        }
    }
    return res;
}

BigInt* big_int_sub(const BigInt* x, const BigInt* y)
{
    // 在此处补充完整
    BigInt* res=get_big_int();
    if(x->sign==minus && y->sign==minus){
        if(unsigned_cmp(x->val,y->val)==-1){
            res->sign=plus;
            res->val=unsigned_sub(y->val,x->val);
        }else{
            res->sign=minus;
            res->val=unsigned_sub(x->val,y->val);
        }
    }else if(x->sign==minus && y->sign==plus){
        res->sign=minus;
        res->val=unsigned_add(x->val,y->val);
    }else if(x->sign==plus && y->sign==plus){
        if(unsigned_cmp(x->val,y->val)==-1){
            res->sign=minus;
            res->val=unsigned_sub(y->val,x->val);
        }else{
            res->sign=plus;
            res->val=unsigned_sub(x->val,y->val);
        }
    }else if(x->sign==plus && y->sign==minus){
        res->sign=plus;
        res->val=unsigned_add(x->val,y->val);
    }
    return res;
}

BigInt* big_int_mul(const BigInt* x, const BigInt* y)
{
    if((is_zero(x))||is_zero(y)){
        return big_int_from_ll(0);
    }else{
        BigInt* res=get_big_int();
        res->sign=(x->sign==y->sign?plus:minus);
        res->val=unsigned_mul(x->val,y->val);
        return res;
    }
}
//对于m%n格式的表达式，当m与n的正负符号不同时，表达式最终取值的符号与m相同
//即当m是正数时，m%n的值是正数，当m是负数时，m%n的值是负数。
BigInt* big_int_div(const BigInt* x, const BigInt* y, BigInt** rem)
{
    // 在此处补充完整
    if(is_zero(x)){
        if(rem!=NULL){
            BigInt* p=*rem;
            *rem=big_int_from_ll(0);
            free(p);
        }
        return big_int_from_ll(0);
    }else if(is_zero(y)){
        //printf("/nArithmeticException: / by zero/n");
        return NULL;
    }else{
        BigInt* res=get_big_int();
        if(rem!=NULL){
            if(*rem==NULL){
                *rem = get_big_int();
            }
            Unsigned* p1=(*rem)->val;
            (*rem)->val=unsigned_from_ll(0);
            unsigned_free(p1);
            (*rem)->sign=x->sign;
        }
        res->sign=(x->sign==y->sign?plus:minus);
        if(rem!=NULL){
            res->val=unsigned_div(x->val,y->val,&((*rem)->val));
        }else{
            res->val=unsigned_div(x->val,y->val,NULL);
        }

        return res;
    }
}

// -----------------------------------------------------------------------------