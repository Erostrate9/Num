
#include <stdlib.h>
#include <string.h>
#include "rational.h"

// -----------------------------------------------------------------------------

static void unsigned_swap(Unsigned* x, Unsigned* y)
{
    Unsigned z = *x;
    *x = *y;
    *y = z;
}

static void big_int_swap(BigInt* x, BigInt* y)
{
    BigInt z = *x;
    *x = *y;
    *y = z;
}

static int unsigned_is_zero(const Unsigned* x)
{
    return x && x->size == 1 && x->head->n == 0;
}

static int big_int_is_zero(const BigInt* bi)
{
    return bi && unsigned_is_zero(bi->val);
}

// 求 x 和 y 的最大公约数。提示：使用欧几里得算法。
static Unsigned* unsigned_gcd(const Unsigned* x, const Unsigned* y)
{
    // 在此处补充完整
    Unsigned* rem=unsigned_from_ll(0);
    Unsigned* zero=unsigned_from_ll(0);
    Unsigned* M=unsigned_copy(x);
    Unsigned* N=unsigned_copy(y);
    // while(N>0)
    while(unsigned_cmp(N,zero)==1)
    {
        // Rem = M % N;
        // M = N;
        // N = Rem;
        unsigned_div(M,N,&rem);
        Unsigned* p=M;
        M = unsigned_copy(N);
        unsigned_free(p);

        Unsigned* q=N;
        N = unsigned_copy(rem);
        unsigned_free(q);
    }
    unsigned_free(N);
    unsigned_free(zero);
    unsigned_free(rem);
    return M;
}

// 以 x 作分子，y 作分母，将它们化简，即同时除以它们
// 的最大公约数。化简后分母应为正数，且若分子为 0，
// 分母应化为 1。若分母为 0，则不用化简。
static void big_int_cancel(BigInt* x, BigInt* y)
{
    // 在此处补充完整
    if(x==NULL || y==NULL || x->val==NULL || y->val==NULL){
        return;
    }
    if(big_int_is_zero(y)){
        return;
    }
    if(big_int_is_zero(x)){
        y->sign=plus;
        Unsigned* p=y->val;
        y->val=unsigned_from_ll(1);
        free(p);
        x->sign=plus;
        return;
    }
    //x!=0 y!=0
    x->sign=(x->sign==y->sign?plus:minus);
    y->sign=plus;
    Unsigned* gcd=unsigned_gcd(x->val,y->val);
    Unsigned* p1=x->val,*p2=y->val;
    x->val=unsigned_div(x->val,gcd,NULL);
    y->val=unsigned_div(y->val,gcd,NULL);
    unsigned_free(gcd);
    unsigned_free(p1);
    unsigned_free(p2);
}

static BigRat* get_big_rat()
{
    BigRat* br = malloc(sizeof(BigRat));
    br->num = br->denom = 0;
    return br;
}

static int big_int_is_one(const BigInt* bi)
{
    return bi &&
           bi->sign == plus &&
           bi->val->size == 1 &&
           bi->val->head->n == 1;
}

// 在此处可定义若干辅助函数，以供定义其它函数时使用


// -----------------------------------------------------------------------------

BigRat* big_rat_from_ll(long long num, long long denom)
{
    BigInt* x = big_int_from_ll(num);
    BigInt* y = big_int_from_ll(denom);

    BigRat* ret = 0;

    if (!big_int_is_zero(y)) {
        ret = get_big_rat();
        big_int_cancel(x, y);
        ret->num   = x;
        ret->denom = y;
        x = y = 0;
    }

    big_int_free(x);
    big_int_free(y);
    return ret;
}

BigRat* big_rat_copy(const BigRat* x)
{
    if (x==NULL)
        return 0;

    BigRat* y = get_big_rat();
    y->num   = big_int_copy(x->num);
    y->denom = big_int_copy(x->denom);
    return y;
}

void big_rat_free(BigRat* br)
{
    if (!br)
        return;

    big_int_free(br->num);
    big_int_free(br->denom);
    free(br);
}

char* big_rat_to_str(const BigRat* br)
{
    if (!br)
        return 0;

    if (big_int_is_one(br->denom))
        return big_int_to_str(br->num);

    char* x = big_int_to_str(br->num);
    char* y = big_int_to_str(br->denom);

    char* ret = 0;
    if (x && y && (ret = malloc(strlen(x) + strlen(y) + 4))) {
        strcpy(ret, "(");
        strcat(ret, x);
        strcat(ret, "/");
        strcat(ret, y);
        strcat(ret, ")");
    }

    free(x);
    free(y);
    return ret;
}

void big_rat_to_ll(const BigRat* br, long long* num, long long* denom)
{
    if (!br)
        return;

    if (num) { *num = big_int_to_ll(br->num); }
    if (denom) { *denom = big_int_to_ll(br->denom); }
}

BigRat* big_rat_add(const BigRat* x, const BigRat* y)
{
    // 在此处补充完整
    BigRat* x1=big_rat_copy(x);
    BigRat* y1=big_rat_copy(y);

    BigRat* res=get_big_rat();
    big_int_cancel(x1->num,x1->denom);
    big_int_cancel(y1->num,y1->denom);
    if(big_int_is_zero(x1->num)){
        big_rat_free(x1);
        big_rat_free(res);
        return y1;
    }else if(big_int_is_zero(y1->num)){
        big_rat_free(y1);
        big_rat_free(res);
        return x1;
    }else{
        res->denom=big_int_mul(x1->denom,y1->denom);
        BigInt* x1n=big_int_mul(x1->num,y1->denom);
        BigInt* y1n=big_int_mul(y1->num,x1->denom);
        res->num=big_int_add(x1n,y1n);
        big_int_cancel(res->num,res->denom);

        big_int_free(x1n);
        big_int_free(y1n);
        big_rat_free(x1);
        big_rat_free(y1);
        return res;
    }
}

BigRat* big_rat_sub(const BigRat* x, const BigRat* y)
{
    // 在此处补充完整
    BigRat* x1=big_rat_copy(x);
    BigRat* y1=big_rat_copy(y);

    BigRat* res=get_big_rat();
    big_int_cancel(x1->num,x1->denom);
    big_int_cancel(y1->num,y1->denom);
    if(big_int_is_zero(x1->num)){
        y1->num->sign=y1->num->sign==plus?minus:plus;
        big_rat_free(x1);
        big_rat_free(res);
        return y1;
    }else if(big_int_is_zero(y1->num)){
        big_rat_free(y1);
        big_rat_free(res);
        return x1;
    }else{
        y1->num->sign=y1->num->sign==plus?minus:plus;
        res->denom=big_int_mul(x1->denom,y1->denom);
        BigInt* x1n=big_int_mul(x1->num,y1->denom);
        BigInt* y1n=big_int_mul(y1->num,x1->denom);
        res->num=big_int_add(x1n,y1n);
        big_int_cancel(res->num,res->denom);

        big_int_free(x1n);
        big_int_free(y1n);
        big_rat_free(x1);
        big_rat_free(y1);
        return res;
    }

}

BigRat* big_rat_mul(const BigRat* x, const BigRat* y)
{
    // 在此处补充完整
    BigRat* x1=big_rat_copy(x);
    BigRat* y1=big_rat_copy(y);
    BigRat* res=get_big_rat();

    big_int_cancel(x1->num,x1->denom);
    big_int_cancel(y1->num,y1->denom);

    if(big_int_is_zero(x1->num)){
        big_rat_free(y1);
        big_rat_free(res);
        return x1;
    }else if(big_int_is_zero(y1->num)){
        big_rat_free(x1);
        big_rat_free(res);
        return y1;
    }else if (big_int_is_one(x1->num)&&big_int_is_one(x1->denom)){
        big_rat_free(x1);
        big_rat_free(res);
        return y1;
    }else if (big_int_is_one(y1->num)&&big_int_is_one(y1->denom)){
        big_rat_free(y1);
        big_rat_free(res);
        return x1;
    }else{
        res->denom=big_int_mul(x1->denom,y1->denom);
        res->num=big_int_mul(x1->num,y1->num);
        big_int_cancel(res->num,res->denom);

        big_rat_free(x1);
        big_rat_free(y1);
        return res;
    }
}

BigRat* big_rat_div(const BigRat* x, const BigRat* y)
{
    // 在此处补充完整
    if(big_int_is_zero(y->num)){
        return NULL;
    }else{
        BigRat* y1=big_rat_copy(y);
        big_int_swap(y1->num,y1->denom);
        BigRat* res=big_rat_mul(x,y1);
        big_rat_free(y1);
        return res;
    }
}

// -----------------------------------------------------------------------------
