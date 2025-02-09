#include<stdio.h>
#include<stdbool.h>
bool issafe(int allocres[10][10], int availres[10], int maxres[10][10], int needres[10][10], int r, int p)
{
    int safeseq[p];
    bool finish[10]={0}; 
    int i,j;
    int work[10];
    for (i=0;i<r;i++)
    {
        work[i]=availres[i];
    }

    int count=0;
    while (count<p)
    {
        bool found =0;
        for (i=0;i<p;i++) // Looping for each process
        {
            if (finish[i]==false)
            {
                bool canallocate=1;
                for (j=0;j<r;j++)
                {
                    if (needres[i][j]>work[j])
                    {
                        canallocate=0;
                        break; // current process exits and then goes to next process
                    }
                }
                if (canallocate)
                {
                    for (j=0;j<r;j++)
                    {
                        work[j]=work[j]+allocres[i][j];
                    }
                    safeseq[count++]=i;
                    finish[i]=1;
                    found =1;
                }
            }
        }
        if (found == 0)
        {
            printf("System is not in safe state\n");
            return false;
        }
    }
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < p; i++) 
    {
        printf("%d ", safeseq[i]);
    }
    printf("\n");

    return true;
}
void main()
{
    int p,r;
    int i,j;
    printf("Enter the number of resources\n");
    scanf("%d",&r);
    printf("Enter the number of processes\n");
    scanf("%d",&p);

    int allocres[10][10],maxres[10][10],needres[10][10],availres[10];

    printf("Enter the allocated resources\n");
    // rows=processes(p), columns=resources(r)
    for (i=0;i<p;i++)
    {
        printf("Enter allocated resources for process %d\n",i+1);
        for (j=0;j<r;j++)
        {
            scanf("%d",&allocres[i][j]);
        }

    }

    printf("Enter the maximum resources\n");
     // rows=processes(p), columns=resources(r)
    for (i=0;i<p;i++)
    {
        printf("Enter maximum resources for process %d\n",i+1);
        for (j=0;j<r;j++)
        {
            scanf("%d",&maxres[i][j]);
        }
    }

    printf("Enter the available resource\n");
    for (i=0;i<r;i++)
    {
        scanf("%d",&availres[i]);
    }

    
    for (i=0;i<p;i++)
    {
        for (j=0;j<r;j++)
        {
            needres[i][j]=maxres[i][j]-allocres[i][j];
        }
    }

    printf("The needed resources\n");
    for (i=0;i<p;i++)
    {
        for (j=0;j<r;j++)
        {
            printf("%d",needres[i][j]);
        }
        printf("\n");
    }


    issafe(allocres,availres,maxres,needres,r,p);

}