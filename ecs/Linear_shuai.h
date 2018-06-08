#include "include/linearRegression.h"


LinearRegression::LinearRegression(Data samples,
                                   Label l, double alpha)
{
    N = samples.size();
    if(N == 0)
        D = 0;
    else D = samples[0].size();
    Samples = samples;
    processData();
    L = l;
    initW();
    updateY();
    updateError();
    Alpha = alpha;
}

void LinearRegression::processData()
{
    Matrix dataMatrix(Samples);
    Data trsData = dataMatrix.getTrsMatrix();
    d_vec aug(N, 1);
    trsData.insert(trsData.begin(), aug);
    Samples = trsData;
    return;
}

void LinearRegression::initW()
{
    W.resize(D + 1, 0);
    return ;
}

void LinearRegression::updateError()
{
    double sumError = 0;
    for(int i = 0; i != N; ++i)
    {
        sumError += (Y[i] - L[i]) * (Y[i] - L[i]);
    }
    Error = sumError / (double)2 * N;
}

void LinearRegression::updateW()
{
    double sum = 0;
    double detaW = 0;
    for(int i = 0; i != D + 1; ++i)
    {
        sum = 0;
        for(int j = 0; j != N; ++j)
        {
            sum += (Y[j] - L[j]) * Samples[i][j];
        }
        detaW = Alpha * (1 / (double)N * sum);
        W[i] = W[i] - detaW;
    }
}

void LinearRegression::updateY()
{
    d_d_vec w;
    w.push_back(W);
    Matrix wMatrix(w);
    Matrix samplesMatrix(Samples);
    Matrix yMatrix;
    yMatrix = wMatrix * samplesMatrix;
    Y = yMatrix.getMatrix()[0];
}

void LinearRegression::train()
{
    int iterCount = 0;
    do
    {
        updateW();
        updateY();
        updateError();
        ++iterCount;
    }while(iterCount < 1000);
    cout<<"训练结束后误差率:"<<Error<<endl;
    cout<<"训练得到权值:("<<W[0]<<", "<<W[1]<<endl;
}

d_vec LinearRegression::predict(Data pdata)
{
    d_vec result;
    d_d_vec w;
    w.push_back(W);
    Matrix wMatrix(w);
    Matrix dataMatrix(pdata);
    Matrix yMatrix;
    yMatrix = wMatrix * dataMatrix;
    result = yMatrix.getMatrix()[0];
    return result;
}
