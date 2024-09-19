int CountOnes(unsigned int n)
{
if (n==0)
return 0;
else if (n==1)
return 1;
else
{
return CountOnes(n/2)+ CountOnes(n%2);
}
}
//4=100 so output will be 1
//5=101 so output will be 2
