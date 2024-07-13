using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            double a = Convert.ToInt32(Console.ReadLine());
            double b = Convert.ToInt32(Console.ReadLine());

            double result = (a+Math.Sin(b)) / (Math.Sqrt(a*a + b*b + 1));

            Console.WriteLine(result.ToString("F6"));
        }
    }
}
