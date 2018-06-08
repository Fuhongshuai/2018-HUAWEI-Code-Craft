#include "predict.h"
#include "Method.h"
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <ctime>
#include <cstring>
#include <set>
#include <algorithm>
#include <sys/time.h>
#include "LinearRegression.h"

#define N 10000

#define MAX_TIME 365*4
using namespace std;


int Name_Time[N][MAX_TIME]={0};

char Begin_Time[N]={0};
char End_Time[N]={0};
char First_Time[N]={0};
char Last_Time[N]={0};
double x[10000]={0};
double x2[10000] = {0};
double y2[10000] = {0};
double x3[10000] = {0};
double y3[10000] = {0};
double y[10000]={0};
int Predict_ID[N+1]={0};
char ID[N]={0};
int flavor_ID=0;
char Time[N]={0};
int Num_Time=0;
int WideTime;
vector<Ecs> ecss;


int TimeToInt(const char Time[],const char Begin_Time[]){

    time_t time1=0;
    time_t time2=0;
    struct tm tm_time1{0};
    struct tm tm_time2{0};
    strptime(Time,"%Y-%m-%d",&tm_time1);
    time1=mktime(&tm_time1);
    strptime(Begin_Time,"%Y-%m-%d",&tm_time2);
    time2=mktime(&tm_time2);
    double time=difftime(time1,time2);
    if(time<0)
        time=0;
    return (int)(time/(24*60*60));

}


void divide_Time(int EndTime, int WideTime){
    int temp[16][100];
    memset(temp,0, sizeof(temp[0])*16);
    puts("\nChange time\n");
    int mod=EndTime%WideTime;
    for(int m=1;m<16;m++)
        for(int L=mod+1;L<=EndTime;L++){
            Name_Time[m][L-mod-1]=Name_Time[m][L];
            printf("change Name_Time[%d][%d]=%d\n",m,L-mod-1,Name_Time[m][L]);
        }

    for(int i=1;i<16;i++){
        for(int j=0;j<=EndTime-mod-1;j++){
            int k=j/WideTime;
            temp[i][k]+=Name_Time[i][j];
        }
    }
    memset(Name_Time,0, sizeof(Name_Time[0])*100);
//    printf("\n%d\n", sizeof(Name_Time[0]));
    for(int i=1;i<16;i++)
        for(int j=0;j<=EndTime-mod-1;j++)
            Name_Time[i][j]=temp[i][j];
}



void predict_server(char * info[MAX_INFO_NUM], char * data[MAX_DATA_NUM], int data_num, char * filename) {
    char NoUseID[N];
    int NoUse = 0;
    sscanf(data[0], "%s\tflavor%d\t%s", NoUseID, &NoUse, Begin_Time);
    printf("Begin_Time:%s\t", Begin_Time);
    sscanf(data[data_num - 1], "%s\tflavor%d\t%s", NoUseID, &NoUse, End_Time);
    printf("End_Time:%s\n", End_Time);
    int EndTime = TimeToInt(End_Time, Begin_Time);

    int Predict_Count = 0;
    sscanf(info[2], "%d", &Predict_Count);
    for (int k = 0; k < Predict_Count; k++) {
        sscanf(info[3 + k], "flavor%d", Predict_ID + k);
    }
    for (int i = 0; i < Predict_Count; i++) {
        printf("flavor:%d\t", Predict_ID[i]);
    }
    putchar('\n');
    sscanf(info[6+Predict_Count], "%s", First_Time);
    sscanf(info[7+Predict_Count], "%s", Last_Time);
    printf("First_Time:%s\tLast_Time:%s\n", First_Time, Last_Time);
    int first = TimeToInt(First_Time, Begin_Time);
    int last = TimeToInt(Last_Time, Begin_Time);
    //int first = 1;
    //int last = 14;
    //printf("first:%d\tlast:%d\n", first, last);

    for (int i = 0; i < data_num; i++) {
//		printf(data[i]);
        sscanf(data[i], "%s\tflavor%d\t%s", ID, &flavor_ID, Time); // NOLINT
        Num_Time = TimeToInt(Time, Begin_Time);
        //printf("ID:%s\tflavor:%d\tTime:%s\ttime:%d\n", ID, flavor_ID, Time, Num_Time);
        Name_Time[flavor_ID][Num_Time]++;
    }
////************************************????????????? Name_Time[flavor_ID][Num_Time]****************////

    for (int j = 1; j < 16; j++) {
        for (int k = 1; k <= EndTime; k++){
            //if(Name_Time[j][k]-Name_Time[j][k-1] > 11){
            //  Name_Time[j][k] = int((Name_Time[j][k-1]+Name_Time[j][k-1])/2);
            //}
            Name_Time[j][k] = int(0.66*Name_Time[j][k] + 0.34*Name_Time[j][k-1]);
            if(Name_Time[j][k]-Name_Time[j][k-1] > 23){
                Name_Time[j][k] = int(Name_Time[j][k]*0.8);
            }
        }
    }
    /*
   for (int j = 1; j < 16; j++) {
       for (int k = 0; k <= EndTime; k++){
           if(Name_Time[j][k] > 20){
               Name_Time[j][k] = int(Name_Time[j][k]*0.6);
           }
       }
   }
     */

    WideTime = last-first+1;

    divide_Time(EndTime,WideTime);
    puts("\nDivide time\n");
    int mod=EndTime%WideTime;
    int END=(EndTime-mod-1)/WideTime;
    for(int j=1;j<16;j++)
        for(int i=0;i<=END;i++)
            printf("divided Name_Time[%d][%d]:%d\n",j,i,Name_Time[j][i]);

    int poly_n = 1;
    int total = 0;
    int num_end[16]={0};
    int start=END+1;
    int end=start+(last-first+1)/WideTime;
    int res1 = end-start;
    printf("\nstart:%d\tend:%d\n",start,end);
    int n = END+1;
    printf("%d\n",n);
    for (int i = 0; i < Predict_Count; i++) {
        memset(x,0, sizeof(x));
        memset(y,0, sizeof(y));
        memset(x2,0,sizeof(x2));
        memset(y2,0,sizeof(y2));
        memset(x3,0, sizeof(x3));
        memset(y3,0,sizeof(y3));

        int Sum_Predict = 0;
        int flag = 0;
        for(int j = 0;j < n;++ j){
            x[j] = flag*1.0;
            y[j] = Name_Time[Predict_ID[i]][j];
            flag++;
        }

        int zhongjian = n-1;
        int flag1 = 0;
        for(int j = 0;j < zhongjian;++ j) {
            x2[j] = flag1*1.0;
            y2[j] = Name_Time[Predict_ID[i]][j];
            flag1++;
        }
        for(int j = zhongjian;j < n;++ j){
            x3[j] = flag1*1.0;
            y3[j] = Name_Time[Predict_ID[i]][j];
            flag1++;
        }

        /*
        double p1;
        double ans_test = 10000.0;
        for(double m = 0.4;m < 0.72;m += 0.001) {
            double ans = expon3(END,y2,1,m);
            //printf("%lf ",ans);
            double test = (ans-y3[flag1-1])*(ans-y3[flag1-1]);
            if(ans_test > test){
                ans_test = test;
                p1 = m;

            }
        }
        int time_span = (last-first+1)/WideTime;

        Sum_Predict = expon3(n,y,time_span,p1);

        num_end[Predict_ID[i]] = Sum_Predict;
        total += num_end[Predict_ID[i]];

        */
        double p1,q1;
        double ans_test = 10000.0;
        for(double m = 0.35;m < 0.6;m += 0.001) {
            for(double l = 0.25;l < 0.5;l += 0.001) {
                double ans = expon(END,y2,1,m,l);
                //printf("%lf ",ans);
                double test = (ans-y3[flag1-1])*(ans-y3[flag1-1]);
                if(ans_test > test){
                    ans_test = test;
                    p1 = m;
                    q1 = l;
                }
            }
        }
        int time_span = (last-first+1)/WideTime;
        //printf("%lf %lf\n",p1,q1);
        Sum_Predict = expon(n,y,time_span,p1,q1);

        num_end[Predict_ID[i]] = Sum_Predict;
        total += num_end[Predict_ID[i]];

    }


    int countOfEsc;


    sscanf(info[0], "%d", &countOfEsc);

    for(int i = 1; i <= countOfEsc; ++ i) {
        istringstream is(info[i]);
        string name;
        int cpu;
        int mem;
        is >> name >> cpu >> mem;
        mem *= 1024;
        ecss.push_back(Ecs{name, cpu, mem});
    }

    int typeOfVm;

    sscanf(info[countOfEsc+2], "%d", &typeOfVm);

    // res = to_string(totalVm) + "\n" + res;
    map<string, Vm> vmSize;
    for (int i = countOfEsc+3, j = 0; j < typeOfVm; ++i, ++ j) {
        istringstream is(info[i]);
        string name;
        int cpu;
        int mem;
        is >> name >> cpu >> mem;
        vmSize[name] = Vm{cpu, mem};
    }


    printf("total: %d\n", total);

    int totalVm = 0;
    string res = "";
    vector<string> vm;
    set<string> vmType;
    map<string, int> vmCnt;
    for (int j = 1; j <= 15; ++j) {
        if (vmSize.count("flavor" + to_string(j))) {
            num_end[j] += 350;
        }
        if (num_end[j]) {
            printf("flavor%d %d\n", j, num_end[j]);
            int x = num_end[j];
            totalVm += x;
            vmCnt["flavor" + to_string(j)] = x;
            vmType.insert("flavor" + to_string(j));
            string debugInfo = "flavor" + to_string(j) + " " + to_string(x) + "\n";
            cout << debugInfo;
            while (x --) {
                vm.push_back("flavor" + to_string(j));
            }
        }
    }



/***************************************DP****************************************************
    {
        string res1 = "";
        int vmCount = 1;
        unsigned int use = 0;
        while (vm.size() > use) {
            vector<int> dp(ees + 10);
            vector<vector<int> > pre(vm.size() + 10, vector<int>(a + 10));
            for (unsigned int j = 0; j < vm.size(); ++j) {
                string x = vm[j];
                if (x == "+") continue;
                for (int i = a; i >= vmSize[x].cpu; --i) {
                    int tmp = dp[i - vmSize[x].cpu] + vmSize[x].mem;
                    if (tmp <= b && tmp > dp[i]) {
                        dp[i] = tmp;
                        pre[j][i] = 1;
                    }
                }
            }

            if (vmCount != 1) {
                res1 += "\n";
            }

            int mxId = a;
            for (int j = a; j >= 0; --j) {
                if (dp[j] > dp[mxId]) {
                    mxId = j;
                }
            }

            res1 += to_string(vmCount);
            int i = vm.size() - 1;
            int j = a;
            int tmp = 0;
            int x = a;
            int y = b;
            while (i >= 0 && j > 0) {
                if (pre[i][j] == 1) {
                    res1 += " " + vm[i] + " 1";
                    use++;
                    j -= vmSize[vm[i]].cpu;
                    tmp += vmSize[vm[i]].mem;
                    x -= vmSize[vm[i]].cpu;
                    y -= vmSize[vm[i]].mem;
                    vm[i] = "+";
                }
                i--;
            }
            while(true) {
                bool ok = false;
                for(string name : vmType) {
                    auto vm = vmSize[name];
                    if(vm.cpu <= x && vm.mem <= y) {
                        x -= vm.cpu;
                        y -= vm.mem;
                        ok = true;
                        res1 += " " + name + " 1";
                        vmCnt[name] ++;
                        totalVm ++;
                        break;
                    }
                }
                if(!ok) break;
            }
            vmCount++;
        }

        res += to_string(totalVm) + "\n";
        for(auto kv : vmCnt) {
            res += kv.first + " " + to_string(kv.second) + "\n";
        }

        res += "\n";
        res += to_string(vmCount-1) + "\n";
        res += res1;
    }

***************************************DP****************************************************/


/********************************First Fit****************************************************/

    int iterationCnt = 0;
    vector<map<string, int> > resMap[10];

    struct timeval l, r;
    gettimeofday( &l, NULL );
    r = l;
    double minRate = 1000;

    while (r.tv_sec-l.tv_sec < 80) {
        vector<Vm> list[10];
        vector<map<string, int> > tmpMap[10];
        double totalOfCpu = 0;
        double useOfCpu = 0;
        double totalOfMem = 0;
        double useOfMem = 0;
        for (int i = 0; i < 10; ++i) {
            tmpMap[i].push_back(map<string, int>());
            list[i].push_back(Vm{ecss[i].cpu, ecss[i].mem});
        }
        for (auto name : vm) {
            Vm now = vmSize[name];
            useOfCpu += now.cpu;
            useOfMem += now.mem;
            int index = rand() % ecss.size();
            int ans = 1;
            for (int i = 0; i < list[index].size(); ++i) {
                Vm x = list[index][i];
                if (x.cpu >= now.cpu && x.mem >= now.mem) {
                    list[index][i].cpu -= now.cpu;
                    list[index][i].mem -= now.mem;
                    tmpMap[index][i][name]++;
                    ans--;
                    break;
                }
            }
            if (ans > 0) {
                map<string, int> tmp;
                tmp[name]++;
                tmpMap[index].push_back(tmp);
                totalOfCpu += ecss[index].cpu;
                totalOfMem += ecss[index].mem;
                list[index].push_back(Vm{ecss[index].cpu - now.cpu, ecss[index].mem - now.mem});
            }
        }
        if (minRate > useOfCpu / totalOfCpu * 0.5 + useOfMem / totalOfMem * 0.5) {
            for (int i = 0; i < ecss.size(); ++i) {
                resMap[i].swap(tmpMap[i]);
            }
            minRate = useOfCpu / totalOfCpu * 0.5 + useOfMem / totalOfMem * 0.5;
        }
        random_shuffle(vm.begin(), vm.end());
        gettimeofday(&r, NULL);
    }

    string section2 = "\n";

    for(int i = 0; i < ecss.size(); ++ i) {
        if(i!=0) section2 += "\n\n";
        section2 += ecss[i].name + " " + to_string(resMap[i].size()) + "\n";
        for(int j = 0; j < resMap[i].size(); ++ j) {
            if(j!=0) section2 += "\n";
            section2 += ecss[i].name + "-" + to_string(j+1);
//            for(int k = 0; k < resMap[i][j].size(); ++ k) {
            for(auto kv : resMap[i][j]) {
                section2 += " " + kv.first + " " + to_string(kv.second);
            }
//            }
        }
    }

    string section1 = "";
    int countOfVm = 0;
    for (auto kv : vmCnt) {
        section1 += kv.first + " " + to_string(kv.second) + "\n";
        countOfVm += kv.second;
    }
    section1 = to_string(countOfVm) + "\n" + section1;

    write_result((section1+section2).c_str(), filename);

/********************************First Fit****************************************************/

//    write_result(res.c_str(), filename);

}
