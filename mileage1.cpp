#include <iostream>

using namespace std;

class Mpg_log{
    double init_mileage;
    double last_odometer;
    double this_odometer;
    double this_gas;
    double sum_gas;
public:
    Mpg_log(double starting_odometer);
    void buy_gas(double odometer, double gas);
    double get_current_mpg();
    double get_average_mpg();
    double get_sum_gas(double total_gas);
    
};

Mpg_log::Mpg_log(double starting_odometer)
{
    last_odometer = starting_odometer;
    init_mileage = starting_odometer;
    
}

void Mpg_log::buy_gas(double odometer, double gas)
{
    this_odometer = odometer;
    this_gas = gas;
    sum_gas = sum_gas + gas;
}

double Mpg_log::get_current_mpg()
{
    double result;
    result = (this_odometer - last_odometer) / this_gas;
    last_odometer = this_odometer;
    return result;
}

double Mpg_log::get_average_mpg()
{
    return (this_odometer - init_mileage) / sum_gas;
}

int main(){
    double starting_odometer,odometer,gas;
    cout << "Initial odometer: ";
    cin >> starting_odometer;
    Mpg_log mpg_log(starting_odometer);
    do
    {
        cout << "Odometer: ";
        cin >> odometer;
        cout << "Gallons: ";
        cin >> gas;
        mpg_log.buy_gas(odometer,gas);
        cout << "This mpg: " << mpg_log.get_current_mpg() <<'\n';
        cout << "Ave mpg: " << mpg_log.get_average_mpg() << '\n';
    }
    while(odometer != 0);{
        cout << "Exiting ...\n";
    }
}
