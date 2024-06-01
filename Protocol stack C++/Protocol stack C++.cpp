#include <iostream>
#include <string>

class Protocol {
protected:
    Protocol* nextProtocol_ = nullptr;

public:
    virtual ~Protocol() = default;

    void SetNextProtocol(Protocol* nextProtocol) {
        nextProtocol_ = nextProtocol;
    }

    virtual void Send(const std::string& data) = 0;
    virtual void Receive(const std::string& data) = 0;
};

class ConcreteProtocolA : public Protocol {
public:
    void Send(const std::string& data) override {
        std::cout << "ProtocolA надсилає: " << data << std::endl;
        if (nextProtocol_) nextProtocol_->Send(data);
    }

    void Receive(const std::string& data) override {
        std::cout << "ProtocolA отримує: " << data << std::endl;
        if (nextProtocol_) nextProtocol_->Receive(data);
    }
};

class ConcreteProtocolB : public Protocol {
public:
    void Send(const std::string& data) override {
        std::cout << "ProtocolB надсилає: " << data << std::endl;
        if (nextProtocol_) nextProtocol_->Send(data);
    }

    void Receive(const std::string& data) override {
        std::cout << "ProtocolB отримує: " << data << std::endl;
        if (nextProtocol_) nextProtocol_->Receive(data);
    }
};

int main() {
    ConcreteProtocolA protocolA;
    ConcreteProtocolB protocolB;
    protocolA.SetNextProtocol(&protocolB);

    protocolA.Send("Hello");
    protocolA.Receive("World");

    return 0;
}
