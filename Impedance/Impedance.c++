#include <iostream>
#include <vector>
#include <complex>
 
class ImpedanceDevice{
public:
 
    virtual std::complex<double> get_impedance(double omega) const = 0;

    virtual ~ImpedanceDevice() { }
};
 
class Resistor : public ImpedanceDevice{
public:
 
    Resistor(double r) : resistance(r) { }
    
    std::complex<double> get_impedance(double omega) const {
 
        std::complex<double> impedance(resistance);
 
        return impedance;
    }
 
private:
    double resistance ;
};
class Inductor : public ImpedanceDevice{
  public:
   Inductor(double l) : inductance(l) { }
   std::complex<double> get_impedance (double omega) const {
     std::complex<double> impedance (0,omega*inductance);

     return impedance;
   }

private :
 double inductance;
 };

 
 
class Capacitor : public ImpedanceDevice{
public:
    Capacitor(double c) : capacitance(c) { }
 
    std::complex<double>get_impedance(double omega) const {
 
        std::complex<double> impedance(0, - 1/(omega * capacitance));
        
        return impedance;
    }
 
private :
 
    double capacitance;
 
};
 
 
int main(){
    std::vector<ImpedanceDevice*> devices;
 
    ImpedanceDevice* tmp_id;
    std::string dev_choice;
    double dev_feature;
    int n_devices;
 
    std::cout << "please enter number of devices:" << std::endl;
    std::cin >> n_devices ;
 
    for(int i=0; i<n_devices ; i++){
 
        std::cout << "please enter device choice (r/c/i):" << std::endl;
        std::cin >> dev_choice;
 
        if(dev_choice=="c"){
            std::cout << "please enter capacitance (F):" << std::endl;
            std::cin >> dev_feature;
            tmp_id = new Capacitor(dev_feature);
        }
        else if (dev_choice=="i"){
          std::cout<<"please enter the inductance (H)"<<std::endl;
          std::cin>> dev_feature;
          tmp_id=new Inductor(dev_feature);
        }
        else{
             std::cout << "please enter resistance (Ohm):" << std::endl;
             std::cin >> dev_feature;
             tmp_id = new Resistor(dev_feature);
        }
 
        devices.push_back(tmp_id);
 
    }
 
    double f, omega;
    std::cout << "please enter frequency (Hz):" << std::endl;
    std::cin >> f;
    omega = 2 * 3.14 * f; 

 
    for(int i=0; i < devices.size(); i++){
        std::cout << "impedance of device " << i + 1 << ": " << std::endl;
 
        std::cout << devices[i]->get_impedance(omega) << " Ohms" << std::endl;
 
    }
 
    for(int i = 0; i < devices.size(); i++) {
        delete devices[i];
    }
}
