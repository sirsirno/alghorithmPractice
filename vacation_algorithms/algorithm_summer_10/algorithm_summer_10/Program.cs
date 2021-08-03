using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

//10번 문제 

namespace algorithm_summer_10
{
    class Program
    {
        static int[] ConvertReverseArray(int num)
        {
            string stringedNum = num.ToString();
            char[] cArrayedNum = stringedNum.ToCharArray();
            int[] reversedResult = new int[cArrayedNum.Length];

            Array.Sort(cArrayedNum);
            Array.Reverse(cArrayedNum);

            for (int i = 0; i < reversedResult.Length; i++)
            {
                reversedResult[i] = cArrayedNum[i] - '0'; // 문자를 int로 변환 꼼수 ㅋㅋ
            }

            return reversedResult;
        }
        static void Main(string[] args)
        {
            int nNum = int.Parse(ReadLine());

            if(nNum < 1)
            {
                WriteLine("자연수 이어야 합니다.");
                return;
            }

            foreach(var item in ConvertReverseArray(nNum))
            {
                WriteLine(item);
                WriteLine(item.GetType());
            }

        }
    }
}
