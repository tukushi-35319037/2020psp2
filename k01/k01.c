#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int i);
extern double var_online(double val,double ave,double square_ave,int i);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    int i=0;
    double ave=0;
    double var=0,square_ave=0,var_h=0;
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
        i++;
        
        
        var=var_online(val,ave,square_ave,i);
      ave=ave_online( val,ave, i);
     square_ave=ave_online(pow(val,2),square_ave,i);



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
var_h=i*var/(i-1);
printf("ave=%f\n",ave);
printf("var=%f\n",var);
printf("h_var=%f\n",var_h);
printf("h_ave=%f\n",ave);
    return 0;



}

 double ave_online(double val ,double ave,int i)
{
        return(((i-1)*ave/i) + (val/i));

}
 double var_online(double val,double ave,double square_ave,int i)
{
    return(((i-1)*square_ave/i)+pow(val,2)/i)-pow((((i-1)*ave/i)+(val/i)),2);
}