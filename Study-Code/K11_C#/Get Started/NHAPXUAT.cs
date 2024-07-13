using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int a = Convert.ToInt32(Console.ReadLine());
            int b = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine($"{a}+{b}={a+b}");
        }
    }
}
