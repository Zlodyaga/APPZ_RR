public class Resource : IDisposable
{
    public Resource()
    {
        // Захоплення ресурсу
        Console.WriteLine("Ресурс захоплено");
    }

    public void UseResource()
    {
        Console.WriteLine("Ресурс використовується");
    }

    public void Dispose()
    {
        // Звільнення ресурсу
        Console.WriteLine("Ресурс звільнено");
    }
}

class Program
{
    static void Main()
    {
        using (var resource = new Resource())
        {
            resource.UseResource();
        }
    }
}
