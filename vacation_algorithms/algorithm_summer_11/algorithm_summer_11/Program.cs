using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace algorithm_summer_11
{
    class Program
    {
        static int SumPerValue(int num)
        {
            int[] fixedNum = num.ToString()
                                .ToArray()
                                .Select(count => int.Parse(count.ToString()))
                                .ToArray();  // 하은쌤 예제코드 고마워요 크흡..

            return fixedNum.Sum();
            
        }
        static void Main(string[] args)
        {
            int nNum = int.Parse(ReadLine());

            if (nNum <1)
            {
                WriteLine("자연수 이어야 합니다.");

                return;
            }

            WriteLine(SumPerValue(nNum));
        }
    }
}
