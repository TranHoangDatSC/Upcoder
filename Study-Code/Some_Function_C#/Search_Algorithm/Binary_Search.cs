using System;

namespace Practice_C_Sharp
{
    internal class Program
    {
        static int Binary_Search(int[] arr, int size, int target)
        {
            int left = 0;
            int right = size - 1;

            while(left <= right)
            {
                int mid = (left + right) / 2;

                if (arr[mid] < target)
                {
                    left = mid + 1;
                }
                else if (arr[mid] == target)
                {
                    return mid;
                }
                else
                {
                    right = mid - 1;
                }
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

            int result = Binary_Search(array, size, target);
            Console.Write($"Position of target is: {result}");

        }
    }
}
