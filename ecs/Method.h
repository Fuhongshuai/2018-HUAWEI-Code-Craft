//
// Created by zhongwen XU on 2018/3/30.
//

#ifndef ECS_METHOD_H
#define ECS_METHOD_H

#include <cstring>
#include <vector>
#include <climits>
using namespace std;
////********************拉格朗日****************////
/*
 * 参数说明：x[]为时间,y[]为相同天数请求个数,n为天数总个数,Predict_Time为预测时间
 */


/*
 * 拉格朗日算法,太差劲了
 */
 void lagrange(unsigned int x[],unsigned int y[],int n,unsigned int Predict_Time) {
    unsigned int L;
    unsigned int yy;
    yy = 0;
    for (int i = 0; i < n; i++) {
        L = 1;
        for (int j = 0; j < n; j++) {
            if (j != i)
                L *= (Predict_Time - x[j]) / (x[i] - x[j]);
        }
        yy += L * y[i];
    }

    printf("Predict_Time:%d\tcount:%d", Predict_Time, yy);
}

////*************************最小二乘法*********************///////

/*
 *    高斯消元法计算得到   n 次多项式的系数
   n: 系数的个数
   ata: 线性矩阵
   sumxy: 线性方程组的Y值
   a: 返回拟合的结果
 */

 void gauss_solve(int n,double A[],double x[],double b[])
{
    int i,j,k,r;
    double max;
    for (k=0;k<n-1;k++)
    {
        max=fabs(A[k*n+k]);                 // find maxmum
        r=k;
        for (i=k+1;i<n-1;i++)
        {
            if (max<fabs(A[i*n+i]))
            {
                max=fabs(A[i*n+i]);
                r=i;
            }
        }
        if (r!=k)
        {
            for (i=0;i<n;i++)        //change array:A[k]&A[r]
            {
                max=A[k*n+i];
                A[k*n+i]=A[r*n+i];
                A[r*n+i]=max;
            }

            max=b[k];                    //change array:b[k]&b[r]
            b[k]=b[r];
            b[r]=max;
        }

        for (i=k+1;i<n;i++)
        {
            for (j=k+1;j<n;j++)
                A[i*n+j]-=A[i*n+k]*A[k*n+j]/A[k*n+k];
            b[i]-=A[i*n+k]*b[k]/A[k*n+k];
        }
    }

    for (i=n-1;i>=0;x[i]/=A[i*n+i],i--)
    {
        for (j=i+1,x[i]=b[i];j<n;j++)
            x[i]-=A[i*n+j]*x[j];
    }

}



/*==================polyfit(n,x,y,poly_n,a,Predict_Time),返回预测结果===================*/
/*=======拟合y=a0+a1*x+a2*x^2+……+apoly_n*x^poly_n========*/
/*=====n是数据个数 xy是数据值 poly_n是多项式的项数======*/
/*===a0,a1,a2,……a[poly_n]，系数比项数多一（常数项）=====*/
 int polyfit(int n,double x[],double y[],int poly_n,double a[], int Predict_Time)
{
    int i,j;
    double *tempx,*tempy,*sumxx,*sumxy,*ata;

    tempx = (double *)calloc(n , sizeof(double));
    sumxx = (double *)calloc((poly_n*2+1) , sizeof(double));
    tempy = (double *)calloc(n , sizeof(double));
    sumxy = (double *)calloc((poly_n+1) , sizeof(double));
    ata = (double *)calloc( (poly_n+1)*(poly_n+1) , sizeof(double) );
    for (i=0;i<n;i++)
    {
        tempx[i]=1;
        tempy[i]=y[i];
    }
    for (i=0;i<2*poly_n+1;i++)
    {
        for (sumxx[i]=0,j=0;j<n;j++)
        {
            sumxx[i]+=tempx[j];
            tempx[j]*=x[j];
        }
    }

    for (i=0;i<poly_n+1;i++)
    {
        for (sumxy[i]=0,j=0;j<n;j++)
        {
            sumxy[i]+=tempy[j];
            tempy[j]*=x[j];
        }
    }

    for (i=0;i<poly_n+1;i++)
    {
        for (j=0;j<poly_n+1;j++)
        {
            ata[i*(poly_n+1)+j]=sumxx[i+j];
        }
    }
    gauss_solve(poly_n+1,ata,a,sumxy);

    double yy=a[0];
    for(int i=0;i<=poly_n;i++) {
        printf("a[%d]=%lf\n", i, a[i]);
        for(int j=1;j<=i;j++)
            yy+= a[i]*Predict_Time;
    }
//    printf("Predict_Time:%d\tcount:%d\n",Predict_Time,(int)yy);

    free(tempx);
    free(sumxx);
    free(tempy);
    free(sumxy);
    free(ata);
    return (yy-(int)yy>0.5)?(int)yy+1:(int)yy;

}

////******************************梯度下降***************************//
//point
class CPoint
{
public:
    CPoint()
    {
        m_x = 0.0;
        m_y = 0.0;
    }

    CPoint(double x, double y)
    {
        m_x = x;
        m_y = y;
    }

    double GetX() const
    {
        return m_x;
    }

    double GetY() const
    {
        return m_y;
    }
private:
    double m_x;
    double m_y;
};
// one-dimensional
// Y=f(X)=aX+b
class CLinearRegression
{
public:
    // 第一步骤：初始化
    int Init(const vector<CPoint>& points)
    {
        if(points.size() == 0)
        {
            return -1;
        }

        m_points = points;
    }

    // 第二步骤：计算a和b
    void Run()
    {
        // 先将a和b取个随机的初值，此处取了0
        m_a = 0;
        m_b = 0;
        long long  minCost =LONG_MAX;

        double curCost = 0.0;
        // 先计算最优的a
        for(double a=MIN_a; a<=MAX_a; a+=INC)
        {
            curCost = CaculateCost(a,m_b);
            if(curCost< minCost)
            {
                m_a = a;
                minCost = curCost;
            }
        }

        // 再计算最优的b
        for(double b=MIN_b; b<=MAX_b; b+=INC)
        {
            curCost = CaculateCost(m_a,b);
            if(curCost< minCost)
            {
                m_b = b;
                minCost = curCost;
            }
        }
    }

    // 第三步骤：输出结果
    double getResult(double x)
    {
        double yy=0;
        printf("Y=f(X)=%lfX+(%lf)\tminCost=%lf\n",m_a,m_b,CaculateCost(m_a,m_b));
        yy=m_a*x+m_b;
        return yy;

    }

private:
    // 内部函数：给定a,b，输出当前所有样本的预计与实际值的方差
    double CaculateCost(double a, double b)
    {
        double cost = 0.0;
        double xReal = 0.0;
        double yReal = 0.0;
        double yPredict = 0.0;
        double yDef = 0.0;
        for(unsigned int i=0;i< m_points.size();++i)
        {
            // x实际值
            xReal = m_points[i].GetX();
            // y实际值
            yReal = m_points[i].GetY();
            // y预测值
            yPredict = a*xReal + b;

            yDef = yPredict - yReal;
            // 累加方差
            cost += (yDef*yDef);
        }
        return cost;
    }

public:
    CLinearRegression() {}

private:
    // a，b的取值范围
     double MIN_a = -100;
    double MAX_a = 100;
      double MIN_b = -100;
      double MAX_b = 100;
    // 梯度递增值
   double INC = 0.0001;
    // a，b，样本的保存
    double m_a;
    double m_b;
    vector< CPoint> m_points;
};


double expon(int n,double x[],int num,double a,double b){
    double y[n+1];
    double t[n+1];
    memset(y,0,sizeof(y));
    memset(t,0,sizeof(t));
    double ans = 0;
    y[0] = x[0];
    t[0] = x[0];
    for(int i = 1;i < n;++ i){
        y[i] = a * x[i]+(1-a)*(y[i-1]+t[i-1]);
        t[i]=b*(y[i]-y[i-1])+(1-b)*t[i-1];
    }
    for(int i = 1;i <= num;++ i){
        ans += y[n-1] + i * t[n-1];
    }
    if(ans < 0){
        ans = 0;
    }
    return int(ans);
}

#endif //ECS_METHOD_H
