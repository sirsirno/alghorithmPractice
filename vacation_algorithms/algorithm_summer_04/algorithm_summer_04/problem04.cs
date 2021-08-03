using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace algorithm_summer_04
{
    class Program
    {
        static int ShowAverageArr(int[] arr)
        {
            int totalValue = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                totalValue += arr[i];
            }

            return (totalValue / arr.Length);
        }


        static void Main(string[] args)
        {
            Random ran = new Random();
            int arrCount = int.Parse(ReadLine());
            if (arrCount <1 || arrCount > 100)
            {
                WriteLine(" 배열의 크기 값은 1이상, 100 이하입니다");
                return;
            }
            int[] iArr = new int[arrCount];

            for (int i = 0; i < iArr.Length; i++)
            {
                iArr[i] = ran.Next(-10000, 10000);
            }



            WriteLine(ShowAverageArr(iArr));
        }
    }
}
