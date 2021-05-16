#include<iostream>

int main () {
  int n,i,m;

  double f;

  std::cin>>n;
  m=n;

  f=1;

  for (i=0; n!=0; i++){
    f= f*n;
    n=n-1;
  }

std::cout<<m<<"!="<<f;
}
