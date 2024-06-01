# APPZ_RR

# UML-діаграми для шаблонів проектування

Цей файл містить UML-діаграми для чотирьох шаблонів проектування: Resource Acquisition Is Initialization (RAII), Decorator, Protocol Stack та Lock.

## Creational Pattern: Resource Acquisition Is Initialization (RAII)

### Діаграма класів (C#)

```mermaid
classDiagram
    class Resource {
        +Resource()
        +void UseResource()
        +void Dispose()
    }
    Resource --|> IDisposable
```

### Діаграма класів (C++)
```mermaid
classDiagram
    class Resource {
        +Resource()
        +void UseResource()
        +~Resource()
    }
```
## Structural Pattern: Decorator

### Діаграма класів (C#)

```mermaid
classDiagram
    class IComponent {
        <<interface>>
        +void Operation()
    }

    class ConcreteComponent {
        +void Operation()
    }

    class Decorator {
        #IComponent _component
        +Decorator(IComponent component)
        +void Operation()
    }

    class ConcreteDecorator {
        +ConcreteDecorator(IComponent component)
        +void Operation()
        +void AddedBehavior()
    }

    IComponent <|-- ConcreteComponent
    IComponent <|-- Decorator
    Decorator <|-- ConcreteDecorator
    Decorator --> IComponent
```

### Діаграма класів (C++)
```mermaid
classDiagram
    class Component {
        <<abstract>>
        +void Operation()
    }

    class ConcreteComponent {
        +void Operation()
    }

    class Decorator {
        #Component* component_
        +Decorator(Component* component)
        +void Operation()
    }

    class ConcreteDecorator {
        +ConcreteDecorator(Component* component)
        +void Operation()
        +void AddedBehavior()
    }

    Component <|-- ConcreteComponent
    Component <|-- Decorator
    Decorator <|-- ConcreteDecorator
    Decorator --> Component
```
## Behavioral Pattern: Protocol Stack

### Діаграма класів (C#)

```mermaid
classDiagram
    class Protocol {
        #Protocol NextProtocol
        +void SetNextProtocol(Protocol nextProtocol)
        +void Send(string data)
        +void Receive(string data)
    }

    class ConcreteProtocolA {
        +void Send(string data)
        +void Receive(string data)
    }

    class ConcreteProtocolB {
        +void Send(string data)
        +void Receive(string data)
    }

    Protocol <|-- ConcreteProtocolA
    Protocol <|-- ConcreteProtocolB
    Protocol --> Protocol : NextProtocol
```

### Діаграма класів (C++)
```mermaid
classDiagram
    class Protocol {
        #Protocol* nextProtocol_
        +void SetNextProtocol(Protocol* nextProtocol)
        +void Send(const std::string& data)
        +void Receive(const std::string& data)
    }

    class ConcreteProtocolA {
        +void Send(const std::string& data)
        +void Receive(const std::string& data)
    }

    class ConcreteProtocolB {
        +void Send(const std::string& data)
        +void Receive(const std::string& data)
    }

    Protocol <|-- ConcreteProtocolA
    Protocol <|-- ConcreteProtocolB
    Protocol --> Protocol : nextProtocol_
```
## Concurrency Pattern: Lock

### Діаграма класів (C#)

```mermaid
classDiagram
    class SafeCounter {
        -int count
        -object lockObject
        +void Increment()
        +int GetCount()
    }
```

### Діаграма класів (C++)
```mermaid
classDiagram
    class SafeCounter {
        -int count
        -std::mutex mtx
        +void Increment()
        +int GetCount()
    }
```
