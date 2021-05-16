#include<iostream>
#include<string>

int main() {
  double n;
  std::string p,t;
  bool variable=true;
  std::cout<<"hello, please enter the temperature"<<std::endl;
  std::cin>>n;
  std::cout<<"Now enter the abbreviation of the unit please"<<std::endl;
  std::cin>>p;
  if ((p== "C") || (p== "c")){
    n=(n*1.8)+32;
    t= "F";
  }
  else if ((p== "F") || (p== "f")){
    n= (n-32)/1.8;
    t= "C";

  }
  else{
    variable=false;
  }
  if (variable==true){
    std::cout<<"The temperature converted is "<<n<<" "<<t<<std::endl;
  }
  else{
    std::cout<<"Error, the unit is not recognised"<<std::endl;
  }
}
