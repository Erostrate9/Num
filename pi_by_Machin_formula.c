
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rational.h"

// -----------------------------------------------------------------------------

// 精确到小数点后 1000 位的 π 值，供与自己求得的 π 值比较，
// 以确定自己所求 π 值的精度（精确到小数点后的位数）。
const char pi_string[] =
        "3."
        "14159265358979323846264338327950288419716939937510"
        "58209749445923078164062862089986280348253421170679"
        "82148086513282306647093844609550582231725359408128"
        "48111745028410270193852110555964462294895493038196"
        "44288109756659334461284756482337867831652712019091"
        "45648566923460348610454326648213393607260249141273"
        "72458700660631558817488152092096282925409171536436"
        "78925903600113305305488204665213841469519415116094"
        "33057270365759591953092186117381932611793105118548"
        "07446237996274956735188575272489122793818301194912"
        "98336733624406566430860213949463952247371907021798"
        "60943702770539217176293176752384674818467669405132"
        "00056812714526356082778577134275778960917363717872"
        "14684409012249534301465495853710507922796892589235"
        "42019956112129021960864034418159813629774771309960"
        "51870721134999999837297804995105973173281609631859"
        "50244594553469083026425223082533446850352619311881"
        "71010003137838752886587533208381420617177669147303"
        "59825349042875546873115956286388235378759375195778"
        "18577805321712268066130019278766111959092164201989";

// -----------------------------------------------------------------------------

// 在此处可定义若干辅助函数，以供定义其它函数时使用
int get_acc(const char* pi_string,const char* pi){
    int acc=0;
    for (int i = 0; pi[i]!='\0'; ++i) {
        if (pi_string[i]==pi[i]){
            acc++;
        }else{
            break;
        }
    }
    return (acc-2)>=0?(acc-2):0;
}
// 将x增大 10 的 n 次方。n>=0
BigInt* big_int_power10(BigInt* x,int n)
{
    static const Int ignore = 42;
    if (x->val->size==1 && x->val->head->n==0){
        return x;
    }
    for (int i = 0; i < n; ++i)
        insert_back(x->val, 0, ignore);
    return x;
}

// 求 arctan(x) 的前 n 项。
BigRat* arctan(const BigRat* x, int n)
{
    // 在此处补充完整
    BigRat* res=big_rat_copy(x);
    Sign key=minus;
    BigRat* k=big_rat_from_ll(1,1);
    BigRat* temp_x=big_rat_copy(x);
    BigInt* two=big_int_from_ll(2);
    BigRat* x2=big_rat_mul(x,x);
    for (long long i = 1; i < n; i++)
    {
        BigRat* temp=NULL;
        //k+=2
        BigInt* p1=k->denom;
        k->denom=big_int_from_ll(2*i+1);
        big_int_free(p1);

        //x^k*=x^2
        BigRat* p2=temp_x;
        temp_x=big_rat_mul(temp_x,x2);
        big_rat_free(p2);

        //temp=temp_x/k
        temp=big_rat_mul(temp_x,k);

        //res +or- temp
        if(key==minus){
            BigRat* p4=res;
            res=big_rat_sub(res,temp);
            big_rat_free(p4);
        }else{
            BigRat* p4=res;
            res=big_rat_add(res,temp);
            big_rat_free(p4);
        }
        key=(key==minus?plus:minus);
        big_rat_free(temp);
    }

    big_rat_free(k);
    big_rat_free(temp_x);
    big_int_free(two);
    big_rat_free(x2);
    return res;
}

// 求 10 的 n 次方。
BigInt* power10(int n)
{
    static const Int ignore = 42;

    BigInt* ret = big_int_from_ll(1);
    for (int i = 0; i < n; ++i)
        insert_back(ret->val, 0, ignore);
    return ret;
}

// 使用 Machin 公式，通过求 arctan(x) 的前 items 项来求 π 值。
BigRat* get_pi(int items)
{
    // 在此处补充完整
    BigRat* A=big_rat_from_ll(16,1);
    BigRat* B=big_rat_from_ll(4,1);
    BigRat* x=big_rat_from_ll(1,5);
    BigRat* y=big_rat_from_ll(1,239);
    BigRat* C=arctan(x,items);
    BigRat* D=arctan(y,items);
//    BigRat* C=big_rat_from_ll(1,5);
//    BigRat* D=big_rat_from_ll(1,239);
//    BigRat* C=big_rat_from_ll(74,375);
//    BigRat* D=big_rat_from_ll(171362,40955757);
    BigRat* s1=big_rat_mul(A,C);
    BigRat* s2=big_rat_mul(B,D);
    BigRat* pi=big_rat_sub(s1,s2);
    big_rat_free(A);
    big_rat_free(B);
    big_rat_free(C);
    big_rat_free(D);
    big_rat_free(x);
    big_rat_free(y);
    big_rat_free(s1);
    big_rat_free(s2);
    return pi;
}

// 将以分数形式表示的 π 值 pi 转换为以小数形式表示。
// 提示：若 pi 是使用 Machin 公式，通过求 arctan(x)
// 的前 items 项求得的 π 值，则将其转换为小数形式后，
// 其精度不超过小数点后 2*items 位。比如，求 arctan(x)
// 的前 2 项得到的 pi 值为 5359397032/1706489875，它
// 化为小数为：3.1405970293260603143045311065792，该小数
// 形式的 π 值的精度不会超过 2*2=4 位，实际只精确到小数点
// 后两位，即 3.14。因此，在将 pi 转换为小数形式时，最多
// 只需保留小数点后 2*items 位。为了保留 pi 的小数点后
// 2*items 位，可将 pi 的分子放大“10 的 2*items 次方”倍，再
// 用分子和分母做整数除法。比如，5359397032/1706489875 的分子
// 放大 10000 倍后再除以分母（整数除法），可得 31405，其中 3 为
// 小数点前数字，1405 为小数点后数字。
char* to_str(const BigRat* pi, int items)
{
    // 在此处补充完整
    BigInt* x=big_int_copy(pi->num);
    big_int_power10(x,2*items);
    BigInt* pi_dec=big_int_div(x,pi->denom,NULL);
    char* pi_src=big_int_to_str(pi_dec);
    int len=(int)pi_dec->val->size;
    char*p = (char *)malloc((len+2)*sizeof(char)); // 申请新的"数组 ";
    p[0]=pi_src[0];
    p[1]='.';
    int i;
    for(i=1;i<len;i++){	// 将原来的数组copy到新申请的更大的数组中
        p[i+1]=pi_src[i];
    }
    p[i+1]='\0';
    free(pi_src);// 释放原数组的空间
    pi_src=p;	// 临时的指针指向该"新数组";
    return  pi_src;

}

// -----------------------------------------------------------------------------

int main(void)
{
    // 在此处补充完整
    int items=40;
    BigRat* pi=get_pi(items);
//    BigRat* pi=big_rat_from_ll(5359397032,1706489875);
    char* pi_str=to_str(pi,items);
    int acc =get_acc(pi_string,pi_str);
    pi_str[acc+2]='\0';
    printf("numerator\t= %s\n",big_int_to_str(pi->num));
    printf("denominator\t= %s\n",big_int_to_str(pi->denom));
    printf("pi\t= %s\n\n",pi_str);
    printf("numerator\t:%lld digits\n",pi->num->val->size);
    printf("denominator\t:%lld digits\n",pi->denom->val->size);
    printf("pi decimal places : %d accurate\n",acc);


}

// -----------------------------------------------------------------------------



