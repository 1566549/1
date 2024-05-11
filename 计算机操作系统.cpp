#include <stdio.h>
 
struct sjf
{
    char name[10]; 
    float arr; 
    float ing; 
    float ks; 
    float jieshu;   
    float zhouz;     
    float Dzhouz; 
};
 
void input(struct sjf *p,int N)
{
    printf("请输入进程号、提交时间、运行时间：\\n");
    printf("\\n");
    for(int i=0; i<N; i++)
    {
        scanf("%s",p[i].name);
        scanf("%f",&p[i].arr);
        scanf("%f",&p[i].ing);
    }
}
 
void sort_arr(struct sjf *p,int N) 
{
    int i,j;
    struct sjf temp;
    for(i=0; i<N-1; i++)
    {
        for(j=0; j<N-i-1; j++)
        {
            if(p[j].arr>p[j+1].arr)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
 
void sort_ing(struct sjf *p,int N)
{
    struct sjf temp;
    int k=0;
    float end=0.0;
    for(int i=0; i<N; i++)
    {
        k=i;
        while(p[i].arr<=end&&i<N)
            i++;
        for (int t=k; t<i-1; t++)
        {
            for (int j = t+1; j<i; j++)
            {
                if(p[t].ing < p[j].ing)
                    continue;
                else
                {
                    temp = p[t];
                    p[t] = p[j];
                    p[j] = temp;
                }
            }
        }
        i=k; 
        end+=p[i].ing;
    }
}
 
void run(struct sjf *p,int N)
{
    float sta = p[0].arr;
    for (int i=0; i<N; i++)
    {
        p[i].ks = sta;
        p[i].jieshu = p[i].ks + p[i].ing;
        p[i].zhouz = p[i].jieshu - p[i].arr;
        p[i].Dzhouz = p[i].zhouz / p[i].ing;
        if (i == N-1)
            break;
        sta = p[i].jieshu>p[i+1].arr?p[i].jieshu:p[i+1].arr;
    }
}
 
void show(struct sjf *p,int N)
{
    int i; 
    printf("进程号	提交时间	运行时间	开始		结束		周转时间	带权周转时间\\n");
    for(i=0; i<N; i++)
    {
        printf("%s	",p[i].name);
        printf("%.2f		",p[i].arr);
        printf("%.2f		",p[i].ing);
        printf("%.2f		",p[i].ks);
        printf("%.2f		",p[i].jieshu);
        printf("%.2f		",p[i].zhouz);
        printf("%.2f		",p[i].Dzhouz);
        printf("\\n");
    }
}
 

int main()
{
    int N; 
 
    printf("请输入进程数目：");
    scanf("%d",&N);
 
    struct sjf a[10]; 
    input(a,N);
    sort_arr(a,N);
    sort_ing(a,N);
    run(a,N);
    show(a,N);
    printf("\\n");
 
    int i;
    float average_zhouz=0;
    float average_Dzhouz=0;
    for(i=0; i<N; i++)
    {
        average_zhouz+=a[i].zhouz;
        average_Dzhouz+=a[i].Dzhouz;
    }
    average_zhouz/=N;
    average_Dzhouz/=N;
    printf("采用短进程优先算法算得平均周转时间 = %.2f \\n",average_zhouz);
    printf("采用短进程优先算法算得平均带权周转时间 = %.2f \\n",average_Dzhouz);
    return 0;
}
      
