#include <iostream>

class Component {
public:
    virtual ~Component() = default;
    virtual void Operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    void Operation() const override {
        std::cout << "ConcreteComponent Операція" << std::endl;
    }
};

class Decorator : public Component {
protected:
    const Component* component_;
public:
    Decorator(const Component* component) : component_(component) {}

    void Operation() const override {
        component_->Operation();
    }
};

class ConcreteDecorator : public Decorator {
public:
    ConcreteDecorator(const Component* component) : Decorator(component) {}

    void Operation() const override {
        Decorator::Operation();
        AddedBehavior();
    }

    void AddedBehavior() const {
        std::cout << "ConcreteDecorator Додана Поведінка" << std::endl;
    }
};

int main() {
    const Component* component = new ConcreteComponent();
    const Component* decorator = new ConcreteDecorator(component);
    decorator->Operation();
    delete component;
    delete decorator;
    return 0;
}
