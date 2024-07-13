using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            double a = Convert.ToDouble(Console.ReadLine());

            if (a < 2.5) { Console.Write("NHAPSAI"); }

            else 
            {
                double result = Math.Sqrt(2 * a - 5);

                Console.WriteLine(result.ToString("F5")); 
            }
        }
    }
}
