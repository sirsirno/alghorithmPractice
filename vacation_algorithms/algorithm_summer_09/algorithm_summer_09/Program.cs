using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

// 9번 문제

namespace algorithm_summer_09
{
    class Program
    {

        static long LowerSortLong(long num)
        {
            long fixedNum = 0;
            string stringedNum = num.ToString();
            char[] arrayedNum = stringedNum.ToArray();

            Array.Sort(arrayedNum);
            Array.Reverse(arrayedNum);

            stringedNum = string.Join("", arrayedNum);

            fixedNum = long.Parse(stringedNum);

            return fixedNum;
        }
        static void Main(string[] args)
        {
            long num = int.Parse(ReadLine());

            if (num < 1 || num > 8000000000)
            {
                WriteLine("1 이상 8000000000 이하 이어야 합니다");
                return;
            }

            WriteLine(LowerSortLong(num));
        }
    }
}
