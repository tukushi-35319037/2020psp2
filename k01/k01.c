#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int i);
extern double var_online(double ave,double val,double square_ave,int i);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    int i=0;
    double ave=0;
    double var,square_ave,var_h;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        i=i+1;
        ave=ave_online( ave, val, i);
        square_ave=(i-1)*ave*ave+val*val/i;
        var=var_online(i,square_ave,val,ave);

    



    }
var_h=i*var/(i-1);
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("平均は%f",ave);
printf("分散は%f",var);
printf("不変分散は%f",var_h);
    return 0;



}

 double ave_online(double ave ,double val,int i)
{
        return((i-1)*ave/i + val/i);

}
 double var_online(double ave,double val,double square_ave,int i)
{
    return( ((i-1)*square_ave/i+val*val/i)-((i-1)*ave/i+val/i));
}