#include<stdio.h>
int main()
{
  int T;
  scanf("%d\n",&T);
  while(T--)
  {
	 int a[3][3],i,j,s1,s2,s3,count=0;
	 for(i=0;i<3;i++)
	  for(j=0;j<3;j++)
		 scanf("%d",&a[i][j]);

	 for(i=0;i<3;i++)
	  for(j=0;j<3;j++)
	  {
			s1=a[i][0]-a[j][0];
			s2=a[i][1]-a[j][1];
			s3=a[i][2]-a[j][2];
			if(s1>=0&&s2>=0&&s3>=0)
				if(s1>0||s2>0||s3>0)
				  count++;
			else if(s1<=0&&s2<=0&&s3<=0)
				if(s1<0||s2<0||s3<0)
				  count++;
	  }
	  if(count==3)
		  printf("yes\n");
	  else
	  printf("no\n");

  }

	return 0;
} 