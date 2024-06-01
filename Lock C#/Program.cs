public class SafeCounter
{
    private int count = 0;
    private readonly object lockObject = new object();

    public void Increment()
    {
        lock (lockObject)
        {
            count++;
        }
    }

    public int GetCount()
    {
        lock (lockObject)
        {
            return count;
        }
    }
}

class Program
{
    static void Main()
    {
        var counter = new SafeCounter();
        var threads = new Thread[10];

        for (int i = 0; i < 10; i++)
        {
            threads[i] = new Thread(() =>
            {
                for (int j = 0; j < 1000; j++)
                {
                    counter.Increment();
                }
            });
            threads[i].Start();
        }

        foreach (var thread in threads)
        {
            thread.Join();
        }

        Console.WriteLine($"Кінцевий рахунок: {counter.GetCount()}");
    }
}
