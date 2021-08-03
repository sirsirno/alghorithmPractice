using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace algorithm_summer_14
{
    class Program
    {

        static int[] ConvertStrToInt(char[] str)
        {
            int[] result = new int[str.Length];

            for (int i = 0; i < str.Length; i++)
            {
                result[i] = str[i] - '0';
            }

            return result;
        }
        static void Main(string[] args)
        {
            
            char[] cStr = ReadLine().ToCharArray();

            if(cStr[0] == '0' || cStr.Length < 1 || cStr.Length > 5)
            {
                WriteLine("길이는 1에서 5이며, 숫자와 부호로만 이루어 져야 합니다. 또한 0으로 시작하지 않습니다.");

                return;
            }

            foreach (var item in ConvertStrToInt(cStr))
            {
                WriteLine(item.GetType());

                WriteLine(item);
            }
        }
    }
}
