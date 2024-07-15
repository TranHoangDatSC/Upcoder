using System;
using System.ComponentModel;

namespace Practice_C_Sharp
{
    internal class Program
    {
        static int Linear_Search(int[] arr, int size, int target)
        {
            for(int i = 0; i < size; i++)
            {
                if (arr[i] == target)
                    return i;
            }
            return -1;
        }
        public static void Main(string[] args)
        {
            int size = Convert.ToInt32(Console.ReadLine());
            int target = Convert.ToInt32(Console.ReadLine());
            int[] array = new int[size];

            for(int  i = 0; i < size; i++)
            {
                array[i] = Convert.ToInt32(Console.ReadLine());
            }

            int result = Linear_Search(array, size, target);
            Console.Write($"Position of target is: {result}");

        }
    }
}
