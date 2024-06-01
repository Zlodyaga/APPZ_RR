public abstract class Protocol
{
    protected Protocol NextProtocol;

    public void SetNextProtocol(Protocol nextProtocol)
    {
        NextProtocol = nextProtocol;
    }

    public abstract void Send(string data);
    public abstract void Receive(string data);
}

public class ConcreteProtocolA : Protocol
{
    public override void Send(string data)
    {
        Console.WriteLine($"ProtocolA надсилає: {data}");
        NextProtocol?.Send(data);
    }

    public override void Receive(string data)
    {
        Console.WriteLine($"ProtocolA отримує: {data}");
        NextProtocol?.Receive(data);
    }
}

public class ConcreteProtocolB : Protocol
{
    public override void Send(string data)
    {
        Console.WriteLine($"ProtocolB надсилає: {data}");
        NextProtocol?.Send(data);
    }

    public override void Receive(string data)
    {
        Console.WriteLine($"ProtocolB отримує: {data}");
        NextProtocol?.Receive(data);
    }
}

class Program
{
    static void Main()
    {
        var protocolA = new ConcreteProtocolA();
        var protocolB = new ConcreteProtocolB();
        protocolA.SetNextProtocol(protocolB);

        protocolA.Send("Hello");
        protocolA.Receive("World");
    }
}
