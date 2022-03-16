#include <stdio.h>
#include<string.h>
#define SIZE 257
#define SIZE1 514

void mul(char str1[],char str2[],int a,int b)
{
    char mul[SIZE1];
    char temp1[SIZE1];
    char temp[SIZE1];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=a-1;
    lb=b-1;

    for(i=0;i<=la;i++)
    {
        str1[i] = str1[i] - 48;
    }

    for(i=0;i<=lb;i++)
    {
        str2[i] = str2[i] - 48;
    }

    for(i=lb;i>=0;i--)
    {
        r=0;
        for(j=la;j>=0;j--)
        {
            temp[k++] = (str2[i]*str1[j] + r)%10;
            r = (str2[i]*str1[j]+r)/10;
        }
        temp[k++] = r;
        x++;
        for(y = 0;y<x;y++)
        {
            temp[k++] = 0;
        }
    }

    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++)
    {
        sum =0;
        y=0;
        for(j=1;j<=lb+1;j++)
        {
            if(i <= la+j)
            {
                sum = sum + temp[y+i];
            }
            y += j + la + 1;
        }
        temp1[k++] = (sum+r) %10;
        r = (sum+r)/10;
    }
    temp1[k] = r;
    j=0;
    for(i=k-1;i>=0;i--)
    {
        mul[j++]=temp1[i] + 48;
    }
    mul[j]='\0';

    printf("%s",mul);
    
}

void sub(char str1[],char str2[],int a,int b)
{
    int x,y,i,large,diff,borrow=0;
    char str4[SIZE];
    
    (a>=b)?(large=a):(large=b);
    
    for(i=large-1;i>=0;i--)
    {
        if(a-1>=0)
        {
            x=str1[a-1]-48;
        }
        else
        {
            x=0;
        }
        
        if(b-1>=0)
        {
            y=str2[b-1]-48;
        }
        else
        {
            y=0;
        }
        
        if((x-borrow)>=y)
        {
            diff=x-y-borrow;
            str4[i]=diff;
            borrow=0;
        }
        else
        {
            diff=(x+10)-y-borrow;
            str4[i]=diff;
            borrow=1;
        }
        
        a--;
        b--;
    }
    str4[large]='\0';

    for(i=0;i<large;i++)
    {
        printf("%d",str4[i]);
    }
}

void add(char str1[],char str2[],int a,int b)
{
    int x,y,i,large,sum,carry=0;
    char str3[SIZE+1];
    
    (a>=b)?(large=a):(large=b);
    
    for(i=large;i>0;i--)
    {
        if(a-1>=0)
        {
            x=str1[a-1]-48;
        }
        else
        {
            x=0;
        }
        
        if(b-1>=0)
        {
            y=str2[b-1]-48;
        }
        else
        {
            y=0;
        }
        
        sum=x+y+carry;
        str3[i]=sum%10;
        carry=sum/10;
        
        a--;
        b--;
    }
    str3[i]=carry;
    str3[large+1]='\0';

    for(i=0;i<=large;i++)
    {
        printf("%d",str3[i]);
    }
}

int main()
{
    char str1[SIZE],str2[SIZE];
    int a,b,flag;
    
    printf("Enter first value:\n");
    scanf("%s",str1);
    printf("Enter second value:\n");
    scanf("%s",str2);
    
    a=strlen(str1);
    b=strlen(str2);
    
    printf("Sum of %s and %s is: ",str1,str2);
    add(str1,str2,a,b);
    
    printf("\nDifference of %s and %s is: ",str1,str2);
    if(a==b)
    {
        flag=strcmp(str1,str2);
        
        if(flag>0)
        {
           sub(str1,str2,a,b);
        }
        else if(flag<0)
        {
            printf("-");
            sub(str2,str1,b,a);
        }
        else
        {
            printf("0");
        }
    }
    else
    {
        if(a>b)
        {
            sub(str1,str2,a,b);
        }
        else
        {
            printf("-");
            sub(str2,str1,b,a);
        }
    }
    
    printf("\nProduct of %s and %s is: ",str1,str2);
    mul(str1,str2,a,b);

    return 0;
}