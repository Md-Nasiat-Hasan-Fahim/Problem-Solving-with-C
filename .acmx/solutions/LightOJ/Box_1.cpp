#include<stdio.h>
int main(){

int t;
scanf("%d",&t);

while(t--){

int row,col,n;

scanf("%d",&n);

for(row=1;row<=n;row++)
{

for(col=1;col<=n;col++)
{
printf("*");
}

printf("\n");

}
printf("\n");
}

return 0;
}