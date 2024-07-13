using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            double a = Convert.ToInt32(Console.ReadLine());

            double result = (Math.Abs(2*a + 3) / Math.Cos(a)) + Math.Sqrt(2 + Math.Cos(a));

            Console.WriteLine(result.ToString("F2"));
        }
    }
}
