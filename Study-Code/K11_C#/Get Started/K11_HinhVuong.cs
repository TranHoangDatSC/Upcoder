using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            double a = Convert.ToDouble(Console.ReadLine());

            if (a < 0) { Console.Write("NHAP SAI"); }

            else { Console.WriteLine(Math.Sqrt(a)); }
        }
    }
}
