#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
int gender,id;
char gender[10];
double height;
}man_data;

int main(void)
{
    int i,t_gender,input_id,n=0;
    char fname_height[FILENAME_MAX],fname_ID[FILENAME_MAX];
    char buf_height[256],buf_ID[254];
    man_data man[100];
    FILE *fp_height, *fp_ID;

    printf("input the filename of sample_heght;");
    fgets(fname_height,sizeof(fname_height),stdin);
    fname_height[strlen(fname_height)-1]='\0';
    printf("the filename of sample_ID;");
    fgets(fname_ID,sizeof(fname_ID),stdin);
    fname_ID[strlen(fname_ID)-1]='\0';
    printf("Which ID?;");
    scanf("%d",&input_id);

    fp_height = fopen(fname_height,"r");

    if(fp_height==NULL)
    {
        fputs("file open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fp_ID = fopen(fname_ID,"r");
    if(fp_ID==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fgets(buf_height,sizeof(buf_height),fp_height);
while(fgets(buf_height,sizeof(buf_height),fp_height) != NULL) && fgets(buf_ID,sizeof(buf_ID),buf_ID) !=NULL)
{
    if(i==-1)
    {
        i++;
        continue;
    }
    sscanf(buf,"%d,%lf",&data[i].gender,&data[i].height);
    i++;
}
}

