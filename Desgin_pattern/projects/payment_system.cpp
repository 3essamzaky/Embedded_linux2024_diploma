#include <iostream>
#include <memory>


class PaymentProcessor {
public:
    virtual void ProcessPayment(double amount) = 0;
    virtual ~PaymentProcessor() = default;

};



class PAyPalPayment {
    public:

    void sendPayment(double amount) {
        std::cout << "Sending payment of $" << amount << " via PayPal" << std::endl;
    }
};

class PyPalAdapter : public PaymentProcessor {

    PAyPalPayment *paypal;
public:
    PyPalAdapter(PAyPalPayment *paypal) : paypal(paypal) {
            
    }
        
    void ProcessPayment(double amount) override {
        paypal->sendPayment(amount);
    }
    ~PyPalAdapter() {
        delete paypal;
    }
    


};




class locakbankPAyment {
    public:
    void charge(double amount) {
        std::cout << "Charging $" << amount << " via Local Bank" << std::endl;
    } 
};
class localbankAdapter : public PaymentProcessor {
public:
    locakbankPAyment *localbank;
    localbankAdapter(locakbankPAyment *localbank) : localbank(localbank) {
            
    }
    void ProcessPayment(double amount) override {
        localbank->charge(amount);
    }
};

class PaymentProcessorFactory {
    public:
        static std::shared_ptr<PaymentProcessor> CreateProcessor(const std::string& type) {
            if (type == "paypal") {
                return std::make_shared<PyPalAdapter>(new PAyPalPayment());
            } else if (type == "localbank") {
                return std::make_shared<localbankAdapter>(new locakbankPAyment());
            }
            return nullptr;
        }
    
    
    virtual ~PaymentProcessorFactory() = default;
};



int main() {
    
    auto paypalprocessor = PaymentProcessorFactory::CreateProcessor("paypal");
    paypalprocessor->ProcessPayment(100.0);
    
    auto localbankprocessor = PaymentProcessorFactory::CreateProcessor("localbank");
    localbankprocessor->ProcessPayment(200.0);

    


    return 0;
}
