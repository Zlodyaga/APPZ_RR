public interface IComponent
{
    void Operation();
}

public class ConcreteComponent : IComponent
{
    public void Operation()
    {
        Console.WriteLine("ConcreteComponent Операція");
    }
}

public class Decorator : IComponent
{
    protected IComponent _component;

    public Decorator(IComponent component)
    {
        _component = component;
    }

    public virtual void Operation()
    {
        _component.Operation();
    }
}

public class ConcreteDecorator : Decorator
{
    public ConcreteDecorator(IComponent component) : base(component) { }

    public override void Operation()
    {
        base.Operation();
        AddedBehavior();
    }

    void AddedBehavior()
    {
        Console.WriteLine("ConcreteDecorator Додана Поведінка");
    }
}

class Program
{
    static void Main()
    {
        IComponent component = new ConcreteComponent();
        IComponent decorator = new ConcreteDecorator(component);
        decorator.Operation();
    }
}
