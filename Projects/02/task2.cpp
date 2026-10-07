#include<iostream>
using namespace std;
class NuclearReactor{
    private:
       double coreTemperature;
    public:
    void setTemperature(double temp){
        if (temp> 1000.0)
            cout <<"Meltdown Prevention: Cannot set temp that high!"<< endl;
        else
            coreTemperature =temp;
    } double* getTemperaturePoint(){
        return & coreTemperature;
    }
};
int main(){
    NuclearReactor reactor;
    reactor.setTemperature(500.0);
    double* temp= reactor.getTemperaturePoint();
    *temp= 1500.0;
    cout<<" Core Temperature: "<< *temp<< endl;
    return 0;

}