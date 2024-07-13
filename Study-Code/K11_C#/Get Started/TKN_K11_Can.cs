using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            double a = Convert.ToInt32(Console.ReadLine());

            double result = Math.Sqrt(a + Math.Sqrt(a + Math.Sqrt(a)));

            Console.WriteLine(result.ToString("F5"));
        }
    }
}
