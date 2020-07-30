#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct man_data
{
int gender;
int id;
double height;
};

int main(void)
{
    int ID,i=0,nothing=0;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE *fp;
    struct man_data data[100];

    printf("input the filename of sample_heght;");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample_ID:%s\n",fname);
    fp = fopen(fname,"r");
    if(fp ==NULL)
    {
        fputs("file open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    fgets(buf,sizeof(buf),fp);
   while(fgets(buf,sizeof(buf),fp) != NULL)
   {
       sscanf(buf,"%d,%lf",&data[i].gender,&data[i].height);
       i++;
   }
    if(fclose(fp) == EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("input filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("filename of sample:%s\n",fname);
    fp=fopen(fname,"r");
    if(fp ==NULL)
    {
        fputs("file open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
   while(fgets(buf,sizeof(buf),fp) != NULL)
   {
       sscanf(buf,"%d",&data[i].id);
       i++;
   }
    if(fclose(fp) == EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("which ID's data do you want?\n");
    scanf("%d",&ID);
    i=0;

    while(i<14)
    {
     if(data[i].id == ID)
     {
         nothing =1;
         if(data[i].gender == 1)
         {
             printf("ID:%d gender:male height:%lf",data[i].id,data[i].height);
         }
         else
         {
          printf("ID:%d gender:female height:%lf",data[i].id,data[i].height);
         }
          
      }
      i++;
    }
    if(nothing ==0)
     {printf("No data");}
    return 0;
}


