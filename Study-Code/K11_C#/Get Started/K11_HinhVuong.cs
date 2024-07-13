using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            double a = Convert.ToInt32(Console.ReadLine());

            if (a < 0) { Console.Write("NHAPSAI"); }

            else { Console.WriteLine(Math.Sqrt(a)); }
        }
    }
}
